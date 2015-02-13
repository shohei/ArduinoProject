#include <SPI.h>		// for Ethernet.h
#include <Ethernet.h>	// for Ethernet
#include <Servo.h> 

#define SERVOPIN1	(7)
#define SERVOPIN2	(8)

#define LINEBUFFERSIZE	(128)
#define DELIMITER	("&")
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 


unsigned char MACADDRESS[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
unsigned char IPADDRESS[] = { 192, 168, 1, 177 };
EthernetServer g_server(80);

void setup()
{
	Ethernet.begin(MACADDRESS, IPADDRESS);
	g_server.begin();
        myservo1.attach(SERVOPIN1);  // attaches the servo on pin to the servo object
        myservo2.attach(SERVOPIN2);
              
        Serial.begin(9600);
}

// HTML出力
void PrintHtml( EthernetClient& client, boolean sw1, boolean sw2, boolean sw1_off, boolean sw2_off)
{
	client.println("HTTP/1.1 200 OK");
	client.println("Content-Type: text/html");
	client.println();

	client.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">");
	client.println("<html lang=\"ja\">");
	client.println("<head>");
	client.println("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
	client.println("<meta http-equiv=\"Content-Style-Type\" content=\"text/css\">");
	client.println("<title></title>");
	client.println("</head>");
	client.println("<body>");

	client.println("<p>");
	client.print("SW1 : "); client.print( sw1 ? "ON" : "off" ); client.println("<br>");
	client.print("SW2 : "); client.print( sw2 ? "ON" : "off" ); client.println("<br>");
	client.println("<br>");

	client.println("<hr>");

	client.println("<form method=\"post\" action=\"\">");
	client.print("<input type=\"radio\" name=\"sw1\" value=\"0\""); client.println(">SW1 OFF");
	client.print("<input type=\"radio\" name=\"sw1\" value=\"1\"" ); client.println(">SW1 ON<br>");
	client.print("<input type=\"radio\" name=\"sw2\" value=\"0\""); client.println(">SW2 OFF");
	client.print("<input type=\"radio\" name=\"sw2\" value=\"1\"" ); client.println(">SW2 ON<br>");

	client.println("<br>");
        client.println("<input type=\"submit\" value=\"送信\">");
	client.println("<input type=\"reset\" value=\"リセット\"></form>");
	client.println("<hr>");
	
	client.println("</body>");
	client.println("</html>");
}

boolean AnalyzeLineString( char* pszLine, boolean& rbSw1, boolean& rbSw2, boolean& rbSw1_off, boolean& rbSw2_off)
{
	char* pszToken = strtok(pszLine, DELIMITER);
	while(pszToken)
	{
  		if( 5 == strlen(pszToken) 
		 && 0 == strncmp(pszToken, "sw", 2) )
		{	
                        Serial.println(pszToken);
                        Serial.println(pszToken[2]);
                        Serial.println(pszToken[4]);
			if('1' == pszToken[2] && '1' == pszToken[4]){ 
                            Serial.println('rbsw1 fired.');
                            rbSw1 = true;
                            rbSw1_off = false;
                         }
                        else if('1' == pszToken[2] && '0' == pszToken[4]){
                            rbSw1_off = true; 
                            rbSw1 = false;                       
                        }
			else if( '2' == pszToken[2] && '1' == pszToken[4]){
                           rbSw2 = true; 
                           rbSw2_off = false;
                        }
                        else if( '2' == pszToken[2] && '0' == pszToken[4]){
                           rbSw2_off = true; 
                           rbSw2 = false;
                        }

		}
		pszToken = strtok(NULL, DELIMITER);
	}
	return true;
}

boolean readHttpRequest( EthernetClient& client, boolean& rbSw1, boolean& rbSw2, boolean& rbSw1_off, boolean& rbSw2_off)
{
	if( !client )
	{
		return false;
	}

	// HTTPリクエスト空行（\r\n\r\n）で終わる。ので、空行を探す。
	boolean foundRNRN = false;
	boolean currentLineIsBlank = true;
	char szLine[LINEBUFFERSIZE];
	int iIndex = 0;
	while( client.connected() )
	{
		if( !client.available() )
		{
			//continue;
			break;
		}
		
		char c = client.read();
		//Serial.print(c);
		if( '\n' == c && currentLineIsBlank )
		{	// 空行発見。
			foundRNRN = true;
		}
		if( '\n' == c )
		{
			// httpリクエストの１行の解析
			if( foundRNRN
			 && 0 != iIndex )
			{
				szLine[iIndex] = '\0';
				AnalyzeLineString( szLine, rbSw1, rbSw2, rbSw1_off, rbSw2_off);
			}
			// 新しい行の始まり。
			currentLineIsBlank = true;
   			iIndex = 0;
		}
		else if( '\r' != c )
		{	// この行は空行ではなかった。
                        currentLineIsBlank = false;
			if( foundRNRN )
			{
				if( LINEBUFFERSIZE - 1 > iIndex )
				{
					szLine[iIndex] = c;
					++iIndex;
				}
			}
		}
	}
	// httpリクエストの終端行の解析
	if( foundRNRN
	 && 0 != iIndex )
	{
		szLine[iIndex] = '\0';
		AnalyzeLineString( szLine, rbSw1, rbSw2,rbSw1_off,rbSw2_off);
	}

	return foundRNRN;
}

void loop()
{
	static boolean s_sw1 = false;
	static boolean s_sw2 = false;
        static boolean s_sw1_off = false;
        static boolean s_sw2_off = false;        
	
	EthernetClient client = g_server.available();
	boolean sw1 = false;
	boolean sw2 = false;
        boolean sw1_off = false;
        boolean sw2_off = false;

	if( readHttpRequest(client, sw1, sw2,sw1_off,sw2_off) )
	{
		// Html出力
		PrintHtml(client, sw1, sw2,sw1_off,sw2_off);

		// Webブラウザに対して、データを取得するための時間を与える。
		delay(1);
		
		// コネクションを閉じる。
		client.stop();

		s_sw1 = sw1;
		s_sw2 = sw2;
                s_sw1_off = sw1_off;
                s_sw2_off = sw2_off;
	}
        //SW1がONのとき、右サーボの上部を動かす
	if( s_sw1 ){ 
            Serial.println("s_sw1 true");
            myservo1.write(78);
            delay(200);
            myservo1.write(105);
            delay(1000);
          }
        
        //SW1がOFFのとき、左サーボの上部を動かす
        if( s_sw1_off ){
           Serial.println("s_sw1_off true");
           myservo2.write(135);
           delay(200);                           // waits for the servo to get there 
           myservo2.write(110);
           delay(1000);
        }
         
        //SW2がONのとき、右サーボの下部を動かす	
        if( s_sw2 ){ 
           Serial.println("s_sw2 true");
           myservo1.write(130);
           delay(200);                           // waits for the servo to get there 
           myservo1.write(105);
           delay(1000);
        }
        
        //SW2がOFFのとき、右サーボの下部を動かす
        if( s_sw2_off ) {
           Serial.println("s_sw2_off true");
           myservo2.write(80);
           delay(200);
           myservo2.write(110);
           delay(1000);
        } 
        
}


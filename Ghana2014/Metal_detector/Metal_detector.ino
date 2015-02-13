// Arduino based metal detector
// (C)Dzl july 2013
// http://dzlsevilgeniuslair.blogspot.dk/

// Connect search coil oscillator (20-200kHz) to pin 5(pin5がカウンタ１で使えるT1ピン)
// Connect piezo between pin 13 and GND
// Connect NULL button between pin 12 anf GND

// REMEMBER TO PRESS NULL BUTTON AFTER POWER UP!!


#define SET(x,y) (x |=(1<<y))		        //-Bit set/clear macros
//#define CLR(x,y) (x &= (‾(1<<y)))       	// |
#define CLR(x,y) (x &= (!(1<<y)))       	// |
#define CHK(x,y) (x & (1<<y))           	// |
#define TOG(x,y) (x^=(1<<y))            	//-+

unsigned long t0=0;         //-Last time
int t=0;                    //-time between ints
unsigned char tflag=0;      //-Measurement ready flag

float SENSITIVITY= 100.0;  //-Guess what

//-Generate interrupt every 1000 oscillations of the search coil
SIGNAL(TIMER1_COMPA_vect)
{
  OCR1A+=1000;//OCR1A自体はオーバーフローしないの？16bitレジスタだから、1000を足していくと65535でオーバーフローする。
  t=micros()-t0;//tの更新式：全経過時間（マイクロ秒）からt0を引く さっき割り込みが起こってから次に割り込みが起こるまでの経過時間
  t0+=t;//t0にtを足すことで更新する
  tflag=1;
}

void setup()
{
  pinMode(13,OUTPUT);    //-piezo pin
  digitalWrite(12,HIGH); //-NULL SW. pull up
  //-Set up counter1 to count at pin 5
  //タイマー1（16bit）を使う
  //参考：http://usicolog.nomaki.jp/engineering/avr/avrPWM.html
  TCCR1A=0;//標準動作（カウンタ動作）
  TCCR1B=0x07;//0b0000 0111, 外部クロック。T1を立ち上がりエッジでカウント。
  SET(TIMSK1,OCF1A);//
}
//-Float ABS
float absf(float f)
{
  if(f<0.0)
    return -f;
  else
    return f;
}

int   v0=0;  //-NULL value
float f=0;   //-Measurement value
unsigned int FTW=0;    //-Click generator rate
unsigned int PCW=0;    //-Click generator phase
unsigned long timer=0; //-Click timer
void loop()
{
  if(tflag)//割り込みが起こった時
  {
    if(digitalRead(12)==LOW)  //-Check NULL SW.
      v0=t;                 //-Sample new null value ：割り込み時にスイッチが押されていたらv0に経過時間を代入
    f=f*0.9+absf(t-v0)*0.1;   //-Running average over 10 samples　：スイッチが押されたときはf=0.9fになる。それ以外は(t-v0)が大きな値になるのでfが増加。
    tflag=0;                  //-Reset flag 割り込みフラグを解除。

    float clf=f*SENSITIVITY;  //-Convert measurement to click frequency 
    if(clf>10000)  
      clf=10000;
    FTW=clf;//FTWはclick generator rate。FTWは10000以上にはならない fは10以上にはならない
  }
  
  //-Click generator
  if(millis()>timer)//経過時間（ミリ秒）がtimer(10ミリ秒)より大きかったら
  {
    timer+=10;//timerを更新
    PCW+=FTW;//PCWはClick generator phase。FTW(rate)だけ進める FTWはf（10個のサンプル移動平均）に倍率（x1000）かけたもの
    if(PCW&0x8000)//PCWの４バイト目の3bit目が1にセットされている時(1000倍＝10^3倍しているので3bit目。つまり10個の移動平均fが1位上であれば、と言う意味)
    {
      digitalWrite(13,HIGH);//音を発する
      PCW&=0x7fff; //0x7fff = 0b(0000 0111)0xfffでマスク(上位5bitをクリア)
    }
    else
      digitalWrite(13,LOW);
  }
}


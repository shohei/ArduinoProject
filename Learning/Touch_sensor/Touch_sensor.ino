int f=0;//フィルタ用変数

void setup(){
  //モニタリングのためシリアル通信開始
  Serial.begin(9600);
  //8番ピンをデジタル出力
  pinMode(8,OUTPUT);
  //9番ピンをデジタル出力
  pinMode(9,INPUT);
  //LED点灯用に13番ピンをデジタル出力
  pinMode(13,OUTPUT);
}

void loop(){
  //静電容量変化量の変数を用意
  int a=0;
  //8番ピンをHIGHで出力
  digitalWrite(8, HIGH);
  //指が触れたとき9番ピンがHIGHになるまでをカウント
  while (digitalRead(9)!=HIGH){
    //カウントする
    a++;
  }
  delay(1);
  //8番ピンをLOWにする
  digitalWrite(8, LOW);

  //値を滑らかにするフィルタ式
  f+=(a-f)/2;
  //モニタリング：フィルタ値を出力
  Serial.println(f);
  
  //Touch detection
  if(f>5){//f value should be adjusted.
    //User touched the sensor 
    digitalWrite(13,HIGH);
  }else{    
    digitalWrite(13,LOW);
  }  
}

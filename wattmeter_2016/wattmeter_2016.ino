 #include <TimerOne.h>

//=====================================================
//電圧67回 + 電流67回 + 待ち866回 = 1000回
//1000回 + タイマー周期250us = 250ms
//250ms * 4ch = 1秒で1巡する
//この設定は60Hz用なので50Hzの場合は、カウントを修正する必要あり
//#define SAMPLE_CNT (80)  //50Hz用
//#define WAIT_CNT   (840) //50Hz用
//=====================================================
#define SAMPLE_CNT (67)          //サンプリング回数（1周期）
#define WAIT_CNT   (866)         //1ch分の電圧電流をサンプリングした後の待ちカウント

//ステート制御用変数
int state_smp;

//サンプリングテーブル
int myArrayA[SAMPLE_CNT];  //電流サンプリング値
int myArrayV[SAMPLE_CNT];  //電圧サンプリング値
int arrCnt;                //サンプリングカウンター

//タイマー割り込みのステート制御用定数
#define STATE_START  0 
#define STATE_ANP1   1
#define STATE_VLT1   2
#define STATE_WAIT1  3
#define STATE_ANP2   4
#define STATE_VLT2   5
#define STATE_WAIT2  6
#define STATE_ANP3   7
#define STATE_VLT3   8
#define STATE_WAIT3  9
#define STATE_ANP4   10
#define STATE_VLT4   11
#define STATE_WAIT4  12

//####################################################
//タイマー割り込み関数（250usごとにコールされる）
//４ｃｈ分のサンプリングを定期的に行う
//####################################################
void callback(){
     switch(state_smp){
     case STATE_START:
       arrCnt = 0;
       state_smp = STATE_ANP1;
       break;
     //----------------------------------------------
     //  CH1
     //----------------------------------------------
     case STATE_ANP1: //電流のサンプリング
       myArrayA[arrCnt] = analogRead(1);
       arrCnt++;
       if(arrCnt == SAMPLE_CNT){
         arrCnt = 0;
         state_smp = STATE_VLT1;
       }
       break;
     case STATE_VLT1: //電圧のサンプリング
       myArrayV[arrCnt] = analogRead(0);
       arrCnt++;
       if(arrCnt == SAMPLE_CNT){
         arrCnt = 0;
         state_smp = STATE_WAIT1;
       }
       break;
     case STATE_WAIT1: //しばらく待ち
       arrCnt++;
       if(arrCnt == WAIT_CNT){
         arrCnt = 0;
         state_smp = STATE_ANP2;
       }       
       break;
     //----------------------------------------------
     //  CH2
     //----------------------------------------------
     case STATE_ANP2: //電流のサンプリング
       myArrayA[arrCnt] = analogRead(2);
       arrCnt++;
       if(arrCnt == SAMPLE_CNT){
         arrCnt = 0;
         state_smp = STATE_VLT2;
       }
       break;
     case STATE_VLT2: //電圧のサンプリング
       myArrayV[arrCnt] = analogRead(0);
       arrCnt++;
       if(arrCnt == SAMPLE_CNT){
         arrCnt = 0;
         state_smp = STATE_WAIT2;
       }
       break;
     case STATE_WAIT2: //しばらく待ち
       arrCnt++;
       if(arrCnt == WAIT_CNT){
         arrCnt = 0;
         state_smp = STATE_ANP3;
       }       
       break;
     //----------------------------------------------
     //  CH3
     //----------------------------------------------
     case STATE_ANP3: //電流のサンプリング
       myArrayA[arrCnt] = analogRead(3);
       arrCnt++;
       if(arrCnt == SAMPLE_CNT){
         arrCnt = 0;
         state_smp = STATE_VLT3;
       }
       break;
     case STATE_VLT3: //電圧のサンプリング
       myArrayV[arrCnt] = analogRead(0);
       arrCnt++;
       if(arrCnt == SAMPLE_CNT){
         arrCnt = 0;
         state_smp = STATE_WAIT3;
       }
       break;
     case STATE_WAIT3: //しばらく待ち
       arrCnt++;
       if(arrCnt == WAIT_CNT){
         arrCnt = 0;
         state_smp = STATE_ANP4;
       }       
       break;
     //----------------------------------------------
     //  CH4
     //----------------------------------------------
     case STATE_ANP4: //電流のサンプリング
       myArrayA[arrCnt] = analogRead(4);
       arrCnt++;
       if(arrCnt == SAMPLE_CNT){
         arrCnt = 0;
         state_smp = STATE_VLT4;
       }
       break;
     case STATE_VLT4: //電圧のサンプリング
       myArrayV[arrCnt] = analogRead(0);
       arrCnt++;
       if(arrCnt == SAMPLE_CNT){
         arrCnt = 0;
         state_smp = STATE_WAIT4;
       }
       break;
     case STATE_WAIT4: //しばらく待ち
       arrCnt++;
       if(arrCnt == WAIT_CNT){
         arrCnt = 0;
         state_smp = STATE_ANP1;
       }
     }
}

//####################################################
//起動時の処理
//####################################################
void setup() {
      Serial.begin(9600);      // パソコンとシリアル通信の準備を行う
      
      //----------------------------------------------
      //変数の初期化
      //----------------------------------------------
      state_smp  = STATE_START;
      arrCnt = 0;
      
      //----------------------------------------------
      //タイマー割り込みの設定(250us周期)
      //250usで67回サンプリングすると、ちょうど１周波（60Hz）
      //----------------------------------------------
      Timer1.initialize(250);
      Timer1.pwm(9, 512);
      Timer1.attachInterrupt(callback);
}

//####################################################
//空き時間処理
//####################################################
void loop() {
     //TODO：
     //ここでサンプリングした結果を計算して、Webページにアップロードする
     delay(1);
}

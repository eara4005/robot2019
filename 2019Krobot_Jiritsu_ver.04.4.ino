//2019年　課題ロボット　自律型ロボット用プログラム

//team name: AYS
//robot name: ときのすけ

//version: 04.3
//last update: 2019/09/26
//author: 竹澤　慎悟
//      : 堅持　晃

//board type: Arduino Mega
//CPU type: ATmega2560

//---description:
//  製品版リリースです
//  タイヤ変更とともに、全パターンの修正と全部キャッチモードを追加したバージョンになります

//---update log
//2019/06/15:vacuum関数とUI処理の追加
//           変数vacuumrangeの追加
//    6月中旬:距離センサと光センサの組み合わせによる壁検知処理の追加
//           それに伴うUI処理の変更・追加
//    6月下旬:ボールの振り落とし処理の追加
//    7月中旬:床の黒線用センサー追加
//       下旬:New基盤に換装
//            リセットボタン押すと左下のモーターが回る(13番ピンが原因)
//              →ピンの位置を変更
//    8月上～中旬:12パターンすべての動きが実装完了
//    09/01:センサの処理を一部変更 ABパターンクイックチェンジ実装　練習モード切替実装
//    09/10～20:タイヤ変更による軽微な修正
/***************************************************/

//変更点
//  パターンの壁間移動のセンサを使用しない方針に変更

//include header file
#include "Krobot_J01_h.h"
#include "Krobot_J01_s.h"

//switch用関数
int mode_run = 0;

//コートの選択用変数
byte select = 0x0F;

//version string
const char VERSION[4] = "03";

//low battery voltage threshold
const float BAT_COM_LOW = 6.2;
const float BAT_MOTOR_LOW = 3.4 * 3; //10.2V

//charactar
char out[32];

//robot status
bool status_lock = true;

struct romdata {
  int motorrange_l;
  int motorrange_r;
  int backrange_l;
  int backrange_r;
  int vacuumrange;
  int servo_up;
  int servo_down;
  int sensorthreshold_w;
  int sensorthreshold_l;
  boolean patternType;
  int countTimer;
  boolean practice;
} value = {
  100, 100,
  100, 100,
  100,
  0, 180,
  30, 500,
  false,
  30,
  false
};

//パターンの表示
int pattern_A[16] = { //Aパターン(7は全取りモード)
  0, 1, 2, 3, 4, 5, 6, 7
};

int pattern_B[16] = { //Bパターン(7は全取りモード)
  0, 1, 2, 3, 4, 5, 6, 7
};
int x = 0;
/************************************************************/
void setup() {
  // put your setup code here, to run once:
  lcd.kanaOn(); //lcdのカタカナ表示を有効に
  delay(50);
  //initialize
  initPin();
  initLib();
  if (!digitalRead(PIN_SW5)) {
    mode_run = 100;
  }
  bootSplash();
  checkRom();

  myservo.write(value.servo_up); //サーボを規定値まで下げる
}

void loop() {
   
     if(value.practice) {
      digitalWrite(LED,HIGH);
     }

  // put your main code here, to run repeatedly:
  switch (mode_run) {
    case 0:
    case 100:
      menu(mode_run == 0);  //設定画面に飛ばす
      break;

    //---処理
    case 10: //動作実行画面
      lcd.clear();
      Serial.println("Moving Mode Select");
      lcd.print("ﾄﾞｳｻ ｾﾝﾀｸ ｶﾞﾒﾝ");
      lcd.setCursor(1, 1); lcd.print("ﾂｳｼﾞｮｳ:1"); lcd.print("  ﾁｴﾝ:5");

      mode_run = 20;
      break;

    case 20:
      if (!digitalRead(PIN_SW5)) { //タイマー処理
        Serial.println("Delay Mode");
        int tim = value.countTimer;

        lcd.clear();
       while(tim > 0) {
          lcd.setCursor(1, 0);
          if (tim > 9) {
            lcd.setCursor(1, 0);
            lcd.print("ﾁｴﾝ ﾋﾞｮｳｽｳ:");
            lcd.print(tim);
          } else if (tim < 6) {
            lcd.setCursor(1, 0);
            lcd.print("ﾁｴﾝ ﾋﾞｮｳｽｳ: ");
            lcd.print(tim);
            tone(PIN_BZ, 1025, 200);
          }
          else {
            lcd.setCursor(1, 0);
            lcd.print("ﾁｴﾝ ﾋﾞｮｳｽｳ: ");
            lcd.print(tim);
          }
          delay(1000);
          tim--;
       }
          if (tim == 0) {
            lcd.clear(); lcd.print("ﾄﾞｳｻ ｼﾞｯｺｳﾁｭｳ");
            vacuum(value.vacuumrange); //バキュームON
            move_pattern();
            mode_run = 30;
          }
      }

      if (!digitalRead(PIN_SW1)) {
        Serial.println("Normal Mode");
        lcd.clear(); lcd.print("ﾄﾞｳｻ ｼﾞｯｺｳﾁｭｳ");
        vacuum(value.vacuumrange); //バキュームON
        move_pattern();
        mode_run = 30;
      }

      break;

    case 30:

      while (sensorRead_W()) {  //距離センサがFalseである限り動作する
        lcd.clear();
        lcd.print("ｶﾍﾞﾇｹ ｹﾝﾁﾏﾁ");
        delay(50);
        //壁抜けるまで走る
        motor  (60, 60,
                 60, 60);
      }
      if (value.practice) { //練習モード（日本海モードにいかない）
        motor (60, 60,
               60, 60);
        delay(800);
        motor(0, 0,
              0, 0);
        servoDown();
        vacuum(0);
        mode_run = 0;
        //software_reset();

      } else {
        japanSea(); //日本海モード
        mode_run = 40;
      }
      break;

    case 40:
      Serial.println("action end");
      lcd.clear();
      lcd.print("ﾄﾞｳｻｼｭｳﾘｮｳ");
      motor(0, 0,
            0, 0);
      delay(100);

      motor(-20, 20,//左平行移動
            20, -20);
      delay(80);

      motor(0, 0,
            0, 0);
      delay(100);

      servoDown();
      delay(300);

      shuffle(3);

      motor(0, 0,
            0, 0);
      delay(2000);

      motor(-20, 20,//左平行移動
            20, -20);
      delay(80);

      motor(0, 0,
            0, 0);
      delay(100);

      servoUp();
      delay(1000);

      motor(-40, 40,//左平行移動
            40, -40);
      delay(600);

      motor(0, 0,
            0, 0);
      delay(100);
            
      mode_run = 50;
      break;

    case 50:
   ///////////////////落とした時の保険
      vacuum(value.vacuumrange);
      //delay(2000);
      motor(40, 40,
            40, 40);
      delay(500);

      motor(0, 0,
            0, 0);
      delay(1000);

      motor(-40, -40,
            -40, -40);
      delay(300);

      motor(0, 0,
            0, 0);
      delay(100);
      //ここまで
      vacuum(0);

      while (analogRead(PIN_SENSOR_W) < 610 ) {
        motor(40, -40,//右平行移動
              -40, 40);
      }
      motor(40, -40,//右平行移動
            -40, 40);
      delay(200);

      motor(0, 0,
            0, 0);
      delay(100);

      motor(-20, 20,//左平行移動
            20, -20);
      delay(80);

      motor(0, 0,
            0, 0);
      delay(100);

      servoDown();
      delay(300);

      shuffle(2);

      motor(0, 0,
            0, 0);
      delay(1000);

      motor(-20, 20,//左平行移動
            20, -20);
      delay(80);

      motor(0, 0,
            0, 0);
      delay(100);

      servoUp();
      delay(1000);

      motor(-40, 40,//左平行移動
            40, -40);
      delay(500);

      motor(0, 0,
            0, 0);
      delay(100);

      motor(40, 40,//前進
            40, 40);
      delay(400);

      motor(0, 0,
            0, 0);
      mode_run = 0;
      software_reset();
      break;
  }

}

/*****************************************************************************************************************************************************************************/
void initPin() { //ピン定義
  //switch pin
  pinMode(PIN_SW1, INPUT_PULLUP);
  pinMode(PIN_SW2, INPUT_PULLUP);
  pinMode(PIN_SW3, INPUT_PULLUP);
  pinMode(PIN_SW4, INPUT_PULLUP);
  pinMode(PIN_SW5, INPUT_PULLUP);
  //motor pin
  pinMode(PIN_MOTOR_L1_DIR, OUTPUT);
  pinMode(PIN_MOTOR_R1_DIR, OUTPUT);
  pinMode(PIN_MOTOR_L2_DIR, OUTPUT);
  pinMode(PIN_MOTOR_R2_DIR, OUTPUT);
  pinMode(PIN_MOTOR_V1_DIR, OUTPUT);
  //LED
  pinMode(LED, OUTPUT);
}

void initLib() {  //各ライブラリの定義まとめ
  //serial port
  Serial.begin(115200); //[bps]
  //LCD
  lcd.begin(16, 2);
  //servo
  myservo.attach(PIN_SERVO);
}

/********************************************************/
int search_SW() { //選択スイッチを読み込む
  for (int i = 3; i >= 0; i--) {
    if (bitRead(select, i)) {
      return i;
    }
  }
  return 0;
}

boolean SW_read(int num) {  //選択スイッチの論理を読み出す
  num = constrain(num, 0, 3); //変数:num 最小値:0 最大値:3
  return bitRead(select, num);
}

void software_reset() {
  asm volatile ("  jmp 0");
}

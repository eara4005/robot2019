/************************************************************************************************************************************************************
  パターンAの集合
  このパターンの選択はリセット右ボタン長押し→設定→Aパターン選択→リセット→ホーム画面 で行えます。
*************************************************************************************************************************************************************/
void pattern_A1() { //pattern A1 横向きスタート
  Serial.println("Pattern A1");
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Pattern A1");
  delay(100);
  int speed1 = 60;

  motor(speed1, speed1, //前進
        speed1, speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1, //９０度回転
        -speed1, speed1);
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }
  motor(speed1, -speed1, //調整　右移動
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(2);//

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1, //９０度回転
        -speed1, speed1);
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1, //調整 後進
        -speed1, -speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLright(1);
  motor(speed1, -speed1, //調整　右移動
        -speed1, speed1);
  delay(80);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1, //調整 後進
        -speed1, -speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, speed1, //前進
        speed1, speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1, //後進
        -speed1, -speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, -speed1, //９０度回転
        speed1, -speed1);
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }
  motor(speed1, -speed1,//右平行移
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_A2() {//縦向きスタート
  Serial.println("Pattern A2");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A2");
  delay(100);
  int speed1 = 60;

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移動
          -speed1, speed1);
  }
  motor(speed1, -speed1,//右平行移
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(1); //直進　黒線1本

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1,
        - speed1, speed1);//90度回転
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1,//調整 後進
        -speed1, -speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLright(1);//右平行移動　黒線1本
  motor(speed1, -speed1, //調整　右移動
        -speed1, speed1);
  delay(80);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1,//調整 後進
        -speed1, -speed1);
  delay(300);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, speed1, //前進
        speed1, speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, -speed1,
        speed1, -speed1);//90度回転
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1,//調整   左平行移動
        speed1, -speed1);
  delay(300);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, speed1,//調整　前進
        speed1, speed1);
  delay(200);

  RLfront(1);//直線1本

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }
  motor(speed1, -speed1,//右平行移
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);
}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_A3() {//縦向きスタート

  Serial.println("Pattern A3");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A3");
  //直進　黒線検知
  delay(100);
  int speed1 = 60;

  RLfront(2);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }
  motor(speed1, -speed1,//調整　右平行移動
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(2);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1,
        - speed1, speed1);//90度回転
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1,//調整 後進
        -speed1, -speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLright(1);
  motor(speed1, -speed1, //調整　右移動
        -speed1, speed1);
  delay(80);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1,//調整 後進
        -speed1, -speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, speed1, //前進
        speed1, speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1, //後進
        -speed1, -speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, -speed1,
        speed1, -speed1);//90度回転
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }
  motor(speed1, -speed1,//右平行移
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);
}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_A4() {//縦向きスタート
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;
  Serial.println("Pattern A4");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A4");
  delay(100);
  int speed1 = 60;

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }
  motor(speed1, -speed1,//右平行移
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfrontS(4);//4本分前

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1,//９０度回転
        -speed1, speed1);
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1,//調整　後進
        -speed1, -speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, speed1, //前進
        speed1, speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1, //後進
        -speed1, -speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLright(1);//右　１本
  motor(speed1, -speed1,// 調整　右平行
        -speed1, speed1);
  delay(30);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1,//調整　後進
        -speed1, -speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(20, 20,//ゆっくり前進
        20, 20);
  delay(1700);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1,//調整 後進
        -speed1, -speed1);
  delay(700);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, -speed1, //９０度回転
        speed1, -speed1);
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }
  motor(speed1, -speed1,//右平行移
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);
}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_A5() {//横向きスタート
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;
  int speed1 = 60;
  Serial.println("Pattern A5");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A5");
  delay(100);

  motor(speed1, speed1, //前進
        speed1, speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -63, //後進
        -speed1, -63);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1, //９０度回転
        -speed1, speed1);
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1,//調整　左移動
        speed1, -speed1);
  delay(300);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(4);
  motor(speed1, speed1, //前進
        speed1, speed1);
  delay(500);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, -speed1,//９０度回転
        speed1, -speed1);
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, -speed1,//調整　後進
        -speed1, -speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1, speed1, //前進
        speed1, speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1, speed1,//９０度回転
        -speed1, speed1);
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }
  motor(speed1, -speed1,//調整　右移動
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);
}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_A6() {//縦向きスタート
  Serial.println("Pattern A6");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A6");
  delay(100);
  int speed1 = 60;

  RLright(2);
  motor(speed1, -speed1,//調整　右移動
        -speed1, speed1);
  delay(80);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(1);

  motor(0, 0,
        0, 0);
  delay(100);

  RLleft(1);
  motor(-speed1, speed1,//左平行移
        speed1, -speed1);
  delay(400);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(2);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620) {
    motor(speed1, -speed1,//右平行移
          -speed1, speed1);
  }

  motor(speed1, -speed1,//調整　右移動
        -speed1, speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

}

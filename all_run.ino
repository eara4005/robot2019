void all_run() {
  int L_sensor;
  int count_L = 0;
  Serial.println("All catch Mode");
  lcd.setCursor(1, 1);
  lcd.print("ﾎﾞｰﾙ ｾﾞﾝﾌﾞﾄﾘ");
  delay(100);
  motor(40, 40, //前進
        40, 40);
  delay(1600);

  motor(0, 0,
        0, 0);
  delay(1000);

  motor(-50, 50, //９０度回転
        -50, 50);
  delay(900);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(40, -40, //調整　右移動
        -40, 40);
  delay(300);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(42, 40,//前進
        42, 40);

  while (count_L < 5) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor < value.sensorthreshold_l ) {
      count_L++;
      delay(100);
    }
  }

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 610 ) {
    motor(40, -40,//右平行移
          -40, 40);
  }
  motor(40, -40,//右平行移
        -40, 40);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLback(5);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-50, 50, //９０度回転
        -50, 50);
  delay(900);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-40, -40, //調整　後進
        -40, -40);
  delay(300);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(40, -40, //調整　右移動
        -40, 40);
  delay(500);

  motor(0, 0,
        0, 0);
  delay(100);

  for (int i = 0; i < 4; i++) {

    motor(-40, -40, //調整　後進
          -40, -40);
    delay(300);

    motor(40, 40, //前進
          40, 40);
    delay(1700);

    motor(0, 0,
          0, 0);
    delay(1000);

    motor(-40, -40, //後進
          -40, -40);
    delay(1700);

    motor(0, 0,
          0, 0);
    delay(100);

    RLright(1);
    motor(40, -40, //調整　右移動
          -40, 40);
    delay(150);

    motor(0, 0,
          0, 0);
    delay(100);
  }

  motor(20, 20,//ゆっくり前進
        20, 20);
  delay(1700);

  motor(0, 0,
        0, 0);
  delay(1000);

  motor(-40, -40,//調整 後進
        -40, -40);
  delay(1100);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(50, -50, //９０度回転
        50, -50);
  delay(900);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 610 ) {
    motor(40, -40,//右平行移
          -40, 40);
  }
  motor(40, -40,//右平行移
        -40, 40);
  delay(200);
}

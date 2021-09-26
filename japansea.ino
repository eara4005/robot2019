void japanSea() { //日本海エリアの動作です
  Serial.println("japan sea mode");
  lcd.clear();
  lcd.print("japan sea");

  motor(60, 60,//直進
        60, 60);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, -60,//右平行移動
        -60, 60);
  delay(1250);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, -60,
        60, -60);//180度回転
  delay(1350);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, 60,//直進
        60, 60);
  delay(1700);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 610) {
    motor(60, -60,//右平行移動)
          -60, 60);
  }
  motor(60, -60,//右平行移動)
        -60, 60);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) > 550) {
    motor(-60, 60,//左平行移動0 )
          60, -60);
  }
  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, 60,//直進
        60, 60);
  delay(1800);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, -60,
        60, -60);//180度回転
  delay(1350);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-60, 60,//左平行移動
        60, -60);
  delay(600);

  motor(0, 0,
        0, 0);
  delay(100);

  vacuum(0);
  motor(60, 61,//直進
        60, 61);
  delay(2500);

  vacuum(value.vacuumrange);
  motor(60, 60,//直進
        60, 60);
  delay(2800);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 610 ) {
    motor(60, -60,//右平行移動
          -60, 60);
  }
  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) > 120) {
    motor  (-value.backrange_l, -value.backrange_r,
            -value.backrange_l, -value.backrange_r);
  }
  motor  (-value.backrange_l, -value.backrange_r,
          -value.backrange_l, -value.backrange_r);
  delay(130);

  motor(0, 0,
        0, 0);
  delay(100);

  vacuum(0);

  while (analogRead(PIN_SENSOR_W) < 610 ) {
    motor(40, -40,//右平行移動
          -40, 40);
  }
  motor(40, -40,//右平行移動
        -40, 40);
  delay(300);
}

/************************************************************************************************************************************************************
  パターンAの集合
  このパターンの選択はリセット右ボタン長押し→設定→Bパターン選択→リセット→ホーム画面 で行えます。
*************************************************************************************************************************************************************/
void pattern_B1() {//横向きスタート
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;
  Serial.println("Pattern B1");
  lcd.setCursor(1, 1);
  lcd.print("Pattern B1");
  delay(100);
   int speed1 = 60;

  motor(speed1 , speed1 , //前進
        speed1 , speed1 );
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , -63, //後進
        -speed1 , -63);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , speed1 , //９０度回転
        -speed1 , speed1 );
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , speed1 , //調整　左移動
        speed1 , -speed1 );
  delay(300);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(4);//前進　4本

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , speed1 , //調整　左移動
        speed1 , -speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1 , -speed1 , //９０度回転
        speed1 , -speed1 );
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , -speed1 , //調整　後進
        -speed1 , -speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLleft(1);//左
  motor(-speed1 , speed1 , //調整　左移動
        speed1 , -speed1 );
  delay(400);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , -speed1 , //調整　後進
        -speed1 , -speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1 , speed1 , //前進
        speed1 , speed1 );
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , speed1 , //９０度回転
        -speed1 , speed1 );
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1 , -speed1 ,//右平行移
          -speed1 , speed1 );
  }
  motor(speed1 , -speed1 ,//右平行移
        -speed1 , speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_B2() {//横向きスタート
  Serial.println("Pattern B2");
  lcd.setCursor(1, 1);
  lcd.print("Pattern B2");
  delay(100);
   int speed1 = 60;

  motor(speed1 , speed1 , //前進
        speed1 , speed1 );
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , speed1 , //９０度回転
        -speed1 , speed1 );
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {//壁取り
    motor(speed1 , -speed1 ,//右平行移
          -speed1 , speed1 );
  }
  motor(speed1 , -speed1 , //調整　右移動
        -speed1 , speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(2);//前　２本

  motor(0, 0,
        0, 0);
  delay(100);

  RLleft(2);//　左
  motor(-speed1 , speed1 , //調整　左移動
        speed1 , -speed1 );
  delay(400);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1 , speed1 , //前進
        speed1 , speed1 );
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1 , -speed1 ,//右平行移
          -speed1 , speed1 );
  }
  motor(speed1 , -speed1 ,//右平行移
        -speed1 , speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_B3() {//横向きスタート
  Serial.println("Pattern B3");
  lcd.setCursor(1, 1);
  lcd.print("Pattern B3");
  delay(100);
   int speed1 = 60;

  RLleft(2);
  motor(-speed1 , speed1 , //調整　左移動
        speed1 , -speed1 );
  delay(400);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , -speed1 , //調整　後進
        -speed1 , -speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1 , speed1 , //前進
        speed1 , speed1 );
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , -speed1 , //後進
        -speed1 , -speed1 );
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , speed1 , //９０度回転
        -speed1 , speed1 );
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , speed1 , //調整　左移動
        speed1 , -speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1 , speed1 , //前進
        speed1 , speed1 );
  delay(1400);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1 , -speed1 ,//右平行移
          -speed1 , speed1 );
  }
  motor(speed1 , -speed1 ,//右平行移
        -speed1 , speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_B4() {//縦向きスタート
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;
  Serial.println("Pattern B4");
  lcd.setCursor(1, 1);
  lcd.print("Pattern B4");
  delay(100);
   int speed1 = 60;

  RLfront(3);//前

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1 , -speed1 ,//右平行移
          -speed1 , speed1 );
  }
  motor(speed1 , -speed1 ,//右平行移
        -speed1 , speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(2);//前

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , speed1 , //９０度回転
        -speed1 , speed1 );
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , -speed1 , //調整　後ろ
        -speed1 , -speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  RLright(1);
  motor(speed1 , -speed1 ,// 調整　右平行
        -speed1 , speed1 );
  delay(30);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-speed1 , -speed1 , //調整　後ろ
        -speed1 , -speed1 );
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

  motor(-speed1 , -speed1 , //調整　後ろ
        -speed1 , -speed1 );
  delay(700);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(speed1 , -speed1 , //９０度回転
        speed1 , -speed1 );
  delay(750);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1 , -speed1 ,//右平行移
          -speed1 , speed1 );
  }
  motor(40, -40,//右平行移
        -40, 40);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_B5() {//縦向きスタート
  Serial.println("Pattern B5");
  lcd.setCursor(1, 1);
  lcd.print("Pattern B5");
  delay(100);
  int speed1 = 60;
  
  RLright(2);
  motor(speed1 , -speed1 ,//調整　
        -speed1 , speed1 );
  delay(50);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(1);
  motor(speed1 , speed1 ,//調整 前進　
        speed1 , speed1 );
  delay(50);

  motor(0, 0,
        0, 0);
  delay(100);

  RLleft(1);
  motor(-speed1 , speed1 ,//調整　左移動
        speed1 , -speed1 );
  delay(400);

  motor(0, 0,
        0, 0);
  delay(100);

  RLfront(1);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(speed1 , -speed1 ,//右平行移
          -speed1 , speed1 );
  }
  motor(speed1 , -speed1 ,//調整　右移動
        -speed1 , speed1 );
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);


}
//***********************************************************************************************************************************************************
//***********************************************************************************************************************************************************
void pattern_B6() {//縦向きスタート
  Serial.println("Pattern B6");
  lcd.setCursor(1, 1);
  lcd.print("Pattern B6");
  delay(100);
  int speed1 = 60;

  RLfront(3);//前へ3本分　

  motor(0, 0,
        0, 0);
  delay(100);

  motor( speed1, - speed1,
         speed1, - speed1);//90度回転
  delay(750 );

  motor(0, 0,
        0, 0);
  delay(100);

  motor (- speed1, - speed1, //後進
         - speed1, - speed1);
  delay(200);

  RLleft(1);//左へ一本
  motor(- speed1,  speed1,//調整　左
        speed1, - speed1);
  delay(300);

  motor(0, 0,
        0, 0);
  delay(100);

  motor (- speed1, - speed1, //後進
         - speed1, - speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor( speed1,  speed1, //前進
         speed1,  speed1);
  delay(1200);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(- speed1,  speed1,
        - speed1,  speed1);//90度回転
  delay(750 );

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor( speed1, - speed1,//右平行移
           - speed1,  speed1);
  }
  motor( speed1, - speed1,//右平行移
         - speed1,  speed1);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(100);

}

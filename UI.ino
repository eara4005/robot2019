
//user interface (button & LCD) process

int UIpage = 0;
int UIpage2 = 0;

void bootSplash() { //起動時の表示　
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("AYS ｼﾞﾘﾂﾛﾎﾞｯﾄ");
  lcd.setCursor(8, 1);
  lcd.print("ver.");
  lcd.print(VERSION);
  delay(300);
}

unsigned long loopcount = 0;  //main loop counter

void menu(int mode) {
  const unsigned int LCD_REFRESHTIME = 500; //LCD refresh rate[ms]
  static unsigned long lasttime = 0;

  //read user actions
  buttonFunc();
  if (millis() - lasttime >= LCD_REFRESHTIME || buttonRead_rep(ID_SW_ALL)) {
    switch (mode) {
      case 0:
        //configure
        usrInput();
        lcdRefresh();
        break;

      case 1:
        //attack select
        atksel();
        break;
    }
    lasttime = millis();
  }

  delay(16);
  loopcount++;
}

void usrInput() { //ボタンごとの処理
  if (buttonRead_p(ID_SW1)) writeRom();

  if (buttonRead_rep(ID_SW2)) UIpage++;
  if (buttonRead_rep(ID_SW3)) UIpage--;
  UIpage = constloop(UIpage, 0, 12); //ページを増減させたいときにはここをいじる

  switch (UIpage) {
    case 0:
      break;

    //左モータ出力設定画面の設定
    case 1:
      if (buttonRead_rep(ID_SW4)) value.motorrange_l++;
      if (buttonRead_rep(ID_SW5)) value.motorrange_l--;
      value.motorrange_l = constloop(value.motorrange_l, 0, 100);
      break;

    //右モータ出力設定画面の設定
    case 2:
      if (buttonRead_rep(ID_SW4)) value.motorrange_r++;
      if (buttonRead_rep(ID_SW5)) value.motorrange_r--;
      value.motorrange_r = constloop(value.motorrange_r, 0, 100);
      break;

    //左バックモータ出力設定画面の設定
    case 3:
      if (buttonRead_rep(ID_SW4)) value.backrange_l++;
      if (buttonRead_rep(ID_SW5)) value.backrange_l--;
      value.backrange_l = constloop(value.backrange_l, 0, 100);
      break;

    //左バックモータ出力設定画面の設定
    case 4:
      if (buttonRead_rep(ID_SW4)) value.backrange_r++;
      if (buttonRead_rep(ID_SW5)) value.backrange_r--;
      value.backrange_r = constloop(value.backrange_r, 0, 100);
      break;

    //バキュームモータ出力設定画面の設定
    case 5:
      if (buttonRead_rep(ID_SW4)) value.vacuumrange++;
      if (buttonRead_rep(ID_SW5)) value.vacuumrange--;
      value.vacuumrange = constloop(value.vacuumrange, 0, 100);
      break;

    //サーボモータ 上げ角出力設定画面の設定
    case 6:
      if (buttonRead_rep(ID_SW4)) value.servo_up++;
      if (buttonRead_rep(ID_SW5)) value.servo_up--;
      value.servo_up = constloop(value.servo_up, 0, 180);
      break;

    //サーボモータ 下げ角出力設定画面の設定
    case 7:
      if (buttonRead_rep(ID_SW4)) value.servo_down++;
      if (buttonRead_rep(ID_SW5)) value.servo_down--;
      value.servo_down = constloop(value.servo_down, 0, 180);
      break;

    //距離センサ設定＆しきい値確認画面の設定
    case 8:
      if (buttonRead_rep(ID_SW4)) value.sensorthreshold_w++;
      if (buttonRead_rep(ID_SW5)) value.sensorthreshold_w--;
      value.sensorthreshold_w = constloop(value.sensorthreshold_w, 0, 1023);
      break;

    //光センサ設定＆しきい値確認画面の設定
    case 9:
      if (buttonRead_rep(ID_SW4)) value.sensorthreshold_l++;
      if (buttonRead_rep(ID_SW5)) value.sensorthreshold_l--;
      value.sensorthreshold_l = constloop(value.sensorthreshold_l, 0, 1023);
      break;

    //パターンABの選択
    case 10:
      if (buttonRead_rep(ID_SW4)) value.patternType = false;
      if (buttonRead_rep(ID_SW5)) value.patternType = true;
      break;

    case 11:
      if (buttonRead_rep(ID_SW4)) value.countTimer++;
      if (buttonRead_rep(ID_SW5)) value.countTimer--;
      value.countTimer = constloop(value.countTimer, 0, 300);
      break;

    case 12:
      if (buttonRead_rep(ID_SW4)) value.practice = false;
      if (buttonRead_rep(ID_SW5)) value.practice = true;
      break;
  }
}

void lcdRefresh() { //読んで字のごとくです

  lcd.clear();

  switch (UIpage) {
    case 0: //バッテリ確認画面
      Serial.println("battery");
      lcd.print("ﾊﾞｯﾃﾘ");
      lcd.setCursor(9, 0);
      dtostrf(batteryRead(PIN_BAT_COM), 4, 1, out);   //Arduino電源
      lcd.print("C:"); lcd.print(out); lcd.print("V");
      lcd.setCursor(0, 1);
      dtostrf(batteryRead(PIN_BAT_M0), 4, 1, out);  //足周り用電源
      lcd.print("M1:"); lcd.print(out); lcd.print("V");
      lcd.setCursor(9, 1);
      dtostrf(batteryRead(PIN_BAT_M1), 4, 1, out);  //バキューム用電源
      lcd.print("M2:"); lcd.print(out); lcd.print("V");
      break;

    case 1: //左モータ（正転）の設定
      Serial.println("left motor go RLRLfront");
      lcd.print("ﾋﾀﾞﾘ ﾓｰﾀ:L");
      lcd.setCursor(1, 1);
      sprintf(out, "%3d%c", value.motorrange_l, '%');
      lcd.print(out);
      break;

    case 2: //右モータ（正転）の設定
      Serial.println("right motor go RLRLfront");
      lcd.print("ﾐｷﾞ ﾓｰﾀ:R");
      lcd.setCursor(1, 1);
      sprintf(out, "%3d%c", value.motorrange_r, '%');
      lcd.print(out);
      lcd.print(" ﾋﾀﾞﾘﾉ -3");
      break;

    case 3: //左モータ（後転）の設定
      Serial.println("left motor go back");
      lcd.print("ﾋﾀﾞﾘ ﾊﾞｯｸ:L");
      lcd.setCursor(1, 1);
      sprintf(out, "%3d%c", value.backrange_l, '%');
      lcd.print(out);
      break;

    case 4: //右モータ（後転）の設定
      Serial.println("right motor go back");
      lcd.print("ﾐｷﾞ ﾊﾞｯｸ:R");
      lcd.setCursor(1, 1);
      sprintf(out, "%3d%c", value.backrange_r, '%');
      lcd.print(out);
      lcd.print(" ﾋﾀﾞﾘﾉ -3");
      break;

    case 5: //バキュームの設定

      Serial.println("vacuum set ");
      lcd.print("ﾊﾞｷｭｰﾑ");
      lcd.setCursor(1, 1);
      sprintf(out, "%3d%c", value.vacuumrange, '%');
      lcd.print(out);
      break;

    case 6: //サーボ　上げ角度の設定
      Serial.println("servo up point");
      lcd.print("ｻｰﾎﾞｱｹﾞ");
      lcd.setCursor(1, 1);
      sprintf(out, "%3d[deg]", value.servo_up);
      myservo.write(value.servo_up);
      lcd.print(out);
      break;

    case 7://サーボ　下げ角度の設定
      Serial.println("servo down point ");
      lcd.print("ｻｰﾎﾞ ｻｹﾞ");
      lcd.setCursor(1, 1);
      sprintf(out, "%3d[deg]", value.servo_down);
      myservo.write(value.servo_down);
      lcd.print(out);
      break;

    case 8: //距離センサのしきい値＆設定
      Serial.println("sensor wall set");
      lcd.print("ｾﾝｻ ｶﾍﾞ");
      lcd.setCursor(1, 1);
      sprintf(out, "%4d (%4d:%c)", value.sensorthreshold_w, analogRead(PIN_SENSOR_W), TF(sensorRead_W()));
      lcd.print(out);
      break;

    case 9: //光センサのしきい値＆設定
      Serial.println("sensor light set ");
      lcd.print("ｾﾝｻ ﾕｶ");
      lcd.setCursor(1, 1);
      sprintf(out, "%4d (%4d:%c)", value.sensorthreshold_l, analogRead(PIN_SENSOR_L), TF(sensorRead_L()));
      lcd.print(out);
      break;

    case 10:  //パターン選択の設定
      lcd.print("ﾊﾟﾀｰﾝ A or B");
      lcd.setCursor(1, 1);
      if (!value.patternType) {
        lcd.print("< A  ");
      } else {
        lcd.print("  B >");
      }
      break;

    case 11://遅延用の秒数設定
      lcd.print("ﾁｴﾝ ﾋﾞｮｳｽｳ");
      lcd.setCursor(7, 1);
      sprintf(out, "%3d ﾋﾞｮｳ", value.countTimer);
      lcd.print(out);
      break;

    case 12:  //練習
      lcd.print("ﾚﾝｼｭｳ ｽﾙ or ｼﾅｲ");
      lcd.setCursor(1, 1);
      if (!value.practice) {
          digitalWrite(LED,LOW);
        lcd.print("< ﾚﾝｼｭｳｼﾅｲ");
      } else {
          digitalWrite(LED,HIGH);
        lcd.print("  ﾚﾝｼｭｳｽﾙ >");
      }
      break;
  }
}

void atksel() { //アタックセレクト　ってよみます
  

  //前回のボタンの状態
  static boolean oldbtn = 0;

  //開始処理
  if (oldbtn && !buttonRead(ID_SW1)) { //ボタンが離されたとき
    writeSelectRom();
    mode_run = 10;
  }

  if (buttonRead(ID_SW1)) { //スタートボタンが押されたとき
    oldbtn = buttonRead(ID_SW1);
  }


  for (int i = 0; i < 3; i++) {
    if (buttonRead_p(bit(i + 1))) bitWrite(select, i, !bitRead(select, i));
  }

  if (buttonRead_p(ID_SW5)) value.patternType = !value.patternType;

  lcd.clear();

  //パターン選択画面
  lcd.setCursor(0, 0); lcd.print("ﾊﾟﾀｰﾝ");
  lcd.setCursor(5, 0);
  if (!value.patternType) {
    lcd.print(" A ");
  } else {
    lcd.print(" B ");
  }

  //
  lcd.setCursor(0, 1);
  if (value.practice) {
    lcd.print("ﾚ");
  }

  lcd.setCursor(2, 1);
  dtostrf(batteryRead(PIN_BAT_COM), 1, 1, out);   //Arduino電源
  lcd.print(out);
  lcd.setCursor(7, 1);
  dtostrf(batteryRead(PIN_BAT_M0), 1, 1, out);  //足周り用電源
  lcd.print(out);
  lcd.setCursor(12, 1);
  dtostrf(batteryRead(PIN_BAT_M1), 1, 1, out);  //バキューム用電源
  lcd.print(out);

  //ヤリ選択表示
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(8 + i * 2, 0);
    if (bitRead(select, i)) {
      lcd.print('*');
    } else {
      lcd.write('_');
    }
  }

  //lcd.setCursor(15, 0); lcd.write((byte)1);



  if (!value.patternType) {
    //Aパターンの表示
    lcd.setCursor(14, 0);
    if(pattern_A[select & 0x0F] == 7){
      lcd.print('A');
    }else{
    lcd.print(pattern_A[select & 0x0F]);
    }
    Serial.println(select & 0x0F);
  } else {
    //Bパターンの表示
    lcd.setCursor(14, 0);
    if(pattern_B[select & 0x0F] == 7){
      lcd.print('A');
    }else{
      lcd.print(pattern_B[select & 0x0F]);
    }
    Serial.println(select & 0x0F);
  }
}

//多分使わない
void uicharset() {
  byte lcdcharlock[8] = {
    B00000,
    B00000,
    B01110,
    B11111,
    B11111,
    B11111,
    B11111,
    B00000
  };
  byte lcdcharbattery[8] = {
    B00000,
    B00000,
    B01110,
    B11111,
    B10001,
    B10001,
    B11111,
    B00000
  };
  lcd.createChar(1, lcdcharlock);
  lcd.createChar(2, lcdcharbattery);
}

//線を読んで進むやつ
/*
  void RLfront(int a) {
  a += 1;
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;
  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor > value.sensorthreshold_l && old_L_sensor < value.sensorthreshold_l) {
      count_L++;
      tone(PIN_BZ, 440, 200);
    } else {
      motor(40, 40,//前進
            40, 40);
    }
    delay(5);
    old_L_sensor = L_sensor;
  }
  }
  void RLback(int a) {
  a += 1;
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;
  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor > value.sensorthreshold_l && old_L_sensor < value.sensorthreshold_l) {
      count_L++;
      tone(PIN_BZ, 440, 200);
    } else {
      motor(-40, -40,//後進
            -40, -40);
    }
    delay(5);
    old_L_sensor = L_sensor;
  }
  }
  void RLright(int a) {
  a += 1;
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;
  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor > value.sensorthreshold_l && old_L_sensor < value.sensorthreshold_l) {
      count_L++;
      tone(PIN_BZ, 440, 200);
    } else {
      motor(40, -40,//右
            -40, 40);
    }
    delay(5);
    old_L_sensor = L_sensor;
  }
  }
  void RLleft(int a) {
  a += 1;
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;
  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor > value.sensorthreshold_l && old_L_sensor < value.sensorthreshold_l) {
      count_L++;
      tone(PIN_BZ, 440, 200);
    } else {
      motor(-40, 40,//左
            40, -40);
    }
    delay(5);
    old_L_sensor = L_sensor;
  }
  }*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RLfront(int a) {
  int L_sensor;
  int count_L = 0;
 
  motor(60, 60,//前進
        60, 60);

  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor < value.sensorthreshold_l ) {
      count_L++;
      delay(100);
    }
  }

  motor(0, 0,//停止
        0, 0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RLfrontS(int a) {
  int L_sensor;
  int count_L = 0;
 
  motor(62, 60,//前進
        62, 60);

  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor < value.sensorthreshold_l ) {
      count_L++;
      delay(100);
    }
  }

  motor(0, 0,//停止
        0, 0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RLback(int a) {
  int L_sensor;
  int count_L = 0;

  motor(-60, -60,//後進
        -60, -60);

  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor < value.sensorthreshold_l ) {
      count_L++;
      delay(100);
    }
  }

  motor(0, 0,//停止
        0, 0);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void RLright(int a) {
  int L_sensor;
  int count_L = 0;

  motor(60, -60,//後進
        -60, 60);

  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor < value.sensorthreshold_l ) {
      count_L++;
      delay(100);
    }
  }

  motor(0, 0,//停止
        0, 0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void RLleft(int a) {
   int L_sensor;
  int count_L = 0;

  motor(-60, 60,//後進
        60, -60);

  while (count_L < a) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor < value.sensorthreshold_l ) {
      count_L++;
      delay(100);
    }
  }

  motor(0, 0,//停止
        0, 0);
}

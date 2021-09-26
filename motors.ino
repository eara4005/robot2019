//モータ関連の処理をまとめました
void motor(int leftpower1, int rightpower1,
           int leftpower2, int rightpower2) {// 左モータ出力（％）、　右モータ出力（％）

  if (leftpower1  < 0) { // -X%の入力時
    digitalWrite(PIN_MOTOR_L1_DIR, HIGH);
    analogWrite(PIN_MOTOR_L1_PWM, leftpower1 * -255 / 100);
  } else {
    digitalWrite(PIN_MOTOR_L1_DIR, LOW);
    analogWrite(PIN_MOTOR_L1_PWM, leftpower1 * 255 / 100);
  }

  if (leftpower2  < 0) { // -X%の入力時
    digitalWrite(PIN_MOTOR_L2_DIR, HIGH);
    analogWrite(PIN_MOTOR_L2_PWM, leftpower2 * -255 / 100);
  } else {
    digitalWrite(PIN_MOTOR_L2_DIR, LOW);
    analogWrite(PIN_MOTOR_L2_PWM, leftpower2 * 255 / 100);
  }

  if (rightpower1  < 0) {
    digitalWrite(PIN_MOTOR_R1_DIR, HIGH);
    analogWrite(PIN_MOTOR_R1_PWM, rightpower1 * -255 / 100);
  } else {
    digitalWrite(PIN_MOTOR_R1_DIR, LOW);

    analogWrite(PIN_MOTOR_R1_PWM, rightpower1 * 255 / 100);
  }

  if (rightpower2  < 0) {
    digitalWrite(PIN_MOTOR_R2_DIR, HIGH);
    analogWrite(PIN_MOTOR_R2_PWM, rightpower2 * -255 / 100);
  } else {
    digitalWrite(PIN_MOTOR_R2_DIR, LOW);
    analogWrite(PIN_MOTOR_R2_PWM, rightpower2 * 255 / 100);
  }
}

void vacuum(int power) {  //バキューム出力（％）
  digitalWrite(PIN_MOTOR_V1_DIR, HIGH);
  analogWrite(PIN_MOTOR_V1_PWM, power * 255 / 100);
}

//---servo
void servoUp() {
  myservo.write(value.servo_up);
  Serial.println("フタ　オープン");
}

void servoDown() {
  myservo.write(value.servo_down);
  Serial.println("フタ　クローズ");
}

void shuffle(int a) {
  int count = 0;
  //ボールの振り落とし
  while (count < a) {
    motor(-60, 60,
          -60, 60);
    delay(60);

    motor(0, 0,
          0, 0);
    delay(100);

    motor(60, -60,
          60, -60);
    delay(60);

     motor(0, 0,
          0, 0);
    delay(100);

    motor(60, -60,//左平行移動
            -60, 60);
      delay(60);

      motor(0, 0,
            0, 0);
      delay(100);
      
    count++;
  }
 
}

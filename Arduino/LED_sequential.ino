// 定义 LED 引脚数组
int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};
int numLeds = 9;

// 定义电位器引脚
int potPin = A0;

void setup() {
  // 将所有 LED 引脚设为输出
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // 可选：开启串口调试
  Serial.begin(9600);
}

void loop() {
  // 读取电位器数值（0 到 1023）
  int potValue = analogRead(potPin);

  // 根据电位器值，决定要点亮多少个灯（0 到 9）
  int ledsToLight = map(potValue, 0, 1023, 0, numLeds);

  // 依次点亮或熄灭灯
  for (int i = 0; i < numLeds; i++) {
    if (i < ledsToLight) {
      digitalWrite(ledPins[i], HIGH);  // 亮
    } else {
      digitalWrite(ledPins[i], LOW);   // 灭
    }
  }

  // 可选：打印调试信息
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | LEDs On: ");
  Serial.println(ledsToLight);

  delay(100);  // 小延迟，让效果更平滑
}
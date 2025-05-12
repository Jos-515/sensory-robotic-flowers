#include <Servo.h>  // 引入舵机控制库

const int lightPin = A0;  // Grove Light Sensor 连接到 A0
Servo myServo;            // 创建舵机对象

int currentAngle = 0;      // 当前舵机角度

void setup() {
  Serial.begin(9600);      // 启动串口监视器
  myServo.attach(9);       // 将舵机连接到 D9 引脚
  myServo.write(currentAngle);  // 初始化角度
}

void loop() {
  int lightValue = analogRead(lightPin);  // 读取光传感器的模拟值
  Serial.println(lightValue);             // 在串口监视器中输出光线强度
  
  // 将光线强度映射到舵机角度范围（0-180）
  int targetAngle = map(lightValue, 0, 1023, 0, 180);

  // 如果当前角度小于目标角度，慢慢加
  if (currentAngle < targetAngle) {
    currentAngle++;
    myServo.write(currentAngle);
    delay(15);  // 每步延时越大，越慢（比如 15~30 毫秒）
  }
  // 如果当前角度大于目标角度，慢慢减
  else if (currentAngle > targetAngle) {
    currentAngle--;
    myServo.write(currentAngle);
    delay(15);
  }

  // 如果相等，不需要动
}
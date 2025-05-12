#include <Servo.h>  // Include the Servo library

// Define the analog input pins for each potentiometer
int potPin1 = A0;  // Potentiometer 1
int potPin2 = A1;  // Potentiometer 2
int potPin3 = A2;  // Potentiometer 3
int potPin4 = A3;  // Potentiometer 4

// Variables to store potentiometer readings
int potValue1 = 0;
int potValue2 = 0;
int potValue3 = 0;
int potValue4 = 0;

// Create Servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // Attach the servos to their respective pins
  servo1.attach(9);  // Servo 1 to pin 9
  servo2.attach(10); // Servo 2 to pin 10
  servo3.attach(11); // Servo 3 to pin 11
  servo4.attach(12); // Servo 4 to pin 12
  
  // Start Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the values from each potentiometer
  potValue1 = analogRead(potPin1);  // Read potentiometer 1 value
  potValue2 = analogRead(potPin2);  // Read potentiometer 2 value
  potValue3 = analogRead(potPin3);  // Read potentiometer 3 value
  potValue4 = analogRead(potPin4);  // Read potentiometer 4 value

  // Map the potentiometer values (0-1023) to servo angles (0-180 degrees)
  int angle1 = map(potValue1, 0, 1023, 0, 180);
  int angle2 = map(potValue2, 0, 1023, 0, 180);
  int angle3 = map(potValue3, 0, 1023, 0, 180);
  int angle4 = map(potValue4, 0, 1023, 0, 180);

  // Set the servo positions based on the mapped potentiometer values
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);

  // Print the potentiometer values and corresponding servo angles to Serial Monitor for debugging
  // Serial.print("Potentiometer 1: ");
  //Serial.print(potValue1);
  //Serial.print("  Servo 1 Angle: ");
  ///Serial.print(angle1);
  //Serial.print("  Potentiometer 2: ");
  //Serial.print(potValue2);
 // Serial.print("  Servo 2 Angle: ");
 // Serial.print(angle2);
  //Serial.print("  Potentiometer 3: ");
 // Serial.print(potValue3);
  //Serial.print("  Servo 3 Angle: ");
  //Serial.print(angle3);
  //Serial.print("  Potentiometer 4: ");
  //Serial.print(potValue4);
 // Serial.print("  Servo 4 Angle: ");
  //Serial.println(angle4);

Serial.print(potValue1);
Serial.print(",");
Serial.print(potValue2);
Serial.print(",");
Serial.print(potValue3);
Serial.print(",");
Serial.println(potValue4);  // Use println for newline


  delay(100);  // Small delay to make the output readable
}

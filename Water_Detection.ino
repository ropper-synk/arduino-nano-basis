#include <Servo.h>

#define WATER_SENSOR A0  // Water sensor signal pin
#define WATER_THRESHOLD 500  // Adjust this based on testing
#define SERVO_PIN 9  // Servo motor control pin

Servo myServo;  // Create Servo object

void setup() {
  pinMode(WATER_SENSOR, INPUT);
  myServo.attach(SERVO_PIN);  // Attach servo to pin 9
  Serial.begin(9600);  // Start Serial Monitor
  myServo.write(0);  // Start with servo at 0°
}

void loop() {
  int waterLevel = analogRead(WATER_SENSOR);  // Read water sensor
  Serial.print("Water Level: ");
  Serial.println(waterLevel);  // Print water level value

  if (waterLevel > WATER_THRESHOLD) {
    Serial.println("💧 Water Drop Detected! Rotating Servo...");
    myServo.write(90);  // Rotate servo to 90°
    delay(1000);  // Hold position for 1 second
    myServo.write(0);  // Return servo to 0°
  }

  delay(500);  // Small delay before next reading
}

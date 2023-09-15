#include <Servo.h>

// Create a Servo object
Servo myservo;

// Set the initial position of the servo (0 degrees)
int initialPosition = 0;

void setup() {
  // Attach the servo to pin 9
  myservo.attach(9);
}

void loop() {
  // Move the servo from 0 to 180 degrees
  for (int pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos); // Set servo position
    delay(15); // Delay for smoother motion (you can adjust this value)
  }

  // Move the servo from 180 to 0 degrees
  for (int pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos); // Set servo position
    delay(15); // Delay for smoother motion (you can adjust this value)
  }
}

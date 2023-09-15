#include <Servo.h>
#include <Wire.h>

Servo baseServo;    // Base servo
Servo shoulderServo; // Shoulder servo
Servo elbowServo;   // Elbow servo
Servo wristServo;   // Wrist servo
Servo gripperServo; // Gripper servo

int baseAngle = 0;    // Initial angles for each servo
int shoulderAngle = 0;
int elbowAngle = 0; 
int wristAngle = 0;
int gripperAngle = 0;  // Gripper angle (0 = open, 90 = closed)

void setup() {
  baseServo.attach(9);       // Attach servos to their respective pins
  shoulderServo.attach(10);
  elbowServo.attach(11);
  wristServo.attach(6);
  gripperServo.attach(5);

  baseServo.write(baseAngle); // Initialize servo positions
  shoulderServo.write(shoulderAngle);
  elbowServo.write(elbowAngle);
  wristServo.write(wristAngle);
  gripperServo.write(gripperAngle);

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the command from Python
    
    // Control each servo individually
    if (command == 'B') {
      baseAngle += 180; // Increment base angle (adjust as needed)
      baseServo.write(baseAngle);
    }
    else if (command == 'S') {
      shoulderAngle += 90; // Increment shoulder angle (adjust as needed)
      shoulderServo.write(shoulderAngle);
    }
    else if (command == 'E') {
      elbowAngle += 5; // Increment elbow angle (adjust as needed)
      elbowServo.write(elbowAngle);
    }
    else if (command == 'W') {
      wristAngle += 5; // Increment wrist angle (adjust as needed)
      wristServo.write(wristAngle);
    }
    else if (command == 'O') {
      gripperAngle = 0; // Open the gripper
      gripperServo.write(gripperAngle);
    }
    else if (command == 'C') {
      gripperAngle = 60; // Close the gripper
      gripperServo.write(gripperAngle);
    }
  }
}

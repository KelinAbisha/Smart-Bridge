#include <Servo.h>

// Define the pins for the ultrasonic sensor
#define trigPin 9
#define echoPin 10

// Define the pins for the two servo motors
#define servo1Pin 2
#define servo2Pin 3

// Define the servo objects
Servo servo1;
Servo servo2;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Initialize the servo objects
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  
  // Set the servo motors to their initial position
  servo1.write(0);
  servo2.write(0);
  
  // Initialize the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the distance to the object
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.println(distance);
  
  // Check if the object is less than 4cm away
  if (distance < 5) 
  {
    // Lift the bridge by rotating the servo motors
    servo1.write(90);
    servo2.write(90);
    Serial.println("Bridge lifted!");
  } 
  else {
    // Lower the bridge by rotating the servo motors
    servo1.write(0);
    servo2.write(0);
    Serial.println("Bridge lowered.");
  }
  
  // Wait for a short time before measuring again
  delay(1000);
}

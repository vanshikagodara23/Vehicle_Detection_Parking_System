// Aim: Vehicle Detection parking system

#include <Servo.h>

Servo gateServo;

// Pin Definitions
const int irPin = 2;
const int servoPin = 9;
const int buzzerPin = 8;

const int redPin = 3;
const int greenPin = 5;


void setup() {
  pinMode(irPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);


  gateServo.attach(servoPin);

  // Initial state
  gateServo.write(0);       // Gate closed
  setColor(255, 0, 0);      // Red
  digitalWrite(buzzerPin, LOW);
}

void loop() {

  int vehicle = digitalRead(irPin);

  // IR sensor outputs LOW when an object is detected
  if (vehicle == LOW) {

    // Turn on buzzer
    digitalWrite(buzzerPin, HIGH);

    // Open gate
    gateServo.write(90);
    setColor(0, 255, 0);    // Green
    delay(2000);

    // Turn off buzzer
    digitalWrite(buzzerPin, LOW);

    // Closing indication
    setColor(0, 0, 255);    // Blue
    delay(1000);

    // Close gate
    gateServo.write(0);
    setColor(255, 0, 0);    // Red
    delay(500);
  }
  else {
    gateServo.write(0);
    setColor(255, 0, 0);    // Red
    digitalWrite(buzzerPin, LOW);
  }
}

// RGB LED Function
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
}

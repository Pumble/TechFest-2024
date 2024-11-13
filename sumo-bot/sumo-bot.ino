/**
 * RESOURCES
 * L298N Stepper Motor Driver Controller: https://www.crcibernetica.com/l298n-stepper-motor-driver-controller/
 */

// INCLUDES
#include <SoftwareSerial.h>

/* ================================== VAR DEFINITION ================================== */

// L298N VARS
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define ENA 6
#define ENB 7

// BUILT-IN LED
#define BLINK_INTERVAL 300

/* ================================== END VAR DEFINITION ================================== */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  // SETUPS
  Serial.println("starting setup");

  L298N_setup();

  Serial.println("setup completed");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);
  delay(5000);

  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 128);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 128);
  delay(5000);

  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 0);
  delay(1000);
}

void L298N_setup() {
  Serial.println("==> L298N setup");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}
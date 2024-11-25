/* ============================================================= INCLUDES ============================================================= */
#include "BluetoothSerial.h"

/* ============================================================= CHECKS ============================================================= */
// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

/* ============================================================= VARS ============================================================= */
// ================================== Bluetooth VARS
BluetoothSerial SerialBT;
#define BL_NAME "PUMBLEBOT"  // Bluetooth device name

// ================================== Serial VARS
#define SERIAL_BAUDS 115200

// ================================== MOVEMENT VARS
#define MOVEMENT_FORWARD 'F'   // 70
#define MOVEMENT_BACKWARD 'B'  // 66
#define MOVEMENT_LEFT 'L'      // 76
#define MOVEMENT_RIGHT 'R'     // 82
#define MOVEMENT_STOP 'S'      // 83
#define SERVO_DOWN 'M'         // 77
#define SERVO_UP 'N'           // 78

// ================================== L298N VARS
#define IN1 27
#define IN2 26
#define ENA 14

#define IN3 4
#define IN4 5
#define ENB 7
int speed = 255;


// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

// ================================== BUILT-IN LED
#define BLINK_INTERVAL 300

/* ============================================================= SETUP ============================================================= */
void setup() {
  Serial.begin(SERIAL_BAUDS);
  Serial.println("Starting setup...");

  bluetooth_setup();
  L298N_setup();

  Serial.println("Setup completed...");
}

void bluetooth_setup() {
  Serial.println("==> Bluetooth setup");

  SerialBT.begin(BL_NAME);
  // bool success = SerialBT.setPin("8462");  // Set Bluetooth PIN to "1234"
  // if (success) {
  //   Serial.println("Bluetooth PIN set successfully.");
  // } else {
  //   Serial.println("Failed to set Bluetooth PIN.");
  // }

  Serial.println("==> Bluetooth setup completed");
}

void L298N_setup() {
  Serial.println("==> L298N setup");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // configure LEDC PWM
  ledcAttachChannel(ENA, freq, resolution, pwmChannel);

  Serial.println("==> L298N setup completed");
}

/* ============================================================= LOOP ============================================================= */
void loop() {
  // if (Serial.available())
  //   SerialBT.write(Serial.read());
  // while (SerialBT.available()) {
  //   int input = SerialBT.read();
  //   Serial.write(input);
  //   // https://randomnerdtutorials.com/esp32-dc-motor-l298n-motor-driver-control-speed-direction/
  //   switch (input) {
  //     case MOVEMENT_FORWARD:
  //       forward();
  //       break;
  //     case MOVEMENT_BACKWARD:
  //       backward();
  //       break;
  //     case MOVEMENT_STOP:
  //       stop();
  //       break;


  //       // case MOVEMENT_LEFT:
  //       //   digitalWrite(LED_BUILTIN, LOW);
  //       //   stop();
  //       //   left();
  //       //   break;
  //       // case MOVEMENT_RIGHT:
  //       //   digitalWrite(LED_BUILTIN, HIGH);
  //       //   stop();
  //       //   right();
  //       //   break;
  //       // case SERVO_DOWN:
  //       //   leftServo.write(SERVO_DOWN_POSITION);
  //       //   rightServo.write(SERVO_DOWN_POSITION);
  //       //   break;
  //       // case SERVO_UP:
  //       //   leftServo.write(SERVO_HIGH_POSITION);
  //       //   rightServo.write(SERVO_HIGH_POSITION);
  //       //   break;
  //   }
  // }
  // delay(20);


  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);

  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);

  // Move DC motor forward with increasing speed
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  while (dutyCycle <= 255) {
    ledcWrite(ENA, dutyCycle);
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 200;
}

/* ============================================================= MOVEMENT ============================================================= */
void backward() {
  stop();

  // digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speed);
}

void forward() {
  stop();

  // digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speed);
}

void stop() {
  // digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

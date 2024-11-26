/**
 * Referencias:
 * https://randomnerdtutorials.com/esp32-dc-motor-l298n-motor-driver-control-speed-direction/
 */

struct L298N {
  int ENA;
  int IN1;
  int IN2;
  int ENB;
  int IN3;
  int IN4;
};

// H-BRIDGE 1 PINS
#define HB1_ENA 15
#define HB1_IN1 2
#define HB1_IN2 4
#define HB1_ENB 19
#define HB1_IN3 5
#define HB1_IN4 18

// H-BRIDGE 2 PINS
#define HB2_ENA 25
#define HB2_IN1 26
#define HB2_IN2 27
#define HB2_ENB 13
#define HB2_IN3 14
#define HB2_IN4 12

int speed = 255;
// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;

L298N HB1 = { HB1_ENA, HB1_IN1, HB1_IN2, HB1_ENB, HB1_IN3, HB1_IN4 };
L298N HB2 = { HB2_ENA, HB2_IN1, HB2_IN2, HB2_ENB, HB2_IN3, HB2_IN4 };

#define SERIAL_BAUDS 115200

void setup() {
  Serial.begin(SERIAL_BAUDS);
  Serial.println("Starting setup...");

  L298N_setup();

  Serial.println("Setup completed...");
}

void loop() {
  forward();
  delay(2000);

  stop();
  delay(500);

  left();
  delay(2000);

  stop();
  delay(500);

  right();
  delay(2000);

  stop();
  delay(500);

  backwards();
  delay(2000);

  stop();
  delay(500);
}

void L298N_setup() {
  Serial.println("==> L298N setup");

  // H-BRIDGE 1 PINS
  pinMode(HB1.ENA, OUTPUT);
  pinMode(HB1.IN1, OUTPUT);
  pinMode(HB1.IN2, OUTPUT);
  pinMode(HB1.ENB, OUTPUT);
  pinMode(HB1.IN3, OUTPUT);
  pinMode(HB1.IN4, OUTPUT);
  // H-BRIDGE 2 PINS
  pinMode(HB2.ENA, OUTPUT);
  pinMode(HB2.IN1, OUTPUT);
  pinMode(HB2.IN2, OUTPUT);
  pinMode(HB2.ENB, OUTPUT);
  pinMode(HB2.IN3, OUTPUT);
  pinMode(HB2.IN4, OUTPUT);

  // configure LEDC PWM
  ledcAttachChannel(HB1.ENA, freq, resolution, pwmChannel);
  ledcAttachChannel(HB1.ENB, freq, resolution, pwmChannel);
  ledcAttachChannel(HB2.ENA, freq, resolution, pwmChannel);
  ledcAttachChannel(HB2.ENB, freq, resolution, pwmChannel);

  Serial.println("==> L298N setup completed");
}

void forward() {
  Serial.println("Moving forward");

  // H-BRIDGE 1
  ledcWrite(HB1.ENA, speed);
  digitalWrite(HB1.IN1, LOW);
  digitalWrite(HB1.IN2, HIGH);
  ledcWrite(HB1.ENB, speed);
  digitalWrite(HB1.IN3, LOW);
  digitalWrite(HB1.IN4, HIGH);

  // H-BRIDGE 2
  ledcWrite(HB2.ENA, speed);
  digitalWrite(HB2.IN1, LOW);
  digitalWrite(HB2.IN2, HIGH);
  ledcWrite(HB2.ENB, speed);
  digitalWrite(HB2.IN3, LOW);
  digitalWrite(HB2.IN4, HIGH);
}

void backwards() {
  Serial.println("Moving backwards");

  // H-BRIDGE 1
  ledcWrite(HB1.ENA, speed);
  digitalWrite(HB1.IN1, HIGH);
  digitalWrite(HB1.IN2, LOW);
  ledcWrite(HB1.ENB, speed);
  digitalWrite(HB1.IN3, HIGH);
  digitalWrite(HB1.IN4, LOW);

  // H-BRIDGE 2
  ledcWrite(HB2.ENA, speed);
  digitalWrite(HB2.IN1, HIGH);
  digitalWrite(HB2.IN2, LOW);
  ledcWrite(HB2.ENB, speed);
  digitalWrite(HB2.IN3, HIGH);
  digitalWrite(HB2.IN4, LOW);
}

void stop() {
  Serial.println("stoping");

  // H-BRIDGE 1
  digitalWrite(HB1.ENA, LOW);
  digitalWrite(HB1.IN1, LOW);
  digitalWrite(HB1.IN2, LOW);
  digitalWrite(HB1.ENB, LOW);
  digitalWrite(HB1.IN3, LOW);
  digitalWrite(HB1.IN4, LOW);

  // H-BRIDGE 2
  digitalWrite(HB2.ENA, LOW);
  digitalWrite(HB2.IN1, LOW);
  digitalWrite(HB2.IN2, LOW);
  digitalWrite(HB2.ENB, LOW);
  digitalWrite(HB2.IN3, LOW);
  digitalWrite(HB2.IN4, LOW);
}

void left() {
  Serial.println("Moving left");

  // H-BRIDGE 1
  ledcWrite(HB1.ENA, speed);
  digitalWrite(HB1.IN1, LOW);
  digitalWrite(HB1.IN2, HIGH);
  ledcWrite(HB1.ENB, speed);
  digitalWrite(HB1.IN3, LOW);
  digitalWrite(HB1.IN4, LOW);

  // H-BRIDGE 2
  ledcWrite(HB2.ENA, speed);
  digitalWrite(HB2.IN1, LOW);
  digitalWrite(HB2.IN2, HIGH);
  ledcWrite(HB2.ENB, speed);
  digitalWrite(HB2.IN3, HIGH);
  digitalWrite(HB2.IN4, LOW);
}

void right() {
  Serial.println("Moving right");

  // H-BRIDGE 1
  ledcWrite(HB1.ENA, speed);
  digitalWrite(HB1.IN1, LOW);
  digitalWrite(HB1.IN2, LOW);
  ledcWrite(HB1.ENB, speed);
  digitalWrite(HB1.IN3, LOW);
  digitalWrite(HB1.IN4, HIGH);

  // H-BRIDGE 2
  ledcWrite(HB2.ENA, speed);
  digitalWrite(HB2.IN1, LOW);
  digitalWrite(HB2.IN2, HIGH);
  ledcWrite(HB2.ENB, speed);
  digitalWrite(HB2.IN3, LOW);
  digitalWrite(HB2.IN4, HIGH);
}

/**
 * Referencias:
 * https://randomnerdtutorials.com/esp32-dc-motor-l298n-motor-driver-control-speed-direction/
 
 */

#define ENA 15
#define IN1 2
#define IN2 4

#define ENB 19
#define IN3 5
#define IN4 18

int speed = 255;
// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;

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

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // configure LEDC PWM
  ledcAttachChannel(ENA, freq, resolution, pwmChannel);
  ledcAttachChannel(ENB, freq, resolution, pwmChannel);

  Serial.println("==> L298N setup completed");
}

void forward() {
  Serial.println("Moving forward");

  ledcWrite(ENA, speed);
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  ledcWrite(ENB, speed);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backwards() {
  Serial.println("Moving backwards");

  ledcWrite(ENA, speed);
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  ledcWrite(ENB, speed);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop() {
  Serial.println("stoping");

  ledcWrite(ENA, speed);
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  ledcWrite(ENB, speed);
  digitalWrite(ENB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void left() {
  Serial.println("Moving left");

  ledcWrite(ENA, speed);
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  ledcWrite(ENB, speed);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void right() {
  Serial.println("Moving right");

  ledcWrite(ENA, speed);
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  ledcWrite(ENB, speed);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

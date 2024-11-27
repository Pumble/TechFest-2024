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

  void setup(int freq, int resolution, int pwmChannel) {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // configure LEDC PWM
    ledcAttachChannel(ENA, freq, resolution, pwmChannel);
    ledcAttachChannel(ENB, freq, resolution, pwmChannel);
  }

  void forward(int speed) {
    ledcWrite(ENA, speed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    ledcWrite(ENB, speed);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  void backward(int speed) {
    ledcWrite(ENA, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    ledcWrite(ENB, speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  void stop() {
    digitalWrite(ENA, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(ENB, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
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
  delay(1000);

  // left();
  // delay(2000);

  // stop();
  // delay(500);

  // right();
  // delay(2000);

  // stop();
  // delay(500);

  // backwards();
  // delay(2000);

  // stop();
  // delay(500);
}

void L298N_setup() {
  Serial.println("==> L298N setup");

  HB1.setup(freq, resolution, pwmChannel);
  HB2.setup(freq, resolution, pwmChannel);

  Serial.println("==> L298N setup completed");
}

void forward() {
  Serial.println("Moving forward");

  HB1.forward(speed);
  HB2.forward(speed);
}

void backwards() {
  Serial.println("Moving backwards");

  HB1.backward(speed);
  HB2.backward(speed);
}

void stop() {
  Serial.println("stoping");

  // H-BRIDGE 1
  HB1.stop();
  HB2.stop();
}

void left() {
  Serial.println("Moving left");

  HB1.forward(speed);
  HB2.backward(speed);
}

void right() {
  Serial.println("Moving right");

  HB1.backward(speed);
  HB2.forward(speed);
}

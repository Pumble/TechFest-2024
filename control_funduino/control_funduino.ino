/* Referencias:
 * Codigo Funduino: https://codebender.cc/sketch:146219#Funduino%20Joystick%20Shield%20Example.ino
 * Tienda Funduino: https://www.crcibernetica.com/funduino-joystick-shield/
 *
 * BLUETOOTH HC-06
 * Ejemplo: https://naylampmechatronics.com/blog/12_tutorial-basico-de-uso-del-modulo-bluetooth-hc-06-y-hc-05.html
 *
 */

// ============================================================= VARS =============================================================

// CONTROL VARS
int TRIANGLE_BUTTON = 2;
int CROSS_BUTTON = 4;
int SQUARE_BUTTON = 5;
int CIRCLE_BUTTON = 3;
int START_BUTTON = 6;
int SELECT_BUTTON = 7;
int JOYSTICK_BUTTON = 8;
int JOYSTICK_AXIS_X = A0;  // MIN: 0, CENTER: 523, MAX: 1023
int JOYSTICK_AXIS_Y = A1;  // MIN: 0, CENTER: 506, MAX: 1023
int BUTTONS[] = { TRIANGLE_BUTTON, CROSS_BUTTON, SQUARE_BUTTON, CIRCLE_BUTTON, START_BUTTON, SELECT_BUTTON, JOYSTICK_BUTTON };

// SERIAL VARS
int BAUDS = 9600;

// ============================================================= SETUP =============================================================
void setup() {
  buttons_setup();
  Serial.begin(BAUDS);
}

void buttons_setup() {
  for (int i; i < 7; i++) {
    pinMode(BUTTONS[i], INPUT);
    digitalWrite(BUTTONS[i], HIGH);
  }
}

// ============================================================= LOOP =============================================================
void loop() {
  // Serial.print("UP = "), Serial.print(digitalRead(TRIANGLE_BUTTON)), Serial.print("\t");
  // Serial.print("DOWN = "), Serial.print(digitalRead(CROSS_BUTTON)), Serial.print("\t");
  // Serial.print("LEFT = "), Serial.print(digitalRead(SQUARE_BUTTON)), Serial.print("\t");
  // Serial.print("RIGHT = "), Serial.print(digitalRead(CIRCLE_BUTTON)), Serial.print("\t");
  // Serial.print("START = "), Serial.print(digitalRead(START_BUTTON)), Serial.print("\t");
  // Serial.print("SELECT = "), Serial.print(digitalRead(SELECT_BUTTON)), Serial.print("\t");
  // Serial.print("ANALOG = "), Serial.print(digitalRead(JOYSTICK_BUTTON)), Serial.print("\t");
  // Serial.print("X = "), Serial.print(map(analogRead(JOYSTICK_AXIS_X), 0, 1000, -1, 1));
  // Serial.print("\t");
  // Serial.print("Y = "), Serial.print(map(analogRead(JOYSTICK_AXIS_Y), 0, 1000, -1, 1));
  // Serial.print("\n");
  // Serial.print("X = "), Serial.print(analogRead(JOYSTICK_AXIS_X));
  // Serial.print("\t");
  // Serial.print("Y = "), Serial.print(analogRead(JOYSTICK_AXIS_Y));
  // Serial.print("\n");
  // delay(100);

  if (Serial.available()) {
    char data = Serial.read();
    Serial.print("Dato recibido: ");
    Serial.println(dato);
  }
}
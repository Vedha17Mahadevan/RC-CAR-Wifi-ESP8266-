// ------------------------------
// NODEMCU + L298N MOTOR DRIVER
// ------------------------------

// Motor driver pins connected to NodeMCU
#define IN1 5   // D1 - Left motor forward
#define IN2 4   // D2 - Left motor backward
#define IN3 0   // D3 - Right motor forward
#define IN4 2   // D4 - Right motor backward

// Optional PWM speed control pins
#define ENA 14  // D5 - Speed control for left motor
#define ENB 12  // D6 - Speed control for right motor

void setup() {
  // Set all pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Start Serial Monitor
  Serial.begin(9600);
  Serial.println("Motor Test Starting...");

  // Optional: set default motor speed (0–1023 for ESP8266)
  analogWrite(ENA, 800); // 80% speed
  analogWrite(ENB, 800); // 80% speed
}

void loop() {
  // Move forward
  Serial.println("Moving Forward...");
  forward();
  delay(2000);

  // Stop
  Serial.println("Stop");
  stopMotors();
  delay(1000);

  // Move backward
  Serial.println("Moving Backward...");
  backward();
  delay(2000);

  // Stop
  Serial.println("Stop");
  stopMotors();
  delay(1000);

  // Turn left
  Serial.println("Turning Left...");
  left();
  delay(1500);

  // Turn right
  Serial.println("Turning Right...");
  right();
  delay(1500);

  // Stop again
  Serial.println("Final Stop");
  stopMotors();
  delay(2000);
}

// ---------------------------
// Motor control functions
// ---------------------------

// Move forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Move backward
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Turn left
void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  // Left motor backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);   // Right motor forward
}

// Turn right
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);   // Left motor forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  // Right motor backward
}

// Stop motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

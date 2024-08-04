#include <Adafruit_MotorShield.h>

int EchoPinR = 12;
int TrigPinR = 13;
int LEDpinR = 7;
float durationR;

int EchoPinL = 5;
int TrigPinL = 4;
int LEDpinL = 6;
float durationL;

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Select which 'port' M1, M2, M3 or M4.
Adafruit_DCMotor *leftWheel = AFMS.getMotor(1);
Adafruit_DCMotor *rightWheel = AFMS.getMotor(2);

void setup() {

if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }

leftWheel->setSpeed(255);
  rightWheel->setSpeed(255);
  leftWheel->run(FORWARD);
    rightWheel->run(FORWARD);
  leftWheel->run(RELEASE);
    rightWheel->run(RELEASE);

pinMode(TrigPinR, OUTPUT);
pinMode(EchoPinR, INPUT);
pinMode(LEDpinR, OUTPUT);

pinMode(TrigPinL, OUTPUT);
pinMode(EchoPinL, INPUT);
pinMode(LEDpinL, OUTPUT);

Serial.begin(9600);
}

void loop() {

digitalWrite(EchoPinR, LOW);

digitalWrite(TrigPinR, HIGH);
delay(10);
digitalWrite(TrigPinR, LOW);

durationR = pulseIn(EchoPinR, HIGH);


digitalWrite(EchoPinL, LOW);

digitalWrite(TrigPinL, HIGH);
delay(10);
digitalWrite(TrigPinL, LOW);

durationL = pulseIn(EchoPinL, HIGH);

// if no sensors are active
if (durationL > 500 && durationR > 500) {
  leftWheel->run(FORWARD);
  rightWheel->run(FORWARD);
}

// if the right sensors activates and left one doesn't
if (durationR < 500 && durationL > 500) {

  digitalWrite(LEDpinR, HIGH);
  
  leftWheel->run(BACKWARD);
  rightWheel->run(FORWARD);
  
  }else{
  if (durationR > 500) {
    digitalWrite(LEDpinR, LOW);
  } }

// if the left sensor activates and right one doesn't
if (durationL < 500 && durationR > 500) {
  
  digitalWrite(LEDpinL, HIGH);

  leftWheel->run(FORWARD);
  rightWheel->run(BACKWARD);
  
  }else{
  if (durationL > 500) {
    digitalWrite(LEDpinL, LOW);
  } }

// if both sensors activate
if (durationL < 500 && durationR < 500) {
  
  digitalWrite(LEDpinL, HIGH);
  digitalWrite(LEDpinR, HIGH);
  
  leftWheel->run(BACKWARD);
  rightWheel->run(FORWARD);
  
  }

delay(10);
}

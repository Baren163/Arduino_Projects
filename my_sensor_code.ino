
// Outputs
int LED_1 = 13;
int LED_2 = 12;
int LED_3 = 11;
int LED_4 = 10;
int TRIG = 6;

// Inputs
int ECHO = 5;

float duration, distance;

void setup() {
  // put your setup code here, to run once:
pinMode(ECHO, INPUT);
pinMode(TRIG, OUTPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(TRIG, LOW);
digitalWrite(ECHO, LOW);
delayMicroseconds(2);
digitalWrite(TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG, LOW);

duration = (pulseIn(ECHO, HIGH));

distance = duration * 0.0001715;

if (distance < 2) {
  digitalWrite(LED_1, HIGH);
} else {
  digitalWrite(LED_1, LOW);
}

if (distance < 1.5) {
  digitalWrite(LED_2, HIGH);
} else {
  digitalWrite(LED_2, LOW);
}

if (distance < 1) {
  digitalWrite(LED_3, HIGH);
} else {
  digitalWrite(LED_3, LOW);
}

if (distance < 0.6) {
  digitalWrite(LED_4, HIGH);
} else {
  digitalWrite(LED_4, LOW);
}

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);


}

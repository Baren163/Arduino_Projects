
// Outputs
int LED_1 = 13;
int LED_2 = 12;
int LED_3 = 11;
int LED_4 = 10;
int TRIG = 6;
int PAUSE_PIN = 4;

// Inputs
int ECHO = 5;
//int interruptPin = 7;

float duration, distance, prevDistance;
float scan_delay = 1000;

int numbers[4] = {0, 0, 0, 0};

int i = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(TRIG, OUTPUT);

  pinMode(ECHO, INPUT);
  //pinMode(interruptPin, INPUT);

  //attachInterrupt(digitalPinToInterrupt(interruptPin), increment, RISING);

  prevDistance = 0.5;

  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ECHO, LOW);
  digitalWrite(TRIG, LOW);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  distance = duration * 0.0001715;

  if (distance < 1 && prevDistance > 1) {
    //digitalWrite(interruptPin, HIGH);
    bool carry = true;
    i = 0;
    
    while (carry) {

      

      if (numbers[i] == 0) {
        numbers[i] = 1;

        switch(i) {
          case 0:
            digitalWrite(LED_1, HIGH);
            break;
          case 1:
            digitalWrite(LED_2, HIGH);
            break;
          case 2:
            digitalWrite(LED_3, HIGH);
            break;
          default:
            digitalWrite(LED_4, HIGH);
        }

        carry = false;

      } else if (numbers[i] == 1) {
        numbers[i] = 0;
        switch(i) {
          case 0:
            digitalWrite(LED_1, LOW);
            break;
          case 1:
            digitalWrite(LED_2, LOW);
            break;
          case 2:
            digitalWrite(LED_3, LOW);
            break;
          default:
            digitalWrite(LED_4, LOW);
        }
      }

      if ((i == 3) && (carry == true)) {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, LOW);
        digitalWrite(LED_4, LOW);
        for (int i = 0; i < 4; i++) {
          numbers[i] = 0;
        }
        carry = false;
      }

      i++;

    }
    
    digitalWrite(PAUSE_PIN, HIGH);

    delay(scan_delay);

    digitalWrite(PAUSE_PIN, LOW);

  }

  Serial.print("Distance: ");
  Serial.println(distance);

  prevDistance = distance;

  delay(200);

}

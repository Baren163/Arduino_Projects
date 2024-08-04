#include "Arduino.h"
#include <SoftwareSerial.h>
char incoming_value = 0;

// The rxPin of the arduino needs to be connected to the tx of the bluetooth (HC05) chip and vice versa

// Then you have to make sure you are using the correct serial/terminal (there are two). There
// is 'Serial' and 'BTSerial'. Serial is just the terminal/serial/communication from the arduino whereas
// BTSerial is the terminal/serial/communication from the bluetooth chip so obviously 
// to control the board via bluetooth you would want to be listening/'BTSerial.read' ing from
// that.

// To access the BTSerial commands you must include this library: #include <SoftwareSerial.h>

// Also make sure to set the rxPin(reciever) of the arduino to input and the txPin(transmit)
// of the arduino to output.

const byte arduino_rxPin = 0;
const byte arduino_txPin = 1;

int incoming_int;

// This is a command from the new library that tells the arduino the paramter pins will
// be used for the recieve and transmit pins to and from the BT chip
SoftwareSerial BTSerial(arduino_rxPin, arduino_txPin); // RX TX

void setup() {

pinMode(arduino_rxPin, INPUT);
pinMode(arduino_txPin, OUTPUT);
  
// This sets up the communication link of the BTSerial/chip
  BTSerial.begin(9600);

//Serial.begin(9600);

// LED pin
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

// This is simply checking to see if there is any data at all to be picked up from the 
// BTSerial/blutooth communication link and then if there is it will go through it
// character by char and each char will go through the process of being assigned
// to the incoming_value variable and being printed to the BTSerial/chip.
  if (BTSerial.available() > 0) {
    incoming_value = BTSerial.read();
    BTSerial.print(incoming_value);

    incoming_int = incoming_value - '0';
    //Serial.println(incoming_int);
    if (incoming_value == '1') {
      while (incoming_int != 0){
        digitalWrite(13, HIGH);
        delay(450);
        digitalWrite(13, LOW);
        delay(450);
      if (BTSerial.available() > 0) {
    incoming_value = BTSerial.read();
    BTSerial.print(incoming_value);

    incoming_int = incoming_value - '0';
        if (incoming_value == 0){
          break;
        }
      }
    }
    digitalWrite(13,LOW);
  }
  }
}



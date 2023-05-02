#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // TX, RX pins of Bluetooth module
const int relayPin = 2; // output pin for the relay
char incomingByte; // variable to store incoming data from the app

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
  BTSerial.begin(9600); // initialize Bluetooth communication at 9600 bits per second
  pinMode(relayPin, OUTPUT); // set the relay pin as output
}

void loop() {
  if (BTSerial.available() > 0) { // if there's data available from the app
    incomingByte = BTSerial.read(); // read the incoming byte
    if (incomingByte == '1') { // if the byte is '1'
      digitalWrite(relayPin, HIGH); // turn on the relay
      BTSerial.println("Switch turned on"); // send a response to the app
    } else if (incomingByte == '0') { // if the byte is '0'
      digitalWrite(relayPin, LOW); // turn off the relay
      BTSerial.println("Switch turned off"); // send a response to the app
    }
  }
}

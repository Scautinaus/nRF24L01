#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int joystickPin=A0;
int servoPos;
int joystickPos;

RF24 radio(9, 8); // CE, CSN

const byte address[6] = "10101";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(joystickPin,INPUT);
}

void loop() {
  //const char text[] = "Hello World";
  joystickPos=analogRead(joystickPin);
  servoPos=(180./1023.)*joystickPos;
  radio.write(&servoPos, sizeof(servoPos));
  Serial.println(servoPos);
  delay(1000);
}

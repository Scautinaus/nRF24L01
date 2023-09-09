#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int servoPin=6;
Servo myServo;

RF24 radio(9, 8); // CE, CSN

const byte address[6] = "10101";

void setup() {
  Serial.begin(9600);
  pinMode(servoPin,OUTPUT);
  myServo.attach(servoPin);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  while (radio.available()) {
    //char text[32] = "";
    int servoPos=0;
    radio.read(&servoPos, sizeof(servoPos));
    Serial.println(servoPos);
    myServo.write(servoPos);
  }
}

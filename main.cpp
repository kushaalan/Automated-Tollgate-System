#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo gateServo;
const int redLed = 3;
const int greenLed = 2;
void setup() {
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
gateServo.attach(5);
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
closeGate();
}
void loop() {
if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
String rfid = "";
for (byte i = 0; i < mfrc522.uid.size; i++) {
rfid += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
rfid += String(mfrc522.uid.uidByte[i], HEX);
}
rfid.toUpperCase();
Serial.println("RFID Tag: " + rfid);
if (rfid == "53656C9F") {
openGate();
delay(5000);
closeGate();
} else {
Serial.println("Invalid RFID");
flashRedLed();
}
mfrc522.PICC_HaltA();
delay(1000);
}
}
void openGate() {
gateServo.write(0);
digitalWrite(greenLed, HIGH);
digitalWrite(redLed, LOW);
}
void closeGate() {
gateServo.write(90);
digitalWrite(greenLed, LOW);
digitalWrite(redLed, HIGH);
}
void flashRedLed() {
for (int i = 0; i < 3; i++) {
digitalWrite(redLed, HIGH);
delay(500);
digitalWrite(redLed, LOW);
delay(500);
}
}
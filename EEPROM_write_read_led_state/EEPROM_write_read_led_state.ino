#include <EEPROM.h>

#define EE_LED_STATE_ADDRESS 0

#define LED_PIN 10
#define BUTTON_PIN 2

int ledState = 0;
int oldButtonState = 0;

int readSavedInt(int address){
  byte value = EEPROM.read(address);
  return int(value);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Serial ready");

  pinMode(LED_PIN,OUTPUT);
  ledState = readSavedInt(EE_LED_STATE_ADDRESS);
  if(ledState != 1 && ledState != 0)ledState = 0;
  Serial.println("Saved LED state: "+String(ledState));
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if(buttonState == 1 && oldButtonState == 0){
    oldButtonState = 1;
    ledState = !ledState;  
    EEPROM.write(EE_LED_STATE_ADDRESS, ledState);
    Serial.println("Saved LED state: "+String(ledState));
    delay(50);
  }
  
  digitalWrite(LED_PIN,ledState);
  delay(20);
  oldButtonState = buttonState;
}

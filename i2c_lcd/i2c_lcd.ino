// See http://playground.arduino.cc/Main/I2cScanner

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x3f);
DHT dht(DHTPIN, DHTTYPE,0); //Last parameter is ignored

int show;

void setup(){
  Serial.begin(9600);
  Serial.println("LCD...");

  lcd.begin(16, 2); // initialize the lcd
}

void loop(){
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.print("Hello LCD");
  delay(1000);

  while(1){
    lcd.setBacklight(0);
    delay(1500);
    lcd.setBacklight(255);
    delay(1500);
  }
}

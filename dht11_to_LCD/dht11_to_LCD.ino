#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <DHT.h>

//DHT constants
#define DHTTYPE DHT11 // DHT11 or DHT22
#define DHTPIN 3

LiquidCrystal_PCF8574 lcd(0x3f);
DHT dht(DHTPIN, DHTTYPE,0); //Last parameter is ignored

const int updateInterval = 500; //Interval in milliseconds

void setup() {
  Serial.begin(9600);
  Serial.println("LCD...");

  lcd.begin(16, 2); // initialize the lcd

  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.print("Hello LCD");
  delay(1000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return false;
  }else{
    lcd.clear();
    lcd.print("T: "+String(t)+" H:"+String(h));
  }

  delay(updateInterval);
}

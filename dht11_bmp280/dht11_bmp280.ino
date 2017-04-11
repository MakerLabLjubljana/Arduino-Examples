#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <DHT.h>

//DHT constants
#define DHTTYPE DHT11 // DHT11 or DHT22
#define DHTPIN 3

//Objects and variables
DHT dht(DHTPIN, DHTTYPE,0); //Last parameter is ignored
Adafruit_BMP280 bmp; //I2C
float h, t, t1, p;

const int updateInterval = 200; //Interval in milliseconds

//Reads DHT sensor data
boolean readDHT(){
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return false;
  }else{
    Serial.print("t:");
    Serial.println(t);
    Serial.print("h:");
    Serial.println(h);
    Serial.println("dht read");
    return true;
  }
}

//Reads BMP sensor data
boolean readBMP(){
  t1 = bmp.readTemperature();
  //Serial.print("Temperature = ");
  Serial.println(t1);
  Serial.println(" *C");

  p = bmp.readPressure();
  
  Serial.print("Pressure = ");
  Serial.print(p/100);
  Serial.println(" hPa");
  
  //Serial.println("bmp read");
  return true;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Serial ready.");
  dht.begin();
  readDHT();

  if (!bmp.begin(0x76)) { //0x76
    Serial.println("Could not find a valid BMP280 sensor, check wiring or address!");
    while(1);
  }
  delay(50);
  readBMP();
}

void loop() { 
  //Read DHT
  readDHT();
  
  //Read BMP
  readBMP();
  
  Serial.println("-----------------------\n\n");
  
  //Wait some time before repeating the process
  delay(updateInterval);
}

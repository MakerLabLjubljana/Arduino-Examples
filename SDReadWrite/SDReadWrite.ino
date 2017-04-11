#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // re-open the file for reading:
  myFile = SD.open("test.csv");
  if (myFile) {
    Serial.println("test.csv:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.csv");
  }
}

void loop() {
  myFile = SD.open("test.csv", FILE_WRITE);
  if (myFile) {
    Serial.print("Writing to test.csv...");
    myFile.println(String(millis())+", 2, 3");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.csv");
  }
  delay(3000);
}

#include <SPI.h>
#include <SD.h>

// Pin definitions
#define MOSI_PIN PA7
#define MISO_PIN PA6
#define SCK_PIN  PA5
#define CS_PIN   PA4

void setup() {
  Serial.begin(115200);
  // Initialize the SPI pins
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, INPUT);
  pinMode(SCK_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);

  // Initialize the SD card
  if (!SD.begin(CS_PIN)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  Serial.println("SD card initialized.");
}


void loop() {
  // Read data from the SD card
  File dataFile = SD.open("datalog.txt");
  if (dataFile) {
    Serial.println("Contents of datalog.txt:");
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    Serial.println("Error opening datalog.txt");
  }

  // Write data to the SD card
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println("Hello, world!");
    dataFile.close();
    Serial.println("Data written to file.");
  } else {
    Serial.println("Error opening datalog.txt");
  }

  delay(5000); // Wait for 5 seconds
}

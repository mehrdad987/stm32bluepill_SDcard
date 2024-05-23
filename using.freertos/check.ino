#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
#include <SD.h>

// Pin definitions
#define MOSI_PIN PA7
#define MISO_PIN PA6
#define SCK_PIN  PA5
#define CS_PIN   PA4

RTC_DS3231 rtc;
File dataFile;

void setup() {
  Serial.begin(115200);

  // Initialize the SPI pins
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, INPUT);
  pinMode(SCK_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);

  // Initialize the RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Initialize the SD card
  while (!SD.begin(CS_PIN)) {
    Serial.println("SD card initialization failed");
    delay(1000);
  }
  Serial.println("SD card initialized");
}

void loop() {
  // Read the current time from the RTC
  DateTime now = rtc.now();

  // Construct the file name
  char fileName[15];
  sprintf(fileName, "%04u%02u%02u.txt", now.year(), now.month(), now.day());

  // Write the time to the SD card
  dataFile = SD.open(fileName, FILE_WRITE);
  if (dataFile) {
    dataFile.print(now.year(), DEC);
    dataFile.print("/");
    dataFile.print(now.month(), DEC);
    dataFile.print("/");
    dataFile.print(now.day(), DEC);
    dataFile.print(" ");
    dataFile.print(now.hour(), DEC);
    dataFile.print(":");
    dataFile.print(now.minute(), DEC);
    dataFile.print(":");
    dataFile.println(now.second(), DEC);
    dataFile.close();
    Serial.println("Time written to SD card");
  } else {
    Serial.println("Error opening file");
  }

  // Wait for 1 second before reading the time again
  delay(1000);
}
//the summry:)
//dataFile.printf("%04u/%02u/%02u %02u:%02u:%02u\n", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());

#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
#include <SD.h>

/* FreeRTOS includes */
#include <STM32FreeRTOS.h>
#include <task.h>

// Pin definitions
#define MOSI_PIN PA7
#define MISO_PIN PA6
#define SCK_PIN  PA5
#define CS_PIN   PA4

/* Task function prototypes */
void TaskReadCAN(void *pvParameters);
void TaskRevolution(void *pvParameters);

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
  DateTime now = rtc.now();
  sprintf(fileName, "%04u%02u%02u.txt", now.year(), now.month(), now.day());

  /* Create the tasks */
  xTaskCreate(TaskReadCAN, "Read CAN", 256, NULL, 1, NULL);
  xTaskCreate(TaskRevolution, "TaskRevolution", 256, NULL, 1, NULL);

  /* Start the scheduler */
  vTaskStartScheduler();
}

void loop() {
}

void TaskReadCAN(void *pvParameters) {
  while (1) {
   
      // Add more data as needed
    }
    vTaskDelay(pdMS_TO_TICKS(100)); // Delay for 100 milliseconds
  }
}

void TaskRevolution(void *pvParameters) {
  while (1) {
    DateTime now = rtc.now();

    // Write the time and CAN data to the SD card
    dataFile = SD.open(fileName, FILE_WRITE);
    if (dataFile) {
      dataFile.printf("%04u/%02u/%02u %02u:%02u:%02u, Engine Speed: %.2f RPM, Engine Boost Pressure: %u kPa, Engine Tilt/Trim Angle: %d degrees\n",
                      now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second(), rpm, (unsigned int)engineBoostPressure, (int)engineTiltTrimAngle);
      dataFile.close();
      Serial.println("Data written to SD card");
    } else {
      Serial.println("Error opening file");
    }

    vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
  }
}

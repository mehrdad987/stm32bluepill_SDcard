### STM32 Blue Pill SD Card Examples ###
This repository contains three examples for using an SD card with an STM32 Blue Pill development board, including two Arduino sketches and one STM32CubeIDE project.
_____________________________________________________________________

# Introduction #
The STM32 Blue Pill is a popular and cost-effective development board based on the STM32F103C8T6 microcontroller. This repository provides three examples that demonstrate how to interface an SD card with the STM32 Blue Pill, allowing you to read and write data to the card.

## Examples ##
Arduino Example 1: Basic SD Card Read/Write in c
______________
This example shows how to perform basic read and write operations on an SD card using the Arduino environment.
in cubeide use stm32f103c8t6 utilizes the RCC (Reset and Clock Control) and SPI (Serial Peripheral Interface) peripherals to communicate with the SD card. Additionally, a UART (Universal Asynchronous Receiver-Transmitter) interface is used for diagnostic purposes.
*

Arduino Example 2: Simple SD Card Read/Write in c++
_____________
This example demonstrates how to create and write data to a file on an SD card using the Arduino environment.
*

STM32CubeIDE Example: SD Card Read/Write mixing with freertos
_____________
This example shows how to perform basic read and write operations on an SD card using the STM32CubeIDE development environment.

Hardware Requirements
STM32 Blue Pill development board
SD card module or adapter
Jumper wires or connection cables

Software Requirements
Arduino IDE (for the Arduino examples)
STM32CubeIDE (for the STM32CubeIDE example)

@================================================
Getting Started

Clone or download the repository to your local machine.
Open the appropriate example in your preferred development environment (Arduino IDE or STM32CubeIDE).
Connect the SD card module or adapter to the STM32 Blue Pill board using the following pin connections:
SD card CS (Chip Select) pin to Blue Pill PA4
SD card MOSI pin to Blue Pill PA7
SD card MISO pin to Blue Pill PA6
SD card SCK pin to Blue Pill PA5
SD card GND pin to Blue Pill GND
SD card VCC pin to Blue Pill 3.3V
Build and upload the project to your STM32 Blue Pill board.

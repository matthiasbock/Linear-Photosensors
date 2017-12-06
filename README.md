How to read out linear photocell arrays
===================

This project aims for supporting readout of CCD modules.
We have access to the following modules for development:
* P/NO:51000101-0001 REV:X2 0237 - PCB,HAX2,CCD/B,TCD2905D
* P/NO:51000042-0006 REV:X7 0038 - PCB,HAX1,CCD/B,UPD8870
* 713-3202-110 REV:1.1
* HP C5110-26501 REV:B
* API 610PLUS CCD.BD N3717 REV:S4

These modules were aquired from deconstructed scanners.
We would like to elaborate and document possible ways,
how to easily read out photo-sensor data,
how to attach modules to a PC
and how to use of them for your own purposes.

Currently we aim for microcontroller support.
For this purpose we would like to develop a shield module for Arduino Mega,
which is based on the Atmel ATmega2560.

## P/NO:51000101-0001 REV:X2 0237 - PCB,HAX2,CCD/B,TCD2905D
* <a href="https://docs.google.com/spreadsheet/ccc?key=0ArDc7Y8Abz1GdHZYNUhHbGhNMXRjc3ROTm8zbE9MMnc">Pinout (Google Docs)</a>

<img src="https://github.com/matthiasbock/Linear-CCD-arrays/blob/master/P-NO:51000101-001%20REV:X2.png?raw=true"/>

## P/NO:51000042-0006 REV:X7 0038 - PCB,HAX1,CCD/B,UPD8870
## 713-3202-110 REV:1.1
## HP C5110-26501 REV:B
## API 610PLUS CCD.BD N3717 REV:S4

# Links
 * Arduino analog inputs tutorial: http://arduino.cc/en/Tutorial/AnalogInput
 * Nathan hooking up a sensor to an oscilloscope: http://www.youtube.com/watch?v=ut9LfQmaYkU

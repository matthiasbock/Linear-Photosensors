Linux support for readout of linear photocell arrays
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

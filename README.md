I built an Arduino-based benchtop prototype that uses changes in laser light reaching a photodiode to control a stepper motor. This setup is a simplified version of a combustion analysis experiment I’m developing as an undergraduate researcher at UNC Charlotte. It lets me test the sensing and motor-control logic without running a combustion experiment.

How It Works

A 650 nm red laser is aimed at a BPW34 photodiode. The Arduino samples the photodiode signal and estimates its rate of change between consecutive readings. When that rate exceeds a preset threshold, the Arduino commands the stepper motor to move through a ULN2003 driver. The trigger is based on how quickly the signal changes, not on the light level alone.

Benchtop Testing

I used a sheet of paper to fully block, partially block, and leave the laser beam unobstructed. This let me check how the photodiode signal and motor responded as I changed the amount of light reaching the sensor.

Hardware

Arduino UNO R4 WiFi

28BYJ-48 5 V stepper motor

ULN2003 stepper motor driver board

BPW34 photodiode

4.7 kΩ resistor

650 nm red laser module

Breadboard and 5 V power supply

Jumper wires and USB cable

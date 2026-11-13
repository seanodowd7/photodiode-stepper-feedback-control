# photodiode-stepper-feedback-control
Built a photodiode feedback control system that received input from a laser and moved a stepper accordingly. This is a smaller scale version for the combustion analysis experiment I am working on as an undergraduate researcher at UNC Charlotte. The program moves the stepper if the derivative of I/t is above a certain threshold. I tested the program by using paper to fully block the photodiode, partially block the photodiode, and not blocking it all. 
Hardware used:

Arduino UNO R4 WiFi,
28BYJ-48 5V stepper motor,
ULN2003 stepper motor driver board,
BPW34 photodiode,
4.7 kΩ resistor,
650 nm red laser module,
Breadboard,
Breadboard power supply / 5V power source,
Jumper wires,
USB cable

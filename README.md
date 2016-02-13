# ObstacleAvoidingRobot-TIVA-C-Series-TM4C123G-Launchpad

This repository contains the code and the Drivers in C Language I wrote for the Distance Sensor (HC-SR04), Motor Driver (L298N from Sparkfun), Servo Motor (SG90 9g Micro Servo) and 20x4 LCD (JHD204A).

#How to Use the Code for each device in your Project

Code for each module/device is written in C language accompanied by an Header File. You need to get the corresponding C file in your project and then include the header file in your project to use the different methods in the C File. The pins for Different modules were used as follows. You can change them in the code only if you have an idea of programming TIVA C-Series TM4C123G Launchpad.

#Distance Sensor Pins

Trigger -> PIN E2

Echo -> PIN PF4

Vcc -> 5V

GND -> GND

#Servo Motor

Power -> 5V

GND -> GND

Signal -> PF2

#Motor Driver

ENA -> PIN PA2

IN1 -> PIN PA3

IN2 -> PIN PA4

IN3 -> PIN PA5

IN4 -> PIN PA6

ENB -> PIN PA7

#LCD 

E (Enable Pin) -> PIN PE3

Read/Write -> PIN PE4

RS (Register Select) -> PIN PE5

D0 to D7 (Data Pins) -> PINS PB0 -> PB7 

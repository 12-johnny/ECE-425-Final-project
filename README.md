# ECE-425-Final-project



## Table of Contents  

[Introduction](#introduction)  

[Methodology](#methodology) 

[Results](#Results)  

[Block-Diagram](#Block-Diagram) 

[Components-list](#Components-list) 

[Pinout-Table](#Pinout-Table) 

[References](#References) 


<a name="Introduction"/>

## Introduction 
This describes our final project, in which we decided to create a robot that follows predetermined paths called the JBOT. Using GPIO, PWM, timers, and interrupts, we successfully got the robot to execute four predetermined paths.
  - ECE 425: Microprossesing systems
  
Completed by:
  - Jonathan Galindo
  - Jonathan pena
    
Professor:
  - Aaron Nanas

<a name="Methodology"/>

## Methodology

As previously mentioned the embedded systems concepts that were applied in our project were GPIO, PWM, timers, and interrupts. GPIO was used for all the motor drivers and the PMOD button module, PWM was used to control the speed of the geared DC motors, interrupts were used with the PMOD button module to have each button perform a different set path, and timers were used to implement delay functions within our code. 
The peripherals we used were GPIO, SysTick, PWM0_0, PWM1_3, Timer0_A, and PMOD_Handler. 
The outcome of our project is a 4 wheeled bot that has four set paths that include incrementally speeding up, slowing down, square, and triangle paths.

<a name="Results"/>

## Results 

### Jbot version 1 
![image](https://github.com/user-attachments/assets/c166ed7d-d93f-4171-b100-cfd7e8749279)

### Jbot version 2
![image](https://github.com/user-attachments/assets/2b131722-aa92-40a4-8511-0cc04d9e8df4)

### Result videos
- Forward motion Demo:  [link](https://www.youtube.com/watch?v=0g-sLS1BYuo)
- Reverse motion Demo:  [link](https://www.youtube.com/shorts/58Ausv4WyR4)
- Square motion Demo:   [link](https://www.youtube.com/shorts/1VXs_1inAJk)
- Triangle motion Demo: [link](https://www.youtube.com/watch?v=Pw7c7Hkyzvk)
- Random motion Demo:   [link](https://www.youtube.com/watch?v=Pw7c7Hkyzvk)

<a name="Block-Diagram"/>

## Block-Diagram

<a name="Components-list"/>

## Components-list

| Description               | Quantity      | Manufactur      |
| --------------------------| ------------- |-----------------|
| Tiva C series TM4C123G    | 1             | Texas Instrument|
| USB-A to Micro-USB cable  | 1             | N/A             |
| PMOD BTN Module           | 1             | Digilent        |
| Geared DC Motors          | 4             | Gibildet        |
| L298N dual DC Motor Driver| 2             | Hiletgo         |
| Tires                     | 4             | Gibilet         |
| 9v batteries              | 2             | Amazon          |
| 9v Battery hardness       | 2             | N/A             |
| Lego Tecnic               | 1             | Lego            |
| Switches                  | 2             | N/A             |
| Breadboard                | 1             | N/A             |
| Wire                      | 1             | N/A             |

<a name="Pinout-Table"/>

## Pinout-Table 

<a name="References"/>

## References

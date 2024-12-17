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

![image](https://github.com/user-attachments/assets/a525f7c1-d97d-4fbb-9548-3a42da477702)
### Full circuit schematic for JBOT

<a name="Components-list"/>

## Components-list

| Description               | Quantity      | Manufacture     |
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

### PMOD BTN Module 

![image](https://github.com/user-attachments/assets/6d5c37fa-10ce-42d5-9dcb-4c18f2d2c540)


| TM4C123G Launchpad| Pin Purpose   | 
| ------------------| ------------- |
| PA2               | BTN_0         |
| PA3               | BTN_1         |
| PA4               | BTN_2         |
| PA5               | BTN_3         |
| VCC (3.3v)        | Vcc           |
| GND               | GND           |

### L289N Dual Motor driver 

![image](https://github.com/user-attachments/assets/35c13ad6-9feb-416b-b242-3b9ffc6a4d31)

| TM4C123G Launchpad| Pin Purpose    | 
| ------------------| ---------------|
| PC4               | In 1,3 Driver R|
| PC5               | In 2,4 Driver R|
| PC6               | In 1,3 Driver L|
| PC7               | In 2,4 Driver L|
| PB6               | PWM0_0         |
| PF2               | PWM0_1         |

<a name="References"/>

## References

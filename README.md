# Autonomous Racing Robot

Autonomous racing robot developed as part of a Computer Engineering project.

## Overview

This project focused on developing control software for an autonomous racing robot. The system was implemented in C on an ATmega328P microcontroller and uses ADC and PWM peripherals for sensor acquisition and motor control. Five infrared sensors mounted underneath the robot were used to detect the race track and guide navigation. The robot continuously processes sensor measurements and adjusts motor speeds in real time to follow the track.

## Features

* Implemented control software for an autonomous racing robot.
* Developed the system in C on an ATmega328P microcontroller.
* Acquired sensor measurements using the ADC peripheral.
* Used infrared sensors for line detection and track following.
* Implemented PWM motor control for differential steering.
* Developed a line-following algorithm based on sensor measurements.
* Performed soft and hard turns using threshold-based control.
* Tuned sensor thresholds and motor parameters experimentally.
* Recorded minimum and maximum sensor values for calibration.
* Improved robustness through iterative testing and debugging.
* Optimized navigation under real-time constraints.

## Control Strategy

The robot continuously reads infrared sensor values and adjusts the left and right motor speeds independently.

The controller:

* Drives straight when the track is centered.
* Performs soft left and right corrections.
* Performs hard left and right turns when larger deviations are detected.
* Controls motor speed using PWM.
* Uses infrared sensors mounted underneath the robot for line tracking.
* Continuously updates navigation decisions in real time.

## Technologies

* C
* ATmega328P
* Embedded Systems
* ADC
* PWM
* Infrared Sensing
* Real-Time Systems
* Motor Control
* Sensor-Based Navigation
* Robotics

## Tools

* PlatformIO
* Visual Studio Code
* Git
* GitHub

## Course

Developed as part of the **Computer Engineering** course at Kristianstad University.

## Collaboration

Developed as a team project involving algorithm development, testing, sensor calibration, and system integration.



**Important:** Before using this repository, remember to install AX-12A library from: https://github.com/jumejume1/AX-12A-servo-library

# About AX12-A
The AX12-A dynamixel servomotor, it can be used for control both velocity and position.

When it's used for velocity control, it works between 0° and 300°, which are represented by the range of 0 and 1023 bits, as it's shown below:

![enter image description here](https://emanual.robotis.com/assets/images/dxl/dx/dx_series_goal_position.png)

Likewise, when it's used for velocity control, its velocity varies from 0 to 1023 bits.

It's composed of three pins: data, vcc and ground, as it's shown below:
![enter image description here](https://os.mbed.com/media/components/pinouts/ax12pinout.png)

Unlike common servomotors, the AX12-A is not controlled by a PWM pins, it's rather **controlled by serial port transmitter pin**
# Circuit Diagram

In order to use the AX12-A dynamixel servomotor in conjunction with the Arduino UNO board, it's necessary to use it as it's shown in the link below:


![enter image description here](https://drive.google.com/file/d/1jubREQObciG_EPda9IJK6XAkuJ8a8kjX/view?usp=drive_link)

As said before, the transmitter pin (TXD) is used because the AX12-A is controlled through serial port connections.
# Code files
In this repository, you'll find codes for:

 - Open-loop position control
 - Open-loop velocity control
 - Setting ID for AX12-A servomotor
 - Resetting ID for AX12-A servomotor

# Recomendations
 - If you don't know your AX12-A's ID, then use 254 as your ID. This is
   a general ID for all the AX-12A
   
 - Share voltage source's ground and Arduino UNO's ground, so the reference it's the same for both


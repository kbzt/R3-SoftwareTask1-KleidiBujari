# R3 Software Task 1
### By: Kleidi Bujari // kbujari@ryerson.ca

## Links
- Tinkercad Diagram [https://www.tinkercad.com/things/jHfTYzODa34]
- Circuit Picture [https://raw.githubusercontent.com/kleidibujari/R3-SoftwareTask1-KleidiBujari/main/assets/circuit.png]

## The Project

The project takes input from a potentiometer as resistance and converts it to a number between 0-99, and finally displaying it on two 7-segment displays connected to a CD4511 chip each, finally connected to an Arduino Uno which handles power and code.

### Technical Description

The system works by first recieving input from the potentiometer, connected to 5V power, ground, and the AnalogIn0 pin on the Arduino. The input is then processed and converted into a usable number between 0-99, and converting once more to a binary number to pass to the CD4511 chips. These pass the respective digits of the number to each 7-segment display, displaying the number for the user.

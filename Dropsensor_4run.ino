/*
   Arduino+DropSensor sample sketch, tested on Uno. 4 Sensor OK!
   This program should be able to handle as many sensor as I2C wire implemetation supports. 

   Setup:
   ----------------------------------------------
   Arduino        Melecs Dropsensor
   5V->2.8v       Vcc
   GND            GND
   GPIO           Referred to GPIO Setup Section
   SCL            SCL
   SDA            SDA
   ----------------------------------------------
   
   Writing a sketch for DropSensor library:
   1. Declare a DropSensor Object
   2. Set the GPIO Pin for Arduino
   3. Implement the _run() function as mentioned. 
   
   Mandatory variables for _run():
   1. Sensor Object
   2. GPIO Pin number 
   3. Sensor Address
   4. Number of Measurement per average
   5. Range (Limit 20-200mm)
   6. Custom name for Sensor
   
   Function prototype:
   void _run(DropSensor _Sensor, int _GPIO, uint8_t new_addr,  int Nr_Of_Measurement, int Range_Limit, String _Name = "Sensor_Name")
   {
   #body
   }
      
   Note: Access to Print method, Input Method, Taking out Signal for robot, etc. could be possible via "Main_Function.h" file.
   
   by: Rahman, Mohammad Mahmudur.
*/



#include "Main_Function.h"
#include "DropSensor.h"

//1. Create Sensor Objects
   DropSensor sensor1;
   DropSensor sensor2;
   DropSensor sensor3;
   DropSensor sensor4;

//2. GPIO Setup
   int ioPin1 = 8;
   int ioPin2 = 7;
   int ioPin3 = 6;
   int ioPin4 = 5;


void setup() {
   // put your setup code here, to run once:
  
   Serial.begin(9600);
   Wire.begin();

   pinMode(ioPin1, OUTPUT);
   pinMode(ioPin2, OUTPUT);
   pinMode(ioPin3, OUTPUT);
   pinMode(ioPin4, OUTPUT);
}


void loop() {
   // put your main code here, to run repeatedly:
  
   /*
    3. HINT: _run(DropSensor Object?, GPIO?, Desired Sensor Address?, Number of Measurement for average?, Range Limit?, Give a Name for Sensor);
   */
  
   _run(sensor1, ioPin1,  0x39,  50, 150, "Sensor1");
   _run(sensor2, ioPin2,  0x49,  50, 150, "Sensor2");
   _run(sensor3, ioPin3,  0x59,  50, 150, "Sensor3");
   _run(sensor4, ioPin4,  0x69,  50, 150, "Sensor4");
   Serial.println("-------------------------------");
  
   //delay(1000);//Use if needed.
}
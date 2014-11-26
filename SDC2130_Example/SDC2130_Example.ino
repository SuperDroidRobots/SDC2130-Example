//=========================HEADER=============================================================
/*
   Roboteq SDC2130/SC2160 Example Code     
   AUTHOR: Jason Traud
   DATE: November 25, 2014
   
   This is a simple test program to demonstrate commands 
   and movements of our programmable MLT-JR platform using
   the Roboteq SDC2130 motor controller.               
      
   Hardware: Arduino Uno R3  (MCU-050-000)
             Roboteq SDC2130 (TE-144-030)
   
   SDC2130 DB-15      -------------   MLT-JR System
   -----------------                    -------
            6*     -------------------   Arduino Rx (D0)
            7*     -------------------   Arduino Tx (D1)
                                                     
            4      -------------------   Right Motor Encoder A Channel
            8      -------------------   Right Motor Encoder B Channel
            14     -------------------   Right Motor Encoder 5V
            13     -------------------   Right Motor Encoder Ground

            10     -------------------   Left Motor Encoder A Channel
            15     -------------------   Left Motor Encoder B Channel
            14     -------------------   Left Motor Encoder 5V
            13     -------------------   Right Motor Encoder Ground
            
   * NOTE: Pins 6 and 7 are for TTL level serial. Pins 2 and 3 are also
           labeled as Tx and Rx in the motor controllers datasheet but 
           these are RS-232 level.  
  
   References:
     Datasheet (Includes detailed pinout of the DB15 connector on page 6)
       http://roboteq.com/index.php/docman/motor-controllers-documents-and-files/documentation/datasheets/sdc21xx-datasheet/63-sdc21xx-datasheet/file
     User Manual (Describes commands and communication protocol)
       http://roboteq.com/index.php/docman/motor-controllers-documents-and-files/documentation/user-manual/7-nextgen-controllers-user-manual/file
     
			
   License: CCAv3.0 Attribution-ShareAlike (http://creativecommons.org/licenses/by-sa/3.0/)
   You're free to use this code for any venture. Attribution is greatly appreciated. 

//============================================================================================
*/

void setup() {
 Serial.begin(115200);      // Roboteq SDC2130 COM (Must be 115200)
 
 // Give the Roboteq some time to boot-up. 
 delay(1000);
 delay(1000);
 delay(1000);
 delay(1000);
}

void loop() {
 
  int x = 0;  // Counter used for ramping loops
  
  // Command Structure
  //  !G [nn] mm
  //  | - "!G" is the "Go" commnand
  //      | - nn = Motor Channel
  //          | - mm = Motor Power (-1000 to 1000)
  //  NOTE: Each command is completed by a carriage
  //        return. CR = dec 12, hex 0x0D
 
  // Ramp Forward
  for (x = 200; x < 400; x=x+10) {
    
    Serial.print("!G");  // Motor GO command
    Serial.print(" ");   //   Space
    Serial.print("1");   // Channel Number
    Serial.print(" ");   //   Space
    Serial.println(-x);   // Motor Power Value

    Serial.print("!G");  // Motor GO command
    Serial.print(" ");   //   Space
    Serial.print("2");   // Channel Number
    Serial.print(" ");   //   Space
    Serial.println(x);   // Motor Power Value

    delay(100);    
  }
  
  // Ramp Backward
  for (x = -200; x >= -400; x=x-10) {
    
    Serial.print("!G");  // Motor GO command
    Serial.print(" ");   //   Space
    Serial.print("1");   // Channel Number
    Serial.print(" ");   //   Space
    Serial.println(-x);   // Motor Power Value

    Serial.print("!G");  // Motor GO command
    Serial.print(" ");   //   Space
    Serial.print("2");   // Channel Number
    Serial.print(" ");   //   Space
    Serial.println(x);   // Motor Power Value

    delay(100);    
  }
  
  // Pivot Ramp Left
  for (x = 200; x < 400; x=x+10) {
    
    Serial.print("!G");  // Motor GO command
    Serial.print(" ");   //   Space
    Serial.print("1");   // Channel Number
    Serial.print(" ");   //   Space
    Serial.println(x);   // Motor Power Value

    Serial.print("!G");  // Motor GO command
    Serial.print(" ");   //   Space
    Serial.print("2");   // Channel Number
    Serial.print(" ");   //   Space
    Serial.println(x);   // Motor Power Value

    delay(100);    
  }
  
  // Pivot Ramp Right
  for (x = -200; x >= -400; x=x-10) {
    
    Serial.print("!G");  // Motor GO command
    Serial.print(" ");   //   Space
    Serial.print("1");   // Channel Number
    Serial.print(" ");   //   Space
    Serial.println(x);   // Motor Power Value

    Serial.print("!G");  // Motor GO command
    Serial.print(" ");   //   Space
    Serial.print("2");   // Channel Number
    Serial.print(" ");   //   Space
    Serial.println(x);   // Motor Power Value

    delay(100);    
  }
}


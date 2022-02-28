/* 
This sketch controls a hobbyist servomotor. 
It rotates the shaft 180 degrees forward and 180 degrees back.
 */

#include <Servo.h> 
 
Servo sv;       // Servo object 
int angle;      // servo's angular position 
 
void setup() { 
  
  // Attach the Servo object to Pin 6  
  sv.attach(6, 800, 2200);  
} 
 
void loop() { 
  
  // Rotate from 0 to 180 degrees
  for(angle = 0; angle < 180; angle += 1) {                                          
    sv.write(angle);              
    delay(10);                      
  } 
  
  // Rotate from 180 to 0 degrees  
  for(angle = 180; angle >= 1; angle -=1) {                                
    sv.write(angle); 
    delay(10);
  } 
}

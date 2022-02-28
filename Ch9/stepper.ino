/* 
This sketch controls a bipolar stepper motor, 
stepping ten times in the forward direction and
ten times in the reverse direction.
The steps/revolution is set to 200 (1.8 deg/step) 
and the speed is set to 10 RPM.
 */

#include <Stepper.h>

// Set the pin numbers
int pwm_a = 3;   
int pwm_b = 11;
int dir_a = 12;
int dir_b = 13;

// Create a stepper object
Stepper s = Stepper(200, dir_a, dir_b);

void setup() {

  // Set speed to 10 revs/min
  s.setSpeed(10);

  // Make sure the two H Bridges are always on
  pinMode(pwm_a, OUTPUT);
  pinMode(pwm_b, OUTPUT);
  digitalWrite(pwm_a, HIGH);  
  digitalWrite(pwm_b, HIGH);  
}

void loop() {

  // Ten steps in the forward direction
  s.step(10);
  delay(1000);

  // Ten steps in the reverse direction
  s.step(-10);
  delay(1000); 
}

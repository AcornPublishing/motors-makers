/* This sketch produces a pulse-width modulation (PWM) signal
whose duty-cycle switches between 0%, 25%, 50%, and 75%. */

// Assign a name to Pin 13
int pwm_pin = 13;

// Configure Pin 13 as an output pin
void setup() {
  pinMode(pwm_pin, OUTPUT);
}

// Switch the duty-cycle between 25% and 75%
void loop() {
  analogWrite(pwm_pin, 0);      // set duty cycle to 0%
  delay(1000);                  // delay one second  
  analogWrite(pwm_pin, 64);     // set duty cycle to 25%
  delay(1000);                  // delay one second
  analogWrite(pwm_pin, 128);    // set duty cycle to 50%
  delay(1000);                  // delay one second  
  analogWrite(pwm_pin, 192);    // set duty cycle to 75%
  delay(1000);                  // delay one second
}

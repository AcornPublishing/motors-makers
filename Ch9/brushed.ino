/* This sketch controls a brushed motor. It drives it in the 
forward direction at 75% duty cycle and halts. Then it
drives it in reverse at 75% duty cycle and halts. */

// Assign names to motor control pins
int dir_a = 12;
int pwm_a = 3;
int brake_a = 9;

// Configure the motor control pins in output mode
void setup() {
  pinMode(dir_a, OUTPUT);  
  pinMode(pwm_a, OUTPUT);
  pinMode(brake_a, OUTPUT);  
}

// Deliver power to the motor
void loop() {
  
  // Drive the motor forward at 75% duty cycle
  digitalWrite(brake_a, LOW);
  digitalWrite(dir_a, HIGH);
  analogWrite(pwm_a, 192);
  delay(2000);

  // Halt the motor for a second
  digitalWrite(brake_a, HIGH);    
  delay(1000);
  
  // Drive the motor in reverse at 75% duty cycle  
  digitalWrite(brake_a, LOW);
  digitalWrite(dir_a, LOW);
  analogWrite(pwm_a, 192);
  delay(2000); 

  // Halt the motor for a second
  digitalWrite(brake_a, HIGH);  
  delay(1000);  
}

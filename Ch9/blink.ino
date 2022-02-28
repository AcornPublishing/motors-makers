/* This sketch sets the voltage of Pin 13 high and low.
This causes the LED connected to the pin to blink. */
 
// Assign a name to Pin 13
int led_pin = 13;

// At startup, configure Pin 13 to serve as output
void setup() {                
  pinMode(led_pin, OUTPUT);     
}

// Repeatedly change the voltage of Pin 13
void loop() {
  digitalWrite(led_pin, HIGH);  // set the pin voltage high
  delay(1000);                  // delay one second
  digitalWrite(led_pin, LOW);   // set the pin voltage low
  delay(1000);                  // delay one second
}

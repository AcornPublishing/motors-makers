"""
This script repeatedly checks a pin's logic level.
If the logic level is low, a second pin is set high.
If the logic level is high, the loop terminates.
"""

import Adafruit_BBIO.GPIO as GPIO

# Assign names
input_pin = "P8_16";
output_pin = "P8_18";

# Set pin directions
GPIO.setup(input_pin, GPIO.IN)
GPIO.setup(output_pin, GPIO.OUT)

# Wait for input_pin to reach low voltage
while(GPIO.input(input_pin) == GPIO.LOW):
  GPIO.output(output_pin, GPIO.HIGH)

# Return pins to default state
GPIO.cleanup()

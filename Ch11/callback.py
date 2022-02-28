"""
This code configures a callback that responds
to changes to the logic level for Pin P8_18.
"""

import Adafruit_BBIO.GPIO as GPIO
import time

def event_callback(pin):
  print("The event was received by Pin %s." % pin)

# Define pin to be tested
test_pin = "P8_18";

# Set pin direction
GPIO.setup(test_pin, GPIO.IN)

# Configure a callback to be executed
GPIO.add_event_detect(test_pin, GPIO.BOTH, event_callback)

# Delay for ten seconds
time.sleep(10)

# Return pin to default state
GPIO.cleanup()

"""
This code repeatedly checks the logic level of in_pin.
If the level is low, out_pin is set high and the reading continues.
If the level is high, the script completes.
"""

import RPIO

# Set input pins
in_pin = 17;
out_pin = 24;

# Specify use of BCM pin numbering
RPIO.setmode(RPIO.BCM)

# Configure pin directions
RPIO.setup(in_pin, RPIO.IN)
RPIO.setup(out_pin, RPIO.OUT)

# Wait for in_pin to reach low voltage
while(RPIO.input(in_pin) == RPIO.LOW):
  RPIO.output(out_pin, RPIO.HIGH)

# Return pins to default state
RPIO.cleanup()

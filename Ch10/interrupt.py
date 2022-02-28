"""
This code sets up interrupt handling for Pin 17.
A change in the logic level executes a callback
that prints a message.
"""

import RPIO

def edge_detector(pin_num, rising_edge):
  if rising_edge:
    print("Rising edge detected on Pin %s" % pin_num)
  else:
    print("Falling edge detected on Pin %s" % pin_num)

# Define input pin
in_pin = 17

# Specify use of BCM pin numbering
RPIO.setmode(RPIO.BCM)

# Configure pin direction
RPIO.setup(in_pin, RPIO.IN)

# Configure interrupt handling for rising and falling edges
RPIO.add_interrupt_callback(in_pin, edge_detector, edge='both')
RPIO.wait_for_interrupts()

# Return pin to default state
RPIO.del_interrupt_callback(in_pin)
RPIO.cleanup()

"""
This program controls a stepper motor by 
energizing its phases in a given sequence.
"""

import rrb2
import time

# Create RRB2 object
robot = rrb2.RRB2()

# Set number of repetitions and step delay
num_reps = 10
step_delay = 0.4

# Repeat the energizing sequence num_reps times
for x in range(0, num_reps):

  robot.set_motors(1.0, 1, 0.0, 0)
  time.sleep(step_delay)

  robot.set_motors(0.0, 0, 1.0, 1)
  time.sleep(step_delay)

  robot.set_motors(1.0, 0, 0.0, 0)
  time.sleep(step_delay)

  robot.set_motors(0.0, 1, 1.0, 0)
  time.sleep(step_delay)

# Stop motor
robot.stop()

"""
This drives a motor forward at full speed for 5 seconds, stops,
drives the motor backward at half-speed, and stops.
"""

import DMCC as DMCC
import time

# Drive motor forward
setMotor(0, 1, 10000)
time.sleep(5)

# Stop
setMotor(0, 1, 0)
time.sleep(3)

# Drive motor backward
setMotor(0, 1, -5000)
time.sleep(10)

# Stop
setMotor(0, 1, 0)
time.sleep(3)

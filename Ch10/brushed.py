"""
This program controls two brushless DC motors:
Forward for five seconds, backwards for four seconds, 
right for three seconds, and left for two seconds.
"""

import rrb2

# Create RRB2 object
robot = rrb2.RRB2()

# Rotate forward for five seconds
robot.forward(seconds=5, speed=1.0)

# Rotate backward for four seconds
robot.reverse(seconds=4, speed=0.8)

# Turn left for three seconds
robot.left(seconds=3, speed=0.6)

# Turn right for two seconds
robot.right(seconds=2, speed=0.4)

# Stop motor
robot.stop()

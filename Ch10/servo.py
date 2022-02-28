"""
This code controls a servomotor, rotating from
the minimum to maximum angle and back.
"""

import RPIO.PWM as PWM
import time

# Define control pin and pulse widths
servo_pin = 18
min_width = 700
max_width = 2300

# Create servo object
servo = PWM.Servo()

# Set the angle to the minimum angle and wait
servo.set_servo(servo_pin, min_width)
time.sleep(1)

# Rotate shaft to maximum angle
for angle in xrange(min_width, max_width, 100):
  servo.set_servo(servo_pin, angle)
  time.sleep(0.25)

# Rotate shaft to minimum angle
for angle in xrange(max_width, min_width, -100):
  servo.set_servo(servo_pin, angle)
  time.sleep(0.5)

# Stop delivering PWM to servo
servo.stop_servo(servo_pin)

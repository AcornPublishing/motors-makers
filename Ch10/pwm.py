"""
This code generates a pulse-width modulation (PWM)
for Pin 18 whose pulses have a width of 1ms.
"""

import RPIO.PWM as PWM
import time

# Define PWM pin
pwm_pin = 18

# Initialize DMA and set pulse width resolution
PWM.setup(1)

# Initialize DMA channel 0
PWM.init_channel(0)

# Set pulse width to 1000us = 1ms
PWM.add_channel_pulse(0, pwm_pin, 0, 1000)

time.sleep(10)

# Clear DMA channel and return pins to default settings
PWM.clear_channel(0)
PWM.cleanup()

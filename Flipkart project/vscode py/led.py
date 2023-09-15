from pyfirmata import Arduino, util

# Define the port where your Arduino is connected
port = 'COM6'  

board = Arduino(port)

led_pin = board.get_pin('d:13:o')

led_pin.write(1)  # Turn the LED on
led_pin.write(0)  # Turn the LED off

# Read analog input (e.g., analog pin A0)
analog_pin = board.get_pin('a:0:i')
value = analog_pin.read()
print("Analog Value:", value)

# Close the serial connection when done
board.exit()

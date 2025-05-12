import time
import board
import busio
import digitalio
from adafruit_mcp3xxx.mcp3008 import MCP3008
from adafruit_mcp3xxx.analog_in import AnalogIn
from adafruit_mcp3xxx.mcp3008 import P0, P2, P4, P6

# Set up SPI bus and chip select (CS)
spi = busio.SPI(clock=board.SCK, MISO=board.MISO, MOSI=board.MOSI)
cs = digitalio.DigitalInOut(board.D8)  # CE0

# Create MCP object
mcp = MCP3008(spi, cs)

# Create analog input channels
sensor_1 = AnalogIn(mcp, P0)
sensor_2 = AnalogIn(mcp, P2)
sensor_3 = AnalogIn(mcp, P4)
sensor_4 = AnalogIn(mcp, P6)

# Read sensors in loop
try:
    while True:
        print(f"Sensor A0: {sensor_1.value} ({sensor_1.voltage:.2f} V)")
        print(f"Sensor A2: {sensor_2.value} ({sensor_2.voltage:.2f} V)")
        print(f"Sensor A4: {sensor_3.value} ({sensor_3.voltage:.2f} V)")
        print(f"Sensor A6: {sensor_4.value} ({sensor_4.voltage:.2f} V)")
        print("-" * 40)
        time.sleep(0.5)
except KeyboardInterrupt:
    print("Stopped by user")

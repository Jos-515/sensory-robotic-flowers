import serial

pot1 = pot2 = pot3 = pot4 = 0

def parse_pot_values(line):
    global pot1, pot2, pot3, pot4
    try:
        pot_values = [int(v) for v in line.split(',')]
        if len(pot_values) == 4:
            pot1, pot2, pot3, pot4 = pot_values
    except ValueError:
        print(f"Malformed data: {line}")


if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer

    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            parse_pot_values(line)
            print(f"Pot1: {pot1}, Pot2: {pot2}, Pot3: {pot3}, Pot4: {pot4}")
 
#pot1 = A0 = Lotus
#pot2 = A1 = Chrysanthenum
#pot3 = A2 = Jasmine
#pot4 = A3 = Peony

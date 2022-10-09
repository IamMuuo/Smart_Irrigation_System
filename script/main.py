import serial
import io
import requests
import time

ser = serial.Serial()

ser.baudrate = 19200
ser.port = "/dev/ttyUSB0"

ser.open()  # open the serial monitor

while ser.is_open:
    try:
        line = ser.readline()
        #print(line.decode('utf').rstrip('\n'))

        x = float(line)
        print("Attempting to send: ",  x)

        response = requests.post("https://ewo-iot-server.herokuapp.com/current/", {"mositure":x})
        print(response.status_code)
        if(response.status_code == 200):
            print("Sent:", x)

        print(x)
        
    except Exception as e:
        pass
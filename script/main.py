import serial
import io
import requests
import time

ser = serial.Serial()

ser.baudrate = 9600
ser.port = "/dev/ttyUSB0"

ser.open()  # open the serial monitor

while ser.is_open:
    try:
        line = ser.readline()
        #print(line.decode('utf').rstrip('\n'))

        x = float(line)
        print("Attempting to send: ",  x)

        response = requests.post(
            "https://ewo-iot-server.herokuapp.com/current/", {"moisture": x})
        print(response.status_code)
        print(response.json())

        if (response.json()["water_now"]):
            ser.write(1)
            print("Turning on pump!")


        if (response.status_code == 200):
            print("Sent:", x)

        print(x)

    except Exception as e:
        pass

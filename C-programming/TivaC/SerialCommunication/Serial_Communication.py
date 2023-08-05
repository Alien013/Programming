import serial
import requests

# Set up serial connection
ser = serial.Serial('COM3', 115200)

# Main loop
while True:
    # Read data from serial port
    data = ser.readline().strip()

    # Print the received data
    print(data)

    # Send data to ThingSpeak cloud server
    url = "https://api.thingspeak.com/update?api_key=JP3YGKTY7WJ60BN1&field1={}".format(data.decode('utf-8'))
    response = requests.get(url)

    # Print the server response
    print(response.text)


# import serial
# import requests
# url = "https://api.thingspeak.com/update.json"

# ser = serial.Serial('COM3', 9600)
# while True:
#     data = ser.readline().decode().strip()
#     print(data)
#     params = {"api_key": "JP3YGKTY7WJ60BN1", "field1": data}
#     response = requests.post(url, params=params)
#     if response.status_code != 200:
#         print("Error sending data to ThingSpeak:", response.text)

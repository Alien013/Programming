from flask import Flask, jsonify, request
import paho.mqtt.client as mqtt

app = Flask(_name_)

appliances = ['AC', 'TV', 'Door-Lock', 'Toaster']

client = mqtt.Client("my_client")


def on_message(client, userdata, message):
    global appliances
    new_appliance = message.payload.decode('utf-8')
    if new_appliance not in appliances:
        appliances.append(new_appliance)


client.on_message = on_message

broker_url = "localhost"
broker_port = 1883
client.connect(broker_url, broker_port)

client.loop_start()


@app.route('/')
def index():
    return 'Welcome to the smart home appliances app!'


@app.route('/appliances', methods=['GET'])
def get_appliances():
    return ', '.join(appliances)


@app.route('/appliances', methods=['POST'])
def add_appliance():
    new_appliance = request.json['appliance']
    if new_appliance not in appliances:
        appliances.append(new_appliance)

        client.publish("home/appliances", new_appliance)
        return f'{new_appliance} added to the inventory!'
    else:
        return f'{new_appliance} already in inventory!'


# @app.route('/appliances/<string:appliance>', methods=['PUT'])
# def update_appliance(appliance):
#     new_appliance = request.json['appliance']
#     if appliance in appliances:
#         appliances[appliances.index(appliance)] = new_appliance

#         client.publish("home/appliances", new_appliance)
#         return 'appliance updated successfully'
#     else:
#         return 'appliance not found'


@app.route('/appliances/<string:appliance>/on', methods=['PUT'])
def on_appliance(appliance):
    if appliance in appliances:
        return f'{appliance} turned on!'
    else:
        return f'{appliance} not found!'


@app.route('/appliances/<string:appliance>/off', methods=['PUT'])
def off_appliance(appliance):
    if appliance in appliances:
        return f'{appliance} turned off!'
    else:
        return f'{appliance} not found!'


@app.route('/appliances/<string:appliance>', methods=['DELETE'])
def delete_appliance(appliance):
    if appliance in appliances:
        appliances.remove(appliance)

        client.publish("home/appliances", appliance)
        return f'Removed {appliance} from inventory!'
    else:
        return f'{appliance} not found!'


if _name_ == '_main_':
    app.run(debug=True)
# import socket
# import threading


# def send_message():
#     while True:
#         message = input("")
#         message = f"{client_name}: {message}"
#         server_socket.sendto(message.encode(), (IP_ADDRESS, PORT))


# for i in range(3):
#     client_name = input("Enter your name: ")
#     client_addresses.append((IP_ADDRESS, PORT+i+1))
#     threading.Thread(target=receive_messages).start()
#     threading.Thread(target=send_message).start()

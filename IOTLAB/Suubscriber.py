import paho.mqtt.client as mqtt

broker_address = "localhost"
broker_port = 1883

topic = "house/appliances/bedroom/light"

def on_message(client, userdata, message):
    print("Received message: " + str(message.payload.decode("utf-8")))


client = mqtt.Client()
client.connect(broker_address, broker_port)

client.subscribe(topic)
client.on_message = on_message

client.loop_forever()

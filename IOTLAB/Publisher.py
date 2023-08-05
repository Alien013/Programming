import paho.mqtt.publish as publish
broker_address = "localhost"
broker_port = 1883
topic = "house/appliances/bedroom/light"
message = "on"
publish.single(topic, message, hostname=broker_address, port=broker_port)

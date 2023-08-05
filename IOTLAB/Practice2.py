from flask import Flask, jsonify, request
import paho.mqtt.client as mqtt

app = Flask(__name__)

# Create a list of programming languages
pizza = ['Margiretta Pizza', 'Corn Pizza', 'Paneer Tikka Pizza', 'Tomato Pizza', 'Morzella Cheese Pizza', 'Veggie Delight Pizza']

# Define the MQTT client
client = mqtt.Client("my_client")

# Define the callback function to receive MQTT messages


def on_message(client, userdata, message):
    global languages
    new_language = message.payload.decode('utf-8')
    if new_language not in languages:
        languages.append(new_language)


# Set the on_message callback function
client.on_message = on_message

# Connect to the MQTT broker
broker_url = "localhost"
broker_port = 1883
client.connect(broker_url, broker_port)

# Start the MQTT loop to receive messages
client.loop_start()

# Define the Flask routes


@app.route('/')
def index():
    return 'Welcome to the programming languages app!'


@app.route('/languages', methods=['GET'])
def get_languages():
    return ', '.join(languages)


@app.route('/languages', methods=['POST'])
def add_language():
    new_language = request.json['language']
    if new_language not in languages:
        languages.append(new_language)
        # Publish the new language to the MQTT broker
        client.publish("programming/languages", new_language)
        return 'Language added successfully'
    else:
        return 'Language already exists'


@app.route('/languages/<string:language>', methods=['PUT'])
def update_language(language):
    new_language = request.json['language']
    if language in languages:
        languages[languages.index(language)] = new_language
        # Publish the updated language to the MQTT broker
        client.publish("programming/languages", new_language)
        return 'Language updated successfully'
    else:
        return 'Language not found'


@app.route('/languages/<string:language>', methods=['DELETE'])
def delete_language(language):
    if language in languages:
        languages.remove(language)
        # Publish the deleted language to the MQTT broker
        client.publish("programming/languages", language)
        return 'Language deleted successfully'
    else:
        return 'Language not found'


# Run the Flask app
if __name__ == '__main__':
    app.run(debug=True)

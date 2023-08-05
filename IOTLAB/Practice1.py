from flask import Flask, jsonify, request

app = Flask(__name__)

# Define a list of programming languages
languages = ['Python', 'Java', 'JavaScript', 'Ruby', 'C#', 'PHP']

# Endpoint for GET request to retrieve the list of programming languages


@app.route('/', methods=['GET'])
def get_languages():
    return jsonify(languages)

# Endpoint for PUT request to replace a programming language


@app.route('/', methods=['PUT'])
def replace_language():
    data = request.get_json()
    old_language = data.get('old_language')
    new_language = data.get('new_language')
    if old_language in languages:
        languages[languages.index(old_language)] = new_language
        return jsonify({'message': f'Replaced {old_language} with {new_language}'})
    else:
        return jsonify({'message': f'{old_language} not found'}), 404

# Endpoint for POST request to add a programming language


@app.route('/', methods=['POST'])
def add_language():
    data = request.get_json()
    language = data.get('language')
    if language not in languages:
        languages.append(language)
        return jsonify({'message': f'Added {language} to the list'})
    else:
        return jsonify({'message': f'{language} already exists'}), 400

# Endpoint for DELETE request to remove a programming language


@app.route('/', methods=['DELETE'])
def remove_language():
    data = request.get_json()
    language = data.get('language')
    if language in languages:
        languages.remove(language)
        return jsonify({'message': f'Removed {language} from the list'})
    else:
        return jsonify({'message': f'{language} not found'}), 404


if __name__ == '__main__':
    app.run(debug=True)

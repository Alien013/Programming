from flask import Flask, jsonify, request

app = Flask(__name__)

# List of programming languages
programming_languages = ['Python', 'Java',
                         'JavaScript', 'C#', 'C++', 'Ruby', 'Go', 'Swift']

# GET request to display list of programming languages


@app.route('/', methods=['GET'])
def get_languages():
    return jsonify(programming_languages)

# PUT request to replace a programming language


@app.route('/', methods=['PUT'])
def update_language():
    old_lang = request.args.get('old')
    new_lang = request.args.get('new')
    if old_lang in programming_languages:
        index = programming_languages.index(old_lang)
        programming_languages[index] = new_lang
        return jsonify({'message': 'Language updated successfully'})
    else:
        return jsonify({'error': 'Language not found'})

# POST request to add a programming language


@app.route('/', methods=['POST'])
def add_language():
    new_lang = request.args.get('new')
    if new_lang not in programming_languages:
        programming_languages.append(new_lang)
        return jsonify({'message': 'Language added successfully'})
    else:
        return jsonify({'error': 'Language already exists'})

# DELETE request to remove a programming language


@app.route('/', methods=['DELETE'])
def delete_language():
    lang_to_delete = request.args.get('lang')
    if lang_to_delete in programming_languages:
        programming_languages.remove(lang_to_delete)
        return jsonify({'message': 'Language deleted successfully'})
    else:
        return jsonify({'error': 'Language not found'})


if __name__ == '__main__':
    app.run(debug=True, port=8000)

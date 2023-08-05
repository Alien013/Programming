#include <bits/stdc++.h>
using namespace std;

const vector<string> keypad = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void gen_mess_help(const string &digits, string &message, vector<string> &messages, int index) {
    if (index == digits.size()) {
        messages.push_back(message);
        return;
    }

    for (char letter : keypad[digits[index] - '0']) {
        message[index] = letter;
        gen_mess_help(digits, message, messages, index + 1);
    }
}

vector<string> sms_generate(const string &digits) {
    vector<string> messages;
    if (digits.empty()) {
        return messages;
    }
    string message(digits.size(), ' ');
    gen_mess_help(digits, message, messages, 0);
    return messages;
}

int main() {
    string digits;
    cin >> digits;
    vector<string> messages = sms_generate(digits);
    for (string message : messages) {
        cout << message << " ";
    }
    cout << endl; 
    return 0;
}

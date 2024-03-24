#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

Node* buildMorseCodeTree(const unordered_map<char, string>& mapping) {
    Node* root = new Node('*');
    for (const auto& pair : mapping) {
        Node* node = root;
        for (char symbol : pair.second) {
            if (symbol == '.') {
                if (!node->left) node->left = new Node('\0');
                node = node->left;
            } else if (symbol == '-') {
                if (!node->right) node->right = new Node('\0');
                node = node->right;
            }
        }
        node->data = pair.first;
    }
    return root;
}

string encodeMessage(const string& message, const unordered_map<char, string>& mapping) {
    stringstream ss;
    for (char c : message) {
        if (mapping.count(tolower(c))) {
            ss << mapping.at(tolower(c)) << " ";
        } else if (c == ' ') {
            ss << "/ ";
        }
    }
    return ss.str();
}

string decodeMessage(const string& encodedMessage, Node* root) {
    stringstream ss(encodedMessage);
    string token, decodedMessage;
    Node* node = root;
    while (ss >> token) {
        if (token == "/") {
            decodedMessage += ' ';
        } else {
            for (char symbol : token) {
                if (symbol == '.') {
                    node = node->left;
                } else if (symbol == '-') {
                    node = node->right;
                }
            }
            decodedMessage += node->data;
            node = root;
        }
    }
    return decodedMessage;
}

int main() {
    unordered_map<char, string> morseCodeMapping = {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."},
        {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"},
        {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"},
        {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
        {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"},
        {'z', "--.."}, {' ', "/"}
    };

    Node* root = buildMorseCodeTree(morseCodeMapping);

    string message;
    cout << "Enter the message to be encoded: ";
    getline(cin, message);

    string encodedMessage = encodeMessage(message, morseCodeMapping);
    cout << "Encoded message: " << encodedMessage << endl;

    string decodedMessage = decodeMessage(encodedMessage, root);
    cout << "Decoded message: " << decodedMessage << endl;

    return 0;
}

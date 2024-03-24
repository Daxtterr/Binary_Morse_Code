/*
 * Created by Aimuel Emmanuel on 2024-03-22.
 * This module contains all the helper functions to be used in this program.
 *
 * This file contains 1 function used to implement the shaker sort algorithm.
 */

/* Include header file */
#include "header.h"


/* Function Definitions */

/*
 * buildMorseCodeTree
 *
 * Purpose: Build the morse code tree for the input
 * Parameter:
 *  <1> unordered_map: alphabet and morse code equivalent
 * 	<2> mapping :maps the morse code strings to the alphabet
 * Precondition: None
 * Returns: root of the morse code
 * Side effect: None
 */
struct Node {
    char data;
    Node* left;
    Node* right;

    // Constructor to initialize a node with given data
    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

Node* buildMorseCodeTree(const unordered_map<char, string>& mapping) {
    Node* root = new Node('*');

	// Iterate over each character and its corresponding Morse Code string in the mapping
    for (const auto& pair : mapping) {
        Node* node = root;

		// Traverse the Morse Code string for the current character
        for (char symbol : pair.second) {
			// If the symbol is a dot ('.'), move to the left child node
            if (symbol == '.') {
                if (!node->left) node->left = new Node('\0');
                node = node->left;
			// If the symbol is a dash ('-'), move to the right child node
            } else if (symbol == '-') {
                if (!node->right) node->right = new Node('\0');
                node = node->right;
            }
        }
		// Assign the character to the leaf node
        node->data = pair.first;
    }
	// Return the root of the Morse Code tree
    return root;
}


/*
 * encodeMessage
 *
 * Purpose: Encode string inputs
 * Parameter:
 *  <1> string: input to be encoded
 * 	<2> unordered_map ,mapping :the map contains key-value pairs, where the key is a character (char) and the value is a string
 * Precondition: None
 * Returns: Encoded message
 * Side effect: None
 */
string encodeMessage(const string& message, const unordered_map<char, string>& mapping) {
    stringstream ss;
    for (char c : message) {
        if (mapping.count(tolower(c))) {

			// Append the Morse code equivalent of the character to the stringstream
            ss << mapping.at(tolower(c)) << " ";
        } else if (c == ' ') {
			// If the character is a space, append a "/" to the stringstream
            ss << "/ ";
        }
    }

	// Return the encoded message as a string
    return ss.str();
}


/*
 * decodeMessage
 *
 * Purpose: Decode encoded inputs
 * Parameter:
 *  <1> string: encoded input to be decoded
 * 	<2> unordered_map ,mapping :the map contains key-value pairs, where the key is a character (char) and the value is a string
 * Precondition: string should be encoded
 * Returns: Decoded message
 * Side effect: None
 */
string decodeMessage(const string& encodedMessage, Node* root) {
    stringstream ss(encodedMessage);
    string token, decodedMessage;
    Node* node = root;
    while (ss >> token) {
		// If the token is a space ("/"), add a space to the decoded message
        if (token == "/") {
            decodedMessage += ' ';
        } else {
			// Iterate over each symbol in the token (dot or dash)
            for (char symbol : token) {
				// Move to the left child if the symbol is a dot, otherwise move to the right child
                if (symbol == '.') {
                    node = node->left;
                } else if (symbol == '-') {
                    node = node->right;
                }
            }
			// Add the character at the current node to the decoded message
            decodedMessage += node->data;
			// Reset the current node to the root for the next token
            node = root;
        }
    }
	// Return the decoded message
    return decodedMessage;
}
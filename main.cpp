/* 
 * This module contains the main function of this program.
 *
 * This file calls the header file as well as the file containing
 * the helper functions and demonstrates Object-Oriented Programming
 */

/* Include header files */
#include "header.h"
#include "helpers.cpp"

/*
 * Module: main
 * Author: Aimuel Emmanuel
 * Date: 2024-03-22
 *
 * Purpose: Point of execution in this program
 * Parameter: None
 * Precondition: None
 * \return 0 if no errors, otherwise 1
 * Side effect: None
 */ 
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

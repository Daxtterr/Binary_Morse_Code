/*
 * Created by Emmanuel Aimuel on 2024-03-22.
 * This module serves as the header file. 
 *
 * The header file contains all preprocessor directives with libraries and namespaces.
 */

// Preprocessor directive
#pragma once

// Libraries & Namespace
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;


/* Function Declarations */

/*
 * encodeMessage
 *
 * Module: helpers
 * Author: Emmanuel Aimuel
 * Date: 2024-03-12
 *
 * Purpose: Encode string input
 * Precondition: None
 *
 * \param const string containing string to be encoded
 *        Node* root the morsecode tree
 * \return None
 *
 * Side effect: None
 */
string encodeMessage() ;


/*
 * decodeMessage
 *
 * Module: helpers
 * Author: Emmanuel Aimuel
 * Date: 2024-03-12
 *
 * Purpose: Decode the endcoded input
 * Precondition: None
 *
 * \param const string containing encoded input to be decoded
 *        Node* root the morsecode tree
 * \return None
 *
 * Side effect: None
 */
string decodeMessage() ;


#include "header.h"

morse_code::morse_code()
{
	root = new letter;
	root->key = ' ';
	root->code.push_back(0);
	root->left = NULL;
	root->right = NULL;
}


void morse_code::insert(char key, vector<char> code)
{
	insert(key, code, root); //calls private insert function starting at root
}

letter* morse_code::search(vector<char> code)
{
	return search(code, root);  //calls and returns result of private search function starting at root
}


void morse_code::insert(char key, vector<char> code, struct letter *leaf)
{
	letter* t = new letter;  //build a new node with the data given
	t->key = key;
	t->code = code;
	t->left = t->right = NULL;

	if (leaf->left == NULL && leaf->right == NULL) //if this is the first node (do not enter at root)
	{
		leaf->left = t;
		return;
	}
	while (leaf) //while we haven't inserted yet
	{
		if (code < leaf->code) //go left
		{
			if (leaf->left == NULL) //if you can insert
			{
				leaf->left = t; //do insert!
				break;
			}
			else //if you cant insert, move down the tree
				leaf = leaf->left;
		}

		else //go right
		{
			if (leaf->right == NULL) //if you can insert
			{
			leaf->right = t; //do insert!
			break;
			}
			else
				leaf = leaf->right; //if you cant insert, move down the tree
		}
	}
}



letter* morse_code::search(vector<char> code, letter *leaf)
{
	if (leaf)  //if there is still tree to traverse
	{
		if (code == leaf->code)  //found correct node
			return leaf;
		else if (code < leaf->code)
			return search(code, leaf->left); //recursively traverse left tree until node is found
		else
			return search(code, leaf->right); //recursively traverse right tree until node is found
	}
	else
		return NULL;  //node was not found
}

bool operator >(const vector<char>& other, const vector<char>& rhs)
{
	int k; //we will only traverse the shorter code
	if (other.size() > rhs.size())
		k = rhs.size();
	else
		k = other.size();

	//(dot) is less than (dash)
	{
		for (int i = 0; i < k; i++)  //compare the following characters
		{
			if (other[i] == '.' && rhs[i] == '_')  //if (dot) > (dash)
				return false;  //we know it is not
			else if (other[i] == '_' && rhs[i] == '.')  //if (dash) > (dot)
				return true;  //we know it is
		}
	}
	return false;  //the two codes are equal or rhs is a shorter code
}

bool operator < (const vector<char>& other, const vector<char>& rhs)
{
	//(dot) is less than (dash)
	int k;  //we will only traverse the shorter code
	if (other.size() > rhs.size())
		k = rhs.size();
	else
		k = other.size();

		for (int i = 0; i < k; i++) //compare the next characters of both codes
		{
			if (other[i] == '_' && rhs[i] == '.')  //(dash) < (dot)
				return false;
			else if (other[i] == '.' && rhs[i] == '_')  //(dot) < (dash)
				return true;
		}
	return false; //the two codes are equal or rhs is a shorter code
}


bool operator == (const vector<char>& other, const vector<char>& rhs)
{
	if (other.size() != rhs.size()) //they arent the same size they cant be equal
		return false;

	for (int i = 0; i < other.size(); i++)  //compare each character in the code
	{
		if (other[i] > rhs[i] || other[i] < rhs[i])  //if they are not equal return false
			return false;
	}
	return true;  //compared entire code, they are equal
}



void build_tree(string file, morse_code& tree)  //builds tree given input file and tree root
{
	cout << "...building tree..." << endl;  //output to let the user know their input worked
	ifstream fin(file); //file where the tree is kept
	string whole_line;  //variable for each line of the file
	char key_hold;  //the character that corresponds with each code
	vector<char> code_hold;  //the code that corresponds which each character
	while (!fin.eof())  //read whole file
	{
		getline(fin, whole_line);  //read in whole line of file
		key_hold = whole_line[0];  //parse line into character and code
		for (int i = 1; i < whole_line.size(); i++)
			code_hold.push_back(whole_line[i]);
		tree.insert(key_hold, code_hold);  //put code/character combo into tree in order
		code_hold.clear();
	}
}

//Generates/populates map using english character as a key and the equivilent morse code as value
map <char, string> populateMap() {
	//Returned map with lower and uppercase chars and equivilent morse code values
	map <char, string> morseMap;

	//Lowercase
	morseMap.insert(make_pair('a', ".-"));
	morseMap.insert(make_pair('b', "-..."));
	morseMap.insert(make_pair('c', "-.-."));
	morseMap.insert(make_pair('d', "-.."));
	morseMap.insert(make_pair('e', "."));
	morseMap.insert(make_pair('f', "..-."));
	morseMap.insert(make_pair('g', "--."));
	morseMap.insert(make_pair('h', "...."));
	morseMap.insert(make_pair('i', ".."));
	morseMap.insert(make_pair('j', ".---"));
	morseMap.insert(make_pair('k', "-.-"));
	morseMap.insert(make_pair('l', ".-.."));
	morseMap.insert(make_pair('m', "--"));
	morseMap.insert(make_pair('n', "-."));
	morseMap.insert(make_pair('o', "---"));
	morseMap.insert(make_pair('p', ".--."));
	morseMap.insert(make_pair('q', "--.-"));
	morseMap.insert(make_pair('r', ".-."));
	morseMap.insert(make_pair('s', "..."));
	morseMap.insert(make_pair('t', "-"));
	morseMap.insert(make_pair('u', "..-"));
	morseMap.insert(make_pair('v', "...-"));
	morseMap.insert(make_pair('w', ".--"));
	morseMap.insert(make_pair('x', "-..-"));
	morseMap.insert(make_pair('y', "-.--"));
	morseMap.insert(make_pair('z', "--.."));

	//Uppercase
	morseMap.insert(make_pair('A', ".-"));
	morseMap.insert(make_pair('B', "-..."));
	morseMap.insert(make_pair('C', "-.-."));
	morseMap.insert(make_pair('D', "-.."));
	morseMap.insert(make_pair('E', "."));
	morseMap.insert(make_pair('F', "..-."));
	morseMap.insert(make_pair('G', "--."));
	morseMap.insert(make_pair('H', "...."));
	morseMap.insert(make_pair('I', ".."));
	morseMap.insert(make_pair('J', ".---"));
	morseMap.insert(make_pair('K', "-.-"));
	morseMap.insert(make_pair('L', ".-.."));
	morseMap.insert(make_pair('M', "--"));
	morseMap.insert(make_pair('N', "-."));
	morseMap.insert(make_pair('O', "---"));
	morseMap.insert(make_pair('P', ".--."));
	morseMap.insert(make_pair('Q', "--.-"));
	morseMap.insert(make_pair('R', ".-."));
	morseMap.insert(make_pair('S', "..."));
	morseMap.insert(make_pair('T', "-"));
	morseMap.insert(make_pair('U', "..-"));
	morseMap.insert(make_pair('V', "...-"));
	morseMap.insert(make_pair('W', ".--"));
	morseMap.insert(make_pair('X', "-..-"));
	morseMap.insert(make_pair('Y', "-.--"));
	morseMap.insert(make_pair('Z', "--.."));

	return morseMap;
}

//Encode message in morse code
string encodeMessage(map <char, string> map, string message){

	string tempString; //Holds return string with morse code
	char tempChar; //Holds char to be encoded

	//For loop to transverse original message and encode chars
	for (unsigned i = 0; i<message.length(); ++i)
	{
		tempChar = message.at(i); //Get char

		//Look up morse code value using char and add that value and a space to returned string
		tempString += map.find(tempChar)->second + " ";
	}

	return tempString;
}


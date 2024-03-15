////
//	Author: suspiciouslyBee
// 
// 
// 
////

#include <istream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "tree.h"
using namespace std;

int main(void) {
	string input = "6 9 3 5 5 7 2 10 4 1 8";
	Tree tree;
	string output;

	cout << " Reading into tree\n";
	cout << "Input list: " << input << endl;
	tree.deserialize(input);
	cout << "Serializeing...\n";
	output = tree.serialize();
	cout << (output == input) << endl;


	return 0;
}
////
// FIle: Tree class implemenation
// Tree class definition from Tree.h
//
// Barebones BST that doesnt even have a destructor, but has a fully functional
// insert function that only adds in unique numbers, yet records each repeated
// datapoint for a later to be implemented use. Can use ostream to print
////




#include "Tree.h"

bool Tree::insert(int newVal)
{
	//if greater, insert to node on right
	//if lesser, insert to node on left
	//if neither, check if there is a head
		//if there is a head, or match, increment occurance.
	//will require recursion, more straight forward
	//must run the node's check

	//if node::insertwhere() == nullptr we have a failure to insert

	cout << "Inserting: " << newVal << endl;
	if (root == nullptr) { //stupid check
		root = new Node(newVal);
		count++;
		cout << "New root node created\n\n";
		return true;
	}

	if (root->insertWhere(newVal) != nullptr) {
		count++;
		cout << "\nSucessful Insert!\n\n";
		return true; //we had a sucessful insert
	}


	cout << "Failure to insert new object (duplicate?)\n\n";
	return false;
}

const int Tree::getCount()
{
	return this->count;
}

string Tree::serialize()
{
	stringstream sstr;
	sstr << *(this->root); //grab root directly skip debug fluff
	

	return sstr.str();
}

void Tree::deserialize(string string)
{
	stringstream inputStr;
	int data = 0;
	inputStr << string; //feed in the argstr
	while (inputStr.eof() == false) {
		inputStr >> data;
		this->insert(data);
	}
}





void Tree::print(ostream& ostr) const
{
	// strategy: recursively reach down to the greatest node, get that node to 
	// print something 
	ostr << "Printing Tree:\n";
	if (this->root == nullptr) {
		ostr << "EMPTY LIST\n";
		return;
	}
	ostr << *(this->root);
}

ostream& operator<<(ostream& ostr, const Tree& tree)
{
	tree.print(ostr);
	return ostr;
}
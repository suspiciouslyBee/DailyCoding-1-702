////
// File: Node class definition
//
// Container for data for the BST. I split this off so I could better implement
// some internal functions such as getter and setters, but also a recursive
// insertion function
//
// Getter and setters may be redudndant due to every variable being public...
////

#include "Node.h"

int Node::getData() const
{
	return this->data;
}

int Node::getOccurance() const
{
	return this->occurance;
}

void Node::print(ostream& ostr) const
{
	//running in an assumption that it will be sorted correctly
	//print smallest to largest recursively
	if (hasLeft) { //check here first
		left->print(ostr);
	}
	//we are now at the 'middle of the chain, the node cant continue to wait
	ostr << data << " ";
	if (hasRight) {
		right->print(ostr);
	}
}

Node* Node::insertWhere(int num)
{
	//given integer, returns the node address for "correct placement"
	//it returns the pointer for which the node was placed into, but nullptr if
	// there is a failure or a duplicate
	// if duplicate, it increments the applicable node's occurrance counter
	//if hit end, then returns self's address
	//nullptr is returned if there is a match

	Node* inserter = nullptr;
	if (num == this->data) { //our number is equal than the parent's number

		//STOP!
		this->occurance++;
		cout << "Match found. Bailing! There are now "
			<< occurance << " occurances!\n";
		return nullptr;
	}
	renumerate();
	//compare and search further
	//enumerate if function HAS end.

	if (num > this->data) { //our number is greater than the parents number
		//if nullptr, create memory here
		if (hasRight) { //we need to go down level if right has something
			cout << "Checking Right Node...\n";
			//start again with the right node as our new 'root'
			return this->right->insertWhere(num);
		}
		//can assume that Right is non existant. allocate now
		cout << "Empty Right Node! Inserting now!\n";
		inserter = new Node(num); // allocate new node
		this->right = inserter;
		renumerate();
		return inserter;
	}
	if (num < this->data) {
		//if nullptr, create memory here
		if (hasLeft) { //we need to go down level if left has something
			cout << "Checking Left Node...\n";
			return this->left->insertWhere(num);
		}
		//can assume that left is non existant. allocate now
		cout << "Empty Left Node! Inserting now!\n";
		inserter = new Node(num); // allocate new node
		this->left = inserter;
		renumerate();
		return inserter;
	}


	cout << "Failure to insert!\n"; //we should NOT be here
	return nullptr; //failsafe
}

void Node::renumerate()
{
	hasRight = (this->right != nullptr);
	hasLeft = (this->left != nullptr);
}

ostream& operator<<(ostream& ostr, const Node& source)
{
	source.print(ostr);
	return ostr;
}
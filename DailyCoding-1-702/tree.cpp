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

	// if greater, insert to node on right
	// if lesser, insert to node on left
	// if neither, check if there is a head
	// if there is a head, or match, increment occurance.
	// will require recursion, more straight forward
	// must run the node's check


	// I can't use C++ recursion?
	// Fine. I'll do it myself.

	Node* iterator = nullptr;
	bool latch = true;

	cout << "Inserting: " << newVal << endl;
	if (root == nullptr) { //stupid check
		root = new Node(newVal);
		count++;
		cout << "New root node created\n\n";
		return true;
	}

	//begin 'recursion'
	iterator = this->root; //we have to start somewhere


	//TODO: how tf do i loop this
	while (latch) { //this feels jank
		if (newVal == iterator->data) {
			//our number is equal than the parent's number?

			//STOP!
			iterator->occurance++;//but leave a trace of the work...
			cout << "Match found. Bailing! There are now "
				<< iterator->occurance << " occurances of this number!\n";
			break; //we need to terminate the loop to keep latch active
			//cursed, but ill explain later
		}

		if (newVal > iterator->data) {
			//our number is greater than the parents number
			if (iterator->hasRight) {
				//we need to go down level if right has something
				cout << "Checking Right Node...\n";
				//start again with the right node as our new 'root'
				iterator = iterator->right;
			}
			else {
				//can assume that Right is non existant. allocate now
				cout << "Empty Right Node! Inserting now!\n";
				// allocate new node to right side
				iterator->right = new Node(newVal);
				iterator->renumerate();//refresh the node
				latch = false;
				//break?
			}
		}
		if (newVal < iterator->data) {
			//our number is less than the parents number
			if (iterator->hasLeft) {
				//we need to go down level if left has something
				cout << "Checking Left Node...\n";
				//start again with the left node as our new 'root'
				iterator = iterator->left;
			}
			else {
				//can assume that left is non existant. allocate now
				cout << "Empty Left Node! Inserting now!\n";
				// allocate new node to right side
				iterator->left = new Node(newVal);
				iterator->renumerate();//refresh the node
				latch = false;
			}
		}
	}

	////
	// by now we either escape the latch naturally by setting to false upon
	// successful insert, or we got out of it by a break. the break exits the
	// while loop without fliping the latch; we have a non unique/entry
	// and ergo, failure.
	////

	if (latch) {
		cout << "Failure to insert new object (duplicate?)\n\n";
		return false;
	}

	//if we made it this far, we have likely inserted properly: latch is false

	count++;
	cout << "Sucessful Insert!\n\n";
	return true; //we had a sucessful insert
}

bool Tree::insertRecursive(int newVal)
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
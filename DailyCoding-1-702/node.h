#pragma once
////
//	Author: suspiciouslyBee
// 
//	File: Node Header
//	
//	Implementing the pseudocode into C++:
/*
class Node :
def __init__(self, val, left = None, right = None) :
	self.val = val
	self.left = left
	self.right = right
*/
// 
////

class Node {
public:

	//Constructors
	Node() : left(nullptr), right(nullptr),
		data(0), occurance(1), hasRight(false), hasLeft(false) {}

	Node(int val) : left(nullptr), right(nullptr), data(val), occurance(1),
		hasRight(false), hasLeft(false) {}



	//Data manipulation
	Node* setLeft();
	Node* getLeft();
	Node* setRight();
	Node
	void setData(int in);
	int getData() const; //return the data


	int getOccurance() const; //how many instances of this element?
	void print(ostream& ostr) const; //prints to an oustream

	// recursively searches the proper place (smallest to greatest) to put new
	// int (left or right node? or children of node?), returns address of the
	// new node if sucessful, otherwise returns nullptr
	// duplicate entries are not entirely discarded, it increments 'occurance'
	// and still returns nullptr.
	Node* insertWhere(int num);
	void renumerate(); //renumerate if node has left or right children nodes

private:
	//Data
	Node* left, 
		* right;
	int data, 
		occurance; //number of the same data

	//'implicit data'
	bool hasRight,
		hasLeft;
};

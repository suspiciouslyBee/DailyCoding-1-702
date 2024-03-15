#pragma once
////
// 
// File: Tree class header
////


#pragma once
#ifndef TREE_H
#define TREE_H

#include <istream>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Node.h"
using namespace std;

class Tree {
public:
    //TODO: destructor
    Tree() : count(0), root(nullptr) {}
    
    // calls print and outputs count
    friend ostream& operator << (ostream& ostr, const Tree& tree);  
    bool insert(int newVal);//inserts a new value into the tree

    const int getCount();

private:
    void print(ostream& ostr) const;  // recursive function
    Node* root;
    int count;
};



#endif
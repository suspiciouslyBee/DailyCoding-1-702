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

    Tree() : count(0), root(nullptr) {}

    friend ostream& operator << (ostream& ostr, const Tree& tree);  // calls print and 
    // outputs count
    bool insert(int newVal);//inserts a new value into the tree


    //depricated
    bool insertRecursive(int newVal); //inserts a new value into the tree
    const int getCount();

private:
    void print(ostream& ostr) const;  // recursive function
    Node* root;
    int count;
};



#endif
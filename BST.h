#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>

using std::string;
using std::iostream;
using std::cout;

class BSTNode
{
    public:
    //constructor for the BSTNode. Takes options for data, left pointer, and right pointer
    BSTNode(const string & data="", BSTNode * left=nullptr, BSTNode * right=nullptr);
    //The getters for the BST Nodes will return references to pointers.
    //If we don't do this, many of the recursive functions in the BST will give an error
    //complaining about a "modifiable lvalue". This is because a reference can only be bound to
    //a variable that has already been given a name. So when you pass in BSTNode::getLeft() to
    //a function, it returns a pointer that hasn't been assigned to any real variable yet.
    //This type of data is called an "rvalue". references without names can be passed into a function,
    //but only if the variable is declared as const, meaning whatever is passed in can't be modified.
    //This is why for instance the data in the constructor is a const string reference.
    BSTNode *& getLeft();
    BSTNode *& getRight();
    //The const tag at the end of the function shows that the function will not modify any of the class' values
    string getData() const;
    //standard setters
    void setLeft(BSTNode * left);
    void setRight(BSTNode * right);
    void setData(const string & data);

    private:
    //A BSTNode is similar to a LinkedList node, except for the fact that it contains two
    //next pointers instead of one: right and left. On insertion a node will traverse left if
    //it's data evaluates as less than the current node's data. Right otherwise.
    BSTNode * leftPtr;
    BSTNode * rightPtr;
    string data;
};

class BST
{
    public:
    //default constructor
    BST();
    //copy constructor, calls copyHelper internally to create deep copy
    BST(const BST &other);
    //destructor, calls destroyHelper internally to destroy tree
    ~BST();
    //inserts a node, calls insertHelper internally to insert
    void insertNode(const string & data);
    //the three traversal functions. Also have recursive helper functions to print recursively.
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    //returns true if the tree is empty
    bool isEmpty();

private:
    BSTNode * copyHelper(BSTNode * oldRoot);
    void insertHelper(BSTNode *& cur, const string & data);
    void inOrderHelper(BSTNode * cur);
    void preOrderHelper(BSTNode * cur);
    void postOrderHelper(BSTNode * cur);
    void destroyTree(BSTNode *& cur);
    BSTNode *root;
}

#endif
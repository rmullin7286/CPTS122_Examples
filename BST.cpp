#include "BST.h"

BSTNode::BSTNode(const string & data, BSTNode * left, BSTNode * right)
{
    this->data = data;
    this->leftPtr = left;
    this->rightPtr = right;
}

string BSTNode::getData() const
{
    return data;
}

BSTNode *& BSTNode::getLeft()
{
    return leftPtr;
}

BSTNode *& BSTNode::getRight()
{
    return rightPtr;
}

void BSTNode::setData(const string & data)
{
    this->data = data;
}

void BSTNode::setLeft(BSTNode * left)
{
    this->leftPtr = left;
}

void BSTNode::setRight(BSTNode * right)
{
    this->rightPtr = right;
}

BST::BST()
{
    root = nullptr;
}

BST::BST(const BST & other)
{
    root = copyHelper(other.root);
}

void BST::insertNode(const string & data)
{
    insertHelper(root, data);
}

//copy helper recursively copies the nodes of a tree.
//It will return the value of the current node created and continue down the left and right paths
BSTNode * BST::copyHelper(BSTNode * oldRoot)
{
    //base case
    if(oldRoot == nullptr)
        return nullptr;
    //recursive case: create a new Node and recursively call copyNode on the left and right paths
    else
        return new BSTNode(oldRoot->getData(), copyHelper(oldRoot->getLeft()),copyHelper(oldRoot->getRight()));
}

void BST::insertHelper(BSTNode *& cur, const string & data)
{
    //base case: we've reached the bottom of the tree
    if(cur == nullptr)
        cur == new BSTNode(data);

    //recursive case 1: if the data is less than the current node's data, traverse to the left
    else if(data < cur->getData())
        insertHelper(cur->getLeft(), data);
    //recursive case 2: if the data is greater than or equal to the current node's data, traverse to the right
    else
        insertHelper(cur->getRight(), data);
}

bool BST::isEmpty()
{
    //The == operator returns a bool of true or false depending on if the values are equal
    return (root == nullptr);
}

BST::~BST()
{
    destroyTree(root);
}

//destroyTree uses the same logic as postOrderTraversal. The tree is traversed to the lowest node,
//and then delete is recursively called up the branches of the tree
void BST::destroyTree(BSTNode *& cur)
{
    if(cur->getLeft != nullptr)
        destroyTree(cur->getLeft());
    if(cur->getRight() != nullptr)
        destroyTree(cur->getRight());
    delete cur;
}

void BST::inOrderTraversal()
{
    inOrderHelper(root);
}

//inOrderTraversal prints the tree in order
//1. recurse to the left until left is a nullptpr
//2. print the current node
//3. recurse to the right unless right is a nullptr
void BST::inOrderHelper(BSTNode * cur)
{
    if(cur->getLeft() != nullptr)
        inOrderHelper(cur->getLeft());
    cout << cur << " ";
    if(cur->getRight() != nullptr)
        inOrderHelper(cur->getRight());
}

void BST::postOrderTraversal()
{
    postOrderHelper(root);
}

//postOrder is similar to inOrder, except it prints only after recursing
//both right AND left. The same logic will be applied to destroyTree
void BST::postOrderHelper(BSTNode * cur)
{
    if(cur->getLeft() != nullptr)
        postOrderHelper(cur->getLeft());
    if(cur->getRight() != nullptr)
        postOrderHelper(cur->getRight());
    cout << cur << " ";
}

void BST::preOrderTraversal()
{
    preOrderHelper(root);
}

//preOrder is the reverse of postOrder. It prints first, and then recurses down the tree.
void BST::preOrderHelper(BSTNode * cur)
{
    cout << cur << " ";
    if(cur->getLeft() != nullptr)
        preOrderHelper(cur->getLeft());
    if(cur->getRight() != nullptr)
        preOrderHelper(cur->getRight());
}
//this is an example file for Stacks in C
//stacks are similar data structures to linked lists.
//However, with stacks only the top data value can be accessed by the user, and data is inserted and removed from the top only.
//This is useful for things like function call stacks or other Last In First Out algorithms.

#include <stdlib.h>

//an enum for boolean statements. FALSE = 0, TRUE = 1
typedef enum boolean
{
	FALSE, TRUE
}Bool;

//This defines a node for the stack. For this example, the data will be an integer
typedef struct node
{
	int data;
	struct node *pNext;
}Node;

//this is a wrapper struct for the Stack. This can be used to avoid double pointer notation
typedef struct stack
{
	Node *top;
}Stack;

//this checks if the stack is empty
Bool isEmpty(Stack *stack);

//this will make a new node from an int
Node * makeNode(int newData);

//this will push a new node on top of the stack
void push(Node * newNode, Stack * stack);

//this will pop data off the top of the stack.
void pop(Stack *stack);

//this will allow the user to peak at the value on the top of the stack.
int peak(Stack *stack);

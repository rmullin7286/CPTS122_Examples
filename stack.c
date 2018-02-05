#include "stack.h"

Bool isEmpty(Stack *stack)
{
	//this code is the exact same as the code for the linked list example
	if (stack->top == NULL)
		return TRUE;
	else
		return FALSE;
	//alternatively, using ternary operator (?:)
	//return TRUE ? stack->top == NULL : FALSE;
}

Node * makeNode(int newData)
{
	//again, this code is exactly the same as linked list
	Node *newNode = (Node *)malloc(sizeof(Node));
	node->data = newData;
	node->pNext = NULL;
	return newNode;
}

void push(Node * newNode, Stack * stack)
{
	//this is similar to insertAtFront from the linked list example
	newNode->pNext = stack->top;
	stack->top = newNode;
}

void pop(Stack *stack)
{
	//make sure to check if the stack is already empty.
	if (!isEmpty(stack))
	{
		//free the top and set the new top to top->pNext
		Node *temp = stack->top;
		stack->top = stack->top->pNext;
		free(temp)
	}
}

int peak(Stack *stack)
{
	//make sure to always use isEmpty before peaking, otherwise you could run into a bug
	return stack->top->data;
}
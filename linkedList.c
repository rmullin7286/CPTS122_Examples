#include "linkedList.h"

//check if pHead is null. if it is, return true. otherwise, return false
Bool isEmpty(LinkedList *list)
{
	if (list->pHead == NULL)
		return TRUE;
	else
		return FALSE;

	//alternatively, this function can be done in one line of code using the ternary operator (?:)
	//return TRUE ? list->pHead == NULL : FALSE
}

//malloc a new node, set the values, and return it.
Node * makeNode(int newData)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = newData;
	//this is shorthand for setting both to NULL
	newNode->pNext = newNode->pPrev = NULL;
	return newNode;
}

void insertAtFront(Node * newNode, LinkedList * list)
{
	//if the list is empty, just insert at the head
	if (isEmpty(list))
	{
		list->pHead = newNode;
	}
	else
	{
		//link pHead and newNode, then make newNode the new head.
		newNode->pNext = list->pHead;
		list->pHead->pPrev = newNode;
		list->pHead = newNode;
	}
}

//inserts node at end
void insertAtEnd(Node * newNode, LinkedList * list)
{
	//if the list is empty, just insert the node at the head
	if (isEmpty(list))
	{
		list->pHead = newNode;
	}
	else
	{
		Node *cur = list->pHead;
		//iterate through until the end of the list is reached (cur->pNext == NULL)
		while (cur->pNext != NULL)
			cur = cur->pNext;
		//link cur and newNode
		cur->pNext = newNode;
		newNode->pPrev = cur;
	}
}

//this function assumes that the list is already in order
void insertinOrder(Node * newNode, LinkedList * list)
{
	//check for empty list
	if (isEmpty(list))
	{
		list->pHead = newNode;
	}
	else
	{
		Node *cur = list->pHead;
		//iterate through until cur->pNext->data >= newNode->data
		while (cur->pNext != NULL && cur->pNext->data < newNode->data)
			cur = cur->pNext;
		//place the node between cur and pNext and link
		newNode->pNext = cur->pNext;
		newNode->pNext->pPrev = newNode;
		newNode->pPrev = cur;
		cur->pNext = newNode;
	}
}

void deleteList(LinkedList *list)
{
	//if the list is empty, nothing needs to be done
	if (!isEmpty(list))
	{
		Node *cur = list->pHead, *next = pHead->pNext;
		while (next != NULL)
		{
			free(cur);
			cur = next;
			next = next->pNext;
		}

		//since the loop will be exited before the last free, free one more time
		free(cur);
	}
}
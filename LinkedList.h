#include <stdlib.h>

//a boolean enum for true and false statements
typedef enum boolean {
	FALSE, TRUE
}Bool;

//this is a node for a linked list. For this example, the data member will be an int.
//For this example, the list will be doublely linked
typedef struct node {
	int data;
	struct node *pNext;
	struct node *pPrev;
}Node;

//I like to use wrapper structs to avoid double pointer notation.
typedef struct LinkedList {
	Node *pHead;
}LinkedList;

//returns TRUE if empty, FALSE if not
Bool isEmpty(LinkedList *list);

//makenode, returns a pointer to the new node
Node * makeNode(int newData);

//inserts node at the front of list
void insertAtFront(Node * newNode, LinkedList * list);

//inserts node at end
void insertAtEnd(Node * newNode, LinkedList * list);

//inserts in order
void insertInOrder(Node * newNode, LinkedList * list);

//deletes the whole list
void deleteList(LinkedList *list);

/*
	Author Fakhra Najm, fnajm09@gmail.com
		Operations on singly Linked List
		1. create
		2. show
		3. find max
		4. find sum
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*head=NULL;


/**
 * creates a node
 * @param value to be inserted into node
 * @return node pointer to created node
 */
struct Node * createNode(int value) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	return node;
}

/**
 * Creates a linkedlist from given integer values
 * @param values from which linked list is to be created
 * @param length of given list of values
 */
void createLinkList(int values[],int length)
{
	head = createNode(values[0]);
	struct Node *last = head, *current;

	// loop over given values and insert into linked list
	for(int i = 1; i < length; i++) {
		current = createNode(values[i]);
		last->next = current;
		last = current;
	}
}

/**
 * calculates sum of values of linked list nodes
 * @param head pointer to the head of linked list
 * @return sum calculated sum of values of Linkedlist
 */
int calculateSum(struct Node *head)
{
	int sum = 0;
	while(head != NULL) {
		sum += head->data;
		head = head->next;
	}
	return sum;
}

/**
 * print values of a linkedlist
 * @param head pointer to the head of linkedlist
 */
void printList(struct Node *head)
{
	while(head != NULL) {
		printf("%d  ",head->data );
		head = head->next;
	}
}

/**
 * finds maximum value from a linkedlist
 * @param head pointer to the head of linkedlist
 * @return max value of LinkedList
 */
int findMax(struct Node *head)
{
	int max = head->data;
	head = head->next;
	// loop over ll and update max
	while(head) {
		if(max < head->data) max = head->data;
		head = head->next;
	}
	return max;
}


int main()
{
	int values[] = { 8, 3, 7, 12, 9 };
	createLinkList(values, 5);
	printList(head);
	printf("\nThe sum of all elements of linkedlist = %d ",calculateSum(head));
	printf("\nThe maxima of the list: %d",findMax(head));
	return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node * next;
}*head = NULL;

struct Node * createNode(int value)
{
	struct Node *node;
	node->data = value;
	node->next = NULL;
	return node;
}

void CreateLinkList(int values[], int length)
{
	head = createNode(values[0]);
	struct Node *current,*last=head;

	for(int i=1; i<length; i++){
		current = createNode(values[i]);
		last->next = current;
		last = current;
	}
}

void showList(struct Node *head)
{
	while(head != NULL){
		printf("%d ",head->data );
		head = head->next;
	}
}

struct Node * insertValue(struct Node *head, int value , int position)
{
	struct Node *node,*pointer;
	while(head != NULL){
		if(head == NULL){
			node = createNode(value);
		}

		else{
			node = createNode(value);
			for(int i=0; i<position-1; i++)
				pointer = pointer->next;

			node->next = pointer->next;
			pointer->next = node;

		}
	}

	return head;
}



int main()
{
	int values[] = {8, 5, 3, 9, 7};
	insertValue(head, 10, 4);
	showList(head);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*head=NULL;


struct Node * CreateNode(int value)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	return node;
}

void createList(int values[],int length)
{
	head=CreateNode(values[0]);
	struct Node *current,*last=head;
	for(int i=1; i<length; i++){
		current = CreateNode(values[i]);
		last->next = current;
		last = current;
	}
}

struct Node * searchList(struct Node * head , int value)
{
	while(head != NULL){
		if(value == head->data)
			return head;
		else
			head = head->next;
	}
	return NULL;
}

void printList(struct Node *head)
{
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
}

struct Node * SearchListImproved(struct Node *node, int value)
{
	struct Node * previous = NULL;
	while(node != NULL){
		if(value == node->data){
		    previous->next = node->next;
			node->next = head;
			head = node;

			return head;
		}
		else{
			previous = node ;
		    node = node->next;
		}
	}
}


int main()
{
	struct Node *searchResult;
	int values[] = {1, 8, 5, 12, 9};
	createList(values, 5);
	printList(head);
	searchResult = searchList(head, 12);
	if(searchResult != NULL)
		printf("search result succeeded\nvalue found: %d ",searchResult->data);
	else
		printf("Failure!!!!\n");

	SearchListImproved(head , 12);

	printf("\nLet's see the effect of improved function\n");
	printList(head);
	return 0;
}

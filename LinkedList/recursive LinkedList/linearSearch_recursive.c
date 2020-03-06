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

void CreateLinkList(int values[], int length)
{
	head=CreateNode(values[0]);
	struct Node * current, *last = head;

	for(int i=1; i<length; i++){
		current = CreateNode(values[i]);
		last->next = current;
		last = current;
	}
}

void ShowList(struct Node * head)
{
	while(head != NULL){
		printf("%d  ", head->data );
		head = head->next;
	}
}

struct Node * searchList(struct Node * head, int key)
{
	if(head)
		if(key == head->data )
			return head;
		else
			return searchList(head->next, key);

	else 
		return NULL;
}

int main(){

	struct Node * searchResult;

	int values[] = {15, 8, 25, 7, 3, 12};

	CreateLinkList(values, 6);

	ShowList(head);

	searchResult = searchList(head, 25);

	if(searchResult != NULL)
		printf("\nlist element Found %d",searchResult->data);
	else
		printf("\nlist element not found");
	return 0;
}
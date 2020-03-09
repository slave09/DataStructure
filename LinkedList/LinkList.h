#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node * next;
}*head=NULL,*last=NULL;

struct Node * createNode(int value)
{
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	return node;
}

struct Node * searchList(struct Node * head , int value)
{
	while(head != NULL){
		if(value == head->data)
			return head;
		else
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

void createLinkList(int value)
{
	struct Node * node;
	node = createNode(value);
	if(head == NULL)
	{
		head = last = node ; 
	}
	else
	{
		last->next = node ; 
		last = node;
	}
}

int countNode(struct Node *head)
{
	int count=0;
	while(node!=NULL){
		count++;
		head=head->next;
	}
	return count;
}

void removeHead()
{
	struct Node * node = createNode(head->data);
	head = head->next;
	node = NULL;
}

void removeNode(struct Node *node, int value)
{
	struct Node * prev_node = (struct Node *)malloc(sizeof(struct Node));
	
	if(head->data == value)
		removeHead();

	else{
		while(node != NULL)
		{
			if(node->data != value)
			{
				prev_node = node ;
				node = node->next;
			}
			else
			{
				prev_node->next = node->next;
				node = NULL;
			}
		}
	}	
}

int CheckSort(struct Node *head)
{
	int x = head->data;
	head = head->next;
	while(head != NULL){
		if(head->data < x)
			return 0;
		x = head->data ;
		head = head->next;
	}
  return 1;
}

void ShowList(struct Node * head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}
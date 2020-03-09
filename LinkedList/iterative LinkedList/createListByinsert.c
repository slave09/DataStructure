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

void createLinkList(int value)
{
	struct Node * node;
	node = createNode(value);
	if(head == NULL)
	{
		head = last = node ; // all the nodes are at one since there is no other node
	}
	else
	{
		last->next = node ; //current node becomes the next to the previous last node
		last = node; 		//here the current node "node" is updated as last node "last"
	}
}

void ShowList(int nodes)
{
	for( int i = 0; i < nodes ; i++)
	{
		printf("%d ", head->data );
		head = head->next;
	}
}

int main()
{
	int value,nodes;
	printf("Enter number of nodes");
	scanf("%d", &nodes);
	printf("\nEnter all elements of the link list:\n");
	for(int i = 0; i < nodes; i++){
		scanf("%d", &value);
		createLinkList(value);
	}
	ShowList(nodes);
	return 0;
}
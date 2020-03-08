#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*head=NULL;

struct Node * createNode(int value)
{
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));

	node->data = value;
	node->next = NULL;

	return node;
}


void createLinkList(int value)
{
	struct Node *node , *last ;
	node = createNode(value);

	if(head == NULL)
	{
		head = last = node ;
	}

	else if(head != NULL)
	{
		last->next = node ; 
		last = node ; 	/* updated the last node "last" to the current node "node"*/
	}
	
}



void showList(struct Node * head, int nodes)
{
	while(head != NULL){
		printf("%d ", head->data );
		head = head->next;
	}
	
}

int main()
{
	int nodes,value;
	printf("Enter number of nodes : ", nodes);
	scanf("%d", &nodes);
	printf("\nEnter values to form link list\n");
	for (int i = 0; i < nodes; ++i)
	{
		scanf("%d", &value);
		createLinkList(value);
		printf("Entered Value :%d\t" ,value);
	}
	printf("List has displayed below\n");
	showList(head, nodes);
	return 0;
}
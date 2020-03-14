#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*head = NULL, *last = NULL;


struct Node * createNode(int value)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	return node;
}

void createLinkList(int value)
{
	struct Node *node = createNode(value);
	if(head == NULL)
	{
		head = last = node;
	}
	else
	{
		last->next = node;
		last = node;
	}
}

void ShowList(struct Node *head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
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

int main()
{
	int nodes, value;
	printf("Enter number of nodes:\n");
	scanf("%d", &nodes);

	printf("\nEnter all elements\n");
	for (int i = 0; i < nodes; i++)
	{
		scanf("%d", &value);
		createLinkList(value);
	}
	
	ShowList(head);

	if(CheckSort(head))
		printf("\nlist is sorted\n");
	else
		printf("\nlist is not sorted\n");

	return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node * next;
}*head=NULL;

struct Node * createNode(int value)
{
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	return node;
}

void createLinkList(int values[], int length)
{
	head = createNode(values[0]);
	struct Node *current, *last = head;
	for(int i = 1; i < length; i++){
		current = createNode(values[i]);
		last->next = current;
		last = current;
	}
}

void PrintList(struct Node * head)
{
	while(head){
		printf("%d ", head->data);
		head = head->next;
	}
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


int main()
{
	int value;
	int values[] = {1, 4, 7, 5, 8};
	createLinkList(values, 5);
	printf("The given link list is\n");
	PrintList(head);
	printf("\nEnter the value for deletion:\n");
	scanf("%d" , &value);
	removeNode(head ,value);
	printf("The new link list is as below\n");
	PrintList(head);
	return 0;
}
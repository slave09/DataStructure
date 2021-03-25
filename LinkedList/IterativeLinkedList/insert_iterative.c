#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node * next;
}*head = NULL;

struct Node * createNode(int value)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	return node;
}

void CreateLinkList(int values[], int length)
{
	head = createNode(values[0]);
	struct Node *current,*last=head;

	for(int i = 1; i < length; i++){
		current = createNode(values[i]);
		last->next = current;
		last = current;
	}
}

int nodesCount(struct Node *node)
{
	int count=0;
	while(node!=NULL){
		count++;
		node=node->next;
	}
	return count;
}

void showList(struct Node *head)
{
	while(head != NULL){
		printf("%d ",head->data );
		head = head->next;
	}
}

void insertValue(struct Node *head, int value , int position)
{
	struct Node * new =(struct Node *)malloc(sizeof(struct Node));
	new->data = value;
	if(position > nodesCount(head) || position < 0)
		return;
	if(position == 0){
		new->next = head;
		head = new;
	}
	else{
		for(int i = 0; i < position-1; i++)
			head = head->next;
		new->next = head->next;
		head->next = new;
	}
}



int main()
{
	int values[] = {8, 5, 3, 9, 7};
	CreateLinkList(values, 5);
	showList(head);
	insertValue(head , 10, 4);
	printf("\nshow new list formed\n");
	showList(head);
	return 0;
}


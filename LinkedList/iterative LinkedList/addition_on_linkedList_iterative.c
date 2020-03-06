#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void Create_linkedList(int a[],int elements)
{
	struct Node *last,*current;
	first=(struct Node *)malloc(sizeof(struct Node));
	int i;
	first->data=a[0];
	first->next=NULL;
	last=first;

	for(i=1;i<elements;i++){
		current=(struct Node *)malloc(sizeof(struct Node));
		current->data=a[i];
		current->next=NULL;
		last->next=current;
		last=current;
	}
}

int Add_all_elements(struct Node *node)
{
	int sum=0;
	while(node!=NULL){
		sum+=node->data;
		node=node->next;
	}
		return sum;
}

void Display_linkedList(struct Node *node)
{
	while(node!=NULL){
		printf("%d  ",node->data );
		node=node->next;

	}
}

int max_element(struct Node *node)
{
	int max=node->data;
	node=node->next;
	while(node){
		if(max<node->data)
			max=node->data;
		node=node->next;
	}

	return max;
}

int main()
{
	int array1[]={8,3,7,12,9};
	Create_linkedList(array1,5);
	Display_linkedList(first);
	printf("\nThe sum of all elements of linked list=%d ",Add_all_elements(first));
	printf("\nThe maxima of the list: %d",max_element(first));
	return 0;
}

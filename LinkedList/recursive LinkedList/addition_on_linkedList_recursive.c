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
	int i;

	first=(struct Node *)malloc(sizeof(struct Node));

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

void Display_linkedList(struct Node *node)
{
	while(node!=NULL){
		printf("%d  ",node->data );
		node=node->next;
	}
}

int recursive_addition(struct Node *node)
{
	if(node)
		return recursive_addition(node->next)+node->data;
	else
		return 0;

}


int main()
{
	int array[]={10,20,30,40,50};
	Create_linkedList(array,5);
	Display_linkedList(first);
	printf("\nthe sum of all elements in list = %d ",recursive_addition(first) );
	return 0;
}

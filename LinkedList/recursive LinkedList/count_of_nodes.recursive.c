#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int Data;
	struct Node *next;
}*first=NULL;

void Create_linkedList(int a[],int elements)
{
	struct Node *last,*current;
	int i;
	first=(struct Node *)malloc(sizeof(struct Node));

	first->Data=a[0];
	first->next=NULL;
	last=first;

	for(i=1;i<elements;i++){
		current=(struct Node *)malloc(sizeof(struct Node ));
		current->Data=a[i];
		current->next=NULL;
		last->next=current;
		last=current;
	}
}

int count_of_node(struct Node *node)
{
	if(node!=NULL)
		return count_of_node(node->next)+1;
	else
		return 0;
}


int main()
{
	int array[]={5,10,15,20,25};
	Create_linkedList(array,5);
	printf("number of nodes:%d", count_of_node(first) );
	return 0;
}

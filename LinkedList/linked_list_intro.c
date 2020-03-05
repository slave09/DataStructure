#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int Data;
	struct Node *Next;
}*first=NULL;

void Create(int A[],int n)
{
	int i;
	struct Node *last,*current;

	first =(struct Node *)malloc(sizeof(struct Node));

	first->Data=A[0];
	first->Next=NULL;
	last=first;

	for(i=1;i<n;i++){
		current=(struct Node *)malloc(sizeof(struct Node));

		current->Data=A[i];
		current->Next=NULL;
		last->Next=current;
		last=current;
	}

}

void Display(struct Node *node)
{
	printf("Elements in the list are:\n");
	while(node!=NULL){
		printf("%d ",node->Data );
		node=node->Next;
	}
}

int main(){
	struct Node *node;
	int Array[]={1,3,5,7,9};
	Create(Array,5);
	Display(first);
	return 0;
}

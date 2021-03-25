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

void Display_recursive(struct Node *node)
{
	if(node!=NULL){
		printf("%d ",node->Data );
		Display_recursive(node->Next);
	}
}

int max_element(struct Node *node)
{   
	int x;
	if(node==NULL)
		return 0;
	x=max_element(node->Next);
	return (x>node->Data)? x:node->Data;

}

int main(){
	struct Node *node;
	int Array[]={8,3,7,12,9};
	Create(Array,5);
	printf("Elements in the list are:\n");
	Display_recursive(first);
	printf("\n");
	printf("The maxima of the list=%d",max_element(first));
	return 0;
}

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
	int max=node->Data;
	node=node->Next;
	if(max<node->Data)
		return max_element(node);
	else
		return max;
}

int main(){
	struct Node *node;
	int Array[]={1,3,5,7,9};
	Create(Array,5);
	printf("Elements in the list are:\n");
	Display_recursive(first);
	printf("the maxima of the list = %d",max_element(first));
	return 0;
}

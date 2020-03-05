#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int Data;
	struct Node *Next;
}*first=NULL;

Void Create(int A[],int n)
{
	int i;
	struct Node *first ,*last,*current;

	first =(struct Node *)malloc(sizeof(struct Node));

	first->Data=A[0];
	first->Next=NULL;
	last=first;

	for(i=1;i<n;i++){
		current=(struct Node *)malloc(sizeof(struct Node));

		current->data=A[i];
		current->Next=NULL;
		last->Next=current;
		last=current;
	}

}

int main(){
	int Array[]={1,3,5,7,9};
	return 0;
}
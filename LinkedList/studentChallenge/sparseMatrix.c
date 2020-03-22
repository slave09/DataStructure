#include<stdio.h>
#include<stdlib.h>

struct Node{
	int column;
	int value;
	struct Node *next;
}*head = NULL, *last = NULL;

struct Node * createNode(int col, int val){
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));
	node->column = col;
	node->value = val;
	node->next = NULL;
	return node;
}

void insertNode(struct Node *node, int col, int val){
	if(head == NULL){
		head = last = createNode(col, val);
	}
	else{
		*rows[i] = createNode(col, val);
		last->next = *rows[i];
		last = *rows[i];
	}
}

void createSparse(){
	int row,col,val;
	printf("Enter number of rows\n");
	scanf("%d",&row);
	int *rows = (int *)malloc(row*sizeof(int));
	printf("Enter all elements\n");
	for(int i = 0 ; i < row ; i++)
		scanf("%d%d", &col,&val);
	for (int i = 0; i < row; ++i){
	  struct Node **rows[i] = (struct Node **)malloc(sizeof(struct Node));
	  insertNode(*rows[i],col,val);
	}
	
}

int main(){
	createSparse();
	return 0;
}
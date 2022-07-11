/*
	Author Fakhra Najm
	email : fnajm09@gmail.com
	Implementation of Stack using LinkedList
	* 1. push
	* 2. pop
	* 3. peek
*/

#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
}*top =  NULL;

/*
	* Inserts value in the stack
	* @param value to be inserted
*/

void push(int value){
	struct stack *node = (struct stack *)malloc(sizeof(struct stack));
	if(node == NULL)
		printf("Stack is full");
	else{
		node->data = value;
		node->next = top;
		top = node; 
	}
}

/*
	* deletes top value of the stack
	* @return deleted value
*/
int pop(){
	int deleted = -1;
	if(top == NULL)
		printf("stack is empty\n");
	else{
		struct stack * node = top;
		deleted = node->data;
		top = top->next;
		free(node);
	}
	return deleted;
}

/*
	* gives the value of element at given position
	* @param index of the stack
	* @return value at the given index
*/

int peek(int index){
	struct stack *node = top;
	for(int i = 0; node!= NULL && i < index-1; ++i){
		node = node->next;
	}
	if(node)
		return node->data;
	return -1;
}

// returns the value of top of stack

int stackTop(){
	if(top != NULL)
		return top->data;
	return -1;
}

// checking whether stack is full or not

int isFull(){
	struct stack *node = (struct stack *)malloc(sizeof(struct stack));
	if(node == NULL)
		return 1;
	return 0;
}

// checking whether stack is empty or not

int isEmpty(){
	if(top == NULL)
		return 1;
	return 0;
}

// prints linkedList

void printStack(){
	struct stack *node = top;
	while(node){
		printf("%d ",node->data );
		node = node->next;
	}
	printf("\n");
}

int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	printStack();
	printf("search Result:%d\n",peek(1) );
	printf("Deleted value:%d\n",pop() );
	printStack();
	printf("search Result:%d\n",stackTop() );
	if(isEmpty() == 1)
		printf("stack is empty\n");
	else
		printf("stack is not empty\n");
	if(isFull() == 1)
		printf("stack is full\n");
	else
		printf("stack is not full\n");
	return 0;
}
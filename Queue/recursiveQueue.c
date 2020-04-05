/*
	* Author Fakhra Najm
	* Email fnajm09@gmail.com
	* Queue using one stack
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*top = NULL;

int isEmpty(){
	if(top == NULL)
		return 1;
	return 0;
}

void push(int value){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	if(node == NULL)
		printf("Stack is Full\n");
	else{
		node->data = value;
		node->next = top;
		top = node;
	}
}

int pop(){
	int value;
	if(isEmpty())
		return -1;
	else{
		struct Node *node = top;
		top = top->next;
		value = node->data;
		free(node);
	}
	return value;
}

void enqueue(int value){
	push(value);
}

int dequeue(struct Node *head){
	int value = -1;
 if(head){
 	dequeue(head->next);
 	value = pop();
 	printf("%d\n",value);
 }
 return value;
}

int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	printf("%d\n",dequeue(top));
	//printf("%d\n",dequeue(top));
	return 0;
}

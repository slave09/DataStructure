/*
	Author : Fakhra Najm
	EMail  : fnajm09@gmail.com

	* Applications of Stack
	* 1. parenthesis matching
*/

#include<stdio.h>
#include<stdlib.h>
struct stack{
	char data;
	struct stack *next;
}*top =  NULL;

/*
	* inserts value inside the node of stack
	* @param value to be inserted
*/

void push(char value){
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
	* deletes the top value of the stack
	* @return deleted value
*/
char pop(){
	char deleted = -1;
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

int checkmatch(char *expression){
	for(int i = 0; expression[i] != '\0'; i++){
		if(expression[i] == '(')
			push(expression[i]);
		else if(expression[i] == ')'){
			if(isEmpty() == 1)
				return 0;
			pop();
		}
	}
	if(isEmpty() == 1)
		return 1;
	else
		return 0;
}

int main(){
	char *expression = "(a+b)*(c-d)";
	printf("%d\n",checkmatch(expression) );
	return 0;
}
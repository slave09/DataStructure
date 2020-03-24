/*
	Author Fakhra Najm
	email  fnajm09@gmail.com
	* stack implementation using array
	* 1. push
	* 2. pop
	* 3. peek
	* 4. stackTop
	* 5. isFull
	* 6. isEmpty
*/

#include<stdio.h>
#include<stdlib.h>

struct stack{
	int size;
	int top;
	int *items;
};

/*
	* inserts value in the stack array
	* @param st pointer to the top pointer of stack
	* @param value to be inserted
*/

void push(struct stack *st, int value){
	if(st->top == st->size-1)
		printf("stack overflow\n");
	else{
		st->top++;
		st->items[st->top] = value;
	}
}

/*
	* deletes the top value of the stack
	* @param st pointer to the top pointer of stack
	* @return removed value
*/

int pop(struct stack *st){
	int removed= -1;
	if(st->top == -1)
		printf("stack underflow\n");
	else{
		removed = st->items[st->top];
		st->top--;
	}
	return removed;
}

/*
	* gives the element of stack at given index
	* @param st calling stack
	* @param index from which value is to be returned
	* @return value at the given index
*/

int peek(struct stack st, int index){
	int value = -1;
	if(st.top-index+1 < 0)
		printf("invalid index\n");
	else{
		value = st.items[st.top-index+1];
	}
	return value;
}

/*
	* gives the element at the top
	* @param st calling stack
	* return value of the top
*/

int stackTop(struct stack st){
	if (st.top == -1){
		return -1;
	}
	else{
		return st.items[st.top];
	}
}

/*
	* checks whether stack is full or not
	* @return true or false
*/

int isFull(struct stack st){
	if(st.top == st.size-1)
		return 1;
	else 
		return 0;
}

/*
	* checks whether stack is empty or not
	* @return true or false
*/

int isEmpty(struct stack st){
	if(st.top == -1)
		return 1;
	else
		return 0;
}

void printStack(struct stack st){
	if(st.top == -1)
		return;
	for (int i = st.top; i >= 0; i--){
		printf("%d ",st.items[i] );
	}
	printf("\n");
}

int main(){
	struct stack st;
	printf("Enter size of stack:\n");
	scanf("%d",&st.size);
	st.items = (int *)malloc(st.size*sizeof(int));
	st.top = -1;
	push(&st,1);
	push(&st,2);
	push(&st,3);
	push(&st,4);
	push(&st,5);
	printStack(st);
	printf("%d\n",pop(&st) );
	printStack(st);
	printf("%d\n",peek(st,0) );
	printf("%d\n",stackTop(st) );
	if(isFull == 1)
	printf("stack is full\n");
	else
	printf("stack is not full\n");
	if(isEmpty == 1)
	printf("stack is empty\n");
	else
	printf("stack is not empty\n");

	return 0;
}
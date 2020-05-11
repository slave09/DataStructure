#include"Queue.h"

struct stack{
  int size;
  int top;
  struct Node **items;
};

void createStack(struct stack *st, int sz){
	st->items = (struct Node **)malloc(sizeof(struct Node));
	st->size = sz;
	st->top = -1;
}

void push(struct stack *st, struct Node *value){
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

struct Node * pop(struct stack *st){
	struct Node * removed = NULL;
	if(st->top == -1)
		printf("stack underflow\n");
	else{
		removed = st->items[st->top];
		st->top--;
	}
	return removed;
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

int isEmptyStack(struct stack st){
	if(st.top == -1)
		return 1;
	else
		return 0;
}
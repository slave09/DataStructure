#include<stdio.h>
#include<stdlib.h>

struct stack{
	int size;
	int top;
	int *items;
};

void push(struct stack *st, int value){
	if(st->top == st->size-1)
		printf("stack overflow\n");
	else{
		st->top++;
		st->items[st->top] = value;
	}
}

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

int peek(struct stack st, int index){
	int value = -1;
	if( < 0)
		printf("invalid index\n");
	else{
		value = st.items[st.top-index+1];
	}
	return value;
}

int main(){
	struct stack st;
	printf("Enter size of stack:\n");
	scanf("%d",&st.size);
	st.items = (struct stack *)malloc(st.size*sizeof(struct stack));
	st.top = -1;
	return 0;
}
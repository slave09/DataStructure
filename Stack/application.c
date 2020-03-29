/*
	Author : Fakhra Najm
	EMail  : fnajm09@gmail.com

	Applications of Stack
	* 1. parenthesis matching
	* 2. infix to postfix conversion
	Operations:
	* 1. checkmatch
	* 2. isOperand
	* 3. precedence
	* 4. inStack
	* 5. outStack
	* 6. makePostfix
	* 7. evaluate
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	int data;
	struct stack *next;
}*top =  NULL;

/*
	* inserts value inside the node of stack
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
	* deletes the top value of the stack
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

// returns the value of top of stack

int stackTop(){
	if(top != NULL)
		return top->data;
	return -1;
}

/*
	* checks whether correctly parenthesised or not
	* @param expression pointer to the given expression
	* @return true or false 
*/

int checkmatch(char *expression){
	for(int i = 0; expression[i] != '\0'; i++){
		if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
			push(expression[i]);
		else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
			if(isEmpty())
				return 0;
			else if(expression[i]-stackTop() == 1 || expression[i]-stackTop() == 2)
				pop();
			else
				return 0;
		}
	}
	if(isEmpty())
		return 1;
	else
		return 0;
}

// gives the precedence inside the stack

int inStack(char exp){
	if(exp == '+' || exp == '-')
		return 2;
	else if(exp == '*' || exp == '/')
		return 4;
	else if(exp == '^')
		return 5;
	else if(exp == '(')
		return 0;
	return 0;
}

// returns outside presedence of expression

int outStack(char exp){
	if(exp == '+' || exp == '-')
		return 1;
	else if(exp == '*' || exp == '/')
		return 3;
	else if(exp == '^')
		return 6;
	else if(exp == '(')
		return 7;
	else if(exp == ')')
		return 0;
}

/*
	* checks whether expression is operand or not
	* @param exp pointer to the given expression
	* @return true or false
*/

int isOperand(char exp){
	if(exp == '+')
		return 0;
	else if(exp == '-')
		return 0;
	else if(exp == '*')
		return 0;
	else if(exp == '/')
		return 0;
	else if(exp == ')')
		return 0;
	else if(exp == '(')
		return 0;
	else if(exp == '^')
		return 0;
	else
		return 1;
}

// finding and returning the precedence order

int precedence(char exp){
	if(exp == '+' || exp == '-')
		return 1;
	else if(exp == '*' || exp == '/')
		return 2;
	else return 0;
}

/*
	* converts infix to postfix configuration
	* @param infix pointer to expression to be converted
	* @return postfix config of the passed infix_config
*/

char * makePostfix(char * infix){
	char * postfix = (char *)malloc(strlen(infix)*sizeof(char));
	int i ,j;
	i = j = 0;
	while(infix[i] != '\0'){
		if(isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else{
			if(inStack(stackTop()) < outStack(infix[i]))
				push(infix[i++]);
			else if(inStack(stackTop()) > outStack(infix[i]))
				postfix[j++] = pop();
			else{
				pop();
				i++;
			}
		}
	}
	while(!isEmpty()){
		if(infix[i] != '(')
				postfix[j++] = pop();
		else 
			pop();
	}
	postfix[j] = '\0';
	return postfix;
}

int evaluate(char * postfix){
	int first, second, result;
	for (int i = 0; postfix[i] != '\0'; ++i){
		if(isOperand(postfix[i]))
			push(postfix[i]-'0');
		else{
			first = pop();
			second = pop();
			switch(postfix[i]){
				case '+' : result = second + first ;  break;
				case '-' : result = second - first ;  break;
				case '/' : result = second / first ;  break;
				case '*' : result = second * first ;  break;
			}
			push(result);
		}
	}
	return stackTop();
}

int main(){
	char *infix = "3*5+6/2-4";
	if(checkmatch(infix))
		printf("Balanced\n");
	else
		printf("unbalanced\n");
	char * postfix = makePostfix(infix);
	printf("%s\n",postfix );
	printf("%d\n",evaluate(postfix) );
	return 0;
}
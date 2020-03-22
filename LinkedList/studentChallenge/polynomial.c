/**
	Author : Fakhra Najm
	email   : fnajm09@gmail.com
	polynomial via linkedList
	* 1. create.
	* 2. evaluate.
	* 3. display.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct polynomial
{
	int coeff;
	int exponent;
	struct polynomial *next_term; 
}*head_term = NULL, *last = NULL;
 
struct polynomial *createNode(int coefficient, int exp){
	struct polynomial *node = (struct polynomial*)malloc(sizeof(struct polynomial));
	if(head_term == NULL){
		head_term = (struct polynomial *)malloc(sizeof(struct polynomial));
		head_term->coeff = coefficient;
		head_term->exponent = exp;
		head_term->next_term = NULL;
		last = head_term;
		return head_term;
  }
  else{
  	last->next_term = node;
  	node->coeff = coefficient;
		node->exponent = exp;
		node->next_term = NULL;
		last = node;
  }
  return node;
}

void createTerm(struct polynomial *head_term){
	int terms, coefficient, exp;
	printf("Enter number of terms\n");
	scanf("%d", &terms);
	printf("enter all terms details\n");
	for (int i = 0; i < terms; ++i){
		scanf("%d%d", &coefficient, &exp);
		createNode(coefficient, exp);
	}
}

int evaluateTerms(struct polynomial * head_term, int var_value){
	int result = 0;
	while(head_term){
		result = result + (head_term->coeff)*pow(var_value, head_term->exponent);
		head_term = head_term->next_term;
	}
	return result;
}

void printTerms(struct polynomial *head_term){
	while(head_term){
		printf("%dx%d+", head_term->coeff, head_term->exponent );
		head_term = head_term->next_term;
	}
	printf("\n");
}

int main(){
	int var_value;
	createTerm(head_term);
	printTerms(head_term);
	printf("Enter variable value:\n");
	scanf("%d", &var_value);
	printf("Result : %d\n",evaluateTerms(head_term, var_value) );
	return 0;
}
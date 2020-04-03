/*
  Author Fakhra Najm
  Email  fnajm09@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *top;
  struct Node *next;
};

struct Queue{
  struct Node *stack1;
  struct Node *stack2;
};

int isEmpty(struct Node *stack){
  if(stack->top == NULL)
    return 1;
  return 0;
}

void push(struct Node *stack, int value){
  stack = (struct Node *)malloc(sizeof(struct Node));
  if(stack == NULL)
    printf("Queue is empty\n");
  else{
    stack->data = value;
    stack->next = stack->top;
    stack->top = stack;
  }
}

int pop(struct Node *stack){
  int value = -1;
  if(isEmpty(stack)){
    printf("stack is empty");
    return value;
  }
  struct Node *node = stack->top;
  value = node->data;
  stack->top = stack->top->next;
  free(node);
  return value;
}

void enqueue(struct Queue *queue, int value){
  push(&queue->stack1, value);
}

int dequeue(struct Queue *queue){
  if(isEmpty(queue->stack2)){
    if(isEmpty(queue->stack1)){
      printf("Queue is empty\n");
      return -1;
    }
    else{
      while(!isEmpty(queue->stack1))
        push(&queue->stack2, pop(&queue->stack1));
    }
  }
  return pop(&queue->stack2);
}

int main(){
  struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
  queue->stack1 = NULL;
  queue->stack2 = NULL;
  enqueue(queue, 10);
  printf("%d\n",dequeue(queue) );
  return 0;
}
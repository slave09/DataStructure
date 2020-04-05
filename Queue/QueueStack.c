/*
  Author Fakhra Najm
  Email fnajm09@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

struct Queue{
  struct Node *stack1;
  struct Node *stack2;
};

int isEmpty(struct Node *stack){
  if(stack == NULL)
    return 1;
  return 0;
}

void push(struct Node **stack, int value){
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  if(node == NULL)
    printf("stack is full\n");
  else{
    node->data = value;
    node->next = (*stack);
    (*stack) = node;
  }
}

int pop(struct Node **stack){
  int value;
  if(isEmpty(*stack))
    return -1;
  else{
    struct Node *node = (*stack);
    *stack = node->next;
    value = node->data;
    free(node);
  }
  return value;
}

void enqueue(struct Queue *queue, int value){
  push(&queue->stack1, value);
}

int dequeue(struct Queue *queue){
  if(isEmpty(queue->stack2)){
    if(isEmpty(queue->stack1)){
      printf("queue is empty");
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
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->stack2 = queue->stack1 = NULL;
  enqueue(queue, 10);
  enqueue(queue, 20);
  printf("%d\n",dequeue(queue) );
  printf("%d\n",dequeue(queue) );

  return 0;
}
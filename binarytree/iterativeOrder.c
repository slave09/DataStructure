/*
  Name  : Fakhra Najm
  email : fnajm09@gmail.com
  Iterative function of tree traversal
*/

#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"stack.h"


struct Node *root = NULL;

void createTree(){
  struct Node *holder, *node;
  struct Queue q;
  createQ(&q);
  int value;
  printf("Enter root value : ");
  scanf("%d", &value);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = value;
  root->left_child = root->right_child = NULL;
  enqueue(&q, root);

  while(! isEmpty(q)){
    holder = dequeue(&q);
    printf("Enter leftChild of %d :", holder->data);  
    scanf("%d", &value);
    if(value != -1){
      node = (struct Node *)malloc(sizeof(struct Node));
      node->data = value;
      node->left_child = node->right_child = NULL;
      holder->left_child = node;
      enqueue(&q, node);
    }

    printf("Enter RighttChild of %d :", holder->data);  
    scanf("%d", &value);
    if(value != -1){
      node = (struct Node *)malloc(sizeof(struct Node));
      node->data = value;
      node->left_child = node->right_child = NULL;
      holder->right_child = node;
      enqueue(&q, node);
    }
  }
}

void preorder(struct Node *node){
  struct stack st;
  createStack(&st, 100);
  while(node != NULL || !isEmptyStack(st)){
    if(node != NULL){
      printf("%d ", node->data);
      push(&st, node);
      node = node->left_child;
    }
    else{
      node = pop(&st);
      node = node->right_child;
    }
  }
}

int main(){

  createTree();
  preorder(root);
  return 0;
}
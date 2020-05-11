/*
  Name  : Fakhra Najm
  email : fnajm09@gmail.com
  Iterative function for tree traversal
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
  printf("\n");
}

void postorder(struct Node *node){
  struct stack st;
  int long store;
  createStack(&st, 100);
  while(node != NULL || !isEmptyStack(st)){
    if(node != NULL){
      push(&st, node);
      node = node->left_child;
    }
    else{
      store = (long int)pop(&st);
      if(store > 0){
        store *= -1;
        push(&st,(struct Node *)store );
        node = ((struct Node *)store)->right_child;
      }
      else{
        printf("%d ", ((struct Node *)store)->data);
        node = NULL;
      }
    }
  }
  printf("\n");
}

void Inorder(struct Node *node){
  struct stack st;
  createStack(&st, 100);
  while(node != NULL || !isEmptyStack(st)){
    if(node != NULL){
      push(&st, node);
      node = node->left_child;
    }
    else{
      node = pop(&st);
      printf("%d ", node->data);
      node = node->right_child;
    }
  }
  printf("\n");
}

int main(){

  createTree();
  printf("Preorder: ");
  preorder(root);
  printf("Inorder: ");
  Inorder(root);
  printf("Postorder: ");
  postorder(root);
  return 0;
}
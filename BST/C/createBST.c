/*
  * Author: Fakhra Najm
  * Email: fnajm09@gmail.com
  * Topic: Generating binary search tree from preorder traversal
*/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

struct Node *root = NULL;

struct Node *createNode(struct Node *node, int value){
  node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  node->left_child = node->right_child = NULL;
  return node;
}

void createBST(int preorder[], int nodes){
  struct Node *temp, *node;
  int i = 0;
  struct stack stk;
  createStack(&stk, 100);
  root = createNode(root, preorder[i++]);
  temp = root;
  while (i < nodes){
    if(preorder[i] < temp->data){
      node = createNode(node, preorder[i++]);
      temp->left_child = node;
      push(&stk, temp);
      temp = node;
    }
    else{
      if(isEmptyStack(stk)){
         node = createNode(node, preorder[i++]);
         temp->right_child = node;
         push(&stk, temp);
         temp = node;
      }
      else if(preorder[i] < stackTop(stk)->data && temp->data < preorder[i]){
        node = createNode(node, preorder[i++]);
        temp->right_child = node;
        push(&stk, temp);
        temp = node;
      }
      else{
        node = createNode(node, preorder[i++]);
        pop(&stk)->right_child = node;
        temp = node;
      }
    }
  }
}


void bstFromPostorder(int postorder[], int nodes){
  struct Node *node, *temp;
  struct stack stk;
  createStack(&stk, 100);
  nodes = nodes - 1;
  root = createNode(root, postorder[nodes--]);
  temp = root;
  while(nodes >= 0){
    if(temp->data < postorder[nodes]){
      node = createNode(node, postorder[nodes--]);
      temp->right_child = node;
      push(&stk, temp);
      temp = node;
    }
    else{
      if(isEmptyStack(stk)){
        node = createNode(node, postorder[nodes--]);
        temp->right_child = node;
        temp = node;
        push(&stk, temp);
      }
      else if(stackTop(stk)->data < postorder[nodes] && postorder[nodes] < temp->data ){
        node = createNode(node, postorder[nodes--]);
        temp->left_child = node;
        push(&stk, temp);
        temp = node;
      }
      else{
        node = createNode(node, postorder[nodes--]);
        pop(&stk)->left_child = node;
        temp = node;
      }
    }
  }
}

void inorder(struct Node *root){
  if(root){
    inorder(root->left_child);
    printf("%d ", root->data);
    inorder(root->right_child);
  }
}

int main(){
  int preorder[7] = {50, 40, 30, 45, 60, 55, 70};
  int postorder[7] = {30, 45, 40, 55, 70, 60, 50};
  createBST(preorder, 7);
  printf("Binary search tree from preorder:");
  inorder(root);
  printf("\n");
  root = NULL;
  bstFromPostorder(postorder, 7);
  printf("Binary search tree from postorder:");
  inorder(root);
  return 0;
}
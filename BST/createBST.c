/*
  * Author: Fakhra Najm
  * Email: fnajm09@gmail.com
  * Topic: Generating binary search tree from preorder traversal
*/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

struct stack *stk;
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
  createStack(&stk, 100);
  root = createNode(root, preorder[i++]);
  temp = root;
  while (i < nodes){
    if(preorder[i] < temp->data){
      node = createNode(node, preorder[i++]);
      temp->left_child = node;
      push(stk, temp);
      temp = node;
    }
    else{
      if(preorder[i] < stackTop(stk)->data && temp->data < preorder[i]){
        node = createNode(node, preorder[i++]);
        temp->right_child = node;
        temp = node;
      }
      else{
        node = createNode(node, preorder[i++]);
        if(! isEmptyStack) 
          pop(stk)->right_child = node;
        else
          temp->right_child = node;
        temp = node;
      }
    }
  }
}

int main(){
  int preorder[5] = {1, 2, 3, 4, 5};
  createBST(preorder, 5);
  return 0;
}
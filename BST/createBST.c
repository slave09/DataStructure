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

createBST(int *preorder, int nodes){
  struct Node *temp;
  createStack(stk, 100);
  root = createNode(root, preorder[0]);
  temp = root;  

}

int main(){
  int *preorder;
  int nodes;
  printf("Number of nodes :");
  scanf("%d", &nodes);
  preorder = (int *)malloc(nodes*sizeof(int));
  printf("\nEnter preorder traversal\n");
  for(int i = 0; i < nodes; i ++){
    scanf("%d", preorder[i]);
  }
  return 0;
}
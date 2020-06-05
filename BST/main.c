/*
  * Author: Fakhra Najm
  * Email:  fnajm09@gmail.com
  * Topic: Implementation of binarySearchTree
  Operations:
    1. Insert
    2. Search
    3. Inorder
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *left;
  struct Node *right;
  int data;
}*root = NULL;

struct Node * createNode(struct Node * node, int value){
  node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  node->left = node->right = NULL;
  return node;
}

void insert(int value){
  struct Node *node, *tail, *present;
  present = root;
  if(! present){
    present = createNode(node, value);
    root = present;
    return;
  }
  while( present){
    if(present->data > value){
      tail = present;
      present = present->left;
    }
    else if(present->data < value){
      tail = present;
      present = present->right;
    }
    else return;
  }
  if(tail->data > value)
    tail->left = createNode(node, value);
  else
    tail->right = createNode(node, value);
}

// returns the address of passed value

struct Node * search(int value){
  struct Node *present = root;
  while(present){ 
    if(present->data > value)
      present = present->left;
    else if(present->data < value)
      present = present->right;
    else
      return present;
  }
  return NULL;
}

// prints all the elements of binary search tree in a sorted manner.
void inorder(struct Node *root){
  if(root){
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(void){
  insert(20);
  insert(10);
  insert(30);
  insert(5);
  insert(25);
  inorder(root);
  if(search(80))
    printf("\nElement is found\n");
  else
    printf("\nElement not found\n");
  
  return 0;
}
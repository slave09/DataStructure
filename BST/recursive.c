/*
  * Author: Fakhra Najm
  * Email: fnajm09@gmail.com
  * Topic: Recursive implementation code for binary search trees.
  Operations: 
            1. Insert
            2. search
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *left;
  struct Node *right;
  int data;
}*root = NULL;

struct Node * insert(struct Node *node, int value){
  struct Node *temp;
  if(node == NULL){
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = value;
  temp->left = temp->right = NULL;
  return temp;
  }
  if(node->data > value)
  node->left = insert(node->left, value);
  else if(node->data < value)
  node->right = insert(node->right, value);
  return node;
}

void inorder(struct Node *node){
  if(node){
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
  }
}

struct Node * search(struct Node *root, int key){
  if(root){
    if(root->data > key){
      return search(root->left, key);
    }
    else if(root->data < key){
      return search(root->right, key);
    }
    else{
      return root;
    }
  }
  return NULL;
}

int main(){
  struct Node * result;
  root = insert(root,10);
  insert(root,5);
  insert(root,20);
  insert(root,15);
  inorder(root);
  result = search(root, 10); 
  if(result)
  printf("\nelement %d Found\n",result->data);
  else
  printf("\nelement Not found!\n");
  return 0;
}
/*
  Author: Fakhra Najm
  Email:  fnajm09@gmail.com
  Topic: creating AVL tree using rotation

  Operation:
    * createNode
    * insert
    * Inorder
    * LL_Rotation
    * LR_Rotation
    * RR_Rotation
    * RL_Rotation
    * Balance_factor
    * Node_height

*/

#include<stdio.h>
#include<stdlib.h>


struct Node{
  int data;

  struct Node *left;
  struct Node *right;

  int height;

}*root = NULL;


int node_height(struct Node *root);

struct Node * RR_Rotation(struct Node *node){

  struct Node * right_node = node->right;
  struct Node * right_left = right_node->left;

  node->right = right_left;
  right_node->left = node;

  node->height = node_height(node);
  right_node->height = node_height(right_node);

  if(root == node)
    root = right_node;
  
  return right_node;
  
}

struct Node *LL_Rotation(struct Node *node){

  struct Node *left_node = node->left;
  struct Node * left_right = left_node->right;

  left_node->right = node;
  node->left = left_right;

  node->height = node_height(node);
  left_node->height = node_height(left_node);

  if(root == node)
    root = left_node;

  return left_node;
}


struct Node * createNode(struct Node *node, int value){

  node = (struct Node *)malloc(sizeof(struct Node));

  node->data = value;
  node->height = 1;

  node->left = node->right = NULL;

  return node;
}


void Inorder(struct Node *root){
  
  if(root){
    
    Inorder(root->left);
    
    printf("%d ",root->data);
    
    Inorder(root->right);
  }

}


int node_height(struct Node *root){

  int left, right;

  left = root && root->left ? node_height(root->left) : 0;
  right = root && root->right ? node_height(root->right) : 0;

  return left > right ? left+1 : right+1;
}


int Balance_factor(struct Node *node){

  int left, right;

  left = root && root->left ? node_height(root->left) : 0;
  right = root && root->right ? node_height(root->right) : 0; 

  return left - right;
}


struct Node *Rotate(struct Node *node, int BALANCE_FACTOR){
  
  if(BALANCE_FACTOR == 2){

    BALANCE_FACTOR == Balance_factor(node->left);

    if(BALANCE_FACTOR == 1)
      return LL_Rotation(node);

    else if(BALANCE_FACTOR == -1)
      return LR_Rotation(node);

  }

  else if(BALANCE_FACTOR == -2){

    BALANCE_FACTOR == Balance_factor(node->right);

    if(BALANCE_FACTOR == 1)
      return RL_Rotation(node);

    else if(BALANCE_FACTOR == -1)
      return RR_Rotation(node);
  }

  return node;
}


struct Node * insert(struct Node *node, int value){

  struct Node *temp;
  int BALANCE_FACTOR;

  if(node == NULL){
    return createNode(temp, value);
  }

  if(node->data > value)
    node->left = insert(node->left, value);

  else if(node->data < value)
    node->right = insert(node->right, value);

  node->height = node_height(node);

  BALANCE_FACTOR = Balance_factor(node);

  if(BALANCE_FACTOR != 0 || BALANCE_FACTOR != 1 || BALANCE_FACTOR != -1)
    Rotate(node, BALANCE_FACTOR);

  return node;
}


int main(){

  root = insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 50);
  insert(root, 10);
  insert(root, 25);
  insert(root, 5);
  insert(root, 15);
  insert(root, 4);
  insert(root, 28);

  Inorder(root);

  return 0;
}

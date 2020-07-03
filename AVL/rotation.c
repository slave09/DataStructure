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
    * Rotate

*/

#include<stdio.h>
#include<stdlib.h>


struct Node{
  int data;

  struct Node *left;
  struct Node *right;

  int height;

}*root = NULL;

struct Node * LR_Rotation(struct Node *node){
  struct Node *node_left = node->left;
  struct Node *left_right = node_left->right;

  node_left->right = left_right->left;
  node->left = left_right->right;

  left_right->left = node->left;
  left_right->right = node;

  node->height = node_height(node);
  node_left->height = node_height(node_left);
  left_right->height = node_height(left_right);

  if(root == node)
    root = left_right;
  
  return left_right;
}


struct Node *RL_Rotation(struct Node *node){
  struct Node * right_node = node->right;
  struct Node * right_left = right_node->left;


  right_left->left = node;
  right_left->right = right_node;

  if(root == node)
    root = right_left;

    node->height = node_height(node);
    right_node->height = node_height(right_node);
    right_left->height = node_height(right_left);

  return right_left;
}


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


int node_height(struct Node *node){

  int left, right;

  left = node && node->left ? node->left->height : 0;
  right = node && node->right ? node->right->height : 0;

  return left > right ? left+1 : right+1;
}


int Balance_factor(struct Node *node){

  int left, right;

  left = node && node->left ? node->left->height : 0;
  right = node && node->right ? node->right->height : 0; 

  return left - right;
}


struct Node *Rotate(struct Node *node, int BALANCE_FACTOR){
  int bf;
  if(BALANCE_FACTOR == 2){

    bf = Balance_factor(node->left);

    if(bf == 1)
      node = LL_Rotation(node);

    else if(bf == -1)
      node = LR_Rotation(node);
  }

  else if(BALANCE_FACTOR == -2){

    bf = Balance_factor(node->right);

    if(bf == 1)
      node = RL_Rotation(node);

    else if(bf == -1)
      node = RR_Rotation(node);
  }

  return node;
}


struct Node * insert(struct Node *node, int value){

  struct Node *temp = NULL;
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
  insert(root, 28);
  insert(root, 4);
  Inorder(root);
  printf("\n%d", Balance_factor(root));
  return 0;
}

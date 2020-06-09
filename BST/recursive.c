/*
  * Author: Fakhra Najm
  * Email: fnajm09@gmail.com
  * Topic: Recursive implementation code for binary search trees.
  Operations: 
            1. Insert
            2. search
            3. height
            4. Predecessor
            5. Successor
            6. Delete
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *left;
  struct Node *right;
  int data;
}*root = NULL;

struct Node * createNode(struct Node *node, int value){
  node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  node->left = node->right = NULL;
  return node;
}

struct Node * insert(struct Node *node, int value){
  struct Node *temp;
  if(node == NULL){
    return createNode(temp, value);
  }
  if(node->data > value)
  node->left = insert(node->left, value);
  else if(node->data < value)
  node->right = insert(node->right, value);
  return node;
}

// printing binary search tree in sorted order
void inorder(struct Node *node){
  if(node){
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
  }
}

struct Node * search(struct Node *root, int key){
  if(root){
    if(root->data > key)
      return search(root->left, key);
    else if(root->data < key)
      return search(root->right, key);
    else
      return root;
  }
  return NULL;
}

int height(struct Node *root){
  int x, y;
  if(!root) 
    return 0;
  x = height(root->left);
  y = height(root->right);
  return x > y ? x+1 : y+1;
}

struct Node* Predecessor(struct Node *root){
  while(root != NULL && root->right != NULL)
    root = root->right;
  return root;
}

struct Node* successor(struct Node *root){
  while(root != NULL && root->left != NULL)
    root = root->left;
  return root;
}

struct Node *Delete(struct Node *node, int key){
  struct Node *temp;
  if(node == NULL) 
  return NULL;
  if(! node->left && ! node->right){
    if(node == root)
      root = NULL;
    free(node);
    return NULL;
  }
  if(node->data > key)
    node->left = Delete(node->left, key);
  else if(node->data < key)
    node->right = Delete(node->right, key);
  else{
    int left, right;
    left = height(node->left);
    right = height(node->right);
    if( left > right){
      temp = Predecessor(node->left);
      node->data = temp->data;
      node->left = Delete(node->left, temp->data);
    }
    else{
      temp = successor(node->right);
      node->data = temp->data;
      node->right = Delete(node->right, temp->data);
    }
  }
  return node;
}

int main(){
  struct Node * result;
  root = insert(root, 10);
  insert(root, 5);
  insert(root, 20);
  insert(root, 15);
  Delete(root, 15);
  inorder(root);
  result = search(root, 10); 
  if(result)
  printf("\nelement %d Found\n",result->data);
  else
  printf("\nelement Not found!\n");
  return 0;
}
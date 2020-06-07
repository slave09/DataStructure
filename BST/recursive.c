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
            6. delete
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *left;
  struct Node *right;
  int data;
};

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

int height(struct Node *root){
  int x, y;
  if(!root) 
    return 0;
  x = height(root->left);
  y = height(root->right);
  return x > y ? x+1 : y+1;
}

struct Node* Predecessor(struct Node *root){
  while(root && root->right != NULL){
    root = root->right;
  }
  return root;
}

struct Node* successor(struct Node *root){
  while(root && root->left != NULL)
    root = root->left;
  return root;
}

struct Node *delete(struct Node *node, int key){
  struct Node *temp;
  if(node == NULL) return NULL;
  if(! root->left && ! root->right){
    if(node == root)
      root = NULL;
    free(node);
    return NULL;
  }
  if(root->data > key)
  return delete(root->left, key);
  else if(root->data < key)
  return delete(root->right, key);
  else{
    if(height(root->left) > height(root->right)){
      temp = Predecessor(root->left);
      root->data = temp->data;
      root->left = delete(root->left, temp->data);
    }
    else{
      temp = successor(root->right);
      root-data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }
  return node;
}

int main(){
  struct Node *root = NULL;
  struct Node * result;
  root = insert(root,10);
  insert(root,5);
  insert(root,20);
  insert(root,15);
  //delete(root, 15);
  inorder(root);
  result = search(root, 10); 
  if(result)
  printf("\nelement %d Found\n",result->data);
  else
  printf("\nelement Not found!\n");
  return 0;
}
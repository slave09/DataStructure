/*
  * Name  : Fakhra Najm
  * Eamil : fnajm09@gmail.com
  * Topic : Count number of nodes of a binary tree
  *   Total number of nodes
  *   Leaf nodes
  *   Nodes with degree 1
  *   Nodes with degree 2
  *   Nodes with either degree 1 or 2
*/

#include<stdio.h>
#include<stdlib.h>

#include"tree.h"


// returns the total count of nodes in the binarytree 

int nodes(struct Node * root){
  if(root){
    return nodes(root->left_child) + nodes(root->right_child) + 1;
  }
  return 0;
}

// returns the number of leaf nodes i.e. nodes having zero child nodes

int leafNodes(struct Node *root){
  if(root){
    if(! root->left_child && !root->right_child){
      return leafNodes(root->left_child) + leafNodes(root->right_child) + 1;
    }
    else{
      return leafNodes(root->left_child) + leafNodes(root->right_child);
    }
  }
  return 0;
}

// returns the number of nodes having both left child and right child

int binaryNodes(struct Node *root){
  if(root){
    if(root->left_child && root->right_child){
      return binaryNodes(root->left_child) + binaryNodes(root->right_child) + 1;
    }
    return binaryNodes(root->left_child) + binaryNodes(root->right_child);
  }
  return 0;
}

// returns the number of nodes only one child

int end_vertex(struct Node *root){
  if(root){
    if(!root->left_child ^ !root->right_child){
      return end_vertex(root->left_child) + end_vertex(root->right_child) + 1;
    }
    return end_vertex(root->left_child) + end_vertex(root->right_child);
  }
  return 0;
}

// Returns the number of nodes having either or one of left and right child

int nonLeaf(struct Node *root){
  if(root){
    if(root->left_child || root->right_child)
      return nonLeaf(root->left_child) + nonLeaf(root->right_child) + 1;
    return nonLeaf(root->left_child) + nonLeaf(root->right_child);
  }
  return 0;
}

int main(){
  createTree();
  printf("Number of nodes: %d\n", nodes(root));
  printf("Number of leaf nodes: %d\n", leafNodes(root));
  printf("Number of binary nodes: %d\n", binaryNodes(root));
  printf("Number of single nodes: %d\n", end_vertex(root));
  printf("Number of non leaf nodes : %d", nonLeaf(root));
  return 0;
}
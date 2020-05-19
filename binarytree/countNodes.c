/*
  * Name  : Fakhra Najm
  * Eamil : fnajm09@gmail.com
  * Topic : count number of nodes of a tree
*/

#include<stdio.h>
#include<stdlib.h>

#include"tree.h"

int count(struct Node * root){
  if(root){
    return count(root->left_child) + count(root->right_child) + 1;
  }
  return 0;
}

int main(){
  createTree();
  printf("Number of nodes are: %d ", count(root));
  return 0;
}
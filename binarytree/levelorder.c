/*
  * Name  : Fakhra Najm
  * Email : fnajm09@gmail.com
  * Topic : Level order tree traversal using queue
*/

#include<stdio.h>
#include<stdlib.h>

#include"Queue.h"

struct Node * root = NULL;
struct Queue q;

void createTree(){
  createQ(&q, 100);
  struct Node * add, *node;
  int value;
  printf("Enter root Value: ");
  scanf("%d", &value);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = value;
  root->left_child = root->right_child = NULL;
  enqueue(&q, root);
  while(! isEmpty(q)){
    add = dequeue(&q);
    printf("Enter left child of %d: ", add->data);
    scanf("%d", &value);
    if(value != -1){
      node = (struct Node *)malloc(sizeof(struct Node));
      node->data = value;
      node->left_child = node->right_child = NULL;
      add->left_child = node;
      enqueue(&q, node);
    }
    printf("Enter rightt child of %d: ", add->data);
    scanf("%d", &value);
    if(value != -1){
      node = (struct Node *)malloc(sizeof(struct Node));
      node->data = value;
      node->left_child = node->right_child = NULL;
      add->right_child = node;
      enqueue(&q, node);
    }
  }
}

void levelorder(struct Node *root){
  createQ(&q, 100);
  printf("%d ", root->data);
  enqueue(&q, root);
  while(! isEmpty(q)){
    root = dequeue(&q);
    if(root->left_child){
      printf("%d ", root->left_child->data);
      enqueue(&q, root->left_child);
    }
    if(root->right_child){
      printf("%d ", root->right_child->data);
      enqueue(&q, root->right_child);
    }
  }
}

int main(){
  createTree();
  levelorder(root);

}

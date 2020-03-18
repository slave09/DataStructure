/*
  Operations on circularDoublyLinkList
  * 1. Create
  * 2. Display
  * 3. Insert
  * 4. Delete
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node * prev;
  int data;
  struct Node * next;
}* Head ;

struct Node * createNode(int value){
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->prev = node;
  node->data = value;
  node->next = node;
  return node;
}

void createLinkList(int values[], int length){
  Head = createNode(values[0]);
  struct Node * current , *last = Head;
  for (int i = 1; i < length; ++i){
    current = createNode(values[i]);
    last->next = current;
    current->prev = last;
    current->next = Head;
    Head->prev = current;
    last = current;
  }
}

int findLength(struct Node * node){
  int length = 0;
  do{
    length++;
    node = node->next;
  }while(node != Head);
  return length;
}

void  insertHead(struct Node *current, int value){
  current = createNode(value);
  current->next = Head;
  Head->prev = current;
  current->prev = Head->prev;
  current = Head;
}

void insertNode(struct Node * Head, int index, int value ){
  if(index < 0 || index > findLength(Head))
    return;
  if(index == 0){
    if(Head == NULL)
      Head = createNode(value);
    else
      insertHead(Head, value);
  }
  else{
    struct Node *node = createNode(value);
    for (int i = 0; i < index; ++i)
      Head = Head->next;
    node->next = Head->next;
    Head->next->prev = node;
    Head->next = node;
    node->prev = Head;
  }
}

void printList(struct Node * node){
  do{
    printf("%d ", node->data);
    node = node->next;
  }while(node != Head);
  printf("\n");
}

int main(){
  int values[] = {10, 20, 30, 40, 50}; 
  createLinkList(values, 5);
  printList(Head);
  insertNode(Head, 0 , 60);
  printList(Head);
  return 0;
}
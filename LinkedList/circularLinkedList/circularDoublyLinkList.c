/*
  Author : Fakhra najm <fnajm09@gmail.com>
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

void insertHead(struct Node *current, int value){
  current = createNode(value);
  current->next = Head;
  Head->prev->next = current;
  current->prev = Head->prev;
  Head->prev = current;
  Head = current; 
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
    for (int i = 0; i < index-1; ++i)
      Head = Head->next;
    node->next = Head->next;
    Head->next->prev = node;
    Head->next = node;
    node->prev = Head;
  }
}

int removeNode(struct Node * node, int index){
  int removed = -1;
  if(index > findLength(Head) || index < 0)
    return -1;
  if(index == 0){
    node->prev->next = Head->next;
    Head = Head->next;
    Head->prev = node->prev;
    removed = node->data;
    free(node);
  }
  else{
    for (int i = 0; i < index; ++i)
      node = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    removed = node->data;
    free(node); 
  }
  return removed;
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
  printf("created link list\n");
  printList(Head);
  insertNode(Head, 0 , 60);
  printf("LinkList after insertion\n");
  printList(Head);
  printf("link list after deletion of node having value %d\n", removeNode(Head,0));
  printList(Head);
  return 0;
}
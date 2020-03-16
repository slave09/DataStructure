#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node * next;
}*Head;

struct Node * createCircularNode(int value){
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  node->next = node;
  return node;
}

void createLinkList(int values[], int length){
  struct Node *last, *current;
  Head = createCircularNode(values[0]);
  last = Head;
  for (int i = 1; i < length; ++i)
  {
    current = createCircularNode(values[i]);
    last->next = current;
    current->next = Head;
    last = current;
  }
}

int calculateLength(struct Node * head){
  int length = 0 ;
  do{
    length++;
    head = head->next;
  }while(head != Head);
  return length;
}

void PrintList(struct Node * head){
  head = Head;
  do{
    printf("%d ", head->data);
    head = head->next;
  }while(head != Head);
  printf("\n");
}

/**
*inserts a new node in the linkList
@param pointer to the Head of the circular LinkList
@param index at which new node to be inserted
@param value to be inserted inside the new node
*/

void insertValue(struct Node * head, int index, int value){
  struct Node * node = createCircularNode(value);
  if(index < 0 || index > calculateLength(Head))
    return;
  if(index == 0){
    if(head == NULL){
      head = node;
    }
    else{
      while(head->next != Head)
        head = head->next;
      node->next = Head;
      head->next = node;
      Head = node;
    }
  }
  else{
    for (int i = 0; i < index-1; i++)
      head = head->next;
    node->next = head->next;
    head->next = node;
  }
}

int main(){
  int values[] = {1, 2, 3, 4, 5};
  createLinkList(values, 5);
  PrintList(Head);
  insertValue(Head, 0, 6);
  PrintList(Head);
  return 0;
}
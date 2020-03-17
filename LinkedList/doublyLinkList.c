/*
  Operations on doubly LinkList
  1. Create
  2. Display
  3. calculateLength
  4. insert
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node * prev;
  int data;
  struct Node * next;
}*Head ;

struct Node * CreateNode(int value){
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->prev = NULL;
  node->data = value;
  node->next = NULL;
  return node;
}

void CreateLinkList(int values[], int length){
  Head = CreateNode(values[0]);
  struct Node *current, *last = Head;
  for (int i = 1; i < length; ++i)
  {
    current = CreateNode(values[i]);
    last->next = current;    
    current->prev = last;
    last = current;
  }
}

int calculateLength(struct Node * Head){
  int length = 0;
  while(Head){
    length ++;
    Head = Head->next;
  }
  return length;
}

void InsertNode(struct Node * Head, int index, int value){
  struct Node * node = CreateNode(value);
  if(index < 0 || index > calculateLength(Head))
    return;
  if(index == 0){
    if (Head == NULL)
      Head = node;
    else{
      node->next = Head;
      Head->prev = node;
      Head = node;
    }
  }
  else{
    for (int i = 0; i < index-1; ++i)
      Head = Head->next;
    node->prev = Head;
    node->next = Head->next;
    if(Head->next)
      Head->next->prev = node;
    Head->next = node;
    Head = node;
  }
}

void PrintList(struct Node * Head)
{
  while(Head != NULL){
    printf("%d ", Head->data);
    Head = Head->next;
  }
  printf("\n");
}

int main(){
  int values[] = {1, 2, 3, 4, 5};
  CreateLinkList(values, 5);
  PrintList(Head);
  printf("length:%d\n", calculateLength(Head) );
  InsertNode(Head, 0, 6);
  PrintList(Head);
  return 0;
}
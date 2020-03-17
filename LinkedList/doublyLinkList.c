/*
  Operations on doubly LinkList
  1. Create
  2. Display
  3. calculateLength
  4. insert
  5. Delete
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

int removeHead(struct Node * current){
  Head = Head->next;
  if(Head)
    Head->prev = NULL;
  int value = current->data;
  free(current);
  return value;
}

int removeValue(struct Node * Head, int index){
  struct Node * current ;
  int value = -1;
  if(index < 0 || index > calculateLength(Head))
    return -1;
  if(index == 0){
   value = removeHead(Head);
  }

  else{
    for (int i = 0; i < index; ++i)
      Head = Head->next;
    value = Head->data;
    Head->prev->next = Head->next;
    if(Head->next)
     Head->next->prev = Head->prev;
    free(Head);
  }
  return value;
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
  InsertNode(Head, 5, 6);
  PrintList(Head);
  printf("value of the deleted node:%d\n", removeValue(Head, 0));
  PrintList(Head);
  return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
  int data;
  struct Node * next;
}*first = NULL , *second = NULL , *third = NULL;

struct Node * createNode(int value)
{
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  node->next = NULL;
  return node;
}

struct Node * createFirstList(int values[], int length)
{
 first= createNode(values[0]);
 struct Node *current ,*last = first;
 for(int i = 1; i < length; i++){
  current = createNode(values[i]);
  last->next = current;
  last = current;
 }
}

struct Node * createSecondList(int values[], int length)
{
 second = createNode(values[0]);
 struct Node *current ,*last = second;
 for(int i = 1; i < length; i++){
  current = createNode(values[i]);
  last->next = current;
  last = current;
 }
}

void ShowList(struct Node * head)
{
  while(head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

struct Node * mergeData(struct Node *first, struct Node *second)
{
  struct Node *last = NULL;
  if(first->data > second->data){
    third = last = second ;
    second = second->next;
    last->next = NULL;
  }
  else{
    third = last = first;
    first = first->next;
    last->next = NULL;
  }
  while(first && second)
  {
    if(first->data > second->data){
      last->next = second;
      last = second;
      second = second->next;
      last->next = NULL;
    }
    else{
      last->next = first;
      last = first;
      first = first->next;
      last->next = NULL;
    }
  }
  if(first)
    last->next = first;
  else
    last->next = second;
  return third;
}

int main()
{
  int values1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int values2[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  createFirstList(values1, 10);
  createSecondList(values2, 10);
  printf("First Link list:\n");
  ShowList(first);
  printf("Second Link list:\n");
  ShowList(second);
  mergeData(first, second);
  printf("after merge new Link list formed:\n");
  ShowList(third);
}
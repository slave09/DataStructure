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

struct Node * createLinkList(int values[], int length)
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

struct Node * joinTwoList(struct Node * head , struct Node * second)
{
  third = first;
  while(first->next != NULL)
  {
    first = first->next;
  }

  first->next = second;
  return third;
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

int main()
{
  int values1[] = {2, 4, 6, 8, 10};
  int values2[]= {1,3,5};
  createLinkList(values1, 5);
  createSecondList(values2, 3);
  ShowList(first);
  ShowList(second);
  joinTwoList(first, second);
  ShowList(third);
}
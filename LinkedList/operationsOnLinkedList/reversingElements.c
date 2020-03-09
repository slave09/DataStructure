#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
  struct Node * next;
}*head = NULL , *last = NULL ;

struct Node * createNode(int value)
{
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  node->next = NULL;
  return node;
}

void createLinkList(int value)
{
  struct Node * node;
  node = createNode(value);
  if(head == NULL)
  {
    head = last = node ; 
  }
  else
  {
    last->next = node ; 
    last = node;
  }
}

void ShowList(struct Node * head)
{
  while(head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
}

struct Node * reverseLinkList(struct Node *node, int nodes)
{
  int i = 0;
  int *values = (int *)malloc(nodes*sizeof(int));
  while(node != NULL)
  {
    values[i++] = node->data;
    node = node->next;
  }

  i--; node = head;
  while(node){
    node->data = values[i--];
    node = node->next;
  }

  return node;
}

int main()
{
  int nodes,value;
  printf("Enter number of nodes :\n");
  scanf("%d", &nodes);
  printf("enter all values of list\n");
  for(int i = 0; i < nodes; i++)
  {
    scanf("%d", &value);
    createLinkList(value);
  }
  ShowList(head);
  reverseLinkList(head , nodes);
  printf("\n");
  ShowList(head);
  return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*head=NULL,*last=NULL;

struct Node * createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node ;
}

void createLinkList(int value)
{
    struct Node *node;
    node = createNode(value);
    if( head == NULL)
        head = last = node ;
    else{
        last->next = node;
        last = node;
    }
}

void InsertSort(int value)
{
  struct Node * node = createNode(value);
  struct Node * pointer = head,*prev_node;
  if(head->data > value){
    node->next = head;
    head = node;
  }

  else {
    while(pointer && pointer->data < value){
      prev_node = pointer;
      pointer = pointer->next;
    }

  node->next = prev_node->next;
  prev_node->next = node;
  }
  
}

void showList(int nodes)
{
  while(head){
    printf("%d ", head->data );
    head = head->next;
  }
}

int main()
{
    int nodes,value;
    printf("Enter number of nodes : \n" );
    scanf("%d", &nodes);
    printf("\nEnter all elements of the list:\n");
    for( int i = 0; i < nodes; i++){
        scanf("%d", &value);
        createLinkList(value);
    }

  InsertSort(10);
  printf("\n");
  showList(nodes);
  return 0;
}
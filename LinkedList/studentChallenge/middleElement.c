/*
  finding middle element of a linked list
  *Here i'm taking circular doubly linkList
  *i am taking two pointers one is pointing on head and another on the previous to the head
  *then moving head pointer to next and last pointer to previous of it
  *the idea is that when head pointer becomes equal to last pointer then it is the middle node
  *when head pointer and last pointer are side by side then there are even number of nodes and hence no middle node 
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node * prev;
  int data;
  struct Node * next;
}*head;

struct Node * createNode(int value){
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->prev = node;
  node->data = value;
  node->next = node;
  return node;
}

void createLinkList(int values[], int length){
  head = createNode(values[0]);
  struct Node * current, *last = head;
  for (int i = 1; i < length; ++i){
    current = createNode(values[i]);
    last->next = current;
    current->next = head;
    current->prev = last;
    head->prev = current;
    last = current;
  }
}

int findMid(struct Node * Head, struct Node *last){
 do{
    Head = Head->next;
    last = last->prev;
    if(Head == last)
      return Head->data;
 }while(Head != head);
 return -1;
}

void printList(struct Node * node){
  do{
    printf("%d ", node->data );
    node = node->next;
  }while(node != head);
  printf("\n");
}

int main(){
  int nodes;
  printf("Enter number of nodes:\n");
  scanf("%d", &nodes);
  int *values = (int *)malloc(nodes*sizeof(int));
  printf("Enter all elements to be inserted in nodes\n");
  for (int i = 0; i < nodes; ++i)
    scanf("%d", &values[i] );
  createLinkList(values, nodes);
  printf("created LinkList is\n");
  printList(head);
  if(findMid(head, head->prev) != -1)
    printf("Middle element:%d ",findMid(head, head->prev) );
  else
    printf("Number of nodes is even i.e. no middle element\n");
  return 0;
}
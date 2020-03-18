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
  node->prev = NULL;
  node->data = value;
  node->next = NULL;
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

int findMid(struct Node * head, struct Node *last){
  while(head->next != last->prev || head->next != last){
    head = head->next;
    last = last->prev; 
  }
  if(head->next == last->prev )
    return head->data;
  else 
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
  int values[5];
  printf("Number of nodes are : 5\n");
  printf("Enter all elements to be inserted in nodes\n");
  for (int i = 0; i < 5; ++i)
    scanf("%d", &values[i] );
  createLinkList(values, 5);
  printf("created LinkList is\n");
  printList(head);
  printf("Middle node value = %d\n",findMid(head,head->prev) );
  return 0;
}
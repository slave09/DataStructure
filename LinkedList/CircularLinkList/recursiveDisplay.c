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

void PrintList(struct Node * head){
 static int round = 0;
 if(head != Head || round == 0){
  round = 1;
  printf("%d ", head->data );
  PrintList(head->next);
 }
 round = 0;
}

int main(){
  int values[] = {1, 2, 3, 4, 5};
  createLinkList(values, 5);
  PrintList(Head);
  return 0;
}
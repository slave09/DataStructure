#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node * next;
}*Head;

/**
* creates the circular node
* @param the value to be inserted into the node
* @return node pointer to created node
*/
struct Node * createCircularNode(int value){
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  node->next = node;
  return node;
}
/**
* creates the circular linkList
* @param value to be inserted into nodes
* @param length of given list of values
*/
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

/**
* prints values of the linkedlist recursively.
* @param pointer to the head of the list .
* if the last becomes head then the linkList has completed one round.
* after one round all the list would have been printed and we have to stop. 
*/

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
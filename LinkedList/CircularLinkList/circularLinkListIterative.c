/*
      operations on circular linkList
      1. create
      2. display
      3. find length
      4. insert 
      5. delete
*/


#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node * next;
}*Head;

/*
  * creates the circular node for a linkList
  * @param value to be inserted into the node
  * @return node pointer to the created node
*/

struct Node * createCircularNode(int value){
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  node->next = node;
  return node;
}

/*
  * creates the circular LinkList
  * @param values from which linkList is to be created
  * @param length of the given list of values
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

/*
  * calculates the length of the CircularlinkList
  * @param head pointer to the Head of the circularLinkList
  * @return the length of the circularLinkList
*/

int calculateLength(struct Node * head){
  int length = 0 ;
  do{
    length++;
    head = head->next;
  }while(head != Head);
  return length;
}

/*
  * prints the values of circular LinkList
  * @param head pointer to the Head of the linkList
*/

void PrintList(struct Node * head){
  head = Head;
  do{
    printf("%d ", head->data);
    head = head->next;
  }while(head != Head);
  printf("\n");
}

/**
  * inserts a new node in the linkList
  * @param pointer to the Head of the circular LinkList
  * @param index at which new node to be inserted
  * @param value to be inserted inside the new node
*/

void insertValue(struct Node * head, int index, int value){
  struct Node * node = createCircularNode(value);
  if(index < 0 || index > calculateLength(Head))
    return;
  if(index == 0){
    if(head == NULL){
      head = node;
    }
    else{
      while(head->next != Head)
        head = head->next;
      node->next = Head;
      head->next = node;
      Head = node;
    }
  }
  else{
    for (int i = 0; i < index-1; i++)
      head = head->next;
    node->next = head->next;
    head->next = node;
  }
}

/*
  * removes the node from the circular LinkList
  * @param current pointer to the Head of the linkList
  * @param Prev_node pointer to the previous of the current node pointer
  * @param index from which node is to be deleted
  * @return the value of the deleted node.
*/

int removeNode(struct Node * current, struct Node * prev_node, int index){
  int value = -1;
  if(index > calculateLength(Head) || index < 0)
    return -1;
  if(index == 0){
    while(current->next != Head)
      current = current->next;
    current->next = Head->next;
    value = Head->data;
    free(Head);
    Head = current->next;
  }
    else{
      for (int i = 0; i < index; ++i){
        prev_node = current;
        current = current->next;
      }
      prev_node->next = current->next;
      value = current->data;
      free(current);
    }
  return value;
}

int main(){
  int values[] = {1, 2, 3, 4, 5};
  createLinkList(values, 5);
  printf("original linkList:\n");
  PrintList(Head);
  insertValue(Head, 0, 6);
  printf("The new linkList:\n");
  PrintList(Head);
  printf("deleted value:%d\n",removeNode(Head, NULL, 0));
  printf("LinkedList Restored\n");
  PrintList(Head);
  return 0;
}
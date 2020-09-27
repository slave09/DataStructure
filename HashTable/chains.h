#ifndef chains_h
#define chains_h

#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node * createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node ;
}

void InsertSort(struct Node *head, int value)
{
  struct Node * node = createNode(value);
  struct Node * pointer = head,*prev_node;
  if(head == NULL){
    head = node;
  }
  if((head)->data > value){
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

struct Node * searchList(struct Node * head , int value)
{
	while(head != NULL){
		if(value == head->data)
			return head;
		else
			head = head->next;
	}
	return NULL;
}

#endif
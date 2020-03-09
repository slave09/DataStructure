#include<stdio.h>
#include<stdlib.h>

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


void reverseLinkList(struct Node *node)
{
	struct Node * current = NULL , * prev_node = NULL;
	while(node != NULL){
		prev_node = current;
		current = node;
		node = node->next;
		current->next = prev_node;
	}
	head = current;

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
  reverseLinkList(head);
  printf("\n");
  ShowList(head);
	return 0;
}
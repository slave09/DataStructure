#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head = NULL;

struct Node * createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}
void CreateLinkList(int values[], int length)
{
    Head = createNode(values[0]);
    struct Node * current, *last = Head;
    for (int  i = 1; i < length; i++) {
      current = createNode(values[i]);
      last->next = current;
      last = current;
    }
}

void PrintList(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void CreateLoop(struct Node * head)
{
    struct Node *first, *last;
    first = head->next;
    while(head->next )
    {
        head = head->next;
    }
    last = head;
    last->next = first;
}

int detectLoop(struct Node *head )
{
    struct Node *current , *last;
    current = last = head;
    do{
        current = current->next;
        last = last->next;
        last = last? last->next:last;
    }while(current && last && current != last);
    if(current == last){
    return 1;
    }
    else{
    return 0;
    }
}

int main()
{
    int values[] = {1, 6, 4, 7, 8, 5, 3, 2, 9, 10};
    CreateLinkList(values, 10);
    PrintList(Head);
    CreateLoop(Head);
    if(detectLoop(Head) == 1)
    {
        printf("loop detected!!");
    }
    else{
        printf("loop not detected!!");
    }
    
    return 0;
}
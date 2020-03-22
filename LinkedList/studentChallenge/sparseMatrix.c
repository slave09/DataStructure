#include<stdio.h>
#include<stdlib.h>

struct Node{
  int column;
  int value;
  struct Node *next;
}*head = NULL, *last = NULL;

// returns a linked list node
struct Node * createNode(int col, int val){
  // create a linked list node and store its location into a pointer
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));

  // assign values to the using pointer of the node
  node->column = col;
  node->value = val;
  node->next = NULL;
  // return created node's pointer
  return node;
}

// inserts values add the end of linked list
void insertNode(int col, int val){
  // store pointer of the created node in head if head is null
  if(head == NULL){
    head = last = createNode(col, val);
  }
  else {
    // create a new node and store its pointer
    struct Node * node = createNode(col, val);
    // make last node point to newly created node
    last->next = node;
    // set newly created node as last node
    last = node;
  }
}

struct Node * createSparse(int row) {
  int col,val;

  // make an array of size equal to row size, which will hold pointer to linked list
  struct Node *rows = (struct Node *)malloc(row * sizeof(struct Node *));
  
  // loop for all elements
  for(int i = 0 ; i < row ; i++) {
    // take the size of column
    printf("Enter number of columns at row: %d\n", i);
    scanf("%d", &col);
    /*
      scan each element at each row
      this loop will end when all values of a row has been read
      for each row a new linked list will be made
      when a linked list becomes complete, the of that list will be
      stored to the row array.
    */
    for (int j = 0; j < col; ++j) {
      printf("Enter value");
      // take the new value
      scanf("%d", &val);
      // insert into the linked list
      // j will be the column number
      insertNode(j,val);
    }
    /*
      rows is array of struct Node*, so each box of array contains
      val, col and next
      as next should point to the head of the linked list
      so we store the head of the created linked list
      val and col will be blank
      array just hold the head of the linked list
    */
    rows[i].next = head; 
    head = NULL; // reset value to null, to create next linked list
    last = NULL; // reset value to null, to create next linked list
  }
  return rows;
}

// print linked list
void printll(struct Node* head) {
  while(head != NULL) {
    printf("%d", head ->value);
    head = head -> next;
  }
}

// iterate over the array and find the head of each linked list
void printsparse(struct Node *sparse, int row) {
  for(int i = 0; i < row; i++) {
    printll(sparse[i].next);
    printf("\n");
  }
}

int main() {
  int row;
   // take number of rows
  printf("Enter number of rows\n");
  scanf("%d",&row);
  struct Node * sparse =  createSparse(row);
  printsparse(sparse, row);
  return 0;
}
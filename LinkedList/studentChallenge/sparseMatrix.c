/*
  Author : Fakhra Najm, 
  Email  : fnajm09@gmail.com
  * creating sparse matrix using LinkedList
  * the idea is to create an array containing matrix's rows as elements
  * each row points to a node of a linkedList
  * each node of the link list will have column index and value non-zero element for that row
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int column;
  int value;
  struct Node *next;
};

struct sparse{
  struct sparse * row;
  struct Node *node;
};

struct Node * createNode(struct sparse *matrix, int rows, int cols, int values){
  struct Node *last = matrix->row[rows].node;
  if(matrix->row[rows].node == NULL){
   matrix->row[rows].node = (struct Node *)malloc(sizeof(struct sparse));
   matrix->row[rows].node->column = cols;
   matrix->row[rows].node->value = values;
   matrix->row[rows].node->next = NULL;
   last = matrix->row[rows].node;
  }
  else{
    last->next = matrix->row[rows].node;
    matrix->row[rows].node->column = cols;
    matrix->row[rows].node->value = values;
    matrix->row[rows].node->next = NULL;
    last =  matrix->row[rows].node;
  }
  return matrix->row[rows].node;
}

void createSparse(struct sparse *matrix, int index){
  int x,rows,cols,values;
  matrix->row = (struct sparse *)malloc(index*sizeof(struct sparse));
  printf("Enter number of non-zero elements\n");
  scanf("%d", &x);
  printf("Enter all non-zero elements and indices: \n");
  for(int i = 0; i < x; i++){
    scanf("%d%d%d", &rows, &cols, &values);
    createNode(matrix, rows, cols, values );
  }
}

int main(){
  int rows,cols;
  struct Sparse *matrix;
  matrix = (struct sparse * )malloc(sizeof(struct sparse));
  printf("Enter dimension:\n");
  scanf("%d",&rows,&cols);
  createSparse(&matrix,rows);

  return 0;
}
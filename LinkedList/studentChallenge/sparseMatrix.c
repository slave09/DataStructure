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
  int values;
  struct Node * next;
};

struct sparse{
  int * index;
  struct Node *node ;
};

struct Node * createNode(struct sparse *matrix, int row, int col, int element){
  matrix->node = (struct Node *)malloc(sizeof(struct Node));
  node->col = column;
  node->element = value;
  node->next = NULL;
  return node;
}

void createSparse(struct sparse *matrix){
 int elements, row, col, element;
 printf("Enter number oof non-zero elements\n");
 scanf("%d", &elements);
 printf("Enter all non-zero elements along with its indices\n");
 for (int i = 0; i < elements; ++i){
   scanf("%d%d%d", &row , &col , &element);
   createNode(&matrix, row, col, element);
 }
}

int main(){
  struct sparse matrix;
  int rows,cols;
  printf("Enter dimension of the sparse matrix\n");
  scanf("%d%d", &rows, &cols);
  matrix.index = (int *)malloc(rows*sizeof(int));
  for (int i = 0; i < rows; ++i)
    matrix.index[i] = i;
  createSparse(&matrix);
  return 0;
}
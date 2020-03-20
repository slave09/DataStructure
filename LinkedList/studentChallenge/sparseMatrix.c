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
  struct Node * next;
};

struct sparse{
  int * index;
  struct Node *node ;
};

void createSparse(struct sparse *matrix, int rows, int cols){
  int elements,position;
  matrix->index = (int *)malloc(rows*sizeof(int));
  printf("Enter number of nonzero elements\n");
  scanf("%d", &elements);
  for(int i = 0; i < rows; ++i)
    matrix->index[i] = i;
  printf("Enter all nonzero elements of the sparse matrix\n");
  for(int i = 0; i < elements; i++){
    scanf("%d",&position )
    if(position == matrix->index[i]){
      scanf("%d%d", &matrix->node->column, &matrix->node->value);
    }
  }
}

int main(){
  struct sparse matrix;
  int rows, cols;
  printf("Enter dimension of the sparse matrix:\n");
  scanf("%d%d", &rows, &cols);
  createSparse(&matrix, rows, cols);
  return 0;
}
/*
  Author: Fakhra Najm
  Email: fnajm09@gmail.com

  Topic: Inplace Max Heap Creation

  Operation:
    * CreateHeap
    * Insert
    * Delete
    * Print
*/

#include <stdio.h>
#include <stdlib.h>

void CreateHeap(int size);
void Insert(int index);
void Print(int size);
int Delete(int last_index);
void swap(int *parent, int *child);

int * heap;
int main()
{
  int size;

  printf("Enter size of Max heap: ");
  scanf("%d", &size);

  CreateHeap(size);
  printf("%d is deleted\n",Delete(size));
  Print(size);

  return 0;
}

/*
  Inserts a value inside the heap from right to left 
  @param heap array of values
  @param index index of the value to be inserted
*/

void Insert(int index)
{
  int i = index, temp = heap[index];

  while (i > 1 && temp > heap[i / 2])
  {
    heap[i] = heap[i / 2];
    i /= 2;
  }

  heap[i] = temp;
}

/*  
  * Creates Heap of provided array
  * @param heap array of values
  * @param size of the array

*/
void CreateHeap(int size)
{
  heap = (int *)malloc(sizeof(int) * (size + 1));
  heap[0] = 0;
  printf("Enter node values: ");
  for (int i = 1; i <= size; i++)
    scanf("%d", &heap[i]);
  for (int i = 2; i <= size; i++)
    Insert(i);
}

/*
  * Prints the Heap
  * @param heap created array of heap
  * @param size is the size of the Max heap 
*/

void Print(int size)
{
  for (int i = 1; i <= size; i++)
    printf("%d ", heap[i]);
  printf("\n");
}

/*
  * Deletes the root of the heap
  * @param heap array of heap
  * @param last_index index of the last element of the complete binary tree
*/

int Delete(int last_index)
{
  int x, i = 1, j = i*2,deleted_val=heap[1];
  heap[i] = heap[last_index];
  heap[last_index] = deleted_val;
  while ( j < last_index -1)
  {
    // compare children of the parent node
    if (heap[j + 1] > heap[j])
      j = j + 1;
    // swap root with child if child is greater than root
    if (heap[i] < heap[j])
    {
      swap(&heap[i], &heap[j]);
      i = j;
      j = 2*i;
    }
    else
      break;
    
  }
  return deleted_val;

}

void swap(int *parent, int *child)
{
  int temp;
  temp = *parent;
  *parent = *child;
  *child = temp;
}
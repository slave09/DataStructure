/*
  Author: Fakhra Najm
  Email: fnajm09@gmail.com

  Topic: Inplace Max Heap Creation

  Operation:
    * Insert
    * CreateHeap
    * Print
*/

#include <stdio.h>
#include <stdlib.h>


void CreateHeap(int heap[], int size);
void Insert(int heap[], int n);
void Print(int heap[], int size);

int main()
{
  int size, *heap;

  printf("Enter size of Max heap: ");
  scanf("%d", &size);

  heap = (int *)malloc(sizeof(int) * (size + 1));

  CreateHeap(heap, size);
  Print(heap, size);

  return 0;
}

/*
  Inserts a value inside the heap from right to left 
  @param heap array of values
  @param index index of the value to be inserted
*/

void Insert(int heap[], int index)
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
void CreateHeap(int heap[], int size)
{
  heap[0] = 0;
  printf("Enter node values: ");
  for (int i = 1; i <= size; i++)
    scanf("%d", &heap[i]);
  for (int i = 2; i <= size; i++)
    Insert(heap, i);
}

/*
  * Prints the Heap
  * @param heap created array of heap
  * @param size is the size of the Max heap 
*/

void Print(int heap[], int size)
{
  for (int i = 1; i <= size; i++)
    printf("%d ", heap[i]);
  printf("\n");
}
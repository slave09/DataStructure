/*
  Author: Fakhra Najm
  Email: fnajm09@gmail.com
  
  Topic: Creation of max heap by heapify
*/

#include <stdio.h>
#include <stdlib.h>

int *__HEAP;
int HEAP_SIZE;
void heapify();

int main()
{

  scanf("%d", &HEAP_SIZE);
  heapify();
  for (int i = 1; i <= HEAP_SIZE; i++)
  {
    printf("%d ", __HEAP[i]);
  }
  printf("\n");

  return 0;
}

void heapify()
{

  int index = HEAP_SIZE / 2, i;
  __HEAP = (int *)malloc(sizeof(int) * (HEAP_SIZE + 1));
  __HEAP[0] = 0;
  for (int i = 1; i <= HEAP_SIZE; i++)
    scanf("%d", &__HEAP[i]);
  i = 2 * index;
  while(index < HEAP_SIZE ){
    if (__HEAP[index * 2] < __HEAP[index * 2 + 1])
    {
      i = i + 1;
    }
    if (__HEAP[index] < __HEAP[i])
    {
      int temp = __HEAP[index];
      __HEAP[index] = __HEAP[i];
      __HEAP[i] = temp;
    }
    index *= 2;
  }
}
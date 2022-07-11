/*
	Author Fakhra Najm
	Email fnajm09@gmail.com
	***********************
	* Implementation of DEQueue using array
*/


#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int size;
	int front;
	int rear;
	int *items;
};

void createQ(struct Queue *queue){
	queue->size = 10;
	queue->front = -1;
	queue->rear = -1;
	queue->items = (int *)malloc(queue->size*sizeof(int));
}

int isEmpty(struct Queue *queue){
	if(queue->front == queue->rear)
		return 1;
	return 0;
}

int isFull(struct Queue *queue){
	if(queue->rear == queue->size-1)
		return 1;
	return 0;
}

void enqueueFront(struct Queue *queue, int value){
	if(isFull(queue))
		printf("Queue is full\n");
	else if(queue->front == -1){
		queue->front ++;
		queue->items[queue->front] = value;
	}
	else{
		queue->items[queue->front] = value;
		queue->front --;
	}
}

void enqueueRear(struct Queue *queue, int value){
	if(isFull(queue))
		printf("Queue is full\n");
	else{
		queue->rear ++;
		queue->items[queue->rear] = value;
	}
}

int dequeueFront(struct Queue *queue){
	int value = -1;
	if(isEmpty(queue))
		return value;
	queue->front ++;
	value = queue->items[queue->front];

	return value;
}

int dequeueRear(struct Queue *queue){
	if(isEmpty(queue))
		return -1;
	int value = queue->items[queue->rear];
	queue->rear --;
	return value;
}

int main(){
	struct Queue queue;
	createQ(&queue);
	enqueueRear(&queue, 10);
	enqueueRear(&queue, 20);
	enqueueRear(&queue, 30);
	enqueueRear(&queue, 40);
	enqueueRear(&queue, 50);
	printf("%d ",dequeueFront(&queue));
	printf("%d ",dequeueRear(&queue));
	printf("%d ",dequeueRear(&queue));
	printf("%d ",dequeueRear(&queue));
	printf("%d ",dequeueRear(&queue));
	enqueueFront(&queue, 60);
	printf("%d\n",dequeueFront(&queue));
	enqueueFront(&queue, 70);
	printf("%d\n",dequeueFront(&queue));
	return 0;
}
/*
	*	Author : Fakhra Najm
	*	EMail  : fnajm09@gmail.com
	* code for DoubleEndedQueue 
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*front = NULL, *rear = NULL;

/*
	* inserts value in queue using rear pointer
	* @param value to be inserted
*/

void enqueueRear(int value){
	struct Node *queue = (struct Node*)malloc(sizeof(struct Node));
	if(queue == NULL)
		printf("queue is full\n");
	else{
		queue->data = value;
		queue->next = NULL;
		if(front == NULL)
			front = rear = queue;
		else{
			rear->next = queue;
			rear = queue;
		}
	}
}

/*
	* inserts value in the queue using front pointer
	* @param value to be inserted
*/

void enqueueFront(int value){
	struct Node * queue = (struct Node *)malloc(sizeof(struct Node));
	if(queue == NULL)
		printf("Queue is full\n");
	else{
		queue->data = value;
		if(front == NULL){
			front = rear = queue;
			queue->next = NULL;
		}
		else{
			queue->next = front;
			front = queue;
		}
	}
}

/*
	* deletes the front of queue using front pointer
	* @return deleted value
*/

int frontDequeue(){
	int value = -1;
	if(front == rear)
		printf("queue is empty\n");
	else{
		struct Node *queue = front;
		front = front->next;
		value = queue->data;
		free(queue);
	}
	return value;
}

/*
	* deletes value from rear pointer
	* @param deleted value
*/


void printQ(){
	struct Node * queue = front;
	while(front){
		printf("%d ",queue->data );
		queue = queue->next;
	}
	printf("\n");
}

int main(){ 
	enqueueRear(10);
	enqueueRear(20);
	enqueueRear(30);
	enqueueRear(40);
	enqueueFront(50);
	enqueueFront(60);
	enqueueFront(70);

	return 0;
}
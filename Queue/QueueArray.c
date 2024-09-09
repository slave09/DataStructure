/*
	* Author Fakhra Najm
	* EMail  fnajm09@gmail.com

	Implementation of Queue using Array
	* 1. createQ
	* 2. enqueue
	* 3. dequeue
	* 4. printQ
*/

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int size;
	int front; // index pointer to front end
	int rear;  // index pointer to rear end
	int *items; 
};

/*
	* creates and initialize the members of queue
	* @param q pointer to the Queue
*/

void createQ(struct Queue *q){
	printf("Enter size of the queue:\n");
	scanf("%d", &q->size);
	q->front = q->rear = -1;
	q->items = (int *)malloc(q->size*sizeof(int));
}

/*
	* inserts the passed value in the queue
	* @param q pointer to the queue
	* @param value to be inserted
*/

void enqueue(struct Queue *q, int value){
	if(q->rear == q->size-1)
		printf("Queue is full\n");
	else{
		q->rear ++;
		q->items[q->rear] = value;
	}
}

/*
	* deletes the front element from queue
	* @param q pointer to the Queue
	* @return deleted value
*/

int dequeue(struct Queue *q){
	int value = -1;
	if(q->front == q->rear)
		printf("Queue is empty\n");
	else{
		q->front ++;
		value = q->items[q->front]; 
	}
	return value;
}

/*
	* prints the elements of Queue
*/

void printQ(struct Queue q){
	for (int i = q.front+1; i <= q.rear; ++i)
		printf("%d ", q.items[i]);
	printf("\n");
}

int main(){
	struct Queue q;
	createQ(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	printQ(q);
	printf("%d\n",dequeue(&q));
	printQ(q);
	return 0;
}

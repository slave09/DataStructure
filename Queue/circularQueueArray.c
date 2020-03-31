/*
	* Author Fakhra Najm
	* EMail  fnajm09@gmail.com

	OPerations on circular queue
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
	q->front = q->rear = 0;
	q->items = (int *)malloc(q->size*sizeof(int));
}

/*
	* inserts the passed value in the circular queue
	* @param q pointer to the que
	* @param value to be inserted
*/

void enqueue(struct Queue *q, int value){
	if((q->rear+1)%q->size == q->front)
		printf("Queue is full\n");
	else{
		q->rear = (q->rear+1)%q->size;
		q->items[q->rear] = value;
	}
}

/*
	* deletes the first inserted element from queue
	* @param q pointer to the Queue
	* @return value deleted
*/

int dequeue(struct Queue *q){
	int value = -1;
	if(q->front == q->rear)
		printf("Queue is empty\n");
	else{
		q->front = (q->front+1)%q->size;
		value = q->items[q->front]; 
	}
	return value;
}

/*
	* prints the elements of circularQueue
	* @param q name of created Queue 
*/

void printQ(struct Queue q){
	int i = q.front+1;
	do{
		printf("%d ",q.items[i] );
		i = (i+1)%q.size;
	}while(i != (q.rear+1)%q.size);
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
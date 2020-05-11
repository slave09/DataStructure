//header file for creating tree using queue.

#ifndef Queue_h
#define Queue_h

struct Node
{
	struct Node *left_child;
	int data;
	struct Node *right_child;
};

struct Queue
{
	int size;
	int front; 
	int rear;  
	struct Node **items; 
};

void createQ(struct Queue *q){
	printf("Enter size of the queue:\n");
	scanf("%d", &q->size);
	q->front = q->rear = 0;
	q->items = ( struct Node **)malloc(q->size*sizeof( struct Node *));
}

void enqueue(struct Queue *q, struct Node *value){
	if((q->rear+1)%q->size == q->front)
		printf("Queue is full\n");
	else{
		q->rear = (q->rear+1)%q->size;
		q->items[q->rear] = value;
	}
}

struct Node * dequeue(struct Queue *q){
	struct Node * value = NULL;
	if(q->front == q->rear)
		printf("Queue is empty\n");
	else{
		q->front = (q->front+1)%q->size;
		value = q->items[q->front]; 
	}
	return value;
}

int isEmpty(struct Queue queue){
	return queue.front == queue.rear;
}

#endif
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

struct CircularQueue
{
	int front, rear;
	int capacity;
	int *array;
};

struct CircularQueue* createCircularQueue(int capacity)
{
	struct CircularQueue* queue=(struct CircularQueue*)malloc(sizeof(struct CircularQueue*));
	if(!queue)
	{
		printf("Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	queue->front=queue->rear=-1;
	queue->capacity=capacity;
	queue->array=(int*)malloc(capacity *sizeof(int));
	if(!queue->array)
	{
		printf("Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	return queue;
}

int isFull(struct CircularQueue* queue)
{
	return(queue->front==(queue->rear +1)% queue->capacity);
}

int isEmpty(struct CircularQueue* queue)
{
	return(queue->front==-1);
}

void enqueue(struct CircularQueue* queue,int item)
{
	if(isFull(queue))
	{
		printf("Queue is  Full.Cannot enqueue %d.\n",item);
		return;
	}
	if(isEmpty(queue))
		queue->front=0;
	
	queue->rear=(queue->rear+1)% queue->capacity;
	queue->array[queue->rear]=item;
	printf("%d enqueued to the queue.\n",item);
}

int dequeue(struct CircularQueue* queue)
{
	if(isEmpty(queue))
	{
		printf("Queue is empty.Cannot Dequeue.\n");
		exit(EXIT_FAILURE);
	}
	int item=queue->array[queue->front];
	if(queue->front==queue->rear)
		queue->front=queue->rear=-1;
	else
		queue->front=(queue->front +1)% queue->capacity;
	return item;
}

void display(struct CircularQueue* queue)
{
	if(isEmpty(queue))
	{
		printf("Queue is empty.\n");
		return;
	}
	int i=queue->front;
	printf("Elements in the circular queue are: ");
	do
	{
		printf("%d ",queue->array[i]);
		i=(i+1)%queue->capacity;
	}
	while(i!=(queue->rear +1)%queue->capacity);
	printf("\n");
}
int main()
{
	struct CircularQueue* queue= createCircularQueue(MAX_SIZE);
	
	enqueue(queue,1);
	enqueue(queue,2);
	enqueue(queue,3);
	enqueue(queue,4);
	enqueue(queue,5);
	
	display(queue);
	
	int dequeued= dequeue(queue);
	printf("%d dequeued from the queue.\n",dequeued);
	
	enqueue(queue,6);
	display(queue);
	return 0;
}
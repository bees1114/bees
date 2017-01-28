#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


int queue[SIZE];
int front = 0;
int rear = 0;

int queueFull(int front, int rear) {
	if((front%SIZE) == (rear+1)%SIZE)
		return 1;
	else return 0;
}
int queueNull(int front, int rear) {
	if(front == rear)
		return 1;
	else return 0;
}
void Push(int queue[], int data,int *front ,int *rear) {
	if(!queueFull(*front, *rear))
		queue[(*rear)++%SIZE] = data;
	else
		printf("queue is full\n");
	
}

int Pop(int queue[], int *front, int *rear) {
	if(!queueNull(*front, *rear))
		return queue[(*front)++%SIZE];
	else
		printf("queue is empty\n");
}

int main(void) {
	Push(queue, 1, &front, &rear);
	Push(queue, 2, &front, &rear);
	Push(queue, 3, &front, &rear);
	Push(queue, 4, &front, &rear);
	Push(queue, 5, &front, &rear);
	Push(queue, 4, &front, &rear);
	Push(queue, 3, &front, &rear);
	Push(queue, 1, &front, &rear);
	Push(queue, 10, &front, &rear);
	Push(queue, 11, &front, &rear);
	Push(queue, 12, &front, &rear);
	printf("%d\n",Pop(queue, &front, &rear));
	
	printf("%d\n",Pop(queue, &front, &rear));
	
	printf("%d\n",Pop(queue, &front, &rear));
	
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	
	Push(queue, 1, &front, &rear);
	
	Push(queue, 2, &front, &rear);
	
	Push(queue, 3, &front, &rear);
	
	Push(queue, 4, &front, &rear);
	
	Push(queue, 5, &front, &rear);
	
	Push(queue, 6, &front, &rear);
	
	Push(queue, 7, &front, &rear);
	
	Push(queue, 8, &front, &rear);
	
	Push(queue, 9, &front, &rear);
	
	Push(queue, 10, &front, &rear);
	
	Push(queue, 11, &front, &rear);
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
	printf("%d\n",Pop(queue, &front, &rear));
}
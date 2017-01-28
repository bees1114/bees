#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct input {
	char* c;
	int freq;
	int level;
} input;

struct Queue {
	input Q[1000];
	int s;
	int e;
}queue;

void enqueue(Queue q, input in) {
	int i;
	q.e++;
	i = q.e;
	while(i > q.s && q.Q[i].freq > in.freq) {
		q.Q[i] = q.Q[i-1];
		i--;
	}
	q.Q[i] = in;
}

int qempty(Queue q) {
	if(q.s == q.e)
		return 1;
	else
		return 0;
}

input dequeue(Queue q) {
	if(!qempty(q)) {
		return q.Q[q.s++];
	}

}

int maxi(int a, int b) {
	if(a>b)
		return a;
	else
		return b;

}

int main(void) {
	int N, S;
	int i;
	input* arr;
	input a, b;
	input c;
	queue.s = 0;
	queue.e = 0;
	
	scanf("%d", &N);
	arr = (input*)malloc(sizeof(input)*N);
	for( i = 0 ; i< N ; i++) {
		scanf("%s %d", &arr[i].c, &arr[i].freq);
		arr[i].level = 0;
		enqueue(queue, arr[i]);
	}
	
	scanf("%d", &S);

	while(queue.s != queue.e) {
		a = dequeue(queue);
		b = dequeue(queue);
		a.level++;
		b.level++;
		c.freq = a.freq + b.freq;
		c.level = maxi(a.level, b.level)+1;
		enqueue(queue, c);
	}
	printf("%d", log((double)N) * S);
	

}
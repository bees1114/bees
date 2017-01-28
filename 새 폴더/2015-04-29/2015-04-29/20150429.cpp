#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
	int key;
}element;
element heap[MAX_ELEMENTS];
int n = 0;

void insert(element item, int *n) {
	int i;
	if(HEAP_FULL(*n)) {
		printf("heap is full\n");
		exit(0);
	}
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i/2].key)) {
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = item;

}

element Delete(int *n) {
	int i, child, parent;
	element item, temp;
	if(HEAP_EMPTY(*n)) {
		printf("heap is empty.\n");
	} else {
		item = heap[1];
		temp = heap[(*n)--];
		parent = 1;
		child = 2;
		while(child <= *n) {
			if((child < *n) && (heap[child].key < heap[child+1].key))
				child++;
			if(temp.key < heap[child].key) {
				heap[parent] = heap[child];
				parent = child;
				child *=2;
			} else
				break;
		}
		heap[parent] = temp;
		return item;
	}

}

void print(int *n) {
	int j = 0;
	if(HEAP_EMPTY(*n))
		printf("heap is empty.\n");
	else {
		for(j = 1; j < (*n)+1; j++) {
		printf("%d	" ,heap[j]);
	}
		printf("\n");
	}
}

int main(void) {
	char sel;
	int input;
	element inp;
	while(1) {
		scanf("%c", &sel);
	switch(sel) {
	case 'i' : 
		scanf("%d", &input);
		inp.key = input;
		insert(inp, &n);
		break;
	case 'd' :
		Delete(&n);
		break;
	case 'p' :
		print(&n);
		break;
	case 'e' :
		exit(1);
	}
	}

}
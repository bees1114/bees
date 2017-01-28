#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef struct {
	int key;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

int IsEmpty(element stack[]) {
	if(top == -1)
		return 1;
	else
		return 0;
}
int isFull(element stack[]) {
	if(top == MAX_STACK_SIZE-1)
		return 1;
	else
		return 0;
}

void Push(element stack[], element item) {
	if(isFull(stack))
		printf("stackFull!\n");
	else
	stack[++top] = item;
		
}

element Pop(element stack[]) {
	if(isEmpty(stack))
		printf("stackEmpty!\n");
	else
		return stack[top--];

int main(void) {
	element items;
	int i, j;
	for(i = 0; i < 10; i ++) {
		items.key= i;
	push(stack, items);

}
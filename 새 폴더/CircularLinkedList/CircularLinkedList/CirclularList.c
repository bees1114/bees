#include <stdio.h>
#include <stdlib.h>

typedef struct cList {
	int data;
	struct cList *next;
}cList;
typedef cList* cListPointer;

cList* createNode(int data) {
	cList *temp = (cList*)malloc(sizeof(cList));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insertNode(cListPointer *p, cList* node) {
	cListPointer head = *p;
	if(head) {
		node->next = head->next;
		head->next = node;
	} else {
		head = node;
		node->next = node;
	}
}

int fibo( int i) {
	if(i == 1)
		return 1;
	else if(i == 0)
		return 0;
	else
		return fibo(i-2)+fibo(i-1);
}

int main(void){
	cListPointer first;
	first = (cListPointer)malloc(sizeof(cList));
	insertNode(&first,createNode(1));
	insertNode(&first,createNode(2));
	insertNode(&first,createNode(3));

	printf("%d", fibo( 5));

}
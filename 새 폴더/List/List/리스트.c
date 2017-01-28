#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node ;

typedef node* list;

node* create_node (int data) {
	node* p = (node*)malloc(sizeof(node));
	p->data = data;
	p->next = NULL;
	return p;
}

void create_list (list* head, node* newnode) {
	node *p;
	p = *head;
	if((*head) == NULL)
		(*head) = newnode;
	else {
		while(p->next != NULL)
			p = p->next;
		p->next = newnode;
	}
}

void print(list head) {
	node *p;
	p = head;
	while(p != NULL) {
		printf("%d ",p->data);
		p = p->next;
	}
}

list invert(list head) {
	list temp = NULL;
	list middle = NULL;
	while((head) != NULL) {
	middle = head;
	(head) = (head)->next;
	middle->next = temp;
	temp = middle;
	}
	return middle;
}
int main(void) {
	list head = NULL;
	list inverthead = NULL;
	create_list(&head, create_node(1));
	create_list(&head, create_node(2));
	create_list(&head, create_node(3));
	create_list(&head, create_node(4));
	create_list(&head, create_node(5));

	print(head);
	inverthead = invert(head);
} 
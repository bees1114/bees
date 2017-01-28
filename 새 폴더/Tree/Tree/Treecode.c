#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	struct tree *leftnode;
	struct tree *rightnode;
} tree;

typedef struct tree* head;

typedef struct stack {
	tree s[30];
	int top;
}stack;

typedef struct queue {
	tree q[30];
	int capacity;
	int size;
	int front;
	int rear;
}queue;

void qinit(queue *Q) {
	Q->capacity = 30;
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;
}

int qisFull(queue *Q) {
	if(Q->capacity == Q->size)
		return 1;
	else
		return 0;
}
int qisEmpty(queue *Q) {
	if(Q->size == 0)
		return 1;
	else return 0;

}

int succ(queue *Q, int value) {
	if( ++value == Q->capacity)
		value = 0;
	return value;
}
void qadd(queue *Q, tree X) {
	Q->rear = succ(Q, Q->rear);
	Q->q[Q->rear] = X;
	Q->size++;
}
tree* qdelete(queue *Q) {
	Q->size--;
	
	return &(Q->q[(Q->front++)%Q->capacity]);
	

}
int isFull(stack *S) {
	if(S->top == 29)
		return 1;
	else
		return 0;
}

int isEmpty(stack *S) {
	if(S->top == -1)
		return 1;
	else
		return 0;
}

void push(stack *S, tree X) {
	if(!isFull(S))
	S->s[++S->top] = X;
}

tree* pop(stack *S) {
	if(!isEmpty(S))
		return &S->s[S->top--];
	else
		return NULL;
}

void maketree(head *p) {
	tree *firstnode = (tree*)malloc(sizeof(tree));
	*p = firstnode;
	(*p)->data = 1;
	(*p)->leftnode = NULL;
	(*p)->rightnode = NULL;
}

tree* makenode(int data) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->data = data;
	p->leftnode = NULL;
	p->rightnode = NULL;
	return p;
}

void add_left(tree *h, tree* p) {
	h->leftnode = p;
}
void add_right(tree *h, tree* p) {
	h->rightnode = p;
}

void pre(head h) {
	if(h != NULL) {
	printf("%d ", h->data);
	pre(h->leftnode);
	pre(h->rightnode);
	}
}

void mid(head h) {
	if(h != NULL) {
	
	mid(h->leftnode);
	printf("%d ", h->data);
	mid(h->rightnode);
	}
}

void last(head h) {
	if(h != NULL) {
	
	last(h->leftnode);
	last(h->rightnode);
	printf("%d ", h->data);
	}
}

void infixbystack(head h) {
	tree *node = h;
	tree a[30];
	stack S;
	S.top = -1;
	for(;;) {
		for(;node;node = node->leftnode)
			push(&S, *node);
		node = pop(&S);
		if(node == NULL) break;
		node = node->rightnode;
	}
}

void prefixbystack(head h) {
	tree *node = h;
	tree a[30];
	stack S;
	S.top = -1;
	for(;;) {
		for(;node;node = node->leftnode) {
			printf("%d ", node->data);
			push(&S, *node);
		}
		node = pop(&S);
		if(node == NULL) break;
		node = node->rightnode;
	}
}

void postfixbystack(head h) {
	tree *node = h;
	tree a[30];
	stack S;
	S.top = -1;
	for(;;) {
		for(;node;node = node->leftnode) 
			push(&S, *node);
		node = pop(&S); 
		if(node == NULL) break;
		node = node->rightnode;
	}
}

void levelorder(head h) {
	tree *node = h;
	queue Q;
	qinit(&Q);
	if(!h) return ;
	qadd(&Q, *h);
	for(;;) {
		if(qisEmpty(&Q))
			break;
		
		node = qdelete(&Q);
		if(node) {
			printf("%d", node->data);
			if(node->leftnode)
				qadd(&Q, *node->leftnode);
			if(node->rightnode)
				qadd(&Q, *node->rightnode);
		}
	}
}

int main(void) {
	head h = NULL;
	maketree(&h);
	add_left(h, makenode(2));
	add_right(h, makenode(3));
	add_left(h->leftnode, makenode(4));
	add_right(h->leftnode, makenode(5));
	printf("prefix\n");
	pre(h);
	printf("\n");
	printf("infix\n");
	
	mid(h);
	printf("\n");
	printf("postfix\n");
	last(h);
	printf("\n");
	
	printf("infixbystack\n");
	infixbystack(h);
	printf("\n");
	printf("prefixbystack\n");
	prefixbystack(h);
	printf("\n");
	printf("postfixbystack\n");
	postfixbystack(h);
	printf("\n");

	printf("traversal levelorder\n");
	levelorder(h);
}
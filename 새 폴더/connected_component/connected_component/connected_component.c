#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct node {
	int value;
	struct node *next;
	int color;
	int component_N;
	int vertex_N;
}vertex;

typedef struct QUEUE {
	vertex *QUEUE[1000];
	int s;
	int e;
}QUEUE;
QUEUE Q;
void initQUEUE(void) {
	Q.s = 0;
	Q.e = 0;
}

int QUEUEempty(void) {
	if(Q.s == Q.e)
		return 1;
	else
		return 0;
}

void enqueue(vertex *vtx) {
	Q.QUEUE[Q.s++] = vtx;
}


vertex* dequeue() {
	if(QUEUEempty() == 0)
	return Q.QUEUE[Q.e++];
}

void BFS(vertex **vtx, int N) {
	int i, component = 1;
	vertex *s;
	vertex *u;
	vertex *v;
	for(i = 1; i <= N; i++) {
		s= vtx[i];
			
		if(s->value == -1) {
			s->value = 0;
			s->color = GRAY;
			initQUEUE();
			enqueue(s);
			s->component_N = component;
			while(!QUEUEempty()) {
				u = dequeue();
				v = u->next;
				while(v != NULL) {
					if(v->color == WHITE) {
						v->color = GRAY;
						v->value = u->value+1;
						v->component_N = component;
						vtx[v->vertex_N]->color = GRAY;
						vtx[v->vertex_N]->value = u->value+1;
						vtx[v->vertex_N]->component_N = component;
						
						enqueue(vtx[v->vertex_N]);
						
					}
					v = v->next;
				}
				u->color = BLACK;
			}
			component++;
		}
	}
}

int main(void) {
	int N;
	int i, j;
	int x, y;
	int cc;
	int *number;
	vertex **s;
	vertex *new_node, *temp;

	scanf("%d", &N);
	s = (vertex **)malloc(sizeof(vertex *)*(N+1));
	for(i = 1; i <= N; i++) {
		s[i] = (vertex *)malloc(sizeof(vertex));
		s[i]->value = -1;
		s[i]->color = WHITE;
		s[i]->component_N = 1;
		s[i]->next = NULL;
		s[i]->vertex_N = i+1;
		
	}

	while(scanf("%d %d", &x, &y)>0){
		if(x == -1)
			break;
		new_node = (vertex *)malloc(sizeof(vertex));
		new_node->value =-1;
		new_node->next = NULL;
		new_node->color = WHITE;
		new_node->vertex_N = y;
		temp = s[x];
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;

		new_node = (vertex *)malloc(sizeof(vertex));
		new_node->value =-1;
		new_node->next = NULL;
		new_node->color = WHITE;
		new_node->vertex_N = x;
		temp = s[y];
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
	cc = 0;
	BFS(s,N);
	for( i = 1; i <= N; i++) {
		if(s[i]->component_N > cc)
			cc = s[i]->component_N;
	}
	printf("%d\n", cc);
	for(i = 1; i <= N ; i++) {
		printf("%d\n", s[i]->component_N);
	}
}
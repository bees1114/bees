#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node {
	char *c;
	int freq;
	int level;
	struct node* left;
	struct node* right;
}node;
int s = 0, e = 0;


int maxi(int a, int b) {
	if(a>b)
		return a;
	else
		return b;

}

int levelcfreq(node *r, int level, int conclude) {
	int retu= conclude;
	r->level = level;
	if(r->left == NULL && r->right == NULL) {
		retu = conclude+ r->level*r->freq;
		return retu;
	}
	else {
		retu += levelcfreq(r->left, level+1, conclude);
		retu += levelcfreq(r->right, level+1, conclude);
	}
	return retu;
}

void enqueue(node *Q, node input) {
	int i = e;
	e++;
	while( i > s && Q[i-1].freq>input.freq) {
		Q[i] = Q[i-1];
		i--;
	}
	Q[i] = input;
}

node* dequeue(node *Q) {
	return &Q[s++];
}


int main(void) {
	int N, S;
	int i;
	node* arr;
	node *a, *b;
	node *c;
	node *Q;
	Q = (node *)malloc(sizeof(node)*1000);


	scanf("%d", &N);
	for( i = 0 ; i< N ; i++) {
		arr = (node*)malloc(sizeof(node));
		
		scanf("%s %d", &arr->c, &arr->freq);
		arr->level = 0;
		arr->left =NULL;
		arr->right= NULL;
		enqueue(Q, *arr);
	}
	scanf("%d", &S);
	for(i = 1 ; i < N; i++) {
		c = (node*)malloc(sizeof(node));
		c->left = a = dequeue(Q);
		c->right = b = dequeue(Q);
		c->freq = a->freq + b->freq;
		enqueue(Q, *c);

	}
	c = dequeue(Q);
	printf("%d\n", ((int)(log((double)N)/log(2.0))+1)*S);
	printf("%d", levelcfreq(c,0,0));
	


}
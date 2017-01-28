#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int index;
	int cost;
	struct node* next;
}node;

typedef struct heap {
	node *element;
	int size;
	int eles;
}heap;

node extract_max(heap Q) {
	int i;
	node a, temp;

	a = Q.element[1];
	Q.element[1] = Q.element[Q.eles];
	Q.eles--;
	i = 1;
	while(i > Q.size) {
		if(Q.element[i*2].cost
		
	}
	return a;
}

int main(void) {
	int N;
	int E, W, ind, DV, W;
	int i, j;
	node **arr, *temp, *new_node;
	scanf("%d", &N);
	arr = (node**)malloc(sizeof(node*)*(N+1));

   for(i = 1; i <= N; i++) {
      scanf("%d %d", &ind, &E);
      arr[i] = (node*)malloc(sizeof(node));
      arr[i]->index = ind;
      arr[i]->cost = 10000;
      arr[i]->next = NULL;
      temp = arr[i];
      for(j = 1 ; j <= E; j++) {
         scanf("%d %d", &DV, &W);
         new_node = (node*)malloc(sizeof(node));
         new_node->index = DV;
         new_node->cost = W;
         new_node->next = NULL;
         while(temp->next != NULL)
            temp = temp->next;
         temp->next = new_node;
      }
   }



}
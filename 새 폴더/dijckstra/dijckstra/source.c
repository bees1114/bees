#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int index;
   int cost;
   struct node* next;
}node;

int main(void) {
   int N, ind, E, i, j;
   int DV, W;
   node **arr, *new_node, *temp;
   int sel, min, max;
   int *weight, *yorn;

   scanf("%d", &N);
   
   weight = (int*)malloc(sizeof(int)*(N+1));
   yorn = (int*)malloc(sizeof(int)*(N+1));
   arr = (node**)malloc(sizeof(node*)*(N+1));

   for(i = 0;i <=N; i++) {
      weight[i] = 10000;
      yorn[i] = 1;
   }
   
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

   sel = 1;
   weight[sel] = 0;
   yorn[sel] = 0;
   temp = arr[sel]->next;
   min = 1;
   for(i = 1;i <= N; i++) {
	   temp = arr[sel]->next;
		for( j = 1; j < N; j++) 
			if(yorn[j] == 1)
				break;
		min = j;
	   while(temp != NULL) {
         if(weight[temp->index] > weight[arr[sel]->index]+temp->cost)
            weight[temp->index] = weight[arr[sel]->index]+temp->cost;
         
         temp = temp->next;
      }
	  for(j = 1; j <= N; j++) {
		  if(weight[min] > weight[j] && yorn[j] == 1)
			  min = j;
	  }
      sel = min;
	  temp = arr[sel];

      yorn[sel] = 0;
   }
   max = 1;
   for(i = 1; i <= N; i++) {
      if(weight[i] > weight[max])
         max = i;
   }
   printf("%d\n", weight[max]);
	return 0;
}
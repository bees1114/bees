#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int cycle = 0;
int time = 0;

typedef struct node {
   int s;
   int f;
   int vertex_N;
   int color;
   struct node* next;
}vertex;

void DFS_VISIT(vertex **vtx, vertex *u,int N) {
   vertex *v;
   time = time+1;
    vtx[u->vertex_N]->s = time;
   vtx[u->vertex_N]->color = GRAY;
   if(u->next != NULL)
      if(vtx[u->next->vertex_N]->color == GRAY && vtx[u->next->vertex_N]->f == -1)
      cycle = 1;
   v = vtx[u->vertex_N]->next;
   while(v != NULL) {
      if(vtx[v->vertex_N]->color == WHITE) {
         DFS_VISIT(vtx, vtx[v->vertex_N], N);
      }
	  v = v->next;
   }
  
   time++;

   vtx[u->vertex_N]->f = time;
   vtx[u->vertex_N]->color = BLACK;

}

void DFS(vertex **vtx, int N) {
   int i;
  
   for(i = 1; i <= N; i++) {
      if(vtx[i]->color == WHITE)
         DFS_VISIT(vtx, vtx[i], N);
   }
}



int main(void) {
   int N, x, y, i, j;
   vertex **s;
   vertex *new_node;
   vertex *temp;
   int min, tempt;
   int *seq;
   scanf("%d", &N);
   s = (vertex **)malloc(sizeof(vertex *)*(N+1));
   seq = (int *)malloc(sizeof(int)*(N+1));
   for(i = 1; i <= N; i++) {
      s[i] = (vertex *)malloc(sizeof(vertex));
      s[i]->color = WHITE;
      s[i]->next = NULL;
      s[i]->f = -1;
      s[i]->s = -1;
      s[i]->vertex_N = i;
      
   }
   while(scanf("%d %d", &x, &y) > 0) {
      if(x == -1)
         break;
      new_node = (vertex *)malloc(sizeof(vertex));
      new_node->next = NULL;
      new_node->color = WHITE;
      new_node->vertex_N = y;
      new_node->s = -1;
      new_node->f = -1;
      temp = s[x];
     if(s[x]->next == NULL)
		  s[x]->next = new_node;
	  else {
		 while(temp->next != NULL) {
			 if(temp->next->vertex_N > new_node->vertex_N)
				 break;
			temp = temp->next;
		   }
		new_node->next = temp->next;
		 temp->next = new_node; 
	  
	  }
	 

      
   }
   DFS(s, N);
   if(cycle == 1)
         printf("0\n");
   else {
      for(i = 1; i <=N; i++) {
         seq[i] = s[i]->f;
      }
      for(i = 1; i <N; i++) {
         min = i;
         for(j = i+1; j <N+1; j++) {
            if(seq[j] < seq[min])
               min = j;
         }
         tempt = seq[i];
         seq[i] = seq[min];
         seq[min] = tempt;
      }
      printf("1\n");
      for(i = N; i >= 1; i--) {
         tempt = seq[i];
         for(j = N; j >= 1; j--) {
            if(tempt == s[j]->f) {
               printf("%d ", s[j]->vertex_N);
               break;
            }
         }
      }
   }
}
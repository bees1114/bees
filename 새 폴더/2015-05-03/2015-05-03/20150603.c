#include <stdio.h>
#include <stdlib.h>

#define infinite 1000

int** createArrayGraph(int size) {
	int **data, i, j;
	data = (int **) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++) {
		data[i] = (int*)malloc(sizeof(int)*size);
	}

	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++) {
			data[i][j] = infinite;
			if(i == j)
				data[i][j] = 0;
		}
		return data;
}

void insrtEdge(int **data, int edge1, int edge2, int weight) {
	data[edge1][edge2] = weight;
}

void print(int **data, int size) {
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++) {
			printf("%6d", data[i][j]);
		
		}
		printf("\n");
	}
}

int distance(int **data, int *dis,int *c,int size, int s, int e) {
	int i, j, min;
	dis[s] = 0;
	c[s] = 1;
	j = 0;
	while(j < size) {
		for(i = 0; i < size; i++) {
			if(dis[s] + data[s][i] < dis[i])
				dis[i] = dis[s] + data[s][i];
		}
			min = 1000;
			for(i = 0; i < size; i ++){
				if(min  > dis[i] && c[i] == 0)
					min  = i;
			}
			
			if(min != 1000)
			s = min;
			c[s] = 1;
	j++;
	}
			


	return dis[e];

}

int main(void) {
	int** data = createArrayGraph(7);
	int dis[7] = {1000,1000,1000,1000,1000,1000,1000};
	int Carray[7] = {0,0,0,0,0,0,0};
	int i;
	insrtEdge(data,0,1,2);
	insrtEdge(data,0,3,1);
	insrtEdge(data,1,4,10);
	insrtEdge(data,1,3,3);
	insrtEdge(data,2,0,4);
	insrtEdge(data,2,5,5);
	insrtEdge(data,3,2,2);
	insrtEdge(data,3,5,8);
	insrtEdge(data,3,6,4);
	insrtEdge(data,3,4,2);
	insrtEdge(data,4,6,6);
	insrtEdge(data,6,5,1);


	
	print(data, 7);

	printf("%d\n", distance(data, dis, Carray, 7, 3,5));
	for (i = 0; i < 7 ;i++) {
		dis[i] = 1000;
		Carray[i] = 0;
	}
	printf("%d\n", distance(data, dis, Carray, 7, 2,6));
	for (i = 0; i < 7 ;i++) {
		dis[i] = 1000;
		Carray[i] = 0;
	}
	printf("%d\n", distance(data, dis, Carray, 7, 0,4));

}
#include <stdio.h>
#include <stdlib.h>

typedef struct pos {
	long x;
	long y;
}pos;


float mini(float a, float b) {
	float r;
	if(a > b)
		r = b;
	else
		r = a;
	return r;
}

float abso(float a, float b) {
	if(a - b < 0)
		return -(a-b);
	else
		return (a - b);

}

float chebyshev(float x1, float x2, float y1, float y2) {
	float x = abso(x1, x2);
	float y = abso(y1, y2);
	if(x > y)
		return x;
	else
		return y;
}

int main(void) {
	int T;
	int N;
	int i, j, k;
	int test_case;
	pos **a;
	float avgx[4], maxx, maxx1;
	float avgy[4], maxy, maxy1;
	float dis = 100000000;
	float temp;
	int tij;

	FILE *file = fopen("sample_input.txt","r");
	
	fscanf(file, "%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		fscanf(file, "%d", &N);
		a = (pos**)malloc(sizeof(pos*)*N);
		for(i = 0; i < N; i++) {
			a[i] = (pos*)malloc(sizeof(pos)*2);
			fscanf(file, "%d %d %d %d", &a[i][0].x,&a[i][0].y, &a[i][1].x, &a[i][1].y);
		}
		//입력완료
		
			for(j = 0; j < 2; j++) {
				for(k = 0; k < 2; k++) {
					avgx[j+k] = (a[0][j].x+a[1][k].x)/2.0;
					avgy[j+k] = (a[0][j].y+a[1][k].y)/2.0;
					temp = mini(dis, chebyshev(a[0][j].x, avgx[j+k], a[0][j].y,avgy[j+k]));
					if(dis > temp) {
						dis = temp;
						tij = j+k;
					}
				}
			}
		printf("%f\n", dis);
	}



	scanf("%d", &i);
}
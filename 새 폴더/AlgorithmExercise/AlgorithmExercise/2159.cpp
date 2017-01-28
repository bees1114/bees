#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct cord {
	int x;
	int y;
}cord;

int main(void) {
	cord arr[3];
	cord pos[4];
	cord temp;
	queue<cord> Q[2];
	int N, i, j, cnt, *distance;
	int dif[4];
	int minimum;
	
	freopen("input.txt", "r", stdin);
	
	cnt = 0;
	
	scanf("%d", &N);

	distance = (int*)malloc(sizeof(int)*(N+1));
	for(i = 1; i <= N; i++) {
		distance[i] = 0;
	}

	scanf("%d %d", &arr[1].x, &arr[1].y);
	Q[0].push(arr[1]);
	for(i = 1;i <= N; i++) {
		scanf("%d %d", &arr[1].x, &arr[1].y);
			while(!Q[(i-1)%2].empty()) {
				temp = Q[(i-1)%2].front();
				Q[(i-1)%2].pop();
				pos[0].x = arr[1].x;
				pos[0].y = arr[1].y + 1;

				pos[1].x = arr[1].x;
				pos[1].y = arr[1].y - 1;

				pos[2].x = arr[1].x - 1;
				pos[2].y = arr[1].y;

				pos[3].x = arr[1].x + 1;
				pos[3].y = arr[1].y;

			for(j = 0; j < 4; j++) {
				dif[j] = abs(pos[j].x - temp.x) + abs(pos[j].y - temp.y);
			}
			
			minimum = dif[0];
			for(j = 1; j < 4; j++) {
				if(dif[j] < minimum)
					minimum = dif[j];
			}
			if(distance[i] == 0) {
				for(j = 0; j < 4; j++) {
						if(dif[j] == minimum) {
							Q[i%2].push(pos[j]);
				

						}
					}
				distance[i] = minimum;
			}
			else {
				if(distance[i] >= minimum) {
					for(j = 0; j < 4; j++) {
						if(dif[j] == minimum) {
							Q[i%2].push(pos[j]);
				

						}
					}		

				distance[i] = minimum;
				}
			}
		}

	
	}
	
	for(i = 1; i <= N; i++){
		cnt += distance[i];
	}
	printf("%d", cnt);
	return 0;

}
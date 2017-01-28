#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

char **arr;
int **number;

typedef struct cord {
	int x;
	int y;
}cord;

void move(queue<cord> *s, int M, int N) {
	
	cord temp = s->front();
	cord save;
	int tempNumber;
	s->pop();	
	if(arr[temp.y][temp.x] == '2')
		return ;

	arr[temp.y][temp.x] = '2';
	
	if((temp.x + 1 < M) && arr[temp.y][temp.x + 1] == '1') {
		save.x = temp.x + 1; save.y = temp.y;
		if(arr[temp.y][temp.x + 1] != 0) {
			s->push(save);
			number[temp.y][temp.x + 1] = number[temp.y][temp.x] + 1;
		
		} else {
			if(number[temp.y][temp.x + 1] > number[temp.y][temp.x] + 1) {
				s->push(save);
				number[temp.y][temp.x + 1] = number[temp.y][temp.x] + 1;
			}
		}
	}
	
	if((temp.y + 1 < N) && arr[temp.y + 1][temp.x] == '1') {
		save.x = temp.x; save.y = temp.y + 1;
		if(arr[temp.y + 1][temp.x] != 0) {
			s->push(save);
			number[temp.y + 1][temp.x] = number[temp.y][temp.x] + 1;
		
		} else {
			if(number[temp.y + 1][temp.x] > number[temp.y][temp.x] + 1) {
				s->push(save);
				number[temp.y + 1][temp.x] = number[temp.y][temp.x] + 1;
			}
		}
	}
	if((temp.x - 1 >= 0) && arr[temp.y][temp.x - 1] == '1') {
		save.x = temp.x - 1; save.y = temp.y;
		if(arr[temp.y][temp.x - 1] != 0) {
			s->push(save);
			number[temp.y][temp.x - 1] = number[temp.y][temp.x] + 1;
		
		} else {
			if(number[temp.y][temp.x - 1] > number[temp.y][temp.x] + 1) {
				s->push(save);
				number[temp.y][temp.x - 1] = number[temp.y][temp.x] + 1;
			}
		}
	}
	if((temp.y - 1 >= 0) && arr[temp.y - 1][temp.x] == '1') {
		save.x = temp.x; save.y = temp.y - 1;
		if(arr[temp.y - 1][temp.x] != 0) {
			s->push(save);
			number[temp.y - 1][temp.x] = number[temp.y][temp.x] + 1;
		
		} else {
			if(number[temp.y - 1][temp.x] > number[temp.y][temp.x] + 1) {
				s->push(save);
				number[temp.y - 1][temp.x] = number[temp.y][temp.x] + 1;
			}
		}
	}



}

int main(void) {
	int N, M;
	int i, j;

	char *input;
	
	queue<cord> S;
	
	cord pos;
	cord temp;
	pos.x = 0; pos.y = 0;

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	arr = (char **)malloc(sizeof(char *)*N);
	number = (int **)malloc(sizeof(int *)*N);
	input = (char *)malloc(sizeof(char)*M);
	for(i = 0; i < N; i++) {
		arr[i] = (char *)malloc(sizeof(char)*M);
		number[i] = (int *)malloc(sizeof(int)*M);
		
	}

	for(i = 0; i < N; i++) {
		scanf("%s", input);
		for(j = 0; j < M; j++) {
			arr[i][j] = input[j];
			number[i][j] = 0;
		}
	}

	S.push(pos);
		number[pos.y][pos.x] = 1;
	while((pos.x != M-1) || (pos.y != N-1)) {
		move( &S, M, N);
		pos = S.front();
	}

	printf("%d", number[pos.y][pos.x]);
	return 0;
}
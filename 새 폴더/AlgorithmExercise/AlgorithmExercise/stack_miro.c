#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define width 15
#define heith 15 
#define _CRT_SECURE_NO_WARNINGS

typedef struct stack {
	int stack[40][2];
	int index;
}stack;
stack stk;

void make_maps(int array[][15]) {
	FILE *file;
	int a,b;
	file = fopen("maps.txt", "r");
	for(a = 0; a < heith; a++) {
		for(b = 0; b < width; b++) {
			fscanf(file,"%d", &array[a][b]);
		}
	}
	fclose(file);
}

void print(int array[][15], int x, int y) {
	int i,j;
	for(i = 0; i < heith; i++) {
		for(j = 0; j < width; j++) {
			if(i == x && j == y)
				printf("★");
			else if(array[i][j] == 0)
			printf("■", array[i][j]);
			else if(array[i][j] == 1 || array[i][j] ==4)
				printf("□",array[i][j]);
			else if(array[i][j] == 2)
				printf("◎",array[i][j]);
			
		}
		printf("\n");
	}
}

void goto_stack(int a, int b) {
	stk.stack[stk.index][0] = a;
	stk.stack[stk.index][1] = b;
	stk.index++;
}

void outto_stack(int *x, int* y) {
	
	*x = stk.stack[stk.index-1][0];
	*y = stk.stack[stk.index-1][1];
	stk.index--;

}

void four(int arr[][15],int x,int y) {
	if(x+1>=0&&x+1<=heith&&(arr[x+1][y]==1 || arr[x+1][y] == 2)) {
	goto_stack(x+1,y);
	arr[x+1][y] = 4;}
	if(x-1>=0&&x-1<=heith && (arr[x-1][y]==1|| arr[x-1][y] == 2)) {
	goto_stack(x-1,y);	arr[x-1][y] = 4;}
	if(y+1>=0&&y+1<=width && (arr[x][y+1]==1|| arr[x][y+1] == 2)) {
	goto_stack(x,y+1);	arr[x][y+1] = 4;}
	if(y-1>=0&&y-1<=width && (arr[x][y-1]==1|| arr[x][y-1] == 2)) {
	goto_stack(x,y-1);	arr[x][y-1] = 4;}
}

void gotoxy(int x, int y)//내가 원하는 위치로 커서 이동
{
    COORD pos = {x-1, y-1};//커서가 X좌표에서 -1 한값. Y좌표에서 -1한 값으로 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API 함수입니다. 이건 알필요 없어요
}

int main(void) {

	int arr[heith][width] = {0};
	int x = 0,y = 7;
	stk.index = 0;
	make_maps(arr);
	print(arr, x, y);
	while(1) {
		four(arr, x, y);
		outto_stack(&x,&y);
		system("cls");
		gotoxy(3,3);
		print(arr,x,y);
		if(x==0&&y==0)
		{
			system("cls");
			gotoxy(3,3);
			printf("Goal");
			break;
		}
		Sleep(200);
	}
}
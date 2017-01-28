#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode *position;
typedef position List;
typedef struct GraphTbl *GraphTable;

struct ListNode {
	int Element;
	position Next;
};

struct GraphTbl {
	int TableSize;
	List *TheLists;
};

#define MinQueueSize 3 //�ּ� Queue ũ��

struct QueueRecord    //Queue ����ü ����
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};

typedef struct QueueRecord *Queue;

int *visited;
#define true 1
#define false 0

void MakeEmpty(Queue Q) //Queue ���� �Ǵ� �ʱ�ȭ
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int value, Queue Q) //Circular Queue�� ���� �� �迭��ǥ ��ȯ
{
	if(++value == Q->Capacity)
		value = 0;
	return value;
}

int IsFull(Queue Q)  //Queue�� ������ Ȯ��
{
	if(Q->Capacity == Q->Size)
		return 1;
	return 0;
}

void Enqueue(int X, Queue Q) //Queue�� X ����
{
	if(IsFull(Q))
		printf("Full Queue");
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear,Q);
		Q->Array[Q->Rear] = X;
		//printf("%d�� ���ԉ���ϴ�.\n",X);
	}
}
void Printfront(Queue Q) //Queue front �� ���
{
	printf("Queue �� First ���� %d�Դϴ�.\n",Q->Array[Q->Front]);
}

void PrintRear(Queue Q) //Queue rear �� ���
{
	printf("Queue �� Rear ���� %d�Դϴ�.\n",Q->Array[Q->Rear]);
}


int IsEmpty(Queue Q) //Queue�� ����ִ��� Ȯ��
{
	return Q->Size == 0;
}

int Dequeue(Queue Q) //Queue�� �� 1�� ����
{
	int r = -1;
	if(IsEmpty(Q))
		printf("Empty Queue");
	else
	{
		Q->Size--;
		Q->Front = Succ(Q->Front,Q);
		r = Q->Array[Q->Front];
		
		//printf("ť�� 1ĭ ������ϴ�.\n");
	}
	return r;
}

Queue CreateQueue(int Capacity) //Queue�� ����
{
	Queue Q;
	if(Capacity <  MinQueueSize) //Queue �ּ� ũ�� Ȯ��
	{
		printf("Queue size is too small");
		return 0;
	}
	Q = (struct QueueRecord *) malloc(sizeof(struct QueueRecord));	//Queue ����ü �޸��Ҵ�
	Q->Capacity=Capacity;
	Q->Array = (int *) malloc (sizeof(int)*Capacity);				//Queue �迭 �޸� �Ҵ�
	if(Q->Array == NULL)
	{
		printf("Out of space!!!");
		return 0;
	}
	MakeEmpty(Q);													//Queue �ʱ�ȭ
	//printf("%d ũ���� Queue�� �����Ǿ����ϴ�.\n",Capacity);
	return Q;
}



GraphTable createGraph(int size) {
	GraphTable G;
	int i;
	G = (struct GraphTbl*)malloc(sizeof(struct GraphTbl));
	G->TableSize = size;

	G->TheLists = (position*)malloc(sizeof(position)*size);

	for(i = 0; i < size; i++)
		G->TheLists[i] = NULL;
	
	visited = (int*)malloc(sizeof(int)*size);
	for(i = 0; i < size ; i++) 
		visited[i] = false;

	return G;
}

void Insert(GraphTable G, int key1, int key2) {
	position Pos, newCell;
	List L;

	newCell = (struct ListNode *)malloc(sizeof(struct ListNode));
	newCell->Element = key1;
	newCell->Next = G->TheLists[key2];
	G->TheLists[key2] = newCell;

	newCell = (struct ListNode*)malloc(sizeof(struct ListNode));
	newCell->Element = key2;
	newCell->Next = G->TheLists[key1];
	G->TheLists[key1] = newCell;

}

void dfs(GraphTable G,int v) {
	position w;
	visited[v] = true;
	printf("%5d",v);
	for(w = G->TheLists[v]; w; w= w->Next)
		if(!visited[w->Element])
			dfs(G, w->Element);

}

void bfs(GraphTable G, Queue Q, int v) {
	position w;
	Q->Rear = Q->Front = NULL;
	printf("%5d", v);
	visited[v] = true;
	Enqueue( v, Q);
	while(!IsEmpty(Q)) {
		v = Dequeue(Q);
		for(w = G->TheLists[v]; w; w = w->Next)
			if(!visited[w->Element]) {
				printf("%5d", w->Element);
				Enqueue(w->Element,Q);
				visited[w->Element] = true;
			}
	}
}

int main(void) {
	int sel, a,b, i;
	GraphTable G = NULL;

	Queue Q = CreateQueue(100);
	G = createGraph(8);
	

	Insert(G, 6, 7);
	Insert(G, 5, 7);
	Insert(G, 4, 7);
	Insert(G, 3, 7);
	Insert(G, 2, 6);
	Insert(G, 1, 4);
	Insert(G, 2, 5);
	Insert(G, 1, 3);
	Insert(G, 0, 2);
	Insert(G, 0, 1);
	
	printf("DFS :\t");
	dfs(G,0);
	printf("\n");
	
	visited = (int*)malloc(sizeof(int)*G->TableSize);
	for(i = 0; i < G->TableSize ; i++) 
		visited[i] = false;

	printf("BFS :\t");
	bfs(G,Q,0);
	printf("\n");
	
	/*while(1) {
		printf("1. Insert 2. DFS 3. BFS 4. Exit\n");
		scanf("%d", &sel);
		switch(sel) {
		case 1:
			scanf("%d %d", &a, &b);
			Insert(G, a, b);
			break;
		case 2:
			dfs(G, 0);
			printf("\n");
			break;
		case 3:
			bfs(G, Q, 0);
			printf("\n");
			break;
		case 4:
			exit(1);
		}
	}*/
}
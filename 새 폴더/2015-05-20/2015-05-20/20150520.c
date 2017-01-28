#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int Element;
	struct ListNode* Next;
};

struct HashTbl {
	int TableSize;
	float A;
	struct ListNode** TheLists;
};

typedef struct ListNode *position;
typedef position List;
typedef struct HashTbl *HashTable;

HashTable createHash(int size, float A) {
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct HashTbl)*size);
	H->TableSize = size;
	H->A = A;

	H->TheLists = (position*)malloc(sizeof(position)*size);

	for(i= 0; i < size; i++) {
		H->TheLists[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
		H->TheLists[i]->Next = NULL;
	}
	return H;
}

int hx(int key, HashTable H) {
	float r = ((H->A) * key);
	int i = r;
	i = (r-i) *(H->TableSize); 

	return i;
}

position Find(int key, HashTable H) {
	position P;
	List L;

	L = H->TheLists[hx(key,H)];
	P = L->Next;

	while(P != NULL && P->Element != key)
		P = P->Next;
	return P;
}

position FindPre(int key, HashTable H) {
	position P;
	List L;

	L = H->TheLists[hx(key,H)];
	P = L;

	while(P->Next != NULL && P->Next->Element != key)
		P = P->Next;
	return P;
}

void insert(int key, HashTable H) {
	position Pos, newCell;
	List L;

	Pos = Find(key, H);

	if(Pos == NULL) {
		newCell = (struct ListNode *)malloc(sizeof(struct ListNode));

		L = H->TheLists[hx(key,H)];
		newCell->Next = L->Next;
		newCell->Element = key;
		L->Next = newCell;
	}
}

void Hdelete(int key, HashTable H) {
	position Pos;
	List L;
	List D;
	Pos = FindPre(key,H);
	D = Pos->Next;
	Pos->Next = Pos->Next->Next;
	free(D);
}

void print(HashTable H) {
	List L = H->TheLists;
	position Pos = H->TheLists;
	int i = 0;
	for(i = 0; i < H->TableSize; i++) {
		Pos = H->TheLists[i];
		printf("Hash[%d] : ", i);
		L = Pos->Next;
		while(L != NULL) {
			printf("%d", L->Element);			
			L = L->Next;
		}
		printf("\n");
	}
}

int main(void) {
	int size, key;
	char select;
	float A;
	HashTable H;
	
		printf("Hash table size : ");
		scanf("%d", &size);
		printf("A : ");
		scanf("%f", &A);
		H = createHash(size, A);
		
	while(1) {
		scanf("%c", &select);
		switch(select) {
		case 'i':
			scanf("%d", &key);
			insert(key, H);
		break;
		case 'd':
			scanf("%d", &key);
			Hdelete(key, H);
		break;
		case 'f':
			scanf("%d", &key);
			printf("Find %d is Hash[%d].\n", key, hx(key,H)); 
			break;
		case 'p':
			print(H);
			break;
		case 'q':
			exit(1);
		}
	}
}
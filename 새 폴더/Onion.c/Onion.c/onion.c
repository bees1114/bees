#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int studentID;
	char* studentName;
}ElementType;

struct Node
{
	ElementType element;
	struct Node *Next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void insert(ElementType X, List L, Position P) {
	Position TmpCell;

	TmpCell = (Position)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of space!");
	
	if(P!= NULL) {
		TmpCell->element = X;
		TmpCell->Next = NULL;
		TmpCell->Next = P->Next;
		P->Next = TmpCell;
	}
}

int IsEmpty(List L) {
	return L->Next == NULL;
}

int IsLast(Position P, List L) {
	return P->Next == NULL;
}

Position Find(ElementType X, List L) {
	Position P;

	P = L->Next;
	while(P != NULL) {
		if(P->element.studentID == X.studentID) {
			P = NULL;
			break;
		}else if(P->element.studentID > X.studentID && P->Next == NULL) {
			P = L;
			break;
	} else if(P->element.studentID < X.studentID && P->Next == NULL)
		break;
		else if(P->element.studentID < X.studentID && P->Next->element.studentID > X.studentID)
			break;
		P = P->Next;

	} 
	return P;
}

Position FindPrevious(int X, List L) {
	Position P;
	int index = 0;
	
	P = L;
	
	while(P->Next != NULL && P->Next->element.studentID != X)
			P = P->Next;
	return P;
}

void Delete(int X, List L) {
	Position P, TmpCell;

	P = FindPrevious(X, L);
	if(!IsLast(P,L)) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	} else {
		TmpCell = P->Next;
		P->Next = NULL;
		free(TmpCell);
	}
}

void DataInsert(ElementType X, List L) {
	Position Tmp;
	if(IsEmpty(L)) {
 			Tmp = L;
			insert(X,L,Tmp);	
	}else {
		insert(X,L,Find(X,L));
	}
}

void PrintList(List L) {
	Position Tmp;
	
	Tmp = L->Next;
	while(Tmp != NULL) {
		printf("%d %s\n", Tmp->element.studentID, Tmp->element.studentName);
		Tmp = Tmp->Next;
	}
}

ElementType MakeElement(int id, char *name) {
	ElementType Element;
	Element.studentID = id;
	Element.studentName = (char *)malloc(sizeof(char)*30);
	strcpy(Element.studentName, name);
	return Element;
}

int main(void) {
	char command;
	int input1;
	char *input2, *input3;
	List header;
	input2 = (char*)malloc(sizeof(char)*30);
	input3 = (char*)malloc(sizeof(char)*30);
	header = (List)malloc(sizeof(struct Node));
	header->Next= NULL;
	while(1) {
		scanf("%c", &command);

		switch(command) {
			case 'i' :
				scanf("%d %s %s", &input1, input2, input3);
				strcat(input2, " ");
				strcat(input2, input3);
				DataInsert(MakeElement(input1, input2), header);
				break;
			case 'd' :
				scanf("%d", &input1);
				Delete(input1, header);
				break;
			//case 'f' :
			//	scanf("%d", &input1);
			//	if(FindPrevious(input1, header) != header && Find(input1, header) != NULL)
			//	printf("%d\n", FindPrevious(input1,header)->data);
			//	break;
			case 'p' :
				PrintList(header);
								
				return 0;
		}
	}
}
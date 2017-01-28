#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EmptyTOS (-1)
#define MinStackSize (5)
#define MAXELEMENT 100

struct StackRecord {
	int Capacity;
	int TopOfStack;
	char *Array;
};

typedef struct StackRecord *Stack;


void MakeEmpty(Stack S) {
	S->TopOfStack = EmptyTOS;
}

int IsEmpty(Stack S) {
	if(S->TopOfStack == EmptyTOS)
		return 1;
	else
		return 0;
}

int IsFull(Stack S) {
	if(S->TopOfStack == S->Capacity)
		return 1;
	else return 0;

}

Stack CreateStack(int MaxElements) {
	Stack S;
	if(MaxElements <MinStackSize)
		printf("Stack Size is too small");
	else {
		S = (Stack)malloc(sizeof(struct StackRecord));
		if(S->Array == NULL)
			printf("Out of space!!");

		S->Array = (char *)malloc(sizeof(char)*MaxElements);
		S->Capacity = MaxElements;
		MakeEmpty(S);

		return S;
	}
}


void Push(char X, Stack S) {
	if(IsFull(S))
		printf("Stack Full!");
	else
		S->Array[++S->TopOfStack] = X;
}

char Top(Stack S) {
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack];
	else
	printf("Empty Stack");
	return 0;
}

void Pop(Stack S) {
	if(IsEmpty(S))
		printf("Empty Stack");
	else
		S->TopOfStack--;
}

int priority(char X) {
	if (X == ')')
		return 3;
	else if (X == '*' || X == '/' || X == '%')
		return 2;
	else if (X == '+' || X == '-')
		return 1;
	else if( X=='(')
		return 0;
}

int main(void) {
	char infix[100];
	int i = 0;
	Stack S;
	S = CreateStack(100);
	printf("original infix form : ");
	scanf("%s", infix);
	printf("converted postfix form : ");
	while(infix[i] != NULL) {
		if(infix[i] >= 48 && infix[i] <= 57)
			printf("%c", infix[i]);
		else if(IsEmpty(S))
			Push(infix[i],S) ;
		else if(priority(infix[i]) == 3) {
			while(Top(S) != '(') {
				printf("%c",Top(S));
				Pop(S);
			}	
			Pop(S);
		}
		else if(priority(infix[i]) == 0)
			Push(infix[i],S);
		else if(priority(infix[i])> priority(Top(S)))
			Push(infix[i],S);
		else if(priority(infix[i])<= priority(Top(S))) {
			printf("%c",Top(S));
			Pop(S);
			i--;
		} 
		
		i++;
	}
	while(!IsEmpty(S)) {
		printf("%c", Top(S));
		Pop(S);
	}
	printf("\n");
}
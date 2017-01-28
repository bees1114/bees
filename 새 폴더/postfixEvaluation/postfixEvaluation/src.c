#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	float *data;
	int top;
	int maxSize;

}Stack;

void StackInitialize(Stack *S) {
	S->data = (float*)malloc(sizeof(float)*30);
	S->maxSize = 30;
	S->top = -1;
}

int Empty(Stack S) {
	if(S.top == -1)
		return 1;
	else return 0;
}

int Full(Stack S) {
	if(S.top == S.maxSize)
		return 1;
	else return 0;

}

void Push(Stack *S, float data) {
	if(!Full(*S))
	S->data[++S->top] = data;
}

float Pop(Stack *S) {
	float data;
	if(!Empty(*S)) {
	data = S->data[S->top--];
	return data;
	}
}

int main(void) {
	Stack S;
	char input[30];
	int i = 0;
	float a, b;
	StackInitialize(&S);
	
	printf("converted postfix form : ");
	scanf("%s",input);
	while(input[i] != '\0') {
		switch (input[i]) {
		case '*' : 
			a = Pop(&S);
			b = Pop(&S);
			Push(&S, a*b);
			break;
		case '+' : 
			a = Pop(&S);
			b = Pop(&S);
			Push(&S, a+b);
			break;
		case '-' : 
			a = Pop(&S);
			b = Pop(&S);
			Push(&S, b-a);
			break;
		case '/' :
			a = Pop(&S);
			b = Pop(&S);
			Push(&S, b/a);
			break;
		default :
		
			Push(&S, input[i] - '0');
		}
		i++;
	}
	
	printf("evaluation result : %f", Pop(&S));
	
}
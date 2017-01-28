#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
	int degree;
	int coef;
	struct polynomial *next;
}polynomial; // 다항식을 저장할 구조체 선언

typedef struct polynomial* header; // 다항식의 헤더 선언

void make_polynomial (header *head) {
	(*head) = (header)malloc(sizeof(polynomial));
	(*head)->next = NULL;
} //헤더를 만드는 함수

polynomial* create_polynomial(int inputCoef, int inputDegree) {
	polynomial *p = (polynomial*)malloc(sizeof(polynomial));
	p->coef = inputCoef;
	p->degree = inputDegree;
	p->next = NULL;
} //입력받은 계수와 차수로 한개의 노드를 만들고 리턴하는함수.

void add_polynomial(header *head, polynomial* node) {
	header h = (*head)->next;
	if(h == NULL) { // 헤더가 비어있으면 헤더에 노드 추가
		(*head)->next = node;
	} else {
		while(h->next != NULL) {
			if(h->degree > node->degree && h->next->degree < node->degree)
				break;//차수의 내림차순으로 구현하기위해서 차수값 비교

			h = h->next;
		}
		node->next = h->next;
		h->next = node;
	}

} // 헤더와 노드를 인자로 받아 헤더에 노드를  차수의 내림차순으로 추가하는 함수

void delete_node(header *poly) {
	header p = *poly;
	polynomial *tmp;
	if(p->next != NULL) {
	tmp = p->next;
	p->next = p->next->next;
		free(tmp);
	}
}//헤더의 가장 앞 노드를 제거한다.

void addition(header *polynomial_add, header polynomial1, header polynomial2) {
	header A = polynomial1->next;
	header B = polynomial2->next;
	header C = *polynomial_add;
	while(!(A == NULL) && !(B == NULL)) { //A나 B 리스트가 NULL이 될때까지
		
		if(A->degree > B->degree) {
			add_polynomial(&C, create_polynomial(A->coef, A->degree));
			delete_node(&polynomial1);
			A = polynomial1->next;//A차수가 B차수보다 크면 C리스트에 A의 노드 추가, A에서 노드 제거
		} else if(A->degree == B->degree) {
			if(A->coef+B->coef != 0)
			add_polynomial(&C, create_polynomial(A->coef+B->coef, A->degree));
			delete_node(&polynomial1);
			delete_node(&polynomial2);
			A = polynomial1->next;//A차수와 B차수가 같으면 둘을 더하여 C리스트에 추가, A,B에서 노드 제거
			B = polynomial2->next;
		} else {
			add_polynomial(&C, create_polynomial(B->coef, B->degree));
			delete_node(&polynomial2);
			B = polynomial2->next;//B차수가 A차수보다 그면 C리스트에 B의 노드 추가, B에서 노드 제거
		
		}
	}	
	while(A !=NULL) {
		add_polynomial(&C, create_polynomial(A->coef, A->degree));
		delete_node(&polynomial1);
			A = polynomial1->next;
		}//B가 먼저 끝에 다다를경우 남아있는 A리스트의 노드를 C리스트에 추가, A에서 노드 제거
	while(B !=NULL) {
		add_polynomial(&C, create_polynomial(B->coef, B->degree));
		delete_node(&polynomial2);
			B = polynomial2->next;
		
	}//A가 먼저 끝에 다다를경우 남아있는 A리스트이 노드를 C리스트에 추가, B에서 노드 제거
	
		

}// 두 다항식의 덧셈을 수행하는 함수

polynomial* find_sameDegree(header polynomial_mult, int degree) {
	polynomial* temp = polynomial_mult->next;
	polynomial* p = NULL;
	while(temp != NULL) {//리스트의 처음부터 끝까지
		if(temp->degree == degree) {
			p = temp;
			break;//degree에 해당하는 노드가 있으면 찾아낸다.
		}
		temp = temp->next;
	}
	return p;//degree에 해당하는 노드를 리턴하든지, NULL을 리턴한다.
} // 리스트에 해당 차수의 노드가 있는지 검사하는 함수

void multiplication(header *polynomial_mult, header polynomial1, header polynomial2) {
	header A = polynomial1->next;
	header B = polynomial2->next;
	header C = *polynomial_mult;
	polynomial *temp = NULL;
	polynomial *findp = NULL;
	while(A != NULL) {						//A리스트가 끝날때까지
		B = polynomial2->next;				 //B노드의 처음 부분을 가리킨다.
		while(B != NULL) {					//B리스트가 끝날때까지
			temp = create_polynomial(A->coef * B->coef, A->degree + B->degree);
			//temp는 다항식 A와 B에서 한 항을 곱한 결과값을 저장한 노드
			findp = find_sameDegree(C, temp->degree);
			// 결과를 저장하는 C리스트에 temp와 같은 차수가 있는지 검사한다.
			if(findp == NULL)		//같은차수가 없다면 C리스트에 노드를 추가한다.
				add_polynomial(&C, temp);
			else {
				findp->coef += temp->coef;
				//같은차수를 가진 노드가 있다면 그 노드에 계수에 temp의 계수를 더한다.
			}
			B = B->next;
		}
		A = A->next;
	}
}

int main(void) {
	FILE *file = fopen("input.txt","r");
	header polynomial1;
	header polynomial2;
	header polynomial_add;
	header polynomial_mult;
	int cnt, inputDegree, inputCoef;

	
	make_polynomial(&polynomial1); //첫번째 다항식리스트를 저장할 헤더노드
	make_polynomial(&polynomial2); //두번째 다항식리스트를 저장할 헤더노드
	make_polynomial(&polynomial_add); // 덧셈결과 다항식리스트를 저장할 헤더노드
	make_polynomial(&polynomial_mult); // 곱셈결과 다항식리스트를 저장할 헤더노드

	while(!feof(file)) {
		fscanf(file,"%d", &cnt);
		for(;cnt > 0 ; cnt-- ) {
			fscanf(file, "%d %d", &inputCoef, &inputDegree);
			add_polynomial(&polynomial1, create_polynomial(inputCoef, inputDegree));
		}
		fscanf(file,"%d", &cnt);
		for(;cnt > 0 ; cnt-- ) {
			fscanf(file, "%d %d", &inputCoef, &inputDegree);
			add_polynomial(&polynomial2, create_polynomial(inputCoef, inputDegree));
		}
	}//input.txt 파일을 읽기용으로 열어서 다항식 2개를 입력받는다.
	fclose(file);
	
	multiplication(&polynomial_mult, polynomial1, polynomial2);//두 다항식의 곱셈을 하여 polynomial_mult에 저장한다.
	addition(&polynomial_add, polynomial1, polynomial2);//두 다항식의 덧셈을 하여 polynomial_add에 저장한다.
	free(polynomial1);
	free(polynomial2);
	
	file = fopen("output.txt","w");
	fprintf(file, "Addition\n");
	while(polynomial_add->next != NULL) {
		fprintf(file, "%d %d\n", polynomial_add->next->coef, polynomial_add->next->degree);
		delete_node(&polynomial_add);
	}//덧셈결과를 output.txt에 출력
	free(polynomial_add);
	fprintf(file, "Multiplication\n");
	while(polynomial_mult->next != NULL) {
		fprintf(file, "%d %d\n", polynomial_mult->next->coef, polynomial_mult->next->degree);
		delete_node(&polynomial_mult);
	}//곱셈결과를 output.txt에 출력
	free(polynomial_mult);
	fclose(file);
}
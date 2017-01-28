#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
	int degree;
	int coef;
	struct polynomial *next;
}polynomial; // ���׽��� ������ ����ü ����

typedef struct polynomial* header; // ���׽��� ��� ����

void make_polynomial (header *head) {
	(*head) = (header)malloc(sizeof(polynomial));
	(*head)->next = NULL;
} //����� ����� �Լ�

polynomial* create_polynomial(int inputCoef, int inputDegree) {
	polynomial *p = (polynomial*)malloc(sizeof(polynomial));
	p->coef = inputCoef;
	p->degree = inputDegree;
	p->next = NULL;
} //�Է¹��� ����� ������ �Ѱ��� ��带 ����� �����ϴ��Լ�.

void add_polynomial(header *head, polynomial* node) {
	header h = (*head)->next;
	if(h == NULL) { // ����� ��������� ����� ��� �߰�
		(*head)->next = node;
	} else {
		while(h->next != NULL) {
			if(h->degree > node->degree && h->next->degree < node->degree)
				break;//������ ������������ �����ϱ����ؼ� ������ ��

			h = h->next;
		}
		node->next = h->next;
		h->next = node;
	}

} // ����� ��带 ���ڷ� �޾� ����� ��带  ������ ������������ �߰��ϴ� �Լ�

void delete_node(header *poly) {
	header p = *poly;
	polynomial *tmp;
	if(p->next != NULL) {
	tmp = p->next;
	p->next = p->next->next;
		free(tmp);
	}
}//����� ���� �� ��带 �����Ѵ�.

void addition(header *polynomial_add, header polynomial1, header polynomial2) {
	header A = polynomial1->next;
	header B = polynomial2->next;
	header C = *polynomial_add;
	while(!(A == NULL) && !(B == NULL)) { //A�� B ����Ʈ�� NULL�� �ɶ�����
		
		if(A->degree > B->degree) {
			add_polynomial(&C, create_polynomial(A->coef, A->degree));
			delete_node(&polynomial1);
			A = polynomial1->next;//A������ B�������� ũ�� C����Ʈ�� A�� ��� �߰�, A���� ��� ����
		} else if(A->degree == B->degree) {
			if(A->coef+B->coef != 0)
			add_polynomial(&C, create_polynomial(A->coef+B->coef, A->degree));
			delete_node(&polynomial1);
			delete_node(&polynomial2);
			A = polynomial1->next;//A������ B������ ������ ���� ���Ͽ� C����Ʈ�� �߰�, A,B���� ��� ����
			B = polynomial2->next;
		} else {
			add_polynomial(&C, create_polynomial(B->coef, B->degree));
			delete_node(&polynomial2);
			B = polynomial2->next;//B������ A�������� �׸� C����Ʈ�� B�� ��� �߰�, B���� ��� ����
		
		}
	}	
	while(A !=NULL) {
		add_polynomial(&C, create_polynomial(A->coef, A->degree));
		delete_node(&polynomial1);
			A = polynomial1->next;
		}//B�� ���� ���� �ٴٸ���� �����ִ� A����Ʈ�� ��带 C����Ʈ�� �߰�, A���� ��� ����
	while(B !=NULL) {
		add_polynomial(&C, create_polynomial(B->coef, B->degree));
		delete_node(&polynomial2);
			B = polynomial2->next;
		
	}//A�� ���� ���� �ٴٸ���� �����ִ� A����Ʈ�� ��带 C����Ʈ�� �߰�, B���� ��� ����
	
		

}// �� ���׽��� ������ �����ϴ� �Լ�

polynomial* find_sameDegree(header polynomial_mult, int degree) {
	polynomial* temp = polynomial_mult->next;
	polynomial* p = NULL;
	while(temp != NULL) {//����Ʈ�� ó������ ������
		if(temp->degree == degree) {
			p = temp;
			break;//degree�� �ش��ϴ� ��尡 ������ ã�Ƴ���.
		}
		temp = temp->next;
	}
	return p;//degree�� �ش��ϴ� ��带 �����ϵ���, NULL�� �����Ѵ�.
} // ����Ʈ�� �ش� ������ ��尡 �ִ��� �˻��ϴ� �Լ�

void multiplication(header *polynomial_mult, header polynomial1, header polynomial2) {
	header A = polynomial1->next;
	header B = polynomial2->next;
	header C = *polynomial_mult;
	polynomial *temp = NULL;
	polynomial *findp = NULL;
	while(A != NULL) {						//A����Ʈ�� ����������
		B = polynomial2->next;				 //B����� ó�� �κ��� ����Ų��.
		while(B != NULL) {					//B����Ʈ�� ����������
			temp = create_polynomial(A->coef * B->coef, A->degree + B->degree);
			//temp�� ���׽� A�� B���� �� ���� ���� ������� ������ ���
			findp = find_sameDegree(C, temp->degree);
			// ����� �����ϴ� C����Ʈ�� temp�� ���� ������ �ִ��� �˻��Ѵ�.
			if(findp == NULL)		//���������� ���ٸ� C����Ʈ�� ��带 �߰��Ѵ�.
				add_polynomial(&C, temp);
			else {
				findp->coef += temp->coef;
				//���������� ���� ��尡 �ִٸ� �� ��忡 ����� temp�� ����� ���Ѵ�.
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

	
	make_polynomial(&polynomial1); //ù��° ���׽ĸ���Ʈ�� ������ ������
	make_polynomial(&polynomial2); //�ι�° ���׽ĸ���Ʈ�� ������ ������
	make_polynomial(&polynomial_add); // ������� ���׽ĸ���Ʈ�� ������ ������
	make_polynomial(&polynomial_mult); // ������� ���׽ĸ���Ʈ�� ������ ������

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
	}//input.txt ������ �б������ ��� ���׽� 2���� �Է¹޴´�.
	fclose(file);
	
	multiplication(&polynomial_mult, polynomial1, polynomial2);//�� ���׽��� ������ �Ͽ� polynomial_mult�� �����Ѵ�.
	addition(&polynomial_add, polynomial1, polynomial2);//�� ���׽��� ������ �Ͽ� polynomial_add�� �����Ѵ�.
	free(polynomial1);
	free(polynomial2);
	
	file = fopen("output.txt","w");
	fprintf(file, "Addition\n");
	while(polynomial_add->next != NULL) {
		fprintf(file, "%d %d\n", polynomial_add->next->coef, polynomial_add->next->degree);
		delete_node(&polynomial_add);
	}//��������� output.txt�� ���
	free(polynomial_add);
	fprintf(file, "Multiplication\n");
	while(polynomial_mult->next != NULL) {
		fprintf(file, "%d %d\n", polynomial_mult->next->coef, polynomial_mult->next->degree);
		delete_node(&polynomial_mult);
	}//��������� output.txt�� ���
	free(polynomial_mult);
	fclose(file);
}
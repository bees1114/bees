#include <math.h>
#include <stdio.h>

int get_eps_float() {
	int n=0;
	float a = 1.0;
	do {
		n++;
		a *= 1.0/2.0;
	}while(1+a != 1);
	return n;
}

int get_eps_double() {
	int n=0;
	double a = 1.0;
	do {
		n++;
		a *= 1.0/2.0;
	}while(1+a != 1);
	return n;
}

int main(void) {
	printf("result : %d", get_eps_float());
	printf("result : %d", get_eps_double());
	return 0;
}
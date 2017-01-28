#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502
#define E 2.71827182818284590452353602874

void problem3_6(double x) {
	double true_value = 0.006737947;
	double exp1, exp2, value1, value2, iter = 1.0;
	int i;
	exp1 = 0.0;exp2 = 0.0;value1 = 1.0;value2 = 1.0;
	for(i = 0; i < 20; i++) {
		exp1 = exp1+value1;
		exp2 = exp2+value2;
		value1 = value1 * ((-1.0)*x)/iter;
		value2 = value2 * x/iter;
		iter = iter + 1.0;	
		printf("%d th relative error for 3.6-1 : %.9lf\n", i + 1, (true_value - exp1)/true_value);
		printf("%d th relative error for 3.6-2 : %.9lf\n", i + 1, (true_value - 1.0/exp2)/true_value);

	}
	printf("final value for 3.6-1 : %.9lf\n", exp1);
	printf("final value for 3.6-2 : %.9lf\n", 1.0/exp2);
}

void problem3_7(double x) {
	double function, digit_3, digit_4;
	function = 6.0*x/(1.0 - 3.0*x*x)*(1.0 - 3.0*x*x);
	digit_3 = floorf(function * 1000.0)/1000;
	digit_4 = floorf(function * 10000.0)/10000;
	printf("value for 3.7 true value : %f\n", function);
	printf("value for 3.7 3-digit : %.3lf\n", digit_3);
	printf("value for 3.7 4-digit : %.4lf\n", digit_4);
	printf("relative error for 3-digit : %f\n", (function - digit_3)/function);
	printf("relative error for 4-digit : %f\n", (function - digit_4)/function);
}

void problem4_2(double x) {
	double sinx, iter = x, true_value;
	int i;
	sinx = 0.0;
	true_value = sin(PI/3.0);
	for(i = 2; i < 20;i = i + 2) {
		sinx = sinx + iter;
		iter = iter * (-1) * x * x /(i*i+1);
		printf("value for 4.2 appr value : %.10f\n", sinx);
		printf("%d th relative error for 4.2 : %.10f\n", i/2, (true_value - sinx) / true_value);
			
	}
	printf("value for 4.2 true value : %.10f\n", true_value);
	printf("value for 4.2 appr value : %.10f\n", sinx);
	printf("relative error for 4.2 : %.10f\n", (true_value - sinx) / true_value);
}

void problem4_5(double x) {
	int arr[4], i;
	double function, iter;
	double value;
	arr[0] = 25-6+7-88;
	arr[1] = 25*3 - 6*2 + 7;
	arr[2] = 25*3*2 - 6*2;
	arr[3] = 25*3*2*1;
	function = 25*x*x*x - 6*x*x + 7*x -88;
	iter = x - 1;
	value = arr[0];
	printf("%d th relative error : %f\n", 1, (function-value)/function);
	for(i = 1; i < 4; i++) {
		value += arr[i]*iter;
		iter = iter * (x - 1)/(i+1);
		printf("%d th relative error : %f\n", i+1, (function-value)/function);
	}
	printf("final value for function : %f value : %f\n", function, value);

}

void problem4_12_a(double x) {
	double function, deffun, condition_number;
	function = sqrt(abs(x - 1)) + 1;
	deffun = 1.0/(2*sqrt(x - 1));
	condition_number = x * deffun / function;
	printf("Condition number of 4.12 (a) : %f\n", condition_number);
}

void problem4_12_b(double x) {
	double function, deffun, condition_number;
	function = 1.0/E;
	deffun = -1*1.0/E;
	condition_number = x * deffun / function;
	printf("Condition number of 4.12 (a) : %f\n", condition_number);
}

void problem4_12_c(double x) {
	double function, deffun, condition_number;
	function = sqrt(x * x + 1) - x;
	deffun = 2*x/(2*sqrt(x * x + 1)) - 1;
	condition_number = x * deffun / function;
	printf("Condition number of 4.12 (a) : %f\n", condition_number);
}
void problem4_12_d(double x) {
	double function, deffun, condition_number;
	function = (1.0/E - 1)/x;
	deffun = (-1.0/E*x - (1.0/E - 1))/x; 
	condition_number = x * deffun / function;
	printf("Condition number of 4.12 (a) : %f\n", condition_number);
}

void problem4_12_e(double x) {
	double function, deffun, condition_number;
	function = sin(x)/(1+cos(x));
	deffun = (cos(x)*(1 + cos(x)) - sin(x)*(-sin(x)))/(1 + cos(x))*(1 + cos(x));
	condition_number = x * deffun / function;
	printf("Condition number of 4.12 (a) : %f", condition_number);
}

int main(void) {
	problem3_6(5.0);
	printf("\n");
	problem3_7(0.577);
	printf("\n");
	problem4_2(PI/3.0);
	printf("\n");
	problem4_5(3);
	printf("\n");
	problem4_12_a(1.00001);
	problem4_12_b(10);
	problem4_12_c(300);
	problem4_12_d(0.001);
	problem4_12_e(1.0001*PI);
	return 0;
}
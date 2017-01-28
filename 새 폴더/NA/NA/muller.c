#include <math.h>
#include <stdio.h>
#define MAXIT 30

float sgn(float x) {
	if ( x == 0.0) return 0.0;
	if (x > 0.0)
		return 1.0;
	else
		return -1.0;

}

float muller(float (*func)(float), float p0, float p1, float p2, float xacc) {
	float p3, a, b, c, f, funcp0, funcp1, funcp2, temp, dx, rtf, del;
	int i;
	void nrerror(char error_text[]);
	for(i = 1; i <= MAXIT; i++) {
		funcp0 = (*func)(p0);
		funcp1 = (*func)(p1);
		funcp2 = (*func)(p2);
		
		c = funcp2;
		b = ((p0-p2)*(p0-p2)*(funcp1-funcp2) - (p1-p2)*(p1-p2)*(funcp0-funcp2))/(p0-p2)*(p1-p2)*(p0-p1);
		a = (p1-p2)*(funcp0-funcp2) - (p0-p2)*(funcp1-funcp2)/(p0-p2)*(p1-p2)*(p0-p1);
		p3 = p2 - 2*c/(b+sgn(b)*sqrtf(b*b-4*a*c));
		
		if(p3 > p2) {
			del = p3-p2;
		} else {
			del = p2-p3;
		}
		p0 = p1;
		p1 = p2;
		p2 = p3;
		f = (*func)(p3);
		if(fabs(del)<xacc || f == 0.0) {
			printf("iter : %d\t", i);
			printf("root : %f\t", p3);
			return p3;
		}

	}
	nrerror("Maximum number of iterations exceeded in muller");
	return 0.0;
}
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	char N[2];
	int ten, one, cycle;
	int oten, oone, sum;
	cin>>N;
	if(strlen(N) == 1) {
		N[1] = N[0];
		N[0] = '0';
		
	}
	ten = N[0] - '0';
	oten = ten;
	one = N[1] - '0';
	oone = one;
	
	cycle = 0;

	do {
		sum = ten + one;
		ten = one;
		one = (sum)%10;
		cycle++;
	}while(!(oone==one &&oten == ten));
	cout<<cycle;
	return 0;

}
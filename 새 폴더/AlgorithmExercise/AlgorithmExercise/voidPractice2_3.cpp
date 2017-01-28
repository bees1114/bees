#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int A, B, C, D, P;
	int X, Y;
	cin>>A>>B>>C>>D>>P;
	
	X = A*P;
	if(P<=C)
		Y = B;
	else
		Y = B + (P-C)*D;

	if(X<Y)
		cout<<X;
	else
		cout<<Y;
	return 0;
}
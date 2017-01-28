#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n;

	int i, j;
	int *a, *b;
	int temp, sum;
	cin>>n;
	a = new int[n];
	b = new int[n];
	for(i = 0; i < n; i++) {
		cin>>a[i];
	}
	b[n-1] = a[n-1];
	for(i = n-2 ; i>=0; i--) {
		if(a[i] + b[i+1] > a[i])
			b[i] = a[i]+ b[i+1];
		else
			b[i] = a[i];
	
	}
	sort(b, b+n);
	cout<<b[n-1];
	return 0;
}
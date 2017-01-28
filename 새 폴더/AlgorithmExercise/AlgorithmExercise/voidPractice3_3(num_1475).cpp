#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	char N[7];
	int arr[10];
	int i, max, temp;
	cin>>N;
	for( i = 0 ; i < 10; i++) {
		arr[i] = 0;
	}
	for(i = 0; i < 7; i++) {
		arr[N[i]-'0']++;
	}
	temp = arr[6];
	arr[6] = (arr[6]+arr[9]+1)/2;
	arr[9] = (arr[9]+temp+1)/2;
	max = arr[0];
	for(i = 0; i < 10;i++) {
		if(arr[i]>max)
			max = arr[i];
	}
	cout<<max;
	return 0;

}
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int arr[1001][3];
	int brr[1001][3];
	int N;
	int i, j, mini, minj, min, temp;
	
	freopen("input.txt", "r", stdin);
	
	cin>>N;
	for(i = 1 ; i <= N; i++) {
		for(j = 0; j < 3; j++) 
		cin>>arr[i][j];
	}
	
	for(i  = 2; i <= N; i++) {
		for(j = 0 ; j < 3; j++) {
			if(arr[i][j] + arr[i-1][(j+1)%3] >= arr[i][j] + arr[i-1][(j+2)%3])
				arr[i][j] = arr[i][j]+arr[i-1][(j+2)%3];
			else if(arr[i][j] + arr[i-1][(j+1)%3] < arr[i][j] + arr[i-1][(j+2)%3])
				arr[i][j] = arr[i][j]+arr[i-1][(j+1)%3];

		}

	}

	int answer;
	sort(arr[N], arr[N]+3);
	answer = arr[N][0];
	cout<<answer<<endl;
	return 0;
}
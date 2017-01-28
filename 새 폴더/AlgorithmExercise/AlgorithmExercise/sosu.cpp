#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	int testcase;
	int arr[10001];
	int cnt[10001];	
	int ten;
	queue<int> Queue;
	int i, j, k,w, num1, num2, temp, var;
	
	k = 0;
	ten = 1000;

	for(i = 1; i <= 10000; i++) {
		arr[i] = i;
		cnt[i] = 0;
	}
	for(i = 2; i <= 5001; i++) {
		if(arr[i] != 0) {
			for(j = 1; j <= 10000; j++) {
				if(arr[j]%i == 0 && arr[j] != i)
					arr[j] = 0;
			}
		}
	}
	for(i = 0; i < 1000; i++) {
		arr[i] = 0;
	}
	cin>>testcase;
	for(i = 0; i < testcase; i++) {
		cin>>num1>>num2;
		if(num1 == num2) {
			cnt[num1] = -1;
			cout<<0<<endl;
			continue;
		}
		for(j = 1; j <= 10000; j++) {
			cnt[j] = 0;
		}
		
		cnt[num1] = 0;
		Queue.push(num1);
		cnt[num1]++;
		while(Queue.empty() != true) {
			num1 = Queue.front();
			Queue.pop();
			ten = 1000;

			for(j = 1; j <=4; j++) {
				var = num1-(num1%(ten*10)/ten)*ten;
				for(k = 0; k <= 9; k++) {
						
					temp = var+k*ten;
						
							if(temp == arr[temp]) {
								if(cnt[temp] == 0) {
									Queue.push(temp);		
									cnt[temp] = cnt[num1]+1;
								}
								else{
									if(cnt[temp] >= cnt[num1]+1) {
										Queue.push(temp);
										cnt[temp] = cnt[num1]+1;
									}
								}
							}
						
					
				}
				ten = ten/10;
			}
		}
	if(cnt[num2] == 0)
		cout<<"Impossible"<<endl;
	else
		cout<<cnt[num2]-1<<endl;
	}


	return 0;
}
#include <iostream>

using namespace std;

int main(void) {
	int N, K;
	int cnt, i, j, k, chk, min, answer;
	int *input, *distance, *plug;

	cin>>N>>K;
	input = new int[K+1];
	distance = new int[N+1];
	plug = new int[N+1];
	for(i = 1; i <= K; i++) {
		cin>>input[i];
	}

	cnt = 1;answer = 0;
	for(i = 1; i <= K; i++) {
		if(cnt != N+1) {
			plug[cnt++] = input[i];
		} else {
			chk = 0;
			for(j = 1; j <= N; j++) {
				if(plug[j] == input[i]) {
					chk = 1;
					break;
				}
			}
			if(chk == 1)
				continue;
			else {
				for(j = 1; j <= N; j++) {
					for(k = i+1; k <= K; k++) {
						if(plug[j] == input[k]) {
							distance[plug[j]] = k-i;
							break;
						}
					}
					if(k == K+1)
						distance[plug[j]] = k-i;
				}
				min = 0;
				distance[0] = -100000;
				for(j = 1; j <= N; j++) {
					if(distance[min] < distance[plug[j]])
						min = plug[j];
				}
				for(j = 1; j <= N; j++) {
					if(plug[j] == min)
						break;
				}
				plug[j] = input[i];
				answer++;
			}
		}



	}

	cout<<answer;

	return 0;
}
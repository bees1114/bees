#include <stdio.h>
#include <stdlib.h>

int main(void) {
	unsigned long long int K, j;
	unsigned long long int zero, one, total, temp, pretotal;
	int i;
	int flag = 0;
	char arr[1000];

	//

	scanf("%lld", &K);
	while(K > 0) {
		zero = 0; one = 1;
		pretotal = 0;
		total = 1;
		for(i = 0 ; i < K; i++) {
			total += zero + one;
				if(total > K)
					break;
			temp = zero;
			zero = one + zero;
			one = temp;
			pretotal = total;
		}
		i++;	
		arr[i] = '1';
		K = K - pretotal;
		if(K == 1) {
			arr[1] = '1';
			break;
		}

	}

	for(i = 999; i >= 1; i--) {
		if(arr[i] == '1') {
			printf("%d", arr[i]-'0');
			flag = 1;
		}
		if(arr[i] != '1' && flag == 1)
			printf("%d", 0);
		arr[i]= '0';
	}
	
	
	return 0;
}
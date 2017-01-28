#include <stdio.h>

int main(void) {
   	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
   	   그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
   	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	
	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 '시간 초과'로 강제 종료 되었을 때,
	   printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   시간 초과 전까지 실행된 결과 점수를 받고자 하신다면 "setbuf(stdout, NULL);" 를 사용하시기 바랍니다. */
	
	int T;
	int test_case;
	int a, b, c, K, N;
	int i, j, aorb;
	int ca, cb;
	char winner;
	
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);


	scanf("%d", &T);

	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        scanf("%d %d %d", &a, &b, &c);
		
		printf("Case #%d\n", test_case);
        
		for ( i = 0 ; i< c; i++) {
			ca = 0; cb = 0; aorb=1;
			
			scanf("%d %d", &N, &K);
			N--;
			while(1) {
				if(aorb%2 ==1) {
				N = N - a*K;
				ca++;
				}
				else {
				N = N - b*K;
				cb++;
				}
				if((aorb%2 == 1 && N < a*K) || (aorb%2 == 0 && N < b*K))
					break;
				aorb++;
			}
			aorb++;
			if(ca == cb)
				winner = 'b';
			else if(aorb%2 == 0 && N%(b*K)!= 0)
				winner = 'b';
			else 
				winner = 'a';

			printf("%c", winner);
		}
       
        printf("\n");


		// 이 부분에서 정답을 출력하십시오.
		
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd) {
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	while(Lpos <=LeftEnd && Rpos <= RightEnd)
		if(A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];

	while(Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];
	while(Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];

	for(i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];
}

void MSort(int A[], int TmpArray[], int Left, int Right) {
	int Center;
	if(Left < Right) {
		Center = (Left + Right)/2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center+1, Right);
		Merge(A, TmpArray, Left, Center+1, Right);
	}
}

int main(void) {
	int i;
	int array[12] = { 5,12,1,3,2,11,8,9,7,4,6,10};
	int Sarray[12] = {0};
	printf("Befor Sorting : ");
	for( i = 0; i < 11; i ++)
	printf("%5d", array[i]);
	printf("\n");
	printf("After Sorting : ");
	MSort(array, Sarray, 0, 11);
	for( i = 0; i < 11; i++)
	printf("%5d", Sarray[i]);
}
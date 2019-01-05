#include <stdio.h>
#include <stdlib.h>

void sorting(int *a, int size) {	//	sorting함수 작성
	int m, n, temp;	//	인덱스를 가르킬 변수 m, n과 temp값을 가질 변수 temp 생성
	for (m = 0; m < size; m++) {	//	인덱스끼리 비교해가며 소팅을 함.
		for (n = m + 1; n < size; n++) {
			if (*(a + m) > *(a + n)) {
				temp = *(a + m);
				*(a + m) = *(a + n);
				*(a + n) = temp;
			}
		}
	}
}

int main(void) {
	int a[5][5];	//	2차원 배열(5x5) 선언
	int *pa = &a[0];	//	a[0]의 주솟값을 갖는 포인터변수 pa 선언

	for (int i = 0; i < 25; i++)
		*(pa++) = rand() % 100;	//	포인터변수를 이용하여 배열 a에 난수 입력

	sorting(a, 25);	//	sorting함수 사용

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%d \t", *(*(a + i) + j));	//	2차원배열의 포인터를 이용한 프린팅
		puts("");	//	가독성을 위한 개행
	}
	puts("");	//	가독성을 위한 개행
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int line;	//	몇 줄로 출력할건지에 대한 변수 선언
	printf("라인 수 입력: ");
	scanf(" %d", &line);	//	line을 사용자에게 입력받음
	int half = line / 2 + 1;	//	line의 절반보다 하나 많은 변수인 half 선언

	if (line % 2 == 0)	//	만약 line이 짝수면, 홀수로 만들어준 후 진행
		line++;	//	line = line + 1;
	if (line % 2 == 1) {	//	만약 line이 홀수면,

		for (int i = 0; i < half; i++) {	//첫줄부터 half줄까지 공백과 별 출력하는 반복문

			for (int j = 1; half - i > j; j++) {	//	공백 출력
				printf(" ");
			}

			for (int k = 0; k < i * 2 + 1; k++) {	//	별 출력
				printf("*");
			}
			printf("\n");	//	개행

		}

		for (int i = 0; i < line - half; i++) {		//	half줄 이후부터 마지막줄까지 공백과 별 출력하는 반복문

			for (int j = 0; j <= i; j++) {	//	공백 출력
				printf(" ");
			}

			for (int k = (line - 2 * i - 2); k > 0; k--) {	//	별 출력
				printf("*");
			}

			printf("\n");	//	개행

		}

	}

}
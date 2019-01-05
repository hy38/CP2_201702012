#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	float inputNumber;	//	float 형 변수 inputNumber 생성
	printf("input number : ");
	scanf("%f", &inputNumber);	//	inputNumber에 입력받은 float형 값을 allocate

	printf("integer : %d\n", (int)inputNumber);	//	float형의 변수 a를 int형으로 형변환하여 소수점을 절사
	printf("float : %f\n", inputNumber - (int)inputNumber);	//	원래의 float형의 변수 a에서 소수점을 절사한 것을 빼서 소수점을 얻어냄.

}
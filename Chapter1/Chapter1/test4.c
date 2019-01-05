#include <stdio.h>

int main(void) {

	double x, y;	//double형 변수 x, y를 선언한다.
	printf("두 정수를 입력하시오: ");	
	scanf(" %lf %lf", &x, &y);	//두 변수 x,y를 입력받는다.

	printf(" %.2lf", (x + y) / 2.);	//두 변수 x,y의 평균을 소수 둘째자리까지 출력한다.

}
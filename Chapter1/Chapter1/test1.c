#include <stdio.h>
#define add(x,y) x+y	//덧셈에 대한 매크로 식
#define subtract(x,y) x-y	//뺄셈에 대한 매크로 식
#define multiply(x,y) x*y	//곱셈에 대한 매크로 식
#define divide(x,y) x/y		//나눗셈에 대한 매크로 식

int main(void) {
	int x, y;	//두 개의 정수형 변수를 선언한다.

	printf("두 정수를 입력하시오: "); 
	scanf(" %d %d", &x, &y);	//두 정수를 입력받는다.

	printf("%d\n", add(x, y));
	printf("%d\n", subtract(x, y));
	printf("%d\n", multiply(x, y));
	printf("%f\n", divide(x, y));

}
#include <stdio.h>
#define toC(x) 5.0/9.0 * (x-32.0)	//입력받은 double형 변수 x를 화씨온도라 가정하고 섭씨온도로 바꾸는 매크로 식.
#define toF(x) (9.0/5.0) * x + 32.0	//입력받은 double형 변수 x를 섭씨온도라 가정하고 화씨온도로 바꾸는 매크로 식.

int main(void) {
	double x;	//double형 변수 x를 선언
	printf("실수를 입력하시오: ");
	scanf(" %lf", &x);	//변수 x를 입력받는다.

	printf("임의의 실수 %.2lf에 대한 섭씨온도 : %+.2lf \n", x, toC(x));	//입력받은 double형 변수 x를 화씨온도라 가정하고 섭씨온도로 바꾼다.	이때 부호를 표시하며, 소수 둘째자리까지 나타낸다.
	printf("임의의 실수 %.2lf에 대한 화씨온도 : %+.2lf \n", x, toF(x));	//입력받은 double형 변수 x를 섭씨온도라 가정하고 화씨온도로 바꾼다. 이때 부호를 표시하며, 소수 둘째자리까지 나타낸다.

}
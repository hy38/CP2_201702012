#include <stdio.h>

int main(void) {
	const double PHI = 3.14;	//const 상수를 이용하여 PHI의 값을 설정한다.
	double radius;	//double형 변수 radius를 선언한다.
	printf("반지름을 입력하시오: ");
	scanf(" %lf", &radius);	//double형 변수 radius를 입력받는다.

	double area = radius * radius * PHI;	//double형 변수인 area (면적)에 관한 함수식을 작성한다.
	double circumference = 2 * PHI * radius;	//double형 변수인 circumference (원주)에 관한 함수식을 작성한다.

	printf("원의 반지름 : %.2lf\n", radius);	//radius를 출력한다.
	printf("원의 면적 : %.2lf\n", area);	//area를 출력한다.
	printf("원의 둘레 : %.2lf\n", circumference);	//circumference를 출력한다.

}

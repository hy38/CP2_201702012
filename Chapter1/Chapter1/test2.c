#include <stdio.h>

int main(void) {
	char x;	//char형 변수 x를 선언.

	printf("char형의 문자를 입력받아 해당 아스키 코드의 8, 10, 16 진수를 출력하시오. \n");
	scanf(" %c", &x);	//char형 변수인 x를 입력받는다.
	printf("문자입력 : ");
	printf("8진수 : %o \t 10진수 : %d \t 16진수 : %x\n", x, x, x);	//x에 대한 각 진수들의 값 출력.

	printf("해당 아스키 코드를 순서대로 입력해서 맞는지 확인하시오.\n");
	printf("%o, %d, %x \n", x, x, x);	//x에 대한 각 진수들의 값을 출력한다.
	printf("%c, %c, %c \n", 0043, 35, 0x23);	//위 출력값들을 이 식에 대입하여 과제를 잘 해결하였는지 확인한다.
	
}
	
	
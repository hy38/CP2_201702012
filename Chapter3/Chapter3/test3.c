#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
//	isalpha가==0이면 영문자가 아니다.	//	isdigit==0이면 숫자가 아니다.	

int main() {
	char a[6];	//	크기가 6인 배열 a를 생성한다.
	while (1) {	//	무한반복문을 작성한다.
		printf("문자 5개를 입력하시오: ");
		scanf("%s", &a);	//	배열 a를 사용자에게 입력받는다.

		if (isalpha(a[0]) == 0 || isdigit(a[0]) != 0) {	//	첫째 수를 검사하는 if문
			if(a[0]!='_')
			break;	//	만약 이 조건문에 해당한다면, 무한반복문을 나간다.
		}

		for (int i = 1; i < 5; i++) {	//	둘째 수부터 다섯번 째 수 까지 검사하는 if문을 반복시켜주는 for 반복문.

			if (isalpha(a[i]) == 0 && isdigit(a[i]) == 0 && a[i] != '_') { 	//	두번째 인덱스의 char이 영문자도 아니고, 숫자도 아니고, _도 아니면 for 반복문을 나간다.
			goto end_of_nested_loop;	//	중첩반복문을 빠져나오기 위해 불가피하게 goto문을 사용하였습니다. goto를 사용하지 않으려면, for문을 사용하지 않고, 바로 위의 if문의 i에 
										//	각각 1부터 4까지를 넣어 코드를 짜면 될 것 같습니다.
			}
		}
		if (!strcmp(a, "float")) {	//	strcmp 함수를 사용하여 배열 a와 float을 비교하여 같으면 while문을 나간다.
			break;
		}
		else if (!strcmp(a, "short")) {	//	strcmp 함수를 사용하여 배열 a와 float을 비교하여 같으면 while문을 나간다.
			break;
		}
		printf("true : it is available \n");	//	모든 조건을 통과하였으면 이를 출력한다.
	}
	end_of_nested_loop:;	//	while문을 탈출한 곳.
}
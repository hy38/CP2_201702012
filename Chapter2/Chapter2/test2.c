#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

void main() {
	char a[6];	//	char형 배열 생성. 마지막 인덱스는 \0이 필요하다고 들어서 5개를 입력할 것이지만 6개로 늘렸습니다.

	printf("input 5 character : ");
	scanf(" %s", a);	//	배열 a를 입력받음.
	//	isalpha가==0이면 영문자가 아니다.	//	isdigit==0이면 숫자가 아니다.	
	if (isalpha(a[0]) == 0 && isdigit(a[0]) != 0 && a[0] != '_') {		//첫번째 인덱스의 char이 영문자는 아니고, 숫자는 맞고, _도 아니면 다음 오류 메세지 출력.
		printf("false : first word wrong \n");
	}

	else if (isalpha(a[1]) == 0 && isdigit(a[1]) == 0 && a[1] != '_') {		//두번째 인덱스의 char이 영문자도 아니고, 숫자도 아니고, _도 아니면 다음 메세지 출력.
		printf("false : second word wrong \n");
	}

	else if (isalpha(a[2]) == 0 && isdigit(a[2]) == 0 && a[2] != '_') {		//세번째 인덱스의 char이 영문자도 아니고, 숫자도 아니고, _도 아니면 다음 메세지 출력.
		printf("false : third word wrong \n");
	}

	else if (isalpha(a[3]) == 0 && isdigit(a[3]) == 0 && a[3] != '_') {		//네번째 인덱스의 char이 영문자도 아니고, 숫자도 아니고, _도 아니면 다음 메세지 출력.
		printf("false : fourth word wrong \n");
	}

	else if (isalpha(a[4]) == 0 && isdigit(a[4]) == 0 && a[4] != '_') {		//다섯번째 인덱스의 char이 영문자도 아니고, 숫자도 아니고, _도 아니면 다음 메세지 출력.
		printf("false : fifth word wrong \n");
	}

	else if (!strcmp(a, "float")) {	//	strcmp 함수를 사용하여 배열 a와 float을 비교
		printf("false : float is keyword \n");
	}

	else if (!strcmp(a, "short")) {	//	strcmp 함수를 사용하여 배열 a와 short를 비교
		printf("false : short is keyword \n");
	}

	else		//	else일 경우 다음 문장 출력.
		printf("true : it is available \n");

	printf("%s \n", a);		//주어진 문자배열 출력

}
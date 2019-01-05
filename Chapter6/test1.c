#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkVariableName(char a[], int size) {	//	함수 작성

	for (int i = 1; i < size - 1; i++) {	//	반복문 사용
		if (isalpha(a[i]) == 0 && isdigit(a[i]) == 0 && a[i] != '_') {	//	a[1] ~ a[4]의 문자가 알파벳이 아니고, 숫자가 아니고 '_'가 아니면 오류 메세지 출력
			return 0;
		}
	}
	if (isalpha(a[0]) == 0 && a[0] != '_') {	//	첫번째 문자가 알파벳이 아니고, '_'가 아니면 오류 메세지 출력
		return 0;
	}

	else if (strcmp(a, "float") == 0) {	//	a와 "float"을 비교하여 같으면 0을 반환
		return 0;
	}

	else if (strcmp(a, "short") == 0) {	//	a와 "short"를 비교하여 같으면 0을 반환
		return 0;
	}

	return 1;
}

void main() {
	char a[6];
	printf("검사할 변수명 입력 : ");

	scanf(" %s", a);

	printf("%d\n", checkVariableName(a, 6));
}
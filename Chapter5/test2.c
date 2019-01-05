#include <stdio.h>

void stringUpper(char* b, int size) {	//	문자열의 각 단어의 시작을 대문자로 바꿔주는 함수 작성
	for (int i = 0; i < size; i++) {
		for (char alpha = 'a'; alpha <= 'z'; alpha++) {
			if (*(b) == alpha)
				*(b + 0) = *(b + 0) - 32;	//	char배열의 시작을 대문자처리
			if (*(b + i) == ' ' && (alpha == *(b + i + 1)))
				*(b + i + 1) = alpha - 32;	//	공백 다음의 문자를 대문자처리
		}
	}
}

void main() {

	char c[92] = "only Get One shot Do Not miss your Chance to blow this opportunity comes once in a lifetime";

	stringUpper(c, 92);	//	'char *'의 간접 참조 수준이 'char (*)[92]'과(와) 다릅니다. 라는 오류가 나서 c앞의 &를 지웠습니다.

	printf("%s \n", c);
}
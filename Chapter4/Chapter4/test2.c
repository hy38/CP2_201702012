#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {		//	main함수

	char inputChar[11];	//	char타입의 크기가 11인 inputChar배열 생성
	printf("문자 10개를 입력: ");
	scanf("%s", &inputChar);	//	사용자에게 10개의 문자를 입력받아 inputChar배열에 저장한다
	int count = 0;	//	int형 변수 count 선언 후 0으로 초기화해준다.

	puts("");	//	가독성을 위하여 개행을 해준다.
	for (char alpha = 'a', ALPHA = 'A'; alpha <= 'z'; alpha++, ALPHA++) {	//	지역변수 alpha와 ALPHA가 각각 'a' 와 'A'일 때, 이들이 각각 'z'와 'Z'가 될 때 까지 for문을 반복한다.
		for (int i = 0; i < 10; i++) {	//	inputChar의 인덱스를 0부터 9까지 늘려가면서
			if (inputChar[i] == (alpha) || inputChar[i] == ALPHA) {	//	 그 인덱스에 있는 문자와 alpha 혹은 ALPHA와 같은지를 검사한다.
				count++;	//	같으면 count = count + 1 을 해준다.
			}
		}
		printf("\t [%c] = %d개 \n", alpha, count);	//	다음을 출력한다.
		count = 0;	//	count를 0으로 다시 초기화 한 후에 다시 처음 for문으로 가서 반복을 수행한다.
	}

}
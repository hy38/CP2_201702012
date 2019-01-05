#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//ctype.h의 isdigit(), isalpha() 사용하지 않기
//반복문 사용 금지
void main() {
	char a[6];	//	char형 배열 a 생성
	printf("input 5 character : ");
	scanf(" %s", a);	//	배열 a를 입력받음.

	if (!(a[0] >= 'A' && a[0] <= 'Z') && !(a[0] >= 'a' && a[0] <= 'z') && (a[0] != '_'))//	a[0]이 영문자가 아니고, '_' 가 아니면 오류 표시
		printf("false : first word wrong \n");
	
	else if (!(a[1] >= 'A' && a[1] <= 'Z') && !(a[1] >= 'a' && a[1] <= 'z') && !(a[1] >= '0' && a[1] <= '9') && (a[1] != '_'))//	a[1]이 영문자가 아니고, 숫자가 아니고, '_' 가 아니면 오류 표시
		printf("false : second word wrong \n");

	else if (!((a[2] >= 'A' && a[2] <= 'Z') || (a[2] >= 'a' && a[2] <= 'z')) && !(a[2] >= '0' && a[2] <= '9') && !(a[2] == '_'))//	a[2]이 영문자가 아니고, 숫자가 아니고, '_' 가 아니면 오류 표시
		printf("false : third word wrong \n");

	else if (!((a[3] >= 'A' && a[3] <= 'Z') || (a[3] >= 'a' && a[3] <= 'z')) && !(a[3] >= '0' && a[3] <= '9') && !(a[3] == '_'))//	a[3]이 영문자가 아니고, 숫자가 아니고, '_' 가 아니면 오류 표시
		printf("false : fourth word wrong \n");

	else if (!((a[4] >= 'A' && a[4] <= 'Z') || (a[4] >= 'a' && a[4] <= 'z')) && !(a[4] >= '0' && a[4] <= '9') && !(a[4] == '_'))//	a[4]가 영문자가 아니고, 숫자가 아니고, '_' 가 아니면 오류 표시
		printf("false : fifth word wrong");

	else if (a[0] == 'f' && a[1] == 'l' && a[2] == 'o' && a[3] == 'a' && a[4] == 't')	//	char형 배열 a가 0부터 4까지의 인덱스에 각각 f, l, o, a, t 를 갖고 있으면 오류 표시
		printf("false : %s is keyword! \n", a);

	else if (a[0] == 's' && a[1] == 'h' && a[2] == 'o' && a[3] == 'r' && a[4] == 't')	//	char형 배열 a가 0부터 4까지의 인덱스에 각각 s, h, o, r, t 를 갖고 있으면 오류 표시
		printf("false : %s is keyword! \n", a);

	else		//	그 외의 경우에는 다음의 문장 표시
		printf("true : it is available \n");

	printf("%s \n", a);		//주어진 문자배열 출력

}
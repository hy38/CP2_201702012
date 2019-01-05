#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//	표준 입출력
#include <stdlib.h>	//	exit() 사용을 위함
#include <string.h>	//	strcpy() 사용을 위함

/*
(실습문제2)
old.txt 를 new.txt로 복사

(과제)
src1.txt의 내용 뒤에 src2.txt의 내용을 붙이기
결과물은 Result.txt로 저장하기

(해야할 것)
== > src1.txt의 뒤에 src2.txt를 복사하고
src1.txt를 Result.txt로 다시 저장하기
*/

int main(int argc, char *argv[])
{
	FILE *src, *src2, *Result;	//	파일 포인터 생성
	char srcn[40], srcn2[40], Resultn[80];
	char txt[512];

	if (argc != 4)	//	뭔진 잘 모르겠지만, 실습문제 2를 참고하여 4로 바꾸었습니다.
	{
		printf("사용법: appendAndCopy appendDesfile srcfile copyDesfile\n");
		exit(1);
	}
	//argv[1] : src1.txt, argv[2] : src2.txt, argv[3] : Result.txt
	strcpy(srcn, argv[1]);// argv[0] = asdf1.c (현재 소스코드 파일 자신)
	strcpy(srcn2, argv[2]);
	strcpy(Resultn, argv[3]);

	if ((src = fopen(srcn, "a")) == NULL)	//	src1.txt 파일을 append 형식으로 열고, 안열리면 다음을 출력
	{
		printf("이어서 추가 작성할 파일이 열리지 않습니다.\n");
		exit(1);
	}
	if ((src2 = fopen(srcn2, "r")) == NULL)	//	src2.txt 파일을 read 형식으로열고, 안열리면 다음을 출력
	{
		printf("읽어올 파일이 열리지 않습니다.\n");
		exit(1);
	}
	if ((Result = fopen(Resultn, "w")) == NULL)	//	Result.txt 파일을 write 형식으로 열고, 안열리면 다음을 출력
	{
		printf("추가 작성한 파일을 복사할 대상 파일이 열리지 않습니다.\n");
		exit(1);
	}
	while (!feof(src2))	//	src2.txt 파일의 feof까지 갈 동안에
	{
		fgets(txt, 81, src2);	//	src2파일의 값을 읽어와서
		fputs(txt, src);	//	src파일에 append한다.
		fputs(txt, stdout);
	}
	fclose(src2);	//	src2.txt파일을 닫아준다.
	fclose(src);	//	src1.txt파일을 닫아준다.

	if ((src = fopen(srcn, "r")) == NULL)	//	src.txt 파일을 이제는 read 형식으로 열고, 안열리면 다음을 출력
	{
		printf("원본 파일이 열리지 않습니다.\n");
		exit(1);
	}

	while (!feof(src))	//	src1.txt파일의 feof까지 갈 동안에
	{
		fgets(txt, 81, src);	//	src1.txt파일의 값을 읽어와서
		fputs(txt, Result);	//	Result.txt파일에 Copy한다.
		fputs(txt, stdout);
	}
	fclose(src);	//	src1.txt파일을 닫아준다.
	fclose(Result);	//	Result.txt파일을 닫아준다.
	return 0;
}



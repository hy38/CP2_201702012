#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//	ǥ�� �����
#include <stdlib.h>	//	exit() ����� ����
#include <string.h>	//	strcpy() ����� ����

/*
(�ǽ�����2)
old.txt �� new.txt�� ����

(����)
src1.txt�� ���� �ڿ� src2.txt�� ������ ���̱�
������� Result.txt�� �����ϱ�

(�ؾ��� ��)
== > src1.txt�� �ڿ� src2.txt�� �����ϰ�
src1.txt�� Result.txt�� �ٽ� �����ϱ�
*/

int main(int argc, char *argv[])
{
	FILE *src, *src2, *Result;	//	���� ������ ����
	char srcn[40], srcn2[40], Resultn[80];
	char txt[512];

	if (argc != 4)	//	���� �� �𸣰�����, �ǽ����� 2�� �����Ͽ� 4�� �ٲپ����ϴ�.
	{
		printf("����: appendAndCopy appendDesfile srcfile copyDesfile\n");
		exit(1);
	}
	//argv[1] : src1.txt, argv[2] : src2.txt, argv[3] : Result.txt
	strcpy(srcn, argv[1]);// argv[0] = asdf1.c (���� �ҽ��ڵ� ���� �ڽ�)
	strcpy(srcn2, argv[2]);
	strcpy(Resultn, argv[3]);

	if ((src = fopen(srcn, "a")) == NULL)	//	src1.txt ������ append �������� ����, �ȿ����� ������ ���
	{
		printf("�̾ �߰� �ۼ��� ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	if ((src2 = fopen(srcn2, "r")) == NULL)	//	src2.txt ������ read �������ο���, �ȿ����� ������ ���
	{
		printf("�о�� ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	if ((Result = fopen(Resultn, "w")) == NULL)	//	Result.txt ������ write �������� ����, �ȿ����� ������ ���
	{
		printf("�߰� �ۼ��� ������ ������ ��� ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	while (!feof(src2))	//	src2.txt ������ feof���� �� ���ȿ�
	{
		fgets(txt, 81, src2);	//	src2������ ���� �о�ͼ�
		fputs(txt, src);	//	src���Ͽ� append�Ѵ�.
		fputs(txt, stdout);
	}
	fclose(src2);	//	src2.txt������ �ݾ��ش�.
	fclose(src);	//	src1.txt������ �ݾ��ش�.

	if ((src = fopen(srcn, "r")) == NULL)	//	src.txt ������ ������ read �������� ����, �ȿ����� ������ ���
	{
		printf("���� ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}

	while (!feof(src))	//	src1.txt������ feof���� �� ���ȿ�
	{
		fgets(txt, 81, src);	//	src1.txt������ ���� �о�ͼ�
		fputs(txt, Result);	//	Result.txt���Ͽ� Copy�Ѵ�.
		fputs(txt, stdout);
	}
	fclose(src);	//	src1.txt������ �ݾ��ش�.
	fclose(Result);	//	Result.txt������ �ݾ��ش�.
	return 0;
}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	float inputNumber;	//	float �� ���� inputNumber ����
	printf("input number : ");
	scanf("%f", &inputNumber);	//	inputNumber�� �Է¹��� float�� ���� allocate

	printf("integer : %d\n", (int)inputNumber);	//	float���� ���� a�� int������ ����ȯ�Ͽ� �Ҽ����� ����
	printf("float : %f\n", inputNumber - (int)inputNumber);	//	������ float���� ���� a���� �Ҽ����� ������ ���� ���� �Ҽ����� ��.

}
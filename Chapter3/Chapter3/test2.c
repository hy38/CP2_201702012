#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int inputedInteger, inputedBinaryNumber, quotient, remainder;	//	�Է¹��� 10������ ����, 2������ ��, ��, ������ ���� ����
	int array1[99999];	//	������ ū �迭 ����
	printf("������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &inputedInteger);	//	10������ ������ �Է¹޴´�.

	int count = 0;	//	count ������ ����� 0���� �ʱ�ȭ�Ѵ�.

	while (inputedInteger / 2 > 0) {	//	�Է¹��� 10������ ������ 2�� ���� ���� 0���� Ŭ �� ������ while���� �ݺ��Ѵ�
		//quotient = inputedInteger / 2;
		remainder = inputedInteger % 2;	//	�������� �Է¹��� 10���� ��ⷯ 2 �� ����Ѵ�.
		inputedInteger = inputedInteger / 2;	//	�Է¹��� 10������ ������ 2�� ��� ������ �ش�. �̴� while���� ���ǿ� ������ ��ģ��.
		array1[count] = remainder;	//	array1�̶�� �迭�� count �ε����� �������� ���� �������ش�. count�� �ʱⰪ�� 0�̿����Ƿ� �� �迭�� 0��° �ε������� ����� ���̴�.

		count++;	//	count�� �ϳ��� �÷��ش�.
	}
	array1[count] = 1;	//	��ⷯ������ ��ġ�� ���� ���� 1�� ������ �ε����� �־��ش�. �̷��� ���� array1 �迭�� ���� ���ϴ� 2������ reverse�� ���·� ������ �ִ� �迭�̴�.

	for (int i = count; i >= 0; i--)	//	���� ���� �� �迭 array1�� �� ������ �ε����� count���� �Ųٷ� ����Ͽ� ���ϴ� 2���� ��°��� ��´�.
		printf("%d", array1[i]);

	printf("\n");	//	�������� ���Ͽ� �������ش�.

	printf("������ 2������ �Է��Ͻÿ�: ");
	scanf("%d", &inputedBinaryNumber);	//	2������ ���� �Է¹޴´�.
	int sum = 0;	//	sum�̶�� ���� ��Ÿ���� ������ �����ϰ� 0���� �ʱ�ȭ���ش�.
	int newCount = 1;	//	���� �� count�ʹ� �ٸ� newCount ������ �����ϰ� 1�� �ʱ�ȭ���ش�.

	while (inputedBinaryNumber / 10 > 0) {	//	�Է¹��� 2������ ���� 10�� �ڸ����� ��� ������ ��, �� 2������ 10���� ���� ���� 0���� Ŭ ���� �� while���� �����Ѵ�.
		sum = sum + (inputedBinaryNumber % 10) * newCount;	//	sum�� �Է¹��� 2������ 10���� ��ⷯ ������ �� �����ٰ� newCount(�� ������ 1, 2, 4, 8, 16, ... �̷������� ����Ǹ�, 
															//����� ���� ���̴�.)�� ���Ѵ�.
		inputedBinaryNumber = inputedBinaryNumber / 10;	//	�Է¹��� �������� ��� 10���� ������ ���� �ٿ��ش�. �� ���� while���� ���ǿ� ������ ��ģ��.

		newCount = newCount * 2;	//	newCount ������ ���� ��ȭ�����ش�.
	}
	sum = sum + (inputedBinaryNumber % 10) * newCount;	//	while���� �������� �� ���� inputedBinaryNumber�� ���� �����Ͽ� �ش�.

	printf("%d \n", sum);	//	sum(2������ 10������ �ٲ� ��)�� ����Ѵ�.

}
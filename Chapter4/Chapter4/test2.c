#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {		//	main�Լ�

	char inputChar[11];	//	charŸ���� ũ�Ⱑ 11�� inputChar�迭 ����
	printf("���� 10���� �Է�: ");
	scanf("%s", &inputChar);	//	����ڿ��� 10���� ���ڸ� �Է¹޾� inputChar�迭�� �����Ѵ�
	int count = 0;	//	int�� ���� count ���� �� 0���� �ʱ�ȭ���ش�.

	puts("");	//	�������� ���Ͽ� ������ ���ش�.
	for (char alpha = 'a', ALPHA = 'A'; alpha <= 'z'; alpha++, ALPHA++) {	//	�������� alpha�� ALPHA�� ���� 'a' �� 'A'�� ��, �̵��� ���� 'z'�� 'Z'�� �� �� ���� for���� �ݺ��Ѵ�.
		for (int i = 0; i < 10; i++) {	//	inputChar�� �ε����� 0���� 9���� �÷����鼭
			if (inputChar[i] == (alpha) || inputChar[i] == ALPHA) {	//	 �� �ε����� �ִ� ���ڿ� alpha Ȥ�� ALPHA�� �������� �˻��Ѵ�.
				count++;	//	������ count = count + 1 �� ���ش�.
			}
		}
		printf("\t [%c] = %d�� \n", alpha, count);	//	������ ����Ѵ�.
		count = 0;	//	count�� 0���� �ٽ� �ʱ�ȭ �� �Ŀ� �ٽ� ó�� for������ ���� �ݺ��� �����Ѵ�.
	}

}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int line;	//	�� �ٷ� ����Ұ����� ���� ���� ����
	printf("���� �� �Է�: ");
	scanf(" %d", &line);	//	line�� ����ڿ��� �Է¹���
	int half = line / 2 + 1;	//	line�� ���ݺ��� �ϳ� ���� ������ half ����

	if (line % 2 == 0)	//	���� line�� ¦����, Ȧ���� ������� �� ����
		line++;	//	line = line + 1;
	if (line % 2 == 1) {	//	���� line�� Ȧ����,

		for (int i = 0; i < half; i++) {	//ù�ٺ��� half�ٱ��� ����� �� ����ϴ� �ݺ���

			for (int j = 1; half - i > j; j++) {	//	���� ���
				printf(" ");
			}

			for (int k = 0; k < i * 2 + 1; k++) {	//	�� ���
				printf("*");
			}
			printf("\n");	//	����

		}

		for (int i = 0; i < line - half; i++) {		//	half�� ���ĺ��� �������ٱ��� ����� �� ����ϴ� �ݺ���

			for (int j = 0; j <= i; j++) {	//	���� ���
				printf(" ");
			}

			for (int k = (line - 2 * i - 2); k > 0; k--) {	//	�� ���
				printf("*");
			}

			printf("\n");	//	����

		}

	}

}
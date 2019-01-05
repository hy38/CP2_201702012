#include <stdio.h>
#include <stdlib.h>

void sorting(int *a, int size) {	//	sorting�Լ� �ۼ�
	int m, n, temp;	//	�ε����� ����ų ���� m, n�� temp���� ���� ���� temp ����
	for (m = 0; m < size; m++) {	//	�ε������� ���ذ��� ������ ��.
		for (n = m + 1; n < size; n++) {
			if (*(a + m) > *(a + n)) {
				temp = *(a + m);
				*(a + m) = *(a + n);
				*(a + n) = temp;
			}
		}
	}
}

int main(void) {
	int a[5][5];	//	2���� �迭(5x5) ����
	int *pa = &a[0];	//	a[0]�� �ּڰ��� ���� �����ͺ��� pa ����

	for (int i = 0; i < 25; i++)
		*(pa++) = rand() % 100;	//	�����ͺ����� �̿��Ͽ� �迭 a�� ���� �Է�

	sorting(a, 25);	//	sorting�Լ� ���

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%d \t", *(*(a + i) + j));	//	2�����迭�� �����͸� �̿��� ������
		puts("");	//	�������� ���� ����
	}
	puts("");	//	�������� ���� ����
}

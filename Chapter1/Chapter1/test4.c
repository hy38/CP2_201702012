#include <stdio.h>

int main(void) {

	double x, y;	//double�� ���� x, y�� �����Ѵ�.
	printf("�� ������ �Է��Ͻÿ�: ");	
	scanf(" %lf %lf", &x, &y);	//�� ���� x,y�� �Է¹޴´�.

	printf(" %.2lf", (x + y) / 2.);	//�� ���� x,y�� ����� �Ҽ� ��°�ڸ����� ����Ѵ�.

}
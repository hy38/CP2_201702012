#include <stdio.h>
#define add(x,y) x+y	//������ ���� ��ũ�� ��
#define subtract(x,y) x-y	//������ ���� ��ũ�� ��
#define multiply(x,y) x*y	//������ ���� ��ũ�� ��
#define divide(x,y) x/y		//�������� ���� ��ũ�� ��

int main(void) {
	int x, y;	//�� ���� ������ ������ �����Ѵ�.

	printf("�� ������ �Է��Ͻÿ�: "); 
	scanf(" %d %d", &x, &y);	//�� ������ �Է¹޴´�.

	printf("%d\n", add(x, y));
	printf("%d\n", subtract(x, y));
	printf("%d\n", multiply(x, y));
	printf("%f\n", divide(x, y));

}
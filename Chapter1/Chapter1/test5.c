#include <stdio.h>

int main(void) {
	const double PHI = 3.14;	//const ����� �̿��Ͽ� PHI�� ���� �����Ѵ�.
	double radius;	//double�� ���� radius�� �����Ѵ�.
	printf("�������� �Է��Ͻÿ�: ");
	scanf(" %lf", &radius);	//double�� ���� radius�� �Է¹޴´�.

	double area = radius * radius * PHI;	//double�� ������ area (����)�� ���� �Լ����� �ۼ��Ѵ�.
	double circumference = 2 * PHI * radius;	//double�� ������ circumference (����)�� ���� �Լ����� �ۼ��Ѵ�.

	printf("���� ������ : %.2lf\n", radius);	//radius�� ����Ѵ�.
	printf("���� ���� : %.2lf\n", area);	//area�� ����Ѵ�.
	printf("���� �ѷ� : %.2lf\n", circumference);	//circumference�� ����Ѵ�.

}

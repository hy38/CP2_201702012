#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//ctype.h�� isdigit(), isalpha() ������� �ʱ�
//�ݺ��� ��� ����
void main() {
	char a[6];	//	char�� �迭 a ����
	printf("input 5 character : ");
	scanf(" %s", a);	//	�迭 a�� �Է¹���.

	if (!(a[0] >= 'A' && a[0] <= 'Z') && !(a[0] >= 'a' && a[0] <= 'z') && (a[0] != '_'))//	a[0]�� �����ڰ� �ƴϰ�, '_' �� �ƴϸ� ���� ǥ��
		printf("false : first word wrong \n");
	
	else if (!(a[1] >= 'A' && a[1] <= 'Z') && !(a[1] >= 'a' && a[1] <= 'z') && !(a[1] >= '0' && a[1] <= '9') && (a[1] != '_'))//	a[1]�� �����ڰ� �ƴϰ�, ���ڰ� �ƴϰ�, '_' �� �ƴϸ� ���� ǥ��
		printf("false : second word wrong \n");

	else if (!((a[2] >= 'A' && a[2] <= 'Z') || (a[2] >= 'a' && a[2] <= 'z')) && !(a[2] >= '0' && a[2] <= '9') && !(a[2] == '_'))//	a[2]�� �����ڰ� �ƴϰ�, ���ڰ� �ƴϰ�, '_' �� �ƴϸ� ���� ǥ��
		printf("false : third word wrong \n");

	else if (!((a[3] >= 'A' && a[3] <= 'Z') || (a[3] >= 'a' && a[3] <= 'z')) && !(a[3] >= '0' && a[3] <= '9') && !(a[3] == '_'))//	a[3]�� �����ڰ� �ƴϰ�, ���ڰ� �ƴϰ�, '_' �� �ƴϸ� ���� ǥ��
		printf("false : fourth word wrong \n");

	else if (!((a[4] >= 'A' && a[4] <= 'Z') || (a[4] >= 'a' && a[4] <= 'z')) && !(a[4] >= '0' && a[4] <= '9') && !(a[4] == '_'))//	a[4]�� �����ڰ� �ƴϰ�, ���ڰ� �ƴϰ�, '_' �� �ƴϸ� ���� ǥ��
		printf("false : fifth word wrong");

	else if (a[0] == 'f' && a[1] == 'l' && a[2] == 'o' && a[3] == 'a' && a[4] == 't')	//	char�� �迭 a�� 0���� 4������ �ε����� ���� f, l, o, a, t �� ���� ������ ���� ǥ��
		printf("false : %s is keyword! \n", a);

	else if (a[0] == 's' && a[1] == 'h' && a[2] == 'o' && a[3] == 'r' && a[4] == 't')	//	char�� �迭 a�� 0���� 4������ �ε����� ���� s, h, o, r, t �� ���� ������ ���� ǥ��
		printf("false : %s is keyword! \n", a);

	else		//	�� ���� ��쿡�� ������ ���� ǥ��
		printf("true : it is available \n");

	printf("%s \n", a);		//�־��� ���ڹ迭 ���

}
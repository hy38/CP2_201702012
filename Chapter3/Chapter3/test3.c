#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
//	isalpha��==0�̸� �����ڰ� �ƴϴ�.	//	isdigit==0�̸� ���ڰ� �ƴϴ�.	

int main() {
	char a[6];	//	ũ�Ⱑ 6�� �迭 a�� �����Ѵ�.
	while (1) {	//	���ѹݺ����� �ۼ��Ѵ�.
		printf("���� 5���� �Է��Ͻÿ�: ");
		scanf("%s", &a);	//	�迭 a�� ����ڿ��� �Է¹޴´�.

		if (isalpha(a[0]) == 0 || isdigit(a[0]) != 0) {	//	ù° ���� �˻��ϴ� if��
			if(a[0]!='_')
			break;	//	���� �� ���ǹ��� �ش��Ѵٸ�, ���ѹݺ����� ������.
		}

		for (int i = 1; i < 5; i++) {	//	��° ������ �ټ��� ° �� ���� �˻��ϴ� if���� �ݺ������ִ� for �ݺ���.

			if (isalpha(a[i]) == 0 && isdigit(a[i]) == 0 && a[i] != '_') { 	//	�ι�° �ε����� char�� �����ڵ� �ƴϰ�, ���ڵ� �ƴϰ�, _�� �ƴϸ� for �ݺ����� ������.
			goto end_of_nested_loop;	//	��ø�ݺ����� ���������� ���� �Ұ����ϰ� goto���� ����Ͽ����ϴ�. goto�� ������� ��������, for���� ������� �ʰ�, �ٷ� ���� if���� i�� 
										//	���� 1���� 4������ �־� �ڵ带 ¥�� �� �� �����ϴ�.
			}
		}
		if (!strcmp(a, "float")) {	//	strcmp �Լ��� ����Ͽ� �迭 a�� float�� ���Ͽ� ������ while���� ������.
			break;
		}
		else if (!strcmp(a, "short")) {	//	strcmp �Լ��� ����Ͽ� �迭 a�� float�� ���Ͽ� ������ while���� ������.
			break;
		}
		printf("true : it is available \n");	//	��� ������ ����Ͽ����� �̸� ����Ѵ�.
	}
	end_of_nested_loop:;	//	while���� Ż���� ��.
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkVariableName(char a[], int size) {	//	�Լ� �ۼ�

	for (int i = 1; i < size - 1; i++) {	//	�ݺ��� ���
		if (isalpha(a[i]) == 0 && isdigit(a[i]) == 0 && a[i] != '_') {	//	a[1] ~ a[4]�� ���ڰ� ���ĺ��� �ƴϰ�, ���ڰ� �ƴϰ� '_'�� �ƴϸ� ���� �޼��� ���
			return 0;
		}
	}
	if (isalpha(a[0]) == 0 && a[0] != '_') {	//	ù��° ���ڰ� ���ĺ��� �ƴϰ�, '_'�� �ƴϸ� ���� �޼��� ���
		return 0;
	}

	else if (strcmp(a, "float") == 0) {	//	a�� "float"�� ���Ͽ� ������ 0�� ��ȯ
		return 0;
	}

	else if (strcmp(a, "short") == 0) {	//	a�� "short"�� ���Ͽ� ������ 0�� ��ȯ
		return 0;
	}

	return 1;
}

void main() {
	char a[6];
	printf("�˻��� ������ �Է� : ");

	scanf(" %s", a);

	printf("%d\n", checkVariableName(a, 6));
}
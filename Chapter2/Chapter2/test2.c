#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

void main() {
	char a[6];	//	char�� �迭 ����. ������ �ε����� \0�� �ʿ��ϴٰ� �� 5���� �Է��� �������� 6���� �÷Ƚ��ϴ�.

	printf("input 5 character : ");
	scanf(" %s", a);	//	�迭 a�� �Է¹���.
	//	isalpha��==0�̸� �����ڰ� �ƴϴ�.	//	isdigit==0�̸� ���ڰ� �ƴϴ�.	
	if (isalpha(a[0]) == 0 && isdigit(a[0]) != 0 && a[0] != '_') {		//ù��° �ε����� char�� �����ڴ� �ƴϰ�, ���ڴ� �°�, _�� �ƴϸ� ���� ���� �޼��� ���.
		printf("false : first word wrong \n");
	}

	else if (isalpha(a[1]) == 0 && isdigit(a[1]) == 0 && a[1] != '_') {		//�ι�° �ε����� char�� �����ڵ� �ƴϰ�, ���ڵ� �ƴϰ�, _�� �ƴϸ� ���� �޼��� ���.
		printf("false : second word wrong \n");
	}

	else if (isalpha(a[2]) == 0 && isdigit(a[2]) == 0 && a[2] != '_') {		//����° �ε����� char�� �����ڵ� �ƴϰ�, ���ڵ� �ƴϰ�, _�� �ƴϸ� ���� �޼��� ���.
		printf("false : third word wrong \n");
	}

	else if (isalpha(a[3]) == 0 && isdigit(a[3]) == 0 && a[3] != '_') {		//�׹�° �ε����� char�� �����ڵ� �ƴϰ�, ���ڵ� �ƴϰ�, _�� �ƴϸ� ���� �޼��� ���.
		printf("false : fourth word wrong \n");
	}

	else if (isalpha(a[4]) == 0 && isdigit(a[4]) == 0 && a[4] != '_') {		//�ټ���° �ε����� char�� �����ڵ� �ƴϰ�, ���ڵ� �ƴϰ�, _�� �ƴϸ� ���� �޼��� ���.
		printf("false : fifth word wrong \n");
	}

	else if (!strcmp(a, "float")) {	//	strcmp �Լ��� ����Ͽ� �迭 a�� float�� ��
		printf("false : float is keyword \n");
	}

	else if (!strcmp(a, "short")) {	//	strcmp �Լ��� ����Ͽ� �迭 a�� short�� ��
		printf("false : short is keyword \n");
	}

	else		//	else�� ��� ���� ���� ���.
		printf("true : it is available \n");

	printf("%s \n", a);		//�־��� ���ڹ迭 ���

}
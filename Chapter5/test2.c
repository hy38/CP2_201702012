#include <stdio.h>

void stringUpper(char* b, int size) {	//	���ڿ��� �� �ܾ��� ������ �빮�ڷ� �ٲ��ִ� �Լ� �ۼ�
	for (int i = 0; i < size; i++) {
		for (char alpha = 'a'; alpha <= 'z'; alpha++) {
			if (*(b) == alpha)
				*(b + 0) = *(b + 0) - 32;	//	char�迭�� ������ �빮��ó��
			if (*(b + i) == ' ' && (alpha == *(b + i + 1)))
				*(b + i + 1) = alpha - 32;	//	���� ������ ���ڸ� �빮��ó��
		}
	}
}

void main() {

	char c[92] = "only Get One shot Do Not miss your Chance to blow this opportunity comes once in a lifetime";

	stringUpper(c, 92);	//	'char *'�� ���� ���� ������ 'char (*)[92]'��(��) �ٸ��ϴ�. ��� ������ ���� c���� &�� �������ϴ�.

	printf("%s \n", c);
}
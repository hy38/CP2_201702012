#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

void choice_1();	//	�Լ� ���� ȣ��
void searchAll();
void searchOne();
int removingIndex;
int count = 2;

struct date {	//	����ü ����
	int year;
	int month;
	int day;
};
struct book {	//	����ü ����
	struct date open;
	char title[99];
	char author[99];
	char company[99];
	char isRented[99];
};

struct book books[15];	//	15���� å�� ������ �� �ִ� �迭 ����

int input() {	//	�Է¹޴� �κ��� �Լ��� �и���.
	puts("������ ���� ���α׷��Դϴ�");
	puts("�޴��� ������ �ּ���.");
	puts("0 : ���� �˻�");
	puts("1 : �ű� ���� ���");
	puts("2 : ��� ���� ����");
	int choice;
	scanf("%d", &choice);
	puts("");
	return choice;
}

void printBooks(int i) {	//	å ������ ����ϴ� �κ��� �Լ��� �и���.
	printf("���� �̸� : %s\n", books[i].title);
	printf("��� ���� : [%d - %d - %d]\n", books[i].open.year, books[i].open.month, books[i].open.day);
	printf("���� : %s\n", books[i].author);
	printf("���ǻ� : %s\n", books[i].company);
	printf("�뿩 ���� : %s\n", books[i].isRented);
	puts("");
}

void choice_0() {	//	0�� ����� ����� �Լ�.
	puts("1 : ��ü ���� �˻�");
	puts("2 : Ư�� ���� �˻�");
	int choice;
	scanf(" %d", &choice);
	if (choice == 1)	//	choice�� 1�̸� searchAll() �Լ� ȣ��.
		searchAll();
	else if (choice == 2)	//	choice�� 2�̸� searchOne() �Լ� ȣ��.
		searchOne();
	else	//	�� ���� �Է��� ���� ���� ó��.
		puts("���� �߻� : 1, 2 �̿��� �Է�.\n");
}

void searchAll() {	//	books[]�� ��� ���ҵ��� ������ �������� ������ִ� searchAll() �Լ�.
	for (int i = 0; i < count; i++)
		printBooks(i);
}

int distinguishingTempVar;	//	������ �ϳ� �����Ͽ� searchOne()�� ã�⸦ ������ ���� ã�⸦ ������ ��츦 �����Ѵ�. ������ ��� �� ������ 3�� ���� ������, ������ ��� 10�� ������.

void searchOne() {	//	books[]�� Ư�� ������ �˻��ϴ� searchOne() �Լ�.
	char cpr1[99];
	getchar();	//	���ۺ���

	printf("ã���ô� å ������ �Է��ϼ���: ");
	gets(cpr1);

	for (int i = 0; i < count; i++) {	//	ã�⿡ ������ ��� ã�� å�� ������ ������ش�.
		if (strcmp(cpr1, books[i].title) == 0) {	//	�Է¹��� ������ books�迭�� �ִ� ��� �������� ���� �� ��ġ�ϴ� ���� ������
			printBooks(i);
			removingIndex = i;
			distinguishingTempVar = 3;
			return 0;
		}
	}
	for (int i = 0; i < count; i++)	//	ã�⿡ ������ ��� �Ʒ��� �޼����� ������ش�.
		if (strcmp(cpr1, books[i].title) != 0) {	//	�Է¹��� ������ books�迭���ִ� ��� ������ ����� ���� ������	
			puts("ã���ô� å�� �����ϴ�.\n");
			distinguishingTempVar = 10;
			return 0;
		}
}

void library() {	//	default���� ���� �����ϴ� library() �Լ� �ۼ�.

	struct book def1;
	def1.open.year = 2017;
	def1.open.month = 04;
	def1.open.day = 06;
	strcpy(def1.title, "���뺸��ó�� ��ٴ� �����̾�");
	strcpy(def1.author, "���ȸ");
	strcpy(def1.company, "��");
	strcpy(def1.isRented, "Y");

	struct book def2;
	def2.open.year = 2017;
	def2.open.month = 03;
	def2.open.day = 02;
	strcpy(def2.title, "Good Night Stories for Rebel Girls");
	strcpy(def2.author, "Elena Favilli");
	strcpy(def2.company, "Penguin Books Ltd");
	strcpy(def2.isRented, "N");

	books[0] = def1;
	books[1] = def2;

}

void choice_1() {	//	1�� ����� ����� �Լ�.
	struct book aBook;	//	struct�� �ϳ� �����, ������ set���ش�.

	printf("����� ������ ������ �Է��Ͻÿ�: ");
	getchar();	gets(aBook.title);

	for (int i = 0; i < count; i++) {
		while (strcmp(aBook.title, books[i].title) == 0) {	//	i�ε��� �����ؾ��� ���ǹ� �ٲ�ߵ�
			printf("������ ������ å�� ��ϵǾ��ֽ��ϴ�. \n������ ����� �� �����ϴ�!\n\n");
			return 0;	//	choice_1() �Լ� ����
		}
	}

	printf("����� ������ �������(��-��-��)�� �Է��Ͻÿ�: ");
	scanf("%d %d %d", &aBook.open.year, &aBook.open.month, &aBook.open.day);

	printf("����� ������ �۰��� �Է��Ͻÿ�: ");
	getchar();	gets(aBook.author);

	printf("����� ������ ���ǻ縦 �Է��Ͻÿ�: ");
	gets(aBook.company);

	printf("����� ������ �뿩 ����(Y / N)�� �Է��Ͻÿ�: ");
	gets(aBook.isRented);

	count++;
	books[count - 1] = aBook;
}

void choice_2() {	//	2�� ����� ����� �Լ�.

	char willRemove;	//	������ ���� ���� ���� ����.

iterate:

	searchOne();	//	searchOne() �Լ� ȣ��.

	if (distinguishingTempVar == 10) {	//	search�� ���������� �ٽ� ���ư���.
		printf("\n���͸� �ѹ� �����ּ���!\n");
		goto iterate;
	}
	if (distinguishingTempVar != 10)	//	search�� �������� �ʾ����� �����Ѵ�.
		if (books[removingIndex].isRented[0] == 'Y') {	//	search������ å�� �뿩���̸� �ٽ� ���ư���.
			printf("å�� �뿩���Դϴ�. ���� ������ �� �����ϴ�.\n");
			printf("\n���͸� �ѹ� �����ּ���!\n");
			goto iterate;
		}

	printf("�� ������ �����Ϸ��� Y, ������ ����Ϸ��� N�� �Է��Ͻÿ�: \n");
	scanf("%c", &willRemove);

	if (willRemove == 'Y') {	//	�迭�� ������
		for (int i = removingIndex; i < count; i++)
			books[i] = books[i + 1];
		count--;
		puts("\n���� �Ϸ�!\n");
	}

	else if (willRemove == 'N') {	//	���� �����
		printf("���������� �����մϴ�.(���� �����)\n\n");
		return 0;
	}

	else {
		printf("�ùٸ��� ���� �Է��Դϴ�. ó������ ���ư��ϴ�.\n\n");
		return 0;
	}
}
int main(void) {	//	main()�Լ�
	library();	//	default�������� ��� library() �Լ��� ȣ���Ѵ�.

	while (1) {	//	���ѷ���
		int choice = input();

		if (choice == 0)
			choice_0();
		else if (choice == 1)
			choice_1();
		else if (choice == 2)
			choice_2();
		else {
			puts("���� �߻� : 0, 1, 2 �̿��� �Է�.\n");
			continue;
		}

	}
}
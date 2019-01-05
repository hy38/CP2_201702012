#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//	�Լ� ���� �ۼ�
void input();
void stdList();
void nameSearch();
void addStd();
void changeGrade();
void deleteStd();
void printstdList(int stdCount);
void open_read();
void open_write();
void open_append();

FILE *src;	//	���� ������ ����
char fname[] = "src.txt";

struct info {	//	����ü�� �����Ѵ�.
	char name[25];
	int stdNum;
	int gender[25];
	char grade[5];
};
struct info list[99];	//	����ü���� �迭�� �����.

void input() {

	int select = 0;

	while (select != 4) {

		printf("[1.�˻�] [2.�߰� �� ����] [3.����] [4.����] \n");
		scanf("%d", &select);

		switch (select) {
		case 1:

			system("cls");
			while (1) {
				system("cls");
				printf("�˻� �޴� �Դϴ�.\n[1.��ü ����Ʈ] [2.�̸� �˻�] [3.�ڷΰ���]\n");
				scanf("%d", &select);
				if (select == 1) {
					system("cls");
					printf("-------------- [�������� ����] --------------\n");

					stdList();	//	���� ������ �������� ����

					system("pause");
				}
				else if (select == 2) {
					system("cls");
					printf("-------------- [�̸� �˻�] -------------\n");
					printf("�˻��� �̸� �Է� : ");

					nameSearch();	//	�̸��� �Է¹޾� �л� ���� ���

					system("pause");
				}
				else
					break;
			}
			break;

		case 2:

			system("cls");
			while (1) {
				system("cls");
				printf("�߰� �� ���� �޴� �Դϴ�.\n[1.�л� �߰�] [2.���� ����] [3.�ڷΰ���]\n");
				scanf("%d", &select);
				if (select == 1) {
					system("cls");
					printf("-------------- [�л� �߰�] --------------\n");

					addStd();	//	�л��� �߰�

				}
				else if (select == 2) {
					system("cls");
					printf("-------------- [���� ����] -------------\n");
					printf("������ �л� �й� �Է� : ");

					changeGrade();	//	�й��� �Է¹޾� ���� ����

				}
				else
					break;
			}
			break;
		case 3:
			system("cls");
			printf("���� �޴� �Դϴ�.\n");

			deleteStd();	//	�й��� �Է¹޾� �л� ����

			break;
		default:
			break;
		}
		system("cls");
	}
}

int main(void) {	//	main�Լ�.
	input();	//	input()�Լ��� ȣ���Ѵ�.
}

void stdList()
{
	open_read();	//	������ �б���� ����.

	int count = 0;
	while (!feof(src)) {	//	������ fscanf�� �о �迭�� �ִ´�.
		fscanf(src, "%s %d %s %s", list[count].name, &list[count].stdNum, list[count].gender, list[count].grade);
		count++;
	}

	for (int i = 0; i < count - 1; i++)		//	���������� �������� ����
	{
		float max = atof(list[i].grade);	//	�����Է��� char�迭�� �޾ұ� ������, atof()��� �Լ��� ����Ͽ� �Ǽ������� �ٲپ ���񱳸� ���ش�.
		int max_index = i;
		for (int j = i + 1; j < count; j++)	//	�������� ������ �����Ѵ�.
		{
			float comp = atof(list[j].grade);
			if (comp > max) {
				max = comp;
				max_index = j;
			}
		}
		struct info temp = list[i];
		list[i] = list[max_index];
		list[max_index] = temp;
	}
	
	fclose(src);	//	������ �ݾ��ش�.

	open_write();	//	src.txt ������ ���� �������� ����.

	for (int i = 0; i < count; i++) {	//	���Ͽ� �迭������ �����Ѵ�.
		if (i == count - 1)	//	�������ٿ����� ������ ���� ����.
			fprintf(src, "%s %d %s %s", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
		else
			fprintf(src, "%s %d %s %s \n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
	}

	fclose(src);	//	src.txt������ �ݾ��ش�.

	printstdList(count);	//	������������ ���ĵ� �迭 ����ϱ�
}

void printstdList(int stdCount) {
	for (int i = 0; i < stdCount; i++) {	//	�迭�� �Էµ� �л������� ������ִ� �Լ�.
		printf("%s %d %s %s\n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
	}
	puts("");
}

void nameSearch() {
	//	list[]�� Ư�� �̸�(list[?].name)�� �˻��ϴ� �Լ�.
	open_read();	//	������ �б��������� ����

	int count = 0;
	while (!feof(src)) {	//	������ fscanf�� �о �迭�� �ִ´�.
		fscanf(src, "%s %d %s %s", list[count].name, &list[count].stdNum, list[count].gender, list[count].grade);
		count++;
	}

	fclose(src);	//	������ �ݴ´�.

	char cpr1[99];	//	�̸� �񱳸� ���� ������ �ϳ� �����Ѵ�.
	getchar();	//	���۸� ����.

	gets(cpr1);	// �̸��� �Է¹޴´�.
	int flag = 1;	//	flag��� ������ ����Ͽ� �̸�ã�⿡ ������ ���� ������ ��츦 �����Ѵ�. ������ ��쿡�� �����޼����� ������ش�.

	for (int i = 0; i < count; i++) {	//	�̸�ã�⿡ ������ ��� ã�� �л��� ������ ������ش�.
		if (strcmp(cpr1, list[i].name) == 0) {	//	�Է¹��� �̸��� list�迭�� �ִ� ��� �л����� �̸� �� ��ġ�ϴ� ���� ������
			printf("\n%s %d %s %s \n\n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
			flag = 0;
			return 0;
		}
	}

	if (flag != 0) {
		for (int i = 0; i < count; i++) {	//	�̸�ã�⿡ ������ ��� �Ʒ��� �޼����� ������ش�.
			if (strcmp(cpr1, list[i].name) != 0) {	//	�Է¹��� �̸��� list�迭���ִ� ��� �л����� �̸� ���� ������	
				puts("\nã���ô� �л��� �����ϴ�.\n\n");
				return 0;
			}
		}
	}
}

void addStd(){	//	�������� ���� ��� ���Ͽ� �߰��ϰ� ����
	open_append();	//	�������� ���� ����.

	struct info aStudent;	//	�ӽñ���ü aStudent ����
	printf("�л��� ���� �Է� : \n (�̸� �й� ���� ����) \n :");
	scanf("%s %d %s %s", aStudent.name, &aStudent.stdNum, aStudent.gender, aStudent.grade);	//	�л� ������ �Է¹޾� aStudent��� �ӽ� ����ü�� ����.

	fprintf(src, "\n%s %d %s %s", aStudent.name, aStudent.stdNum, aStudent.gender, aStudent.grade);	//	�Է¹��� ����ü�� ���Ͽ� ����.
	printf("�л� �߰� ����");

	fclose(src);	//	���� �ݱ�.
}

void changeGrade()
{
	open_read();	//	������ �б��������� ����.

	int count = 0;
	for (int i = 0; !feof(src); i++) {	//	������ �迭�� �о�´�
		fscanf(src, "%s %d %s %s\n", list[i].name, &list[i].stdNum, list[i].gender, list[i].grade);
		count++;
	}

	fclose(src);	//	���ϴݱ�

	int changeIndex;
	int aStdNum;
	int flag = 0;	//	flag��� ������ �̿��Ͽ� �л��� ã������ ã�� ���Ѱ�츦 ����.
	scanf("%d", &aStdNum);	//	������ �й� �Է¹���

	for (int i = 0; i < count; i++) {	//	������ �л��� �ε��� ã��
		if (aStdNum == list[i].stdNum) {
			printf("%s %d %s %s\n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
			changeIndex = i;
			flag = 1;
		}
	}
	if (flag == 0)	//	�л��� ã�� ���Ѱ�� ������ ���
		printf("�л��� ã�� ���߽��ϴ�.\n");

	printf("������ �������� �����ϰ� ��������? : ");	//	���� �������
	char aStdGrd[5];	//	�ӽ÷� char�迭�� ������ ����
	scanf(" %s", aStdGrd);	//	�Է¹ް�
	strcpy(list[changeIndex].grade, aStdGrd);	//	strcpy�� ����Ͽ� �ٲپ��ش�.

	open_write();	//	������ ������� ���

	for (int i = 0; i < count; i++) {	//	������ �迭�� ���Ͽ� ����.
		if (i == count - 1)	//	�������ٿ����� ������ ���� ����.
			fprintf(src, "%s %d %s %s", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
		else
			fprintf(src, "%s %d %s %s \n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
	}

	fclose(src);
}

void deleteStd()
{
	open_read();	//	���� �б���� ����

	int count = 0;
	while (!feof(src)) {	//	�о�ͼ� �迭�� ����
		fscanf(src, "%s %d %s %s", list[count].name, &list[count].stdNum, list[count].gender, list[count].grade);
		count++;
	}
	fclose(src);	//	������ �ݾ��ش�.

	printstdList(count);	//	�迭������ ��� ������ش�.(������ ���� �ʴ´�)

	printf("������ �й��� �Է� : ");
	int delStdNum;
	scanf("%d", &delStdNum);	//	������ �й��� �Է¹޾Ƽ�
	for (int i = 0; i < count; i++) {	//	���� �˰����� �̿��Ͽ� ����
		if (list[i].stdNum == delStdNum) {	//	i�ε����� ���� �����ϰ�����
			for (int j = i; j < count; j++)
				list[j] = list[j + 1];
		}
	}
	count--;	//	count�� �ϳ� ���̰�
	open_write();	//	������� ���

	for (int i = 0; i < count; i++) {	//	 ���Ͽ� �迭������ �����Ѵ�.
		if (i == count - 1)	//	�������ٿ����� ������ ���� ����.
			fprintf(src, "%s %d %s %s", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
		else
			fprintf(src, "%s %d %s %s \n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
	}

	fclose(src);	//	������ �ݾ��ش�
}

void open_read()
{
	if (fopen_s(&src, fname, "r") != 0) {	//	���� ������� ���
		printf("������ ������ �ʽ��ϴ�.");
		exit(1);
	}
}

void open_write()
{
	if (fopen_s(&src, fname, "w") != 0) {	//	���� �б���� ���
		printf("������ ������ �ʽ��ϴ�.");
		exit(1);
	}
}

void open_append()
{
	if (fopen_s(&src, fname, "a") != 0) {	//	���� �߰����� ���
		printf("������ ������ �ʽ��ϴ�.");
		exit(1);
	}
}
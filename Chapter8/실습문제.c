#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//	함수 원형 작성
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

FILE *src;	//	파일 포인터 생성
char fname[] = "src.txt";

struct info {	//	구조체를 선언한다.
	char name[25];
	int stdNum;
	int gender[25];
	char grade[5];
};
struct info list[99];	//	구조체들의 배열을 만든다.

void input() {

	int select = 0;

	while (select != 4) {

		printf("[1.검색] [2.추가 및 변경] [3.삭제] [4.종료] \n");
		scanf("%d", &select);

		switch (select) {
		case 1:

			system("cls");
			while (1) {
				system("cls");
				printf("검색 메뉴 입니다.\n[1.전체 리스트] [2.이름 검색] [3.뒤로가기]\n");
				scanf("%d", &select);
				if (select == 1) {
					system("cls");
					printf("-------------- [내림차순 정렬] --------------\n");

					stdList();	//	학점 순으로 내림차순 정렬

					system("pause");
				}
				else if (select == 2) {
					system("cls");
					printf("-------------- [이름 검색] -------------\n");
					printf("검색할 이름 입력 : ");

					nameSearch();	//	이름을 입력받아 학생 정보 출력

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
				printf("추가 및 변경 메뉴 입니다.\n[1.학생 추가] [2.학점 변경] [3.뒤로가기]\n");
				scanf("%d", &select);
				if (select == 1) {
					system("cls");
					printf("-------------- [학생 추가] --------------\n");

					addStd();	//	학생을 추가

				}
				else if (select == 2) {
					system("cls");
					printf("-------------- [학점 변경] -------------\n");
					printf("변경할 학생 학번 입력 : ");

					changeGrade();	//	학번을 입력받아 학점 변경

				}
				else
					break;
			}
			break;
		case 3:
			system("cls");
			printf("삭제 메뉴 입니다.\n");

			deleteStd();	//	학번을 입력받아 학생 삭제

			break;
		default:
			break;
		}
		system("cls");
	}
}

int main(void) {	//	main함수.
	input();	//	input()함수를 호출한다.
}

void stdList()
{
	open_read();	//	파일을 읽기모드로 오픈.

	int count = 0;
	while (!feof(src)) {	//	파일을 fscanf로 읽어서 배열에 넣는다.
		fscanf(src, "%s %d %s %s", list[count].name, &list[count].stdNum, list[count].gender, list[count].grade);
		count++;
	}

	for (int i = 0; i < count - 1; i++)		//	학점순으로 내림차순 정렬
	{
		float max = atof(list[i].grade);	//	학점입력을 char배열로 받았기 때문에, atof()라는 함수를 사용하여 실수형으로 바꾸어서 값비교를 해준다.
		int max_index = i;
		for (int j = i + 1; j < count; j++)	//	내림차순 정렬을 수행한다.
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
	
	fclose(src);	//	파일을 닫아준다.

	open_write();	//	src.txt 파일을 쓰기 형식으로 오픈.

	for (int i = 0; i < count; i++) {	//	파일에 배열정보를 저장한다.
		if (i == count - 1)	//	마지막줄에서는 개행을 하지 않음.
			fprintf(src, "%s %d %s %s", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
		else
			fprintf(src, "%s %d %s %s \n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
	}

	fclose(src);	//	src.txt파일을 닫아준다.

	printstdList(count);	//	내림차순으로 정렬된 배열 출력하기
}

void printstdList(int stdCount) {
	for (int i = 0; i < stdCount; i++) {	//	배열에 입력된 학생정보를 출력해주는 함수.
		printf("%s %d %s %s\n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
	}
	puts("");
}

void nameSearch() {
	//	list[]의 특정 이름(list[?].name)을 검색하는 함수.
	open_read();	//	파일을 읽기형식으로 열기

	int count = 0;
	while (!feof(src)) {	//	파일을 fscanf로 읽어서 배열에 넣는다.
		fscanf(src, "%s %d %s %s", list[count].name, &list[count].stdNum, list[count].gender, list[count].grade);
		count++;
	}

	fclose(src);	//	파일을 닫는다.

	char cpr1[99];	//	이름 비교를 위한 변수를 하나 생성한다.
	getchar();	//	버퍼를 비운다.

	gets(cpr1);	// 이름을 입력받는다.
	int flag = 1;	//	flag라는 변수를 사용하여 이름찾기에 성공한 경우와 실패한 경우를 구분한다. 실패한 경우에는 에러메세지를 출력해준다.

	for (int i = 0; i < count; i++) {	//	이름찾기에 성공한 경우 찾은 학생의 정보를 출력해준다.
		if (strcmp(cpr1, list[i].name) == 0) {	//	입력받은 이름이 list배열에 있는 모든 학생들의 이름 중 일치하는 것이 있으면
			printf("\n%s %d %s %s \n\n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
			flag = 0;
			return 0;
		}
	}

	if (flag != 0) {
		for (int i = 0; i < count; i++) {	//	이름찾기에 실패한 경우 아래의 메세지를 출력해준다.
			if (strcmp(cpr1, list[i].name) != 0) {	//	입력받은 이름이 list배열에있는 모든 학생들의 이름 같지 않으면	
				puts("\n찾으시는 학생이 없습니다.\n\n");
				return 0;
			}
		}
	}
}

void addStd(){	//	수정모드로 파일 열어서 파일에 추가하고 저장
	open_append();	//	수정모드로 파일 오픈.

	struct info aStudent;	//	임시구조체 aStudent 생성
	printf("학생의 정보 입력 : \n (이름 학번 성별 학점) \n :");
	scanf("%s %d %s %s", aStudent.name, &aStudent.stdNum, aStudent.gender, aStudent.grade);	//	학생 정보를 입력받아 aStudent라는 임시 구조체에 저장.

	fprintf(src, "\n%s %d %s %s", aStudent.name, aStudent.stdNum, aStudent.gender, aStudent.grade);	//	입력받은 구조체를 파일에 저장.
	printf("학생 추가 성공");

	fclose(src);	//	파일 닫기.
}

void changeGrade()
{
	open_read();	//	파일을 읽기형식으로 오픈.

	int count = 0;
	for (int i = 0; !feof(src); i++) {	//	파일을 배열로 읽어온다
		fscanf(src, "%s %d %s %s\n", list[i].name, &list[i].stdNum, list[i].gender, list[i].grade);
		count++;
	}

	fclose(src);	//	파일닫기

	int changeIndex;
	int aStdNum;
	int flag = 0;	//	flag라는 변수를 이용하여 학생을 찾은경우와 찾지 못한경우를 구분.
	scanf("%d", &aStdNum);	//	변경할 학번 입력받음

	for (int i = 0; i < count; i++) {	//	변경할 학생의 인덱스 찾기
		if (aStdNum == list[i].stdNum) {
			printf("%s %d %s %s\n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
			changeIndex = i;
			flag = 1;
		}
	}
	if (flag == 0)	//	학생을 찾지 못한경우 다음을 출력
		printf("학생을 찾지 못했습니다.\n");

	printf("학점을 무엇으로 변경하고 싶은가요? : ");	//	학점 변경과정
	char aStdGrd[5];	//	임시로 char배열형 변수를 만들어서
	scanf(" %s", aStdGrd);	//	입력받고
	strcpy(list[changeIndex].grade, aStdGrd);	//	strcpy를 사용하여 바꾸어준다.

	open_write();	//	파일을 쓰기모드로 열어서

	for (int i = 0; i < count; i++) {	//	수정한 배열을 파일에 쓴다.
		if (i == count - 1)	//	마지막줄에서는 개행을 하지 않음.
			fprintf(src, "%s %d %s %s", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
		else
			fprintf(src, "%s %d %s %s \n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
	}

	fclose(src);
}

void deleteStd()
{
	open_read();	//	파일 읽기모드로 오픈

	int count = 0;
	while (!feof(src)) {	//	읽어와서 배열에 저장
		fscanf(src, "%s %d %s %s", list[count].name, &list[count].stdNum, list[count].gender, list[count].grade);
		count++;
	}
	fclose(src);	//	파일을 닫아준다.

	printstdList(count);	//	배열정보를 모두 출력해준다.(정렬은 하지 않는다)

	printf("삭제할 학번을 입력 : ");
	int delStdNum;
	scanf("%d", &delStdNum);	//	삭제할 학번을 입력받아서
	for (int i = 0; i < count; i++) {	//	삭제 알고리즘을 이용하여 삭제
		if (list[i].stdNum == delStdNum) {	//	i인덱스의 값을 삭제하고자함
			for (int j = i; j < count; j++)
				list[j] = list[j + 1];
		}
	}
	count--;	//	count를 하나 줄이고
	open_write();	//	쓰기모드로 열어서

	for (int i = 0; i < count; i++) {	//	 파일에 배열정보를 저장한다.
		if (i == count - 1)	//	마지막줄에서는 개행을 하지 않음.
			fprintf(src, "%s %d %s %s", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
		else
			fprintf(src, "%s %d %s %s \n", list[i].name, list[i].stdNum, list[i].gender, list[i].grade);
	}

	fclose(src);	//	파일을 닫아준다
}

void open_read()
{
	if (fopen_s(&src, fname, "r") != 0) {	//	파일 쓰기모드로 열어서
		printf("파일이 열리지 않습니다.");
		exit(1);
	}
}

void open_write()
{
	if (fopen_s(&src, fname, "w") != 0) {	//	파일 읽기모드로 열어서
		printf("파일이 열리지 않습니다.");
		exit(1);
	}
}

void open_append()
{
	if (fopen_s(&src, fname, "a") != 0) {	//	파일 추가모드로 열어서
		printf("파일이 열리지 않습니다.");
		exit(1);
	}
}
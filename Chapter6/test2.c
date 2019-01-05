#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

void choice_1();	//	함수 원형 호출
void searchAll();
void searchOne();
int removingIndex;
int count = 2;

struct date {	//	구조체 선언
	int year;
	int month;
	int day;
};
struct book {	//	구조체 선언
	struct date open;
	char title[99];
	char author[99];
	char company[99];
	char isRented[99];
};

struct book books[15];	//	15개의 책을 보관할 수 있는 배열 생성

int input() {	//	입력받는 부분을 함수로 분리함.
	puts("도서관 대출 프로그램입니다");
	puts("메뉴를 선택해 주세요.");
	puts("0 : 서적 검색");
	puts("1 : 신규 서적 등록");
	puts("2 : 등록 서적 제거");
	int choice;
	scanf("%d", &choice);
	puts("");
	return choice;
}

void printBooks(int i) {	//	책 정보를 출력하는 부분을 함수로 분리함.
	printf("서적 이름 : %s\n", books[i].title);
	printf("등록 일자 : [%d - %d - %d]\n", books[i].open.year, books[i].open.month, books[i].open.day);
	printf("저자 : %s\n", books[i].author);
	printf("출판사 : %s\n", books[i].company);
	printf("대여 여부 : %s\n", books[i].isRented);
	puts("");
}

void choice_0() {	//	0을 골랐을 경우의 함수.
	puts("1 : 전체 서적 검색");
	puts("2 : 특정 서적 검색");
	int choice;
	scanf(" %d", &choice);
	if (choice == 1)	//	choice가 1이면 searchAll() 함수 호출.
		searchAll();
	else if (choice == 2)	//	choice가 2이면 searchOne() 함수 호출.
		searchOne();
	else	//	그 외의 입력의 경우는 예외 처리.
		puts("오류 발생 : 1, 2 이외의 입력.\n");
}

void searchAll() {	//	books[]의 모든 원소들을 일정한 포맷으로 출력해주는 searchAll() 함수.
	for (int i = 0; i < count; i++)
		printBooks(i);
}

int distinguishingTempVar;	//	변수를 하나 선언하여 searchOne()이 찾기를 성공한 경우와 찾기를 실패한 경우를 구분한다. 성공의 경우 이 변수는 3의 값을 가지며, 실패의 경우 10을 가진다.

void searchOne() {	//	books[]의 특정 서적을 검색하는 searchOne() 함수.
	char cpr1[99];
	getchar();	//	버퍼비우기

	printf("찾으시는 책 제목을 입력하세요: ");
	gets(cpr1);

	for (int i = 0; i < count; i++) {	//	찾기에 성공한 경우 찾은 책의 정보를 출력해준다.
		if (strcmp(cpr1, books[i].title) == 0) {	//	입력받은 제목이 books배열에 있는 모든 서적들의 제목 중 일치하는 것이 있으면
			printBooks(i);
			removingIndex = i;
			distinguishingTempVar = 3;
			return 0;
		}
	}
	for (int i = 0; i < count; i++)	//	찾기에 실패한 경우 아래의 메세지를 출력해준다.
		if (strcmp(cpr1, books[i].title) != 0) {	//	입력받은 제목이 books배열에있는 모든 서적의 제목과 같지 않으면	
			puts("찾으시는 책이 없습니다.\n");
			distinguishingTempVar = 10;
			return 0;
		}
}

void library() {	//	default값을 따로 저장하는 library() 함수 작성.

	struct book def1;
	def1.open.year = 2017;
	def1.open.month = 04;
	def1.open.day = 06;
	strcpy(def1.title, "보노보노처럼 살다니 다행이야");
	strcpy(def1.author, "김신회");
	strcpy(def1.company, "놀");
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

void choice_1() {	//	1을 골랐을 경우의 함수.
	struct book aBook;	//	struct를 하나 만들고, 각각을 set해준다.

	printf("등록할 서적의 제목을 입력하시오: ");
	getchar();	gets(aBook.title);

	for (int i = 0; i < count; i++) {
		while (strcmp(aBook.title, books[i].title) == 0) {	//	i인덱스 수정해야함 조건문 바꿔야됨
			printf("동일한 제목의 책이 등록되어있습니다. \n서적을 등록할 수 없습니다!\n\n");
			return 0;	//	choice_1() 함수 종료
		}
	}

	printf("등록할 서적의 등록일자(년-월-일)를 입력하시오: ");
	scanf("%d %d %d", &aBook.open.year, &aBook.open.month, &aBook.open.day);

	printf("등록할 서적의 작가를 입력하시오: ");
	getchar();	gets(aBook.author);

	printf("등록할 서적의 출판사를 입력하시오: ");
	gets(aBook.company);

	printf("등록할 서적의 대여 여부(Y / N)를 입력하시오: ");
	gets(aBook.isRented);

	count++;
	books[count - 1] = aBook;
}

void choice_2() {	//	2를 골랐을 경우의 함수.

	char willRemove;	//	제거할 지를 묻는 변수 생성.

iterate:

	searchOne();	//	searchOne() 함수 호출.

	if (distinguishingTempVar == 10) {	//	search를 실패했으면 다시 돌아간다.
		printf("\n엔터를 한번 눌러주세요!\n");
		goto iterate;
	}
	if (distinguishingTempVar != 10)	//	search를 실패하지 않았으면 진행한다.
		if (books[removingIndex].isRented[0] == 'Y') {	//	search했지만 책이 대여중이면 다시 돌아간다.
			printf("책이 대여중입니다. 따라서 제거할 수 없습니다.\n");
			printf("\n엔터를 한번 눌러주세요!\n");
			goto iterate;
		}

	printf("위 서적을 제거하려면 Y, 세션을 취소하려면 N을 입력하시오: \n");
	scanf("%c", &willRemove);

	if (willRemove == 'Y') {	//	배열을 덮어씌우기
		for (int i = removingIndex; i < count; i++)
			books[i] = books[i + 1];
		count--;
		puts("\n삭제 완료!\n");
	}

	else if (willRemove == 'N') {	//	제거 불희망
		printf("삭제세션을 종료합니다.(제거 불희망)\n\n");
		return 0;
	}

	else {
		printf("올바르지 않은 입력입니다. 처음으로 돌아갑니다.\n\n");
		return 0;
	}
}
int main(void) {	//	main()함수
	library();	//	default정보들이 담긴 library() 함수를 호출한다.

	while (1) {	//	무한루프
		int choice = input();

		if (choice == 0)
			choice_0();
		else if (choice == 1)
			choice_1();
		else if (choice == 2)
			choice_2();
		else {
			puts("오류 발생 : 0, 1, 2 이외의 입력.\n");
			continue;
		}

	}
}
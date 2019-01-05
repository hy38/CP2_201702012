#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int inputedInteger, inputedBinaryNumber, quotient, remainder;	//	입력받을 10진수의 정수, 2진수의 수, 몫, 나머지 변수 생성
	int array1[99999];	//	임의의 큰 배열 생성
	printf("임의의 정수를 입력하시오: ");
	scanf("%d", &inputedInteger);	//	10진수의 정수를 입력받는다.

	int count = 0;	//	count 변수를 만들고 0으로 초기화한다.

	while (inputedInteger / 2 > 0) {	//	입력받은 10진수의 정수가 2로 나눈 몫이 0보다 클 때 동안은 while문을 반복한다
		//quotient = inputedInteger / 2;
		remainder = inputedInteger % 2;	//	나머지는 입력받은 10진수 모듈러 2 로 계산한다.
		inputedInteger = inputedInteger / 2;	//	입력받은 10진수의 정수를 2로 계속 나누어 준다. 이는 while문의 조건에 영향을 미친다.
		array1[count] = remainder;	//	array1이라는 배열의 count 인덱스에 나머지를 각각 저장해준다. count의 초기값이 0이였으므로 이 배열은 0번째 인덱스부터 저장될 것이다.

		count++;	//	count를 하나씩 늘려준다.
	}
	array1[count] = 1;	//	모듈러연산을 마치고 남은 몫인 1을 마지막 인덱스에 넣어준다. 이렇게 얻은 array1 배열이 내가 원하는 2진수를 reverse한 형태로 가지고 있는 배열이다.

	for (int i = count; i >= 0; i--)	//	따라서 나는 이 배열 array1을 맨 마지막 인덱스인 count부터 거꾸로 출력하여 원하는 2진수 출력값을 얻는다.
		printf("%d", array1[i]);

	printf("\n");	//	가독성을 위하여 개행해준다.

	printf("임의의 2진수를 입력하시오: ");
	scanf("%d", &inputedBinaryNumber);	//	2진수의 수를 입력받는다.
	int sum = 0;	//	sum이라는 합을 나타내는 변수를 선언하고 0으로 초기화해준다.
	int newCount = 1;	//	위에 쓴 count와는 다른 newCount 변수를 선언하고 1로 초기화해준다.

	while (inputedBinaryNumber / 10 > 0) {	//	입력받은 2진수의 수를 10의 자리마다 끊어서 생각할 때, 이 2진수가 10으로 나눈 몫이 0보다 클 동안 만 while문을 진행한다.
		sum = sum + (inputedBinaryNumber % 10) * newCount;	//	sum에 입력받은 2진수를 10으로 모듈러 연산을 한 값에다가 newCount(이 변수는 1, 2, 4, 8, 16, ... 이런식으로 진행되며, 
															//계산을 도울 것이다.)를 곱한다.
		inputedBinaryNumber = inputedBinaryNumber / 10;	//	입력받은 이진수를 계속 10으로 나누어 점점 줄여준다. 이 역시 while문의 조건에 영향을 미친다.

		newCount = newCount * 2;	//	newCount 변수의 값을 변화시켜준다.
	}
	sum = sum + (inputedBinaryNumber % 10) * newCount;	//	while문을 빠져나온 후 남은 inputedBinaryNumber의 값도 생각하여 준다.

	printf("%d \n", sum);	//	sum(2진수를 10진수로 바꾼 값)을 출력한다.

}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcdOperaton(int, int);
void gcdDetailOpeartion(int, int);

int main(int argc, char* argv[]){
	int number1, number2, result;
	printf("두 정수를 입력하세요 : ");
	scanf("%d %d", &number1, &number2);

	if (number1 > number2){
		result = gcdOperaton(number1, number2);
	}else{
		result = gcdOperaton(number2, number1);
	}

	printf("%d %d의 최대 공약수는 %d입니다.\n", number1, number2, result);

	printf("\n\n최대 공약수의 디테일을 확인\n");
	if (number1 > number2){
		gcdDetailOpeartion(number1, number2);
	} else{
		gcdDetailOpeartion(number2, number1);
	}
	return 0;
}

int gcdOperaton(int first, int second){
	int result = 0;

	while(second){
		result = first % second;
		first = second;
		second = result;	
	}
	return result;
}

void gcdDetailOpeartion(int first, int second){
	int result = 0;
	int i = 1;
	while(second){
		printf("%d번째 최대 공약수 계산 과정 : %d %d\n", i, first, second);
		result = first % second;
		first = second;
		second = result;
		i++;
	}
	printf("%d번째는 최대공약수를 찾은 마지막 연산 : %d %d\n", i, first, second);
}



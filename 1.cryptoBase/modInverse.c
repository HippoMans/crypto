#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int modInverse(int, int);

int main(int argc, char* argv[]){
	int number1, number2;
	int result;

	printf("먼저 수를 입력하세요 : ");
	scanf("%d", &number1);
	printf("다음으로 원하는 역원의 수를 입력하세요 : ");
	scanf("%d", &number2);

	result = modInverse(number1, number2);

	printf("%d와 %d의 역원은 %d입니다.\n", number1, number2, result);

	return 0;
}

int modInverse(int first, int second){
	int result = 0;
	for(int i = 1; i<second; i++){
		if ((first * i ) % second == 1){
			result = i;
		}
	}
	return result;
}


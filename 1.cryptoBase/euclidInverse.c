#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int inverseEuclid(int, int);

int main(int argc, char* argv[]){
	int number1, number2, result;

	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &number1, &number2);

	if(number1 > number2){
		result = inverseEuclid(number1, number2);
	}else{
		result = inverseEuclid(number2, number1);
	}


	if (result){
		printf("%d와 %d의 역원은 %d입니다.\n", number1, number2, result);
	}else{
		printf("역원이 존재하지 않습니다.\n");
	}
}

int inverseEuclid(int first, int second){
	int middle;

	int x1, x2;
	int y1, y2;
	int z1, z2;

	if (second == 0){
		return 0;
	}

	y2 = second;
	x2 = first;
	x1 = 0;
	y1 = 1;

	while(y2 > 1){
		middle = x2 / y2;

		z2 = x2 - (middle * y2);
		x2 = y2;
		y2 = z2;

		z1 = x1 - (middle * y1);
		x1 = y1;
		y1 = z1;

	}

	if (y2 == 1){
		if (y1 < 0){
			y1 += first;
			return y1;
		}
		return 0;
	}
}


/*
전치 암호
평문 문자의 순서를 어떤 특별한 절차에 따라 문자 위치를 재배치하여 평문을 암호화하는 방식
단순 전치 암호는 정상적인 평문 배열을 특정한 키의 순서에 따라 재배치하여 암호화하는 방식
단순 전치 암호는 평문 문장을 키의 순서에 따라 재배치한다. 
 
 오류가 많은 프로젝트이다. 수정이 필요
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BLOCK_SIZE 6
const int encryptKey[7] = {3, 5, 1, 6, 4, 2};
const int decryptKey[7] = {3, 6, 1, 5, 2, 4};

char* encrypt(char*);
char* decrypt(char*);

int main(int argv, char* argc[]){
	int choice = 1;
	char* encryptString;
	char* decryptString;

	printf("암호화할 경우 1번을 누르고, 복호화할 경우 2번을 누르세요 : ");
	scanf("%d", &choice);
	while(getchar() != '\n');

	char plainText[64] = {0,};
	printf("평문을 입력하세요 : ");
	fgets(plainText, sizeof(plainText), stdin);
	if (choice == 1){
		encryptString = encrypt(plainText);	
		printf("다음 암호문은 : %s", encryptString);
	} else if (choice == 2){
	

	} else {
	

	}

	return 0;
}

char* encrypt(char* text){
	int encryptSize = strlen(text);
	int block_number = 0;
	char* encryptText;

	if(encryptSize % BLOCK_SIZE > 0){
		block_number = (strlen(text) / BLOCK_SIZE) + 1;
		
		for(int i = strlen(text); i < block_number * BLOCK_SIZE; i++){
			text[i] = 'x';
		}

	}else{
		block_number = strlen(text) / BLOCK_SIZE;
	}

	for (int i = 0; i < block_number; i++){
		for (int j = 0; j < BLOCK_SIZE; j++){
			encryptText[i * BLOCK_SIZE + j] = text[(encryptKey[j] - 1) + i * BLOCK_SIZE]; 
		}
	}
	return encryptText;
}	



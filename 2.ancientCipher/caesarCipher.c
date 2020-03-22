/*
시저암호(Caesar Cipher)는 가장 대표적인 대치 암호(substitution cipher)으로 평문 문자를 다른 문자로 일대일 대응시켜 암호문을 만든다.
영문자에 숫자 0에서 25까지의 숫자를 부여한 번호와 비밀키를 조합하여 암호화한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encrypto(char*, int);
char* decrypto(char*, int);

int main(int argv, char* argc[]){
	int cryptoKey = 0;
	char plainText[50] = {0,};
	char* cipherText;
	char* decipherText;
	int choice = 0;

	printf("평문을 입력하세요 : ");
	fgets(plainText, sizeof(plainText), stdin);

	printf("암호화와 복호화 중 원하는 작업을 선택하세요. (암호화 : 1, 복호화 :2) : ");
	scanf("%d", &choice);
	
	//암호화
	if (choice == 1){
		printf("비밀키를 입력하세요 : ");
		scanf("%d", &cryptoKey);

		printf("암호화 한 결과 출력 : ");
		cipherText = encrypto(plainText, cryptoKey);
		puts(cipherText);

	}else if (choice == 2){		
		printf("복호화키를 입력하세요 : ");
		scanf("%d", &cryptoKey);

		printf("복호화한 결과 출력 : ");
		decipherText = decrypto(plainText, cryptoKey);
		puts(decipherText);

	}else{
		printf("오류 발생~~~ Good Bye~~!\n");
		exit(1);
	}
	
	return 0;
}

char* encrypto(char* text, int crypto){
	int len = strlen(text);
	for(int i = 0; i < len; i++){
		if((text[i] >= 'a') && (text[i] <= 'z')) {
			text[i] -= 'a';

			text[i] = ((text[i] + crypto) % 26);
			text[i] += 'a';
		}

		if((text[i] >= 'A') && (text[i] <= 'Z')) {
			text[i] -= 'A';

			text[i] = ((text[i] + crypto) % 26);
			text[i] += 'A';
		}
	}
	
	return text; 
}

char* decrypto(char* text, int crypto){
	int len = strlen(text);
	for(int i = 0; i < len; i++){
		if((text[i] >= 'a') && (text[i] <= 'z')) {
			text[i] -= 'a';
			
			if ((text[i] - crypto) < 0 ){
				text[i] += 26;
			}

			text[i] = ((text[i] - crypto) % 26);
			text[i] += 'a';
		}

		if((text[i] >= 'A') && (text[i] <= 'Z')) {
			text[i] -= 'A';

			if ((text[i] - crypto) < 0){
				text[i] += 26;
			}

			text[i] = ((text[i] - crypto) % 26);
			text[i] += 'A';
		}
	}
	
	return text; 
}

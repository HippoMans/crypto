/*
Vigenere 암호
다중 문자 대치 암호(ployalphabetic substitution cipher)에서는 하나의 평문 문자가 여러 개의 암호 문자로 대치될 수 있다.
다중 문자 대치 암호의 대표적인 방법으로 Vigenere 암호가 있다. 아래는 Vigenere 알고리즘이다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* inputKey();
char* encrypto(char*, char*);
char* decrypto(char*, char*);

int main(int argv, char* argc[]){
	int choice = 1;
	char plainText[50] = {0,};
	char* cipherText;
	char* decipherText;
	char* Key;

	printf("암호화 하기 위해서는 1번을 입력하고, 복호화 하기 위해서는 2번을 입력하세요 : ");
	scanf("%d", &choice);
	while(getchar() != '\n');

	if (choice == 1){
		printf("암호문을 입력하세요 : ");
		fgets(plainText, sizeof(plainText), stdin);
		Key = inputKey();
		cipherText = encrypto(plainText, Key);
		printf("암호화한 평문은 : %s", cipherText);

	} else if (choice == 2){
		printf("복호문을 입력하세요 : ");
		fgets(plainText, sizeof(plainText), stdin);
		Key = inputKey();
		decipherText = decrypto(plainText, Key);
		printf("복호화한 평문은 :  %s", decipherText);

	} else {
		printf("암호화와 복호화에 대한 번호 입력이 필요합니다.");
		exit(1);		
	}

	return 0;
}

char* inputKey(){
	char* Key;
	printf("키 값을 입력하세요(오직 소문자만) : ");
	fgets(Key, sizeof(Key), stdin);
	return Key;
}

char* encrypto(char* text, char* crypto) {
	int textsize = strlen(text);
	int cryptosize = strlen(crypto);

	for(int i = 0; i < textsize; i++){
		int j = i % (cryptosize-1);
		
		if((text[i] >= 'a') && (text[i] <= 'z')){
			text[i] -= 'a';
			crypto[j] -= 'a';
			
			text[i] = (text[i] + crypto[j]) % 26;
			text[i] += 'a';
			crypto[j] += 'a';
		}

		if((text[i] >= 'A') && (text[i] <= 'Z')){
			text[i] -= 'A';
			crypto[j] -= 'A';

			text[i] = (text[i] + crypto[j]) % 26;
			text[i] += 'A';
			crypto[j] += 'A';
		}
	}
	return text;
}

char* decrypto(char* text, char* crypto) {
	int textsize = strlen(text);
	int cryptosize = strlen(crypto);

	for(int i = 0; i < textsize; i++){
		int j = i % (cryptosize -1);
		
		if((text[i] >= 'a') && (text[i] <= 'z')){
			text[i] -= 'a';
			crypto[j] -= 'a';
			
			if((text[i] - crypto[j]) < 0){
				text[i] += 26;
			}

			text[i] = (text[i] - crypto[j]) % 26;
			text[i] += 'a';
			crypto[j] += 'a';
		}

		if((text[i] >= 'A') && (text[i] <= 'Z')){
			text[i] -= 'A';
			crypto[j] -= 'A';

			if((text[i] - crypto[j]) <0){
				text[i] += 26;
			}

			text[i] = (text[i] - crypto[j]) % 26;
			text[i] += 'A';
			crypto[j] += 'A';
		}
	}
	return text;
}

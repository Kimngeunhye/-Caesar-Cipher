#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Encryption(int kEY, int encryption[], char input[]);   
void Decryption(int KEY, int decryption[], char input[]);

int main(void)
{
	char input[1000];
	int KEY;
	int encryption[1000] = { NULL, };  //배열을 통해 암호화 문자과 복호화 문장을 받아올 공간을 확보한다.
	int decryption[1000] = { NULL, };

	printf("Enter the txt:\n");  //암호화 할 text를 입력받는다.
	scanf("%[^\n]", input);

	printf("Enter the key from 1 to 25:\n");  //key값을 설정하여서 암호로 사용할 값 공간을 할당해준다.
	scanf("%d", &KEY);

	Encryption(KEY, encryption, input);

	printf("\n\n");
	Decryption(KEY, Decryption, input, encryption);
	printf("\n");
	return 0;
}

void Encryption(int kEY, int* encryption, char* input)
{
	int i;
	int KEY;
	printf("Enter the encryption:\n");  
	for (i = 0; i < strlen(input); i++)  //앞서 암호화 text로 받은 배열을 순환한다.
	{
		encryption[i] = (input[i] + KEY); //암호화 = 암호화 문자열 + KEY 값
		if (input[i] == 32)      
			encryption[i] = input[i];
		else if (encryption[i] > 122)
			encryption[i] = encryption[i] - 26;

		printf("%c", encryption[i]);  // 암호화 시킨 문장 반환받음
	}
}

void Decryption(int KEY, int* decryption, char* input, int* encryption)
{
	int i;
	int KEY;
	printf("Enter the decryption:\n"); 
	for (i = 0; NULL != encryption[i]; i++)   //암호화 시킨 문장을 복호화 시킨다.
		//반복문을 돌면서 NULL 값이 암호화 값이 아닐 때까지 반복한다.
	{
		decryption[i] = (encryption[i] - KEY);    //복호화 = 암호화 - KEY값
		if (encryption[i] == 32)
		{
			decryption[i] = encryption[i];  
		}
		else if
		
			(decryption[i] < 97)
		
			decryption[i] = encryption[i] + 26 - KEY;         

			printf("%c\n", decryption[i]);
		
	}
}


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
	int encryption[1000] = { NULL, };  //�迭�� ���� ��ȣȭ ���ڰ� ��ȣȭ ������ �޾ƿ� ������ Ȯ���Ѵ�.
	int decryption[1000] = { NULL, };

	printf("Enter the txt:\n");  //��ȣȭ �� text�� �Է¹޴´�.
	scanf("%[^\n]", input);

	printf("Enter the key from 1 to 25:\n");  //key���� �����Ͽ��� ��ȣ�� ����� �� ������ �Ҵ����ش�.
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
	for (i = 0; i < strlen(input); i++)  //�ռ� ��ȣȭ text�� ���� �迭�� ��ȯ�Ѵ�.
	{
		encryption[i] = (input[i] + KEY); //��ȣȭ = ��ȣȭ ���ڿ� + KEY ��
		if (input[i] == 32)      
			encryption[i] = input[i];
		else if (encryption[i] > 122)
			encryption[i] = encryption[i] - 26;

		printf("%c", encryption[i]);  // ��ȣȭ ��Ų ���� ��ȯ����
	}
}

void Decryption(int KEY, int* decryption, char* input, int* encryption)
{
	int i;
	int KEY;
	printf("Enter the decryption:\n"); 
	for (i = 0; NULL != encryption[i]; i++)   //��ȣȭ ��Ų ������ ��ȣȭ ��Ų��.
		//�ݺ����� ���鼭 NULL ���� ��ȣȭ ���� �ƴ� ������ �ݺ��Ѵ�.
	{
		decryption[i] = (encryption[i] - KEY);    //��ȣȭ = ��ȣȭ - KEY��
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


//���ַ�����д����fgetc()��fputc()

#include <stdio.h>

int main() {
	FILE* fpI = NULL;
	fpI = fopen("E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\seven times.txt", "rt");//��/txt�ļ�
	if (fpI == NULL) {
		printf("Failed to Open File!\n");
		exit(0);	//�����˳�����
	}

	FILE* fpO = NULL;
	//��������fputc1.txt�ļ����򴴽����ļ�
	fpO = fopen("E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\fputc1.txt", "wt");//д/txt�ļ�
	if (fpO == NULL) {
		printf("Failed to Open File!\n");
		exit(0);	//�����˳�����
	}

	//��ת�ַ������������ļ��ж�����ַ�����temp�У��ٽ�tempд������ļ�
	char temp = '\0';

	while (!feof(fpI)) {	//�����ļ�β������1
		temp = fgetc(fpI);	//fgetc()���ض����ַ���ASCII�룬���ļ�β������󣬷���EOF
		if (temp != EOF)
			putc(temp, fpO);	//����д���ַ���ASCII�룬���򷵻�EOF
	}

	fclose(fpI);
	fclose(fpO);
	return 0;
}
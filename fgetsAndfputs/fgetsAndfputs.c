//【字符串】读写函数fgetc()和fputc()

#include <stdio.h>
#include <conio.h>

int main() {
	char str[100], FileA[50];
	printf("Please input a string:\n");
	gets_s(str, sizeof(str));

	printf("The Path you want to save:\n");
	gets_s(FileA, sizeof(FileA));	//输入文件保存路径

	FILE* fpO = NULL;
	fpO = fopen(FileA, "wt");
	if (fpO == NULL) {
		printf("Failed to Open File!\n");
		exit(0);	//正常退出程序
	}

	if (fputs(str, fpO) == EOF) {
		printf("String read in error!\n");
		exit(0);
	}

	fclose(fpO);
	return 0;
}
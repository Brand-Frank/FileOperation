//【字符】读写函数fgetc()和fputc()

#include <stdio.h>

int main() {
	FILE* fpI = NULL;
	fpI = fopen("E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\seven times.txt", "rt");//读/txt文件
	if (fpI == NULL) {
		printf("Failed to Open File!\n");
		exit(0);	//正常退出程序
	}

	FILE* fpO = NULL;
	//若不存在fputc1.txt文件，则创建该文件
	fpO = fopen("E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\fputc1.txt", "wt");//写/txt文件
	if (fpO == NULL) {
		printf("Failed to Open File!\n");
		exit(0);	//正常退出程序
	}

	//中转字符串，从输入文件中读入的字符存入temp中，再将temp写入输出文件
	char temp = '\0';

	while (!feof(fpI)) {	//到达文件尾，返回1
		temp = fgetc(fpI);	//fgetc()返回读入字符的ASCII码，若文件尾部或错误，返回EOF
		if (temp != EOF)
			putc(temp, fpO);	//返回写入字符的ASCII码，否则返回EOF
	}

	fclose(fpI);
	fclose(fpO);
	return 0;
}
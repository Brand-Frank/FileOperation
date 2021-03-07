//向某个文件写入一个字符串，再从该文件中倒着读入该字符串，然后显示在屏幕上。

#include <stdio.h>

int main() {
	FILE* fp = NULL;
	fp = fopen("E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\test.txt", "wt");
	if (fp == NULL) {
		printf("Operation Error(1): Failed to read in file.\n");
		exit(0);
	}
	fputs("BeiJingOlympic", fp);	//将一个字符串写入到文件指针上
	fclose(fp);

	fp = fopen("E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\test.txt", "rt");
	if (fp == NULL) {
		printf("Operation Error(2): Failed to read in file.\n");
		exit(0);
	}

	for (int i = 1; fseek(fp, -i, SEEK_END) == 0; i++) {	//起始点在尾部，从尾部往前移动文件位置指针
		putchar(fgetc(fp));		//读取文件中的内容(fgetc)，并打印到屏幕上
	}
	printf("\n");
	fclose(fp);
	return 0;
}
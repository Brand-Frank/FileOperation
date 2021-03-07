//【字符串】读写函数fgets()和fputs()

/*读取"E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\fgetsAndfputs.txt"
将其中的字符串显示在屏幕上。
*/
#include <stdio.h>
#include <conio.h>

int main() {
	char FileA[100];	//注意分配足够的字符串长度
	
	printf("The Path you want to input from:\n");
	gets_s(FileA, sizeof(FileA));	//输入文件保存路径
	//fgets(FileA, sizeof(FileA), stdin);

	FILE* fpI = NULL;
	fpI = fopen(FileA, "rt");
	if (fpI == NULL) {
		printf("Failed to Open File!\n");
		exit(0);	//正常退出程序
	}

	char str[100] = { '0' };

	//从文件中读入字符并存储到str中
	if (fgets(str, sizeof(FileA), fpI) == NULL) {
		printf("String read out error!\n");
		exit(0);
	}

	puts(str);
	fclose(fpI);
	//getchar();
	return 0;
}
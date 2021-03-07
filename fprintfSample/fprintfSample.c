//fprintf()和fscanf():	“读写对象是【磁盘文件】而不是【键盘和显示器】”

#include <stdio.h>

int main() {
	char FileA[100];
	printf("The Path want to save:\t");
	gets_s(FileA, sizeof(FileA));

	FILE* fpO = NULL;
	fpO = fopen(FileA, "wt");
	if (fpO == NULL) {
		printf("Operation Error: Failed to open the file.\n");
		exit(0);
	}

	char name[20] = { '0' };
	int age = 0;

	printf("Please input your name:\t");
	gets_s(name, sizeof(name));
	printf("Please input your age:\t");
	scanf("%d", &age);

	getchar();		//从输入缓冲区中抛掉换行符

	if ((fprintf(fpO, "%s %d", name, age) == EOF)) {
		printf("Operation Error: Failed to read in.\n");
		exit(0);
	}
	printf("Opration Successed: Read in is OK.\n");
	fclose(fpO);
	return 0;
}
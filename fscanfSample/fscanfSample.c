//fprintf()和fscanf():	“读写对象是【磁盘文件】而不是【键盘和显示器】”

#include <stdio.h>

int main() {
	char FileA[100];
	printf("The Path want to read in:\t");
	gets_s(FileA, sizeof(FileA));

	FILE* fpI = NULL;
	fpI = fopen(FileA, "rt");
	if (fpI == NULL) {
		printf("Operation Error: Failed to read in file.\n");
		exit(0);
	}

	char name[20] = { '0' };
	int age = 0;

	fscanf(fpI, "%s %d", name, &age);
	printf("Opration Successed: Read in is OK.\n");
	printf("Name:\t%s\nAge:\t%d", name, age);
	fclose(fpI);
	return 0;
}
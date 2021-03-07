//【块读写函数】——fread()和fwrite()
//将一块内存数据写到文件fwriteSample

#include "fwriteSample.h"

void getInfo(person* pInfo) {
	printf("Please input name:\t");
	gets_s(pInfo->name, sizeof(pInfo->name));
	printf("Please input age:\t");
	//gets_s(pInfo->age, sizeof(pInfo->age));
	scanf("%d", &pInfo->age);

	getchar();		//从输入缓冲区中抛掉换行符

	printf("Please input Email:\t");
	gets_s(pInfo->email, sizeof(pInfo->email));
}

int main() {
	person People[NUM];		//声明结构体变量数组People
	char FileA[100];			//s声明创建字符串数组，用以保存文件位置	--> 需要给定足够的容量

	printf("The Path you wan to save:\t");
	gets_s(FileA, sizeof(FileA));

	FILE* fpO = NULL;		//**一定要先初始化文件指针为NULL**
	fpO = fopen(FileA, "wt");
	if (fpO == NULL) {
		printf("Operation Error: failed to open file.\n");
		exit(0);	//正常退出
	}

	for (int i = 0; i < NUM; i++) {
		getInfo(&People[i]);
		/*	将当前person结构体变量占据的一块内存写入文件中	*/
		if (fwrite(&People[i], sizeof(person), 1, fpO) == 0) {
			printf("Operation Error: Block write failure.\n");
			exit(0);
		}
	}
	printf("Successed: Block write OK.\n");
	fclose(fpO);
	return 0;
}
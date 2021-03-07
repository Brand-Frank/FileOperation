#include <stdio.h>

int main() {
	FILE* fp = NULL;		//声明一个FILE结构的指针变量fpI，初始化为NULL

	//fopen():	为文件分配缓冲区，并填充FILE结构体变量fp，可将fp传递给其它库函数完成所需操作。
	fp = fopen("E:\\Program\\c\\samples\\struct_union_enum_typedef\\md-styles.css", "r");
	if (fp == NULL) {
		printf("Failed to open file!\n");
		exit(0);
	}

	//无任何操作

	getchar();
	//fclose():  将文件关闭，防止其被误用，切断文件指针和其指向文件的联系。
	fclose(fp);
	return 0;
}
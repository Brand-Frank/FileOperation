//��ĳ���ļ�д��һ���ַ������ٴӸ��ļ��е��Ŷ�����ַ�����Ȼ����ʾ����Ļ�ϡ�

#include <stdio.h>

int main() {
	FILE* fp = NULL;
	fp = fopen("E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\test.txt", "wt");
	if (fp == NULL) {
		printf("Operation Error(1): Failed to read in file.\n");
		exit(0);
	}
	fputs("BeiJingOlympic", fp);	//��һ���ַ���д�뵽�ļ�ָ����
	fclose(fp);

	fp = fopen("E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\test.txt", "rt");
	if (fp == NULL) {
		printf("Operation Error(2): Failed to read in file.\n");
		exit(0);
	}

	for (int i = 1; fseek(fp, -i, SEEK_END) == 0; i++) {	//��ʼ����β������β����ǰ�ƶ��ļ�λ��ָ��
		putchar(fgetc(fp));		//��ȡ�ļ��е�����(fgetc)������ӡ����Ļ��
	}
	printf("\n");
	fclose(fp);
	return 0;
}
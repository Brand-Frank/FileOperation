//���ַ�������д����fgets()��fputs()

/*��ȡ"E:\\Program\\c\\samples\\FileOperation\\fopenAndfclose\\testFile\\fgetsAndfputs.txt"
�����е��ַ�����ʾ����Ļ�ϡ�
*/
#include <stdio.h>
#include <conio.h>

int main() {
	char FileA[100];	//ע������㹻���ַ�������
	
	printf("The Path you want to input from:\n");
	gets_s(FileA, sizeof(FileA));	//�����ļ�����·��
	//fgets(FileA, sizeof(FileA), stdin);

	FILE* fpI = NULL;
	fpI = fopen(FileA, "rt");
	if (fpI == NULL) {
		printf("Failed to Open File!\n");
		exit(0);	//�����˳�����
	}

	char str[100] = { '0' };

	//���ļ��ж����ַ����洢��str��
	if (fgets(str, sizeof(FileA), fpI) == NULL) {
		printf("String read out error!\n");
		exit(0);
	}

	puts(str);
	fclose(fpI);
	//getchar();
	return 0;
}
#include <stdio.h>

int main() {
	FILE* fp = NULL;		//����һ��FILE�ṹ��ָ�����fpI����ʼ��ΪNULL

	//fopen():	Ϊ�ļ����仺�����������FILE�ṹ�����fp���ɽ�fp���ݸ������⺯��������������
	fp = fopen("E:\\Program\\c\\samples\\struct_union_enum_typedef\\md-styles.css", "r");
	if (fp == NULL) {
		printf("Failed to open file!\n");
		exit(0);
	}

	//���κβ���

	getchar();
	//fclose():  ���ļ��رգ���ֹ�䱻���ã��ж��ļ�ָ�����ָ���ļ�����ϵ��
	fclose(fp);
	return 0;
}
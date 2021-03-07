//【块读写函数】——fread()和fwrite()

#include <stdio.h>
#include <conio.h>
#define NUM 2

typedef struct
{
	char name[20];
	int age;
	char email[50];
}person;

void display(person p1)
{
	printf("Name:%s\n", p1.name);
	printf("Age:%d\n", p1.age);
	printf("Email:%s\n", p1.email);
}

void main(void) {
	person People[NUM];
	char FileA[100] = { 0 };
	//errno_t err;

	printf("The Path want to read in data:\t");
	gets(FileA);
	
	FILE * fpI = NULL;
	fpI = fopen(FileA, "rt");
	if (fpI == NULL) {
		printf("Operation Error: failed to open file.\n");
		exit(0);
	}

	for (int i = 0; i < NUM; i++) {
		//if ((err = fread(&People[i], sizeof(person), 1, fpI)) != 0)	
		if (fread(&People[i], sizeof(person), 1, fpI) == 0) {
			printf("Operation Error: Block read failure.\n");
			exit(0);
		}
		display(People[i]);
	}
	fclose(fpI);
	//getchar();
	return 0;
}
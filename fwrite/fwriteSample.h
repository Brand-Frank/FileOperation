#include <stdio.h>
#define NUM 2

typedef struct {
	char name[20];
	int age;
	char email[50];
}person;

void getInfo(person* pInfo);
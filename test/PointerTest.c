#include <stdio.h>

int main() {
	char ch = 'c';
	char *chptr = &ch;
	int i = 20;
	int *intptr = &i;
	float f = 1.20000;
	float *fptr = &f;
	char *ptr = "I am a string";
	printf("-> Character pointer @<%d> points to -> [%c]\n", chptr, *chptr);
	printf("-> Integer pointer @<%d> points to -> [%d]\n", intptr, *intptr);
	printf("-> Float pointer @<%d> points to -> [%f]\n", fptr, *fptr);
	printf("-> String[0] pointer @<%d> points to -> [%c]\n", ptr, *ptr);
	printf("-> String pointer @<%d> points to -> [%s]\n", ptr, ptr);
	return 0;
}


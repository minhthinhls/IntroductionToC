#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char* buffer = (char*)malloc(100 * sizeof(char)); // Bi�n' buffer chua' duoc. 100 k� tu.
	printf("Enter a string: ");
	gets(buffer); // Nh�p. k� tu. v�o tu` b�n ph�m
	printf("String is: %s\n", buffer);
	
	int i = atoi(buffer);
	float f = atof(buffer);
	if (i != 0) {
		printf("The input is an integer: %d", i);
	}
	if (f != 0) {
		printf("The input is a float: %f", f);
	}
	
}


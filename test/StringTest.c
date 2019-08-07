#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat(char *original, char *add) {
	while(*original) {
		original++;
	}
	while(*add) {
		*original = *add;
		add++;
		original++;
	}
	*original = '\0';
}

int main() {
	char s1[] = "Hello ";
	concat(s1, "World !"); // Success !
	printf("%s\n", s1);
	
	char* s2 = "Surprise ";
	char* s3 = "Mother F*cker !";
	concat(s2, s3); // Failed !
	printf("%s", s2);
}


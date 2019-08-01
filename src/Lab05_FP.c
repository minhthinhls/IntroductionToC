#include <stdio.h>	// printf()
#include <string.h>	// strlen(), strcpy()
#include <stdlib.h>	// malloc(), calloc()

void ex01(char *s, char *delimiter) {
	printf("\n-----EXERCISE 1-----\n");
	char *p, *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	do {
		p = strtok(str, delimiter); // Return the trimmed String <$p> before the $delimiter
		printf("%s\n", p);
		p = strtok(NULL, ""); // Return the remained String <$p> after the $delimiter
		if (p) { // If <$p> is not NULL, then do copy the remained <$p> to <$str>
			strcpy(str, p);
		}
	} while(p != NULL);
	printf("-> String after running: <%s>\n", str);
	printf("-> String as input: <%s>", s);
}

void ex02(char *s1, char *s2, char *s3) {
	printf("\n-----EXERCISE 2-----\n");
	char *input = (char*) calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));
	strcpy(input, s1);
	printf("$input before concatenation: %s\n", input);
	strcat(input, s2);
	printf("$input after concatenation: %s\n", input);
	int i, k = 0;
	for (i = 0; i < strlen(input); i++) {
		if (strchr(s3, input[i])) {
			k++;
		}
	}
	printf("\nThe result <=> The times appear of [aeiou] in String: %d", k); 
}

int ex03(int maxLength) {
	printf("\n-----EXERCISE 3-----\n");
	char *str = (char*) calloc(maxLength, sizeof(char));
	printf("Input the String: ");
	int num = strlen(gets(str));
	printf("-> Number of characters in String = %d", num);
	return num;
}

int ex04(char *s) {
	printf("\n-----EXERCISE 4-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	int numSpace = 0, i;
	for (i = 0; i < strlen(str); i++) {
		if (*(str + i) == ' ') {
			numSpace++;
		}
	}
	printf("-> Num of spaces in String = %d", numSpace);
	return numSpace;
}

char* ex05(char *s) {
	printf("\n-----EXERCISE 5-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	int i = 0, j = 0;
	while (str[i]) {
		if (str[i] != ' ') {
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
	printf("-> String after remove spaces = <%s>", str);
	return str;
}

char* ex06(char *s1, char *s2) {
	printf("\n-----EXERCISE 6-----\n");
	char *str = (char*) calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));
	printf("String 1 = %s\nString 2 = %s\n", strcpy(str, s1), s2);
	printf("-> String concatenated = <%s>", strcat(str, s2));
	return str;
}

char* ex07(char *s) {
	printf("\n-----EXERCISE 7-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	int i;
	for (i = 0; i < strlen(str); i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}
	printf("-> String after lowercasing = <%s>", str);
	return str;
}

char* ex08(char *s) {
	printf("\n-----EXERCISE 8-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	int i;
	for (i = 0; i < strlen(str); i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
	}
	printf("-> String after uppercasing = <%s>", str);
	return str;
}

char* ex09(char *s) {
	printf("\n-----EXERCISE 9-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	int i, toUpper = 1; // True
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') { // If Space !
			toUpper = 1; // Reset the upper value after each word.
		} else { // If character !
			if (toUpper) { // At the first position of considering word !
				if (str[i] >= 'a' && str[i] <= 'z') { // If lowercase char at this position.
					str[i] = str[i] - 32;
				}
				toUpper = 0; // Set toUpper to False until found new space.
			} else {
				if(str[i] >= 'A' && str[i] <= 'Z') { // If UPPERCASE char after Title-Character.
					str[i] = str[i] + 32;
				}
			}
		}
	}
	printf("-> String after title uppering = <%s>", str);
	return str;
}

char* ex10(char *str) {
	printf("\n-----EXERCISE 10-----\n");
	char *toConvert = (char*) calloc(strlen(str) + 1, sizeof(char));
	toConvert[0] = "\0";
	printf("The String is: <%s>\n", str);
	int i, j = 0;
	int isCharLower = str[i] >= 'a' && str[i] <= 'z'; // Check first character is lower ? (isCharLower == 0 == FALSE)
	toConvert[0] = str[0];
	isCharLower = !isCharLower; // isCharLower == 1 == TRUE
	for (i = 1; i < strlen(str); i++) {
		if(isCharLower) { // This char must be to lowercase
			if (str[i] >= 'a' && str[i] <= 'z') {
				toConvert[i] = str[i]; // Skip this char
			} else if (str[i] >= 'A' && str[i] <= 'Z') {
				toConvert[i] = str[i] + 32; // lowercasing
			} else {
				toConvert[i] = str[i]; // Keep considering value the same if character not in [A-Za-z]
			}
		} else { // This char must be to UPPERCASE
			if (str[i] >= 'A' && str[i] <= 'Z') {
				toConvert[i] = str[i]; // Skip this char
			} else if (str[i] >= 'a' && str[i] <= 'z') {
				toConvert[i] = str[i] - 32; // UPPERCASING
			} else {
				toConvert[i] = str[i]; // Keep considering value the same if character not in [A-Za-z]
			}
		}
		isCharLower = !isCharLower; // Announce that the next char must be converted UPPER/lower !
	}
	printf("-> Interleaved Upper-Lower case of the String = <%s>", toConvert);
	return toConvert;
}

char* ex11(char *s) {
	printf("\n-----EXERCISE 11-----\n");
	char temp, *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	int i = 0, j = strlen(str) - 1;
	while (i < j) {
		temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
	printf("-> Reverse of the String = <%s>", str);
	return str;
}

char* ex12(char *str, char c) {
	printf("\n-----EXERCISE 12-----\n");
	char *buffer = (char*) calloc(10, sizeof(char));
	char *position = (char*) calloc(strlen(str) * 3, sizeof(char));
	printf("The String is: <%s>\n", str);
	int i;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			strcat(position, itoa(i + 1, buffer, 10));
			strcat(position, "|");
		}
	}
	printf("-> Character <%c> appears at position [%s]", c, position);
	return position;
}

int ex13(char *str, char c) {
	printf("\n-----EXERCISE 13-----\n");
	printf("The String is: <%s>\n", str);
	int i, times = 0;
	for (i = 0; i < strlen(str); i++) {
		if(str[i] == c) {
			times++;
		}
	}
	printf("-> Character <%c> appears %d times", c, times);
	return times;
}

int ex14(char *fullName, char *name) {
	printf("\n-----EXERCISE 13-----\n");
	printf("Full Name is: <%s>\n", fullName);
	int i, j, nameLength = strlen(name);
	for (i = 0, j = 0; fullName[i] != '\0' && name[j] != '\0'; i++) {
        if (fullName[i] == name[j]) {
            j++;
        } else {
            j = 0;
        }
    }
    if (j == nameLength && (fullName[i] == '\0' || fullName[i] == ' ')) { // Make sure that this is a name! Followed by a space!
    	printf("-> Found name <%s> inside Full Name !", name);
        return 1; /* Substring found ! Return TRUE */
    }
    printf("-> Cannot found <%s> inside Full Name !", name);
	return 0; /* Substring not found ! Return FALSE */
}

void swapStrings(char** str1, char** str2){
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

char** split(char *s) {
	int i, index = 0, strlength = strlen(s) + 1;
	char *str = (char*) calloc(strlength, sizeof(char)); // Initialized $<str> to cut String using strtok() with delimiter.
	char *word = (char*) calloc(strlength, sizeof(char));
	char **words = (char**) calloc(strlength, sizeof(char*));
	
	for (i = 0; i < strlength; i++) { // Dynamic-continuous allocation for each word in the array of words !
		words[i] = (char*) calloc(strlength, sizeof(char));
	}
	strcpy(str, s); // Copy $<s> to $<str> and print out the copied String.
	char *p = strtok(str, " ");
	while (p != NULL) { // Repeat the String-cutting process !
		strcpy(words[index], p); // Assign the trimmed word $<p> to array of words !
		p = strtok(NULL, " ");
		index++;
	}
	words[index] = NULL; // Mark that list of words only have N = index (values) !
	return words;
}

char** ex15(char *s) {
	printf("\n-----EXERCISE 15-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char)); // Initialized $<str> to cut String using strtok() with delimiter.
	char *word = (char*) calloc(strlen(s) + 1, sizeof(char));
	char **words = (char**) calloc(strlen(s) + 1, sizeof(char*));
	int i, index = 0;
	for (i = 0; i < strlen(s) + 1; i++) { // Dynamic-continuous allocation for each word in the array of words !
		words[i] = (char*) calloc(strlen(s) + 1, sizeof(char));
	}
	printf("The String is: <%s>\n", strcpy(str, s)); // Copy $<s> to $<str> and print out the copied String.
	char *p = strtok(str, " ");
	while (p != NULL) { // Repeat the String-cutting process !
		strcpy(words[index], p); // Assign the cutted word $<p> to array of words !
		p = strtok(NULL, " ");
		index++;
	}
	// At this point, index == 3, and you have an array of words: words[0] == "I", words[1] == "was", words[2] == "You"
	swapStrings(words[0], words[index - 1]); // Swap the 1st and the last String !
	for (i = 0; i < index; i++) {
		strcat(word, words[i]);
		strcat(word, " ");
	}
	printf("-> The reversed first/last substring is: <%s>\n", word);
	return words;
}

char** ex16(char *s) {
	printf("\n-----EXERCISE 16-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char)); // Initialized $<str> to cut String using strtok() with delimiter.
	char *lastName = (char*) calloc(strlen(s) + 1, sizeof(char));
	char **names = (char**) calloc(strlen(s) + 1, sizeof(char*)); // Storing all the words from the String !
	int i, index = 0;
	for (i = 0; i < strlen(s) + 1; i++) { // Dynamic-continuous allocation for each name in the array of names !
		names[i] = (char*) calloc(strlen(s) + 1, sizeof(char));
	}
	printf("The String is: <%s>\n", strcpy(str, s)); // Copy $<s> to $<str> and print out the copied String.
	char *p = strtok(str, " ");
	while (p != NULL) { // Repeat the String-cutting process !
		strcpy(names[index], p); // Assign the cutted word $<p> to array of words !
		p = strtok(NULL, " ");
		index++;
	}
	// At this point, index == 3, and you have an array of names: names[0] == "Nguyen", names[1] == "Van", names[2] == "A"
	for (i = 0; i < index - 1; i++) {
		strcat(lastName, names[i]);
		strcat(lastName, " ");
	}
	printf("-> Last Name: <%s>\n", lastName);
	printf("-> First Name: <%s> ", names[index - 1]);
	return names;
}

int ex17(char *str) {
	printf("\n-----EXERCISE 17-----\n");
	printf("The String is: <%s>\n", str);
	int l = 0, h = strlen(str) - 1;	// Start from leftmost and rightmost corners of <$str>
	while (h > l) {	// Keep comparing characters, using 2 pointers until they cross-over each others.
		if (tolower(str[l++]) != tolower(str[h--])) { // Lowercasing the letter before checking !
			printf("-> <%s> is Not Palindrome", str);
			return 0; // Return FALSE
		}
	}
	printf("-> <%s> is Palindrome", str);
	return 1; // Return TRUE
}

int* ex18(char *str) {
	printf("\n-----EXERCISE 18-----\n");
	printf("The String is: <%s>\n", str);
	int *digitArray = (int*) calloc(strlen(str) + 1, sizeof(int));
	int i, j = 0;
	printf("-> All digits contained are: ");
	for (i = 0; i < strlen(str); i++) { // Print out the value of each extracted digits !
		if (str[i] > '0' && str[i] < '9') {
			printf("[%c]", str[i]);
			digitArray[j++] = str[i] - '0';
		}
	}
	return digitArray; // Return an array of extracted digits.
}

char* ex19(char *s, char delete) {
	printf("\n-----EXERCISE 5-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	int i = 0, j = 0;
	while (str[i]) {
		if (str[i] != delete) {
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
	printf("-> String after deleting <%c> = <%s>", delete, str);
	return str;
}

char* ex20(char *str) {
	printf("\n-----EXERCISE 20-----\n");
	printf("The String is: <%s>\n", str);
	int *visited = (int*) calloc(500, sizeof(int)); // 500 continous data blocks to count visited characters !
	char *charsMaxFreq = (char*) calloc(strlen(str) + 1, sizeof(char)); // String contains max-frequency characters !
	int i, j = 0, maxFrequency = 0;
	for (i = 0; i < strlen(str); i++) {
		if (maxFrequency < ++visited[str[i]]) {
			maxFrequency = visited[str[i]];
		}
	}
	for (i = 0 + '0'; i < 255 + '0'; i++) {
		if (visited[i] == maxFrequency) {
			charsMaxFreq[j++] = i;
		}
		charsMaxFreq[j] = '\0';
	}
	printf("-> Characters with Max Frequency: <%s>\n", charsMaxFreq);
	printf("-> Number of occurrences: %d ", maxFrequency);
	return charsMaxFreq;
}

char* ex21(char *s, char *delete) {
	printf("\n-----EXERCISE 21-----\n");
	char *str = (char*) calloc(strlen(s) + 1, sizeof(char));
	printf("The String is: <%s>\n", strcpy(str, s));
	int i, j, start, stop, deleteLength = strlen(delete);
	
	for (i = 0, j = 0; str[i] != '\0' && delete[j] != '\0'; i++) {
        if (str[i] == delete[j]) {
            j++;
        } else {
            j = 0;
        }
    }
    if (j == deleteLength) {
        start = i - j; /* Substring found at index <$start> */
    } else {
        start = -1; /* Substring not found ! */
        printf("-> Cannot found Substring <%s> !", delete);
        return "Substring not found !";
    }
    for (i = start; str[i] != '\0'; i++) {
    	str[i] = str[i + deleteLength];
	}
	str[i] = '\0';
	printf("-> String after deleting <%s> = <%s>", delete, str);
	return str;
}

int main () {
	ex01("International University Ph.D Loan", " ");
	ex02(" International University", "Tp. HCM", "aeiou");
	ex03(100);
	ex04("I n p u t ! ");
	ex05(" H e l l o W o r l d ! ");
	ex06("Hello ", "World !");
	ex07("ToLowerCase");
	ex08("ToUpperCase");
	ex09("10_hEllO - inTerNational uniVerSity !");
	ex10("A--BCDE__fghi++jk");
	ex11("ABCDE");
	ex12("Hello World !", 'l');
	ex13("Hello World !", 'l');
	ex14("Johnny Tri Nguyen", "Tri");
	ex15("I was You");
	ex16("Nguyen Van A");
	ex17("Racecar");
	ex18("H3ll0 th1s 1s my 1st g4m3 th40ry !");
	ex19("Hello World !", 'l');
	ex20("Helloo WWWorld !");
	ex21("Faculty of Information Technology", " Technology");
}


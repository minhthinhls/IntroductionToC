#include <stdio.h>	// printf()
#include <string.h>	// strlen(), strcpy()
#include <stdlib.h>	// malloc(), calloc()

void swapStrings(char** str1, char** str2){
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

char* getArg(int strlength) { // Get an argument / word !
	char *arg = (char*) calloc(strlength, sizeof(char));
	return arg;
}

char** getArgv(int vectorlength, int strlength) { // Get an argument vector / list-of-words !
	int i;
	char **argv = (char**) calloc(vectorlength, sizeof(char*));
	for (i = 0; i < vectorlength; i++) { // Dynamic-continuous allocation for each word in the array of words !
		argv[i] = (char*) calloc(strlength, sizeof(char));
	}
	return argv;
}

char** split(char *s, char *delimiter) {
	int i, index = 1, strlength = strlen(s) + 1;
	char *buffer = getArg(10); // Buffer to convert int to String !
	char *str = getArg(strlength); // Initialized $<str> to cut String using strtok() with delimiter.
	char *word = getArg(strlength);
	char **words = getArgv(strlength, strlength);
	char *p = strtok(strcpy(str, s), delimiter); // Copy $<s> to $<str> and run the first delimiting program !
	while (p != NULL) { // Repeat the String-cutting process !
		strcpy(words[index++], p); // Assign the trimmed word $<p> to array of words !
		p = strtok(NULL, delimiter);
	}
	words[index] = NULL; // Mark that the list-of-words ends at index (values) !
	words[0] = itoa(index - 1, buffer, 10); // List-of-words only has N = index - 1 (values) ; Stored at words[0] !
	return words; // $<words[0]> == Numbers of words contained in this vector ! $<words>[1...index - 1] == the splitted words !
}

void ex01(char *s, char *delimiter) {
	printf("\n-----EXERCISE 1-----\n");
	char *p, *str = getArg(strlen(s) + 1);
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
	printf("-> String as input: <%s>\n", s);
}

void ex02(char *s1, char *s2, char *s3) {
	printf("\n-----EXERCISE 2-----\n");
	char *input = getArg(strlen(s1) + strlen(s2) + 1);
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
	printf("\nThe result <=> The times appear of [aeiou] in String: %d\n", k); 
}

int ex03(int maxLength) {
	printf("\n-----EXERCISE 3-----\n");
	char *str = getArg(maxLength);
	printf("Input the String: ");
	int num = strlen(gets(str));
	printf("-> Number of characters in String = %d\n", num);
	return num;
}

int ex04(char *s) {
	printf("\n-----EXERCISE 4-----\n");
	char *str = getArg(strlen(s) + 1);
	printf("The String is: <%s>\n", strcpy(str, s));
	int numSpace = 0, i;
	for (i = 0; i < strlen(str); i++) {
		if (*(str + i) == ' ') {
			numSpace++;
		}
	}
	printf("-> Num of spaces in String = %d\n", numSpace);
	return numSpace;
}

char* ex05(char *s) {
	printf("\n-----EXERCISE 5-----\n");
	char *str = getArg(strlen(s) + 1);
	printf("The String is: <%s>\n", strcpy(str, s));
	int i = 0, j = 0;
	while (str[i]) {
		if (str[i] != ' ') {
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
	printf("-> String after remove spaces = <%s>\n", str);
	return str;
}

char* ex06(char *s1, char *s2) {
	printf("\n-----EXERCISE 6-----\n");
	char *str = getArg(strlen(s1) + strlen(s2) + 1);
	printf("String 1 = %s\nString 2 = %s\n", strcpy(str, s1), s2);
	printf("-> String concatenated = <%s>\n", strcat(str, s2));
	return str;
}

char* ex07(char *s) {
	printf("\n-----EXERCISE 7-----\n");
	char *str = getArg(strlen(s) + 1);
	printf("The String is: <%s>\n", strcpy(str, s));
	int i;
	for (i = 0; i < strlen(str); i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}
	printf("-> String after lowercasing = <%s>\n", str);
	return str;
}

char* ex08(char *s) {
	printf("\n-----EXERCISE 8-----\n");
	char *str = getArg(strlen(s) + 1);
	printf("The String is: <%s>\n", strcpy(str, s));
	int i;
	for (i = 0; i < strlen(str); i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
	}
	printf("-> String after uppercasing = <%s>\n", str);
	return str;
}

char* ex09(char *s) {
	printf("\n-----EXERCISE 9-----\n");
	char *str = getArg(strlen(s) + 1);
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
	printf("-> String after title uppering = <%s>\n", str);
	return str;
}

char* ex10(char *str) {
	printf("\n-----EXERCISE 10-----\n");
	char *toConvert = getArg(strlen(str) + 1);
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
	printf("-> Interleaved Upper-Lower case of the String = <%s>\n", toConvert);
	return toConvert;
}

char* ex11(char *s) {
	printf("\n-----EXERCISE 11-----\n");
	char temp, *str = getArg(strlen(s) + 1);
	printf("The String is: <%s>\n", strcpy(str, s));
	int i = 0, j = strlen(str) - 1;
	while (i < j) {
		temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
	printf("-> Reverse of the String = <%s>\n", str);
	return str;
}

char* ex12(char *str, char c) {
	printf("\n-----EXERCISE 12-----\n");
	char *buffer = getArg(10);
	char *position = getArg(strlen(str) * 3);
	printf("The String is: <%s>\n", str);
	int i;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			strcat(position, itoa(i + 1, buffer, 10));
			strcat(position, "|");
		}
	}
	printf("-> Character <%c> appears at position [%s]\n", c, position);
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
	printf("-> Character <%c> appears %d times\n", c, times);
	return times;
}

int ex14(char *fullName, char *name) {
	printf("\n-----EXERCISE 14-----\n");
	printf("Full Name is: <%s>\n", fullName);
	int i, j, nameLength = strlen(name);
	for (i = 0, j = 0; fullName[i] != '\0' && name[j] != '\0'; i++) {
        if (fullName[i] == name[j]) {
            j++;
        } else {
            j = 0;
        }
    }
    if (j == nameLength && (fullName[i] == '\0' || fullName[i] == ' ')) { // Make sure that this is a name, followed by a space or end !
    	printf("-> Found name <%s> inside Full Name !\n", name);
        return 1; /* Substring found ! Return TRUE */
    }
    printf("-> Cannot found <%s> inside Full Name !\n", name);
	return 0; /* Substring not found ! Return FALSE */
}

char* ex15(char *str) {
	printf("\n-----EXERCISE 15-----\n");
	printf("The String is: <%s>\n", str);
	char *word = getArg(strlen(str));
	char **words = split(str, " ");
	int i, index = 0, wlength = atoi(words[0]);
	swapStrings(words[1], words[wlength]); // Swap the 1st and the last String !
	for (i = 1; i < wlength; i++) { // Concatenating from the 1st to the word right before the last word !
		strcat(word, words[i]);
		strcat(word, " ");
	}
	strcat(word, words[i]); // Concatenating the last word !
	printf("-> The reversed first/last substring is: <%s>\n", word);
	return word;
}

char** ex16(char *str) {
	printf("\n-----EXERCISE 16-----\n");
	printf("The String is: <%s>\n", str);
	char *lastName = getArg(strlen(str));
	char **words = split(str, " ");
	int i, index = 0, wlength = atoi(words[0]);
	for (i = 1; i < wlength - 1; i++) { // Concatenating from the 1st to the word right before the Last-Name word !
		strcat(lastName, words[i]);
		strcat(lastName, " ");
	}
	strcat(lastName, words[i]); // Concatenating the Last-Name word !
	char **names = getArgv(2, strlen(str));
	names[0] = lastName;
	names[1] = words[wlength];
	printf("-> Last Name: <%s>\n", names[0]);
	printf("-> First Name: <%s>\n", names[1]);
	return names;
}

int ex17(char *str) {
	printf("\n-----EXERCISE 17-----\n");
	printf("The String is: <%s>\n", str);
	int l = 0, h = strlen(str) - 1;	// Start from leftmost and rightmost corners of <$str>
	while (h > l) {	// Keep comparing characters, using 2 pointers until they cross-over each others.
		if (tolower(str[l++]) != tolower(str[h--])) { // Lowercasing the letter before checking !
			printf("-> <%s> is Not Palindrome\n", str);
			return 0; // Return FALSE
		}
	}
	printf("-> <%s> is Palindrome\n", str);
	return 1; // Return TRUE
}

int* ex18(char *str) {
	printf("\n-----EXERCISE 18-----\n");
	printf("The String is: <%s>\n", str);
	int *digitArray = (int*) calloc(strlen(str) + 1, sizeof(int));
	int i, j = 0;
	printf("-> All digits contained are: ");
	for (i = 0; i < strlen(str); i++) { // Print out the value of each extracted digits !
		if (str[i] >= '0' && str[i] <= '9') {
			printf("[%c]", str[i]);
			digitArray[j++] = str[i] - '0'; // Convert character to integer !
		}
	}
	printf("\n");
	return digitArray; // Return an array of extracted digits.
}

char* ex19(char *s, char delete) {
	printf("\n-----EXERCISE 19-----\n");
	char *str = getArg(strlen(s) + 1);
	printf("The String is: <%s>\n", strcpy(str, s));
	int i = 0, j = 0;
	while (str[i]) {
		if (str[i] != delete) {
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
	printf("-> String after deleting <%c> = <%s>\n", delete, str);
	return str;
}

char* ex20(char *str) {
	printf("\n-----EXERCISE 20-----\n");
	printf("The String is: <%s>\n", str);
	int *visited = (int*) calloc(500, sizeof(int)); // 500 continous data blocks to count visited characters !
	char *charsMaxFreq = getArg(strlen(str) + 1); // String contains max-frequency characters !
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
	printf("-> Number of occurrences: %d\n", maxFrequency);
	return charsMaxFreq;
}

char* ex21(char *s, char *delete) {
	printf("\n-----EXERCISE 21-----\n");
	char *str = getArg(strlen(s) + 1);
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
	printf("-> String after deleting <%s> = <%s>\n", delete, str);
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


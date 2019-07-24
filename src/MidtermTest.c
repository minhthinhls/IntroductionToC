#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* numToWords(int n, char* s, char** single, char** tenth) {
	if (n < 0 || 999 < n) {
		return "INPUT ERROR";
	}
    //char* str = (char*) malloc(100 * sizeof(char));
    char* str = (char*) calloc(100, sizeof(char));
    *str = "";
    // If n is more than 19, divide it 
    if (n > 19) {
    	if (n > 99) {
    		*str = strcat(str, single[n / 100]);
    		*str = strcat(str, "hundred ");
    		n %= 100;
		}
    	*str = strcat(strcat(str, tenth[n / 10]), single[n % 10]);
	} else {
		*str = strcat(str, single[n]);
	}
    // If n is non-zero 
    if (n) {
    	*str = strcat(str, s);
	} else {
		*str = strcat(str, "zero.");
	}
    return str;
}

void exercise_13() {
	int n;
	printf("Input 3 digits integer 'n' to convert to words: ");
	scanf("%d", &n);
	/* The first string is not used, it is to simplify the array indexing */
    char *single[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", 
						"twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
	/* The first & second strings are not used, they are to simplify the array indexing */
    char *tenth[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
	printf("%d = %s",n ,numToWords(n, ".", single, tenth));
}

int factorial(int n) { 
    if (n <= 0) {
		return 1;
	}
    return n * factorial(n - 1); 
}

void exercise_14() {
	int n;
	printf("Input n to compute factorial: ");
	scanf("%d", &n);
	printf("(%d)! = %d",n ,factorial(n));
}

int combination(int n, int k) {
	if (n < k) {
		return -1;
	}
	int i, numerator = 1;
	for (i = n - k + 1; i <= n; i++) {
		numerator *= i;
	}
	return numerator / factorial(k);
}

void exercise_15() {
	int N, K;
	printf("Input N: ");
	scanf("%d", &N);
	printf("Input K: ");
	scanf("%d", &K);
	printf("%dC%d = %d", N, K, combination(N, K));
}

void exercise_16() {
	int i, n;
	printf("Input n: ");
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		printf("%dC%d = %d\n", n, i, combination(n, i));
	}
}

void exercise_17() {
	int a, b, c, maxAB, maxBC;
	printf("Input a: ");
	scanf("%d", &a);
	printf("Input b: ");
	scanf("%d", &b);
	printf("Input c: ");
	scanf("%d", &c);
	if (a > b) {
		maxAB = a;
	} else {
		maxAB = b;
	}
	if (b > c) {
		maxBC = b;
	} else {
		maxBC = c;
	}
	if (maxAB > maxBC) {
		printf("Max is: %d", maxAB);
	} else {
		printf("Max is: %d", maxBC);
	}
	
}

int fibbonacci(int n) {
	if(n <= 1){
		return n;
	} else {
		return (fibbonacci(n-1) + fibbonacci(n-2));
	}
}

void exercise_18() {
	int i, n;
	printf("Input n values for Fibbonacci series: ");
	scanf("%d", &n);
	printf("Fibbonacci of first %d elements: ", n);
	for(i = 0; i < n; i++) {
		printf("%d ", fibbonacci(i));            
	}
}

void exercise_19() {
	int number, max = 0, maxPos = 1, pos = 1;
	printf("Input integer has 3 digits: ");
	scanf("%3d", &number);
	while (pos <= 100) {
		int modulo = number % 10;
		if (modulo > max) {
			max = modulo;
			maxPos = pos;
		}
		number /= 10;
		pos *= 10;
	}
	printf("Max value is: %d\n", max);
	printf("Max position is at %d-th position !\n", maxPos);
}

void exercise_20() {
	int i, j, m, n;
	printf("Input m: ");
	scanf("%d", &m);
	printf("Input n: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("* ");
		}
		printf("\n");
	}
}

void main() {
	exercise_13();
	//exercise_14();
	//exercise_15();
	//exercise_16();
	//exercise_17();
	//exercise_18();
	//exercise_19();
	//exercise_20();
}

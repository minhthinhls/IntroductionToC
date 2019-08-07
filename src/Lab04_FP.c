#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* ex01(int n) {
	int i, arr[n];
	printf("---------- EXERCISE 1 ----------\n");
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 100 + 1;
		printf("A[%d] = %d\n", i, arr[i]);
	}
	return arr; // Return value is currently not used !
}

int* ex02(int n) {
	int i, value, arr[n], stored[n];
	printf("---------- EXERCISE 2 ----------\n");
	for (i = 0; i < n; i++) { // Initializing storing array with all value == True
		stored[i] = 1;
	}
	for (i = 0; i < n; i++) {
		while(1) {
			value = rand() % n + 1;
			if (stored[value]) { // If the value hasn't been yet used, stored[value] == True
				arr[i] = value;
				stored[value] = 0; // Mark down this value is used, stored[value] == False !
				break;
			}
		}
		printf("A[%3d]\t= %d\t:: Stored[%3d]\t= %d\n", i, arr[i], value, stored[value]);
	}
	return arr; // Return value is currently not used !
}

int isPrime(int n) { 
    /* Corner cases ! */
    if (n <= 1) {
    	return 0; // False
	} else if (n <= 3) {
    	return 1; // True
	}
    /* All number that is divisible by 2 or 3, excepting 2 or 3, are not Prime ! */
    if (n % 2 == 0 || n % 3 == 0) {
        return 0; // False
    }
    int i;
    for (i = 5; i * i <= n; i = i + 6) { // The same loop as i < sqrt(n), continue with value == 5
        if (n % i == 0 || n % (i + 2) == 0) {
        	return 0; // False
		}
	}
    return 1; // True
}

int* ex03(int n) {
	float primes = (float) n / (log(n) - 1); // How many primes are in range [0, n) !
	int i, arr[(int) primes], j = 0;
	printf("---------- EXERCISE 3 ----------\n");
	for (i = 0; i < n; i++) {
		if (isPrime(i)) {
			arr[j] = i;
			printf("A[%2d] = %d\n", j, arr[j++]);
		}
	}
	return arr; // Return value is currently not used !
}

int main() {
	//ex01(100);
	//ex02(100);
	ex03(100);
}


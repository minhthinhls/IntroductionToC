#include <stdio.h>
#include <string.h>

void threeIntegers() {
	printf("Input three different integers: ");
	int i, arr[3];
	for (i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}
	int sum, avg, product, smallest, largest;
	sum = product = smallest = largest = arr[0]; // First elements in the array is assigned for variables.
	for (i = 1; i < 3; i++) {
		sum += arr[i]; // Sum 2 next values.
		product *= arr[i]; // Multiply 2 next values.
		if (arr[i] < smallest) {
			smallest = arr[i]; // Find smallest values.
		}
		if (largest < arr[i]) {
			largest = arr[i]; // Find largest values.
		}
		
	}
	avg = sum / 3;
	printf("Sum is: %d\n", sum);
	printf("Average is: %d\n", avg);
	printf("Product is: %d\n", product);
	printf("Smallest is: %d\n", smallest);
	printf("Largest is: %d\n", largest);
}

void arbitraryIntegers() {
	char* str = (char*)malloc(sizeof(char));
	printf("Input arbitrary integers: ");
	if ( !scanf("%[0-9 ]", str) ) { // Only accepted numbers and space.
		printf("ERROR! INPUT MUST CONTAINS ONLY NUMBERS!");
		return;
	}
	char* ptr = strtok(str, " ");
	int numbers = 0, sum = 0, product = 1, smallest, largest;
	smallest = largest = atoi(ptr); // First elements in the array is assigned for variables.
	while (ptr != NULL) {
		printf("\"%s\"\n", ptr);
		int currentValue = atoi(ptr);
		sum += currentValue; // Sum arbitrary next values.
		product *= currentValue; // Multiply arbitrary next values.
		if (currentValue < smallest) {
			smallest = currentValue; // Find smallest values.
		}
		if (largest < currentValue) {
			largest = currentValue; // Find largest values.
		}
		numbers++;
		ptr = strtok(NULL, " ");
	}
	printf("Sum is: %d\n", sum);
	printf("Average is: %d\n", sum / numbers);
	printf("Product is: %d\n", product);
	printf("Smallest is: %d\n", smallest);
	printf("Largest is: %d\n", largest);
}

void nDigits() {
	int n;
	printf("Input: ");
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("-> %d is an even number !\n", n);
	} else {
		printf("-> %d is an odd number !\n", n);
	}
	printf("Output: ");
	while (n > 0) {
		printf("%d ", n % 10);
		n /= 10;
	}
	printf("\n");
}

void minMax() {
	int i = 0, j;
	printf("Input: ");
	int arr[10];
	while ( scanf("%d", &arr[i]) && arr[i] != 0 ) { // If scanf() throw erros, exit the loop.
		i++;
	} // The value of i stopped at: printf("The current value of i = %d\n", i);
	printf("The current value of i = %d\n", i);
	for (j = 0; j < i; j++) {
		printf("A[%d] = %d\n", j, arr[j]); // Show the array's values.
	}
	int smallest = arr[0], largest = arr[0]; // Assuming the 1st number in array is both smallest & largest one.
	for (j = 1; j < i; j++) {
		if (arr[j] < smallest) {
			smallest = arr[j]; // Find smallest values.
		}
		if (largest < arr[j]) {
			largest = arr[j]; // Find largest values.
		}
	}
	printf("Min: %d\n", smallest);
	printf("Max: %d\n", largest);
}

int main() {
	threeIntegers(); // Example input: 2 -1 4
	fflush(stdin); // Clearing buffers !
	arbitraryIntegers(); // Example input: -3 5 -2 9 8 10 5 -1 0
	fflush(stdin); // Clearing buffers !
	nDigits(); // Example input: 2328
	fflush(stdin); // Clearing buffers !
	minMax(); // Example input: -3 5 -2 9 8 10 5 -1 0
	return 0;
}


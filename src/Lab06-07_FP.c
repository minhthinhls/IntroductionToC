#include <stdio.h>	// printf()
#include <string.h>	// strlen(), strcpy()
#include <stdlib.h>	// malloc(), calloc()

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

void print(int *arr, int nElems) { // This function is for debugging the array !
	int i;
	char *buffer = getArg(10), *text = getArg(10);
	printf("-> The 1-dimensional array is printed below...\n");
	for (i = 0; i < nElems; i++) {
		strcpy(text, "A[");
		strcat(text, itoa(i, buffer, 10));
		printf("%7s", strcat(text, "]"));
	}
	printf("\n");
	for (i = 0; i < nElems; i++) {
		printf("%7d", arr[i]);
	}
	printf("\n");
}

int* getIntArg(int intlength) { // Get an integer argument vector / list-of-integer !
	int *arg = (int*) calloc(intlength, sizeof(int));
	return arg;
}

int** getIntArgv(int vectorlength, int intlength) { // Get integers argument vectors / list-of-array-integers !
	int i, **argv = (int**) calloc(vectorlength, sizeof(int*));
	for (i = 0; i < vectorlength; i++) { // Dynamic-continuous allocation for each integer in the array of integers !
		argv[i] = (int*) calloc(intlength, sizeof(int));
	}
	return argv;
}

void swap(int *left, int *right) {
	int temp = *right;
	*right = *left;
	*left = temp;
}

int* cloneArray1D(int *arr, int nElems) {
	int i, *clone = getIntArg(nElems);
	for (i = 0; i < nElems; i++) {
		clone[i] = arr[i];
	}
	return clone;
}

int** getRandomIntArray2D(int nRows, int nColumns, int minVal, int maxVal, int isIncreasing) {
	if (nRows < 1 || nColumns < 1 || minVal > maxVal) {
		printf("-> Error during creating 2D array of integers !\n");
		return NULL;
	}
	int i, j, **arr = getIntArgv(nRows, nColumns);
	int maxStep = (maxVal - minVal) / (nRows + nColumns - 2); // Each next-value must not larger than this maxStep !
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			if (isIncreasing) { /* For question 2, the 2D integer array follows the increasing order rule ! */
				while (1) {
					int val = (rand() % (maxVal - minVal + 1)) + minVal; // Value ranged from [min, max]
					if (j == 0) { // At first column !
						if (i == 0) { // At first column & first row !
							arr[i][j] = minVal; // Assuming the first value in the array is min value !
							break;
						} else { // At first column & from 2nd to n-th rows !
							int prev = arr[i - 1][j];
							if (val <= prev || val - prev > maxStep) {
								continue; // Checking is this a larger values in row, while not exceed the step !
							} else {
								arr[i][j] = val;
								break;
							}
						}
					} else { // From 2nd to n-th columns !
						if (i == 0) { // At first row & from 2nd to n-th columns !
							int prev = arr[i][j - 1];
							if (val <= prev || val - prev > maxStep) {
								continue; // Checking is this a larger values in column, while not exceed the step !
							} else {
								arr[i][j] = val;
								break;
							}
						} else { // From 2nd to n-th rows & 2nd to n-th columns !
							int prev1 = arr[i - 1][j];
							int prev2 = arr[i][j - 1];
							if (val <= prev1 || val <= prev2 || val - prev1 > maxStep || val - prev2 > maxStep) {
								continue; // Checking is this a larger values in both row & column, while not exceed the step !
							} else {
								arr[i][j] = val;
								break;
							}
						}
					}
				}
			} else { /* For question 1, the 2D integer array is generated randomly ! */
				arr[i][j] = (rand() % (maxVal - minVal + 1)) + minVal;
			}
		}
	}
	return arr;
}

int sumArray1D(int *arr, int n) {
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

int minArray1D(int *arr, int n) {
	int i, min = arr[0];
	for (i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int minArray2D(int **arr, int nRows, int nColumns) {
	int i, j, min = arr[0][0];
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
	}
	return min;
}

int maxArray1D(int *arr, int n) {
	int i, max = arr[0];
	for (i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int maxArray2D(int **arr, int nRows, int nColumns) {
	int i, j, max = arr[0][0];
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	return max;
}

int* getRow(int irow, int **arr, int nRows, int nColumns) {
	if (irow < 0 || nRows <= irow) {
		printf("-> Error while get row[%d] from array !\n", irow);
		return NULL;
	}
	int column, value;
	int *row = getIntArg(nColumns); // Earch row has $<nColumns> elements !
	for (column = 0; column < nColumns; column++) {
		row[column] = arr[irow][column];
	}
	return row;
}

int* getColumn(int icolumn, int **arr, int nRows, int nColumns) {
	if (icolumn < 0 || nColumns <= icolumn) {
		printf("-> Error while get column[%d] from array !\n", icolumn);
		return NULL;
	}
	int row, value;
	int *column = getIntArg(nRows); // Earch column has $<nRows> elements !
	for (row = 0; row < nRows; row++) {
		column[row] = arr[row][icolumn];
	}
	return column;
}

int* majorDiagonal(int **arr, int n) {
	int i, *diag = getIntArg(n);
	for (i = 0; i < n; i++) {
		diag[i] = arr[i][i];
	}
	return diag;
}

int* minorDiagonal(int **arr, int n) {
	int i, j, *diag = getIntArg(n);
	for (i = 0; i < n; i++) {
		diag[i] = arr[n - 1 - i][i];
	}
	return diag;
}

int isPerfectSquare(int number) {
	float fVar = sqrt((double) number);
	int iVar = fVar;
	if (iVar == fVar) {
		return 1;
	}
	return 0;
}

int numPerfectSquare(int *arr, int n) {
	int i, numOfSquare = 0;
	for (i = 0; i < n; i++) {
		if (isPerfectSquare(arr[i])) {
			numOfSquare++;
		}
	}
	return numOfSquare;
}

int isPrime(int n) {
	if (n <= 1) { // Corner cases !
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

int numPrime(int *arr, int n) {
	int i, numPrime = 0;
	for (i = 0; i < n; i++) {
		if (isPrime(arr[i])) {
			numPrime++;
		}
	}
	return numPrime;
}

int numOccurrencesOf(int *arr, int n, int x) {
	int i, numOccurrences = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] == x) {
			numOccurrences++;
		}
	}
	return numOccurrences;
}

int horizontalZigzagIncrement(int **arr, int nRows, int nColumns) {
	int evenRow = 0; // Starts from the first row !
	int oddRow = 1; // Starts from the next row !
	int column, curValue, preValue; // Current value and previous value to check is this increasing !
	while (evenRow < nRows) { // Exceed the last row of the array -> Stop iterating !
		for (column = 0; column < nColumns; column++) {
			if (evenRow == 0 && column == 0) {
				curValue = arr[0][0];
				printf("[%d]", curValue);
				continue; // Skip the first value since we need to initiate $<curValue>
			}
			preValue = curValue;
			curValue = arr[evenRow][column];
			printf("[%d]", curValue); // evenRow will be printed in the same direction !
			if (preValue > curValue) {
				return 0; // Return FALSE
			}
		}
		evenRow += 2; // Skipping next row so as to get the next evenRow !
		
		if(oddRow < nRows) {
			for (column = nColumns - 1; column >= 0; column--) {
				preValue = curValue;
				curValue = arr[oddRow][column];
				printf("[%d]", curValue); // oddRow will be printed in the opposite direction !
				if (preValue > curValue) {
					return 0; // Return FALSE
				}
			}
		}
		oddRow += 2; // Skipping next row so as to get the next oddRow !
	}
	return 1; // Return TRUE
}

int verticalZigzagIncrement(int **arr, int nRows, int nColumns) {
	int evenColumn = 0; // Starts from the first column !
	int oddColumn = 1; // Starts from the next column !
	int row, curValue, preValue; // Current value and previous value to check is this increasing !
	while (evenColumn < nColumns) { // Exceed the last row of the array -> Stop iterating !
		for (row = 0; row < nRows; row++) {
			if (evenColumn == 0 && row == 0) {
				curValue = arr[0][0];
				printf("[%d]", curValue);
				continue; // Skip the first value since we need to initiate $<curValue>
			}
			preValue = curValue;
			curValue = arr[row][evenColumn];
			printf("[%d]", curValue); // evenRow will be printed in the same direction !
			if (preValue > curValue) {
				return 0; // Return FALSE
			}
		}
		evenColumn += 2; // Skipping next row so as to get the next evenRow !
		
		if(oddColumn < nColumns) {
			for (row = nRows - 1; row >= 0; row--) {
				preValue = curValue;
				curValue = arr[row][oddColumn];
				printf("[%d]", curValue); // oddRow will be printed in the opposite direction !
				if (preValue > curValue) {
					return 0; // Return FALSE
				}
			}
		}
		oddColumn += 2; // Skipping next row so as to get the next oddRow !
	}
	return 1; // Return TRUE
}

int isPalindrome(int *arr, int n) {
	int low = 0, high = n - 1; // Start from leftmost and rightmost corners of array
	while (low < high) { // Keep comparing integers, using 2 pointers until they cross-over each others.
		if (arr[low++] != arr[high--]) {
			return 0; // Return FALSE
		}
	}
	return 1; // Return TRUE
}

int isAllEven(int *arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] % 2) {
			return 0; // Return FALSE
		}
	}
	return 1; // Return TRUE
}

int isAscendingSorted(int *arr, int n) {
	int i;
	for (i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			return 0; // Return FALSE
		}
	}
	return 1; // Return TRUE
}

int* inputRecursiveArray1D(int *arr, int i, int n) {
	if (i < 0 || i >= n) {
		return arr;
	}
	printf("Input arr[%d]: ", i);
	scanf("%d", arr + i);
	return inputRecursiveArray1D(arr, i + 1, n);
}

int sumRecursiveArray1D(int *arr, int *endingPointer) {
	if (arr == endingPointer) {
		return 0;
	}
	return *arr + sumRecursiveArray1D(arr + 1, endingPointer);
}

int sumRecursiveOptionalArray1D(int *arr, int *endingPointer, char *option) {
	if (arr == endingPointer) {
		return 0;
	}
	if (!strcmp(option, "positive")) {
		if (*arr > 0) {
			return *arr + sumRecursiveOptionalArray1D(arr + 1, endingPointer, "positive");
		} else {
			return sumRecursiveOptionalArray1D(arr + 1, endingPointer, "positive");
		}
	} else if (!strcmp(option, "negative")) {
		if (*arr < 0) {
			return *arr + sumRecursiveOptionalArray1D(arr + 1, endingPointer, "negative");
		} else {
			return sumRecursiveOptionalArray1D(arr + 1, endingPointer, "negative");
		}
	} else if (!strcmp(option, "odd")) {
		if (*arr % 2) {
			return *arr + sumRecursiveOptionalArray1D(arr + 1, endingPointer, "odd");
		} else {
			return sumRecursiveOptionalArray1D(arr + 1, endingPointer, "odd");
		}
	} else if (!strcmp(option, "even")) {
		if (*arr % 2 == 0) {
			return *arr + sumRecursiveOptionalArray1D(arr + 1, endingPointer, "even");
		} else {
			return sumRecursiveOptionalArray1D(arr + 1, endingPointer, "even");
		}
	} else if (!strcmp(option, "prime")) {
		if (isPrime(*arr)) {
			return *arr + sumRecursiveOptionalArray1D(arr + 1, endingPointer, "prime");
		} else {
			return sumRecursiveOptionalArray1D(arr + 1, endingPointer, "prime");
		}
	} else if (!strcmp(option, "square")) {
		if (isPerfectSquare(*arr)) {
			return *arr + sumRecursiveOptionalArray1D(arr + 1, endingPointer, "square");
		} else {
			return sumRecursiveOptionalArray1D(arr + 1, endingPointer, "square");
		}
	}
	printf("-> What's your option ? Please choose one !\n");
	return NULL;
}

int maxRecursiveArray1D(int *arr, int *endingPointer) {
	if (arr == endingPointer) {
		return *(arr - 1);
	}
	int maxProgram = maxRecursiveArray1D(arr + 1, endingPointer);
	return *arr > maxProgram ? *arr : maxProgram;
}

int minRecursiveArray1D(int *arr, int *endingPointer) {
	if (arr == endingPointer) {
		return *(arr - 1);
	}
	int minProgram = minRecursiveArray1D(arr + 1, endingPointer);
	return *arr < minProgram ? *arr : minProgram;
}

int maxNegativeRecursively(int *arr, int *endingPointer, int min) {
	if (arr == endingPointer) {
		if (*arr < 0) {
			return *arr;
		}
		return min; // Return smallest element of array if out of bound index !
	}
	if (*arr < 0) {
		int maxProgram = maxNegativeRecursively(arr + 1, endingPointer, min);
		return *arr > maxProgram ? *arr : maxProgram;
	}
	return maxNegativeRecursively(arr + 1, endingPointer, min);
}

int minPositiveRecursively(int *arr, int *endingPointer, int max) {
	if (arr == endingPointer) {
		if (*arr > 0) {
			return *arr;
		}
		return max; // Return largest element of array if out of bound index !
	}
	if (*arr > 0) {
		int minProgram = minPositiveRecursively(arr + 1, endingPointer, max);
		return *arr < minProgram ? *arr : minProgram;
	}
	return minPositiveRecursively(arr + 1, endingPointer, max);
}

int numRecursiveOccurrencesOf(int *arr, int *endingPointer, int x) {
	if (arr == endingPointer) {
		return 0;
	}
	if (*arr == x) {
		return 1 + numRecursiveOccurrencesOf(arr + 1, endingPointer, x);
	}
	return numRecursiveOccurrencesOf(arr + 1, endingPointer, x);
}

int isAscendingRecursively(int *arr, int *endingPointer) {
	if (arr == endingPointer) {
		return 1; // Return TRUE
	}
	if (*arr > *(arr + 1)) {
		return 0; // Return FALSE
	}
	return isAscendingRecursively(arr + 1, endingPointer);
}

int isDescendingRecursively(int *arr, int *endingPointer) {
	if (arr == endingPointer) {
		return 1; // Return TRUE
	}
	if (*arr < *(arr + 1)) {
		return 0; // Return FALSE
	}
	return isDescendingRecursively(arr + 1, endingPointer);
}

int isNegativeElementRecursively(int *arr, int *endingPointer) {
	if (arr == endingPointer) {
		return 0; // Return FALSE
	}
	if (*arr < 0) {
		return 1; // Return TRUE
	}
	return isNegativeElementRecursively(arr + 1, endingPointer);
}

int isPalindromeRecursively(int *low, int *high) {
	if (low > high) {
		return 1; // Return TRUE
	}
	if (*low != *high) {
		return 0; // Return FALSE
	}
	return isPalindromeRecursively(low + 1, high - 1);
}

void ascendingRecursiveSort(int *arr, int n) {
	if (n == 1) {
		return;
	}
	int i;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			swap(arr + i, arr + i + 1);
		}
	}
	ascendingRecursiveSort(arr, n - 1);
}

void descendingRecursiveSort(int *arr, int n) {
	if (n == 1) {
		return;
	}
	int i;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] < arr[i + 1]) {
			swap(arr + i, arr + i + 1);
		}
	}
	descendingRecursiveSort(arr, n - 1);
}

int* reverseArrayRecursively(int *des, int* arr, int i, int nElems) {
	if (i == nElems) {
		return des;
	}
	des[i] = arr[nElems - i - 1];
	return reverseArrayRecursively(des, arr, i + 1, nElems);
}

/* ------------------------------------------------------------- */
/* --------------------ULTILITIES END HERE !-------------------- */
/* ------------------------------------------------------------- */

int** ex01(int nRows, int nColumns, int min, int max) {
	int i, j;
	int **arr = getRandomIntArray2D(nRows, nColumns, min, max, 0); // isIncreasing == 0 == FALSE
	printf("\n-----EXERCISE 1-----\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			printf("%-5d", arr[i][j]);
		}
		printf("\n");
	}
	return arr; // Return value is currently not used !
}

int** ex02(int nRows, int nColumns, int min, int max) {
	int i, j;
	int **arr = getRandomIntArray2D(nRows, nColumns, min, max, 1); // isIncreasing == 1 == TRUE
	printf("\n-----EXERCISE 2-----\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			printf("%-5d", arr[i][j]);
		}
		printf("\n");
	}
	return arr; // Return value is currently not used !
}

int ex03(int **arr, int nRows, int nColumns) {
	int i, j, k, sum = 0;
	int maxVal = maxArray2D(arr, nRows, nColumns);
	int minVal = minArray2D(arr, nRows, nColumns);
	int *occurrences = getIntArg(maxVal + 1);	/* Create an array stored number occurences of 127 ASCII values !
													Initializing storing array with all value == 0 == FALSE */
	printf("\n-----EXERCISE 3-----\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			occurrences[arr[i][j]]++;
		}
	}
	for (k = minVal; k <= maxVal; k++) {
		if (occurrences[k] > 1) {
			printf("[%d]", k);
		} else if (occurrences[k] == 1) {
			sum += k;
		}
	}
	printf(" -> The distinct sum of values: <%d>\n", sum);
	return sum;
}

int ex04(int **arr, int nRows, int nColumns) {
	int i, j, k, sum = 0, value;
	int maxVal = maxArray2D(arr, nRows, nColumns);
	int minVal = minArray2D(arr, nRows, nColumns);
	int *occurrences = getIntArg(maxVal + 1);	/* Create an array stored number occurences of 127 ASCII values !
													Initializing storing array with all value == 0 == FALSE */
	printf("\n-----EXERCISE 4-----\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			value = arr[i][j];
			if (!occurrences[value]++) { // If the value hasn't been used yet !
				sum += value;
			}
		}
	}
	for (k = minVal; k <= maxVal; k++) {
		if (occurrences[k] > 1) {
			printf("[%d]", k);
		}
	}
	printf(" -> The non-repeating sum of values: <%d>\n", sum);
	return sum;
}

void ex05(int *arr, int nSize) {
	int sumMainDiag = 0, sumMinorDiag = 0;
	printf("\n-----EXERCISE 5-----\n");
	printf("-> The sum of major diagonal: <%d>\n", sumArray1D(majorDiagonal(arr, nSize), nSize));
	printf("-> The sum of minor diagonal: <%d>\n", sumArray1D(minorDiagonal(arr, nSize), nSize));
}

float ex06(int **arr, int nRows, int nColumns) {
	int i, j, sum = 0, num = 0;
	printf("\n-----EXERCISE 6-----\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			if (arr[i][j] > 0) {
				sum += arr[i][j];
				num++;
			}
		}
	}
	float avgPositiveSum = (float) sum / (float) num;
	printf("-> The average of positive integers: <%f>\n", avgPositiveSum);
	return avgPositiveSum;
}

int ex07(int **arr, int nRows, int nColumns, int x) {
	int i, j, occurrences = 0;
	printf("\n-----EXERCISE 7-----\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			if (arr[i][j] == x) {
				occurrences++;
			}
		}
	}
	printf("-> The occurrences of x = <%d> is: <%d> times\n", x, occurrences);
	return occurrences;
}

void ex08(int **arr, int nRows, int nColumns) {
	int irow, numOfSquare;
	printf("\n-----EXERCISE 8-----\n");
	for (irow = 0; irow < nRows; irow++) {
		int *row = getRow(irow, arr, nRows, nColumns);
		numOfSquare = numPerfectSquare(row, nColumns);
		printf("-> Occurrences of squared number on row[%d] is: <%d> times\n", irow, numOfSquare);
	}
	return;
}

int* ex09(int **arr, int nRows, int nColumns) {
	printf("\n-----EXERCISE 9-----\n");
	int *minMax = getIntArg(2);
	minMax[0] = minArray2D(arr, nRows, nColumns);
	minMax[1] = maxArray2D(arr, nRows, nColumns);
	printf("-> Max value of the array is: <%d>\n", minMax[1]);
	printf("-> Min value of the array is: <%d>\n", minMax[0]);
	return minMax;
}

void ex10(int **arr, int nRows, int nColumns) {
	int irow;
	printf("\n-----EXERCISE 10-----\n");
	for (irow = 0; irow < nRows; irow++) {
		int *row = getRow(irow, arr, nRows, nColumns);
		int max = maxArray1D(row, nColumns);
		int min = minArray1D(row, nColumns);
		printf("-> On row[%d]: Max=[%d] Min=[%d]\n", irow, max, min);
	}
	return;
}

void ex11(int **arr, int nRows, int nColumns) {
	int icolumn;
	printf("\n-----EXERCISE 11-----\n");
	for (icolumn = 0; icolumn < nColumns; icolumn++) {
		int *column = getColumn(icolumn, arr, nRows, nColumns);
		int max = maxArray1D(column, nRows);
		int min = minArray1D(column, nRows);
		printf("-> On column[%d]: Max=[%d] Min=[%d]\n", icolumn, max, min);
	}
	return;
}

int* ex12(int **arr, int nRows, int nColumns) {
	int irow = 0, icolumn = 0, largestRow = 0, largestColumn = 0;
	printf("\n-----EXERCISE 12-----\n");
	int *maxRowColumn = getIntArg(2);
	maxRowColumn[0] = sumArray1D(getRow(irow, arr, nRows, nColumns), nColumns);
	maxRowColumn[1] = sumArray1D(getColumn(icolumn, arr, nRows, nColumns), nRows);
	for (irow = 1; irow < nRows; irow++) {
		int *row = getRow(irow, arr, nRows, nColumns);
		int sumRow = sumArray1D(row, nColumns);
		if (maxRowColumn[0] < sumRow) {
			largestRow = irow;
			maxRowColumn[0] = sumRow;
		}
	}
	for (icolumn = 1; icolumn < nColumns; icolumn++) {
		int *column = getColumn(icolumn, arr, nRows, nColumns);
		int sumColumn = sumArray1D(column, nRows);
		if (maxRowColumn[1] < sumColumn) {
			largestColumn = icolumn;
			maxRowColumn[1] = sumColumn;
		}
	}
	printf("-> Largest sum on row[%d]: Sum=[%d]\n", largestRow, maxRowColumn[0]);
	printf("-> Largest sum on column[%d]: Sum=[%d]\n", largestColumn, maxRowColumn[1]);
	return maxRowColumn;
}

int ex13(int **arr, int nRows, int nColumns) {
	printf("\n-----EXERCISE 13-----\n");
	int i, j, min = minArray2D(arr, nRows, nColumns);
	if (min >= 0) {
		printf("-> There's no negative element of the array !\n");
		return NULL;
	}
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			if (arr[i][j] < 0 && arr[i][j] > min) {
				min = arr[i][j];
			}
		}
	}		
	printf("-> Largest negative element of the array is: <%d>\n", min);
	return min;
}

int ex14(int **arr, int nRows, int nColumns) {
	int i, j, k, maxFrequency = 0;
	int maxVal = maxArray2D(arr, nRows, nColumns);
	int minVal = minArray2D(arr, nRows, nColumns);
	printf("\n-----EXERCISE 14-----\n");
	int *visited = getIntArg(maxVal + 1); // (maxVal + 1) continous data blocks to count visited characters !
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			if (maxFrequency < ++visited[arr[i][j]]) {
				maxFrequency = visited[arr[i][j]];
			}
		}
	}
	for (k = minVal; k <= maxVal; k++){
		if (visited[k] == maxFrequency) {
			printf("[%d]", k);
		}
	}
	printf(" -> Highest frequency element of the array is: <%d>\n", maxFrequency);
	return maxFrequency;
}

int ex15(int **arr, int nRows, int nColumns) {
	int irow = 0, primeRow = 0;
	int maxNumPrimeRow = numPrime(getRow(irow, arr, nRows, nColumns), nColumns);
	printf("\n-----EXERCISE 15-----\n");
	for (irow = 1; irow < nRows; irow++) {
		int *row = getRow(irow, arr, nRows, nColumns);
		int numPrimeRow = numPrime(row, nColumns);
		if (maxNumPrimeRow < numPrimeRow) {
			primeRow = irow;
			maxNumPrimeRow = numPrimeRow;
		}
	}
	if (!maxNumPrimeRow) {
		printf("-> Cannot found primes in any column !\n");
		return 0;
	}
	printf("-> On row[%d] contains the most %d times of primes\n", primeRow, maxNumPrimeRow);
	return maxNumPrimeRow;
}

int ex16(int **arr, int nRows, int nColumns, int x) {
	int icolumn = 0, xColumn = 0;
	int maxOccurrencesColumn = numOccurrencesOf(getColumn(icolumn, arr, nRows, nColumns), nRows, x);
	printf("\n-----EXERCISE 16-----\n");
	for (icolumn = 1; icolumn < nColumns; icolumn++) {
		int *column = getColumn(icolumn, arr, nRows, nColumns);
		int occurrences = numOccurrencesOf(column, nRows, x);
		if (maxOccurrencesColumn < occurrences) {
			xColumn = icolumn;
			maxOccurrencesColumn = occurrences;
		}
	}
	if (!maxOccurrencesColumn) {
		printf("-> Cannot found x=[%d] in any column !\n", x);
		return 0;
	}
	printf("-> On column[%d] contains the most %d times x=[%d]\n", xColumn, maxOccurrencesColumn, x);
	return maxOccurrencesColumn;
}

void ex17(int **arr, int nRows, int nColumns) {
	printf("\n-----EXERCISE 17-----\n");
	printf(" -> Horizontal Zig-zag increment ? [%s]\n", horizontalZigzagIncrement(arr, nRows, nColumns) ? "True" : "False");
	printf(" -> Vertical Zig-zag increment ? [%s]\n", verticalZigzagIncrement(arr, nRows, nColumns) ? "True" : "False");
}

int ex18(int **arr, int nSize) {
	printf("\n-----EXERCISE 18-----\n");
	if (isPalindrome(majorDiagonal(arr, nSize), nSize)) {
		printf("-> Major diagonal is palindrome !\n");
		return 1;
	}
	printf("-> Major diagonal is NOT palindrome !\n");
	return 0;
}

int ex19(int **arr, int nSize) {
	printf("\n-----EXERCISE 19-----\n");
	if (isPalindrome(minorDiagonal(arr, nSize), nSize)) {
		printf("-> Minor diagonal is palindrome !\n");
		return 1;
	}
	printf("-> Minor diagonal is NOT palindrome !\n");
	return 0;
}

int ex20(int **arr, int nRows, int nColumns, int x) {
	int i, j;
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			if (arr[i][j] == x) {
				printf("-> Found x=[%d] in the array !\n", x);
				return 1; // TRUE
			}
		}
	}
	printf("-> Cannot found x=[%d] in the array !\n", x);
	return 0; // FALSE
}

int ex21(int **arr, int nRows, int nColumns) {
	int irow, isRowAllEven = 0, found = 0;
	printf("\n-----EXERCISE 21-----\n");
	for (irow = 0; irow < nRows; irow++) {
		int *row = getRow(irow, arr, nRows, nColumns);
		isRowAllEven = isAllEven(row, nColumns);
		if (isRowAllEven) {
			printf("-> On row[%d] all values are even !\n", irow);
			found = 1; // Found at least 1 row !
		}
	}
	if (!found) {
		printf("-> Cannot found all-even row in the array !\n");
	}
	return found; // FALSE if isRowALlEven keeps the initialized value == 0 !
}

int ex22(int **arr, int nRows, int nColumns) {
	int icolumn, isAscendingColumn = 0, found = 0;
	printf("\n-----EXERCISE 22-----\n");
	for (icolumn = 0; icolumn < nColumns; icolumn++) {
		int *column = getColumn(icolumn, arr, nRows, nColumns);
		isAscendingColumn = isAscendingSorted(column, nRows);
		if (isAscendingColumn) {
			printf("-> On column[%d] all values are in Ascending Order !\n", icolumn);
			found = 1; // Found at least 1 column !
		}
	}
	if (!found) {
		printf("-> Cannot found any column in Ascending Order !\n");
	}
	return found; // FALSE if isAscendingColumn keeps the initialized value == 0 !
}

int ex23(int **arr, int n) {
	int ascendingSorted = 0;
	printf("\n-----EXERCISE 23-----\n");
	ascendingSorted = isAscendingSorted(majorDiagonal(arr, n), n);
	if (ascendingSorted) {
		printf("-> The major diagonal have been sorted in Ascending Order already !\n");
	} else {
		printf("-> The major diagonal have not been sorted in Ascending Order yet !\n");
	}
	return ascendingSorted; // FALSE if ascendingSorted keeps the initialized value == 0 !
}

int* ex24(int **arr, int nRows, int nColumns) {
	int *array1D = getIntArg(nRows * nColumns + 1); // Return this 1D array !
	int i, j, k = 0, value, maxVal = maxArray2D(arr, nRows, nColumns);
	int *occurrences = getIntArg(maxVal + 1);	/* Create an array stored number occurences of 127 ASCII values !
													Initializing storing array with all value == 0 == FALSE */
	printf("\n-----EXERCISE 24-----\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			occurrences[arr[i][j]] += 1;
		}
	}
	printf("-> All distinct elements in the matrix are:\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			value = arr[i][j];
			if (occurrences[value] == 1) { // The occurences of $<value> must be equal to 1 !
				array1D[k++] = value;
				printf("[%d]\t", value);
			}
		}
		printf("\n");
	}
	return array1D;
}

int** ex25(int **arr, int nRows, int nColumns) {
	int i, j, **array2D = getIntArgv(nRows, nColumns); // Return this 2D array !
	printf("\n-----EXERCISE 25-----\n");
	printf("-> All modified elements in the matrix are:\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			int *row = getRow(i, arr, nRows, nColumns);
			int *column = getColumn(j, arr, nRows, nColumns);
			array2D[i][j] = maxArray1D(row, nColumns) + maxArray1D(column, nRows);
			printf("[%d]\t", array2D[i][j]);
		}
		printf("\n");
	}
	return array2D;
}

int ex26(int **arr, int nRows, int nColumns) {
	int i, j, numMaxElems = 0, center, up, down, left, right;
	printf("\n-----EXERCISE 26-----\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			center = arr[i][j];
			up = i - 1 >= 0 ? arr[i - 1][j] : NULL;
			down = i + 1 < nRows ? arr[i + 1][j] : NULL;
			left = j - 1 >= 0 ? arr[i][j - 1] : NULL;
			right = j + 1 < nColumns ? arr[i][j + 1] : NULL;
			if (up && center < up) {
				continue;
			}
			if (down && center < down) {
				continue;
			}
			if (left && center < left) {
				continue;
			}
			if (right && center < right) {
				continue;
			}
			numMaxElems++;
		}
	}
	printf("-> Number of maximum-compared-to-neighbours elements is: [%d]\n", numMaxElems);
	return numMaxElems;
}

void ex27(int **arr, int nRows, int nColumns) {
	int i, j, numPositiveNeighbours = 0, up, down, left, right;
	printf("\n-----EXERCISE 27-----\n");
	printf("-> All positions have having more than 2 positive neighbours are:\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			up = i - 1 >= 0 ? arr[i - 1][j] : NULL;
			down = i + 1 < nRows ? arr[i + 1][j] : NULL;
			left = j - 1 >= 0 ? arr[i][j - 1] : NULL;
			right = j + 1 < nColumns ? arr[i][j + 1] : NULL;
			if (up && up > 0) {
				numPositiveNeighbours += 1;
			}
			if (down && down > 0) {
				numPositiveNeighbours += 1;
			}
			if (left && left > 0) {
				numPositiveNeighbours += 1;
			}
			if (right && right > 0) {
				numPositiveNeighbours += 1;
			}
			if (numPositiveNeighbours > 2) {
				printf("[%d, %d] ", i, j);
			}
			numPositiveNeighbours = 0; // Reset the counter !
		}
		printf("\n");
	}
}

void ex28(int **arr, int nRows, int nColumns) {
	int i, j, numMaxElems = 0, center, up, down, left, right;
	printf("\n-----EXERCISE 28-----\n");
	printf("-> All maximum-compared-to-neighbours elements in the matrix are:\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			center = arr[i][j];
			up = i - 1 >= 0 ? arr[i - 1][j] : NULL;
			down = i + 1 < nRows ? arr[i + 1][j] : NULL;
			left = j - 1 >= 0 ? arr[i][j - 1] : NULL;
			right = j + 1 < nColumns ? arr[i][j + 1] : NULL;
			if (up && center < up) {
				continue;
			}
			if (down && center < down) {
				continue;
			}
			if (left && center < left) {
				continue;
			}
			if (right && center < right) {
				continue;
			}
			printf("[%d]", center, numMaxElems++);
		}
		printf("\n");
	}
	printf("-> Number of maximum-compared-to-neighbours elements is: [%d]\n", numMaxElems);
	return numMaxElems;
}

void ex29(int **arr, int nRows, int nColumns) {
	int i, j, numMinElems = 0, center, up, down, left, right;
	printf("\n-----EXERCISE 29-----\n");
	printf("-> All minimum-compared-to-neighbours elements in the matrix are:\n");
	for (i = 0; i < nRows; i++) {
		for (j = 0; j < nColumns; j++) {
			center = arr[i][j];
			up = i - 1 >= 0 ? arr[i - 1][j] : NULL;
			down = i + 1 < nRows ? arr[i + 1][j] : NULL;
			left = j - 1 >= 0 ? arr[i][j - 1] : NULL;
			right = j + 1 < nColumns ? arr[i][j + 1] : NULL;
			if (up && center > up) {
				continue;
			}
			if (down && center > down) {
				continue;
			}
			if (left && center > left) {
				continue;
			}
			if (right && center > right) {
				continue;
			}
			printf("[%d]", center, numMinElems++);
		}
		printf("\n");
	}
	printf("-> Number of minimum-compared-to-neighbours elements is: [%d]\n", numMinElems);
	return numMinElems;
}

int* ex30(int nElems) {
	printf("\n-----EXERCISE 30-----\n");
	printf("-> Input <%d> elements respectively to the array:\n", nElems);
	return inputRecursiveArray1D(getIntArg(nElems), 0, nElems);
}

int ex31(int *arr, int nElems) {
	printf("\n-----EXERCISE 31-----\n");
	int sum = sumRecursiveArray1D(arr, arr + nElems);
	printf("-> Total sum of <%d> elements from the array = [%d]\n", nElems, sum);
	return sum;
}

void ex32(int *arr, int nElems) {
	printf("\n-----EXERCISE 32-----\n");
	print(arr, nElems);
	printf("-> Sum of positive elements from the array = [%d]\n", sumRecursiveOptionalArray1D(arr, arr + nElems, "positive"));
	printf("-> Sum of negative elements from the array = [%d]\n", sumRecursiveOptionalArray1D(arr, arr + nElems, "negative"));
	printf("-> Sum of odd elements from the array = [%d]\n", sumRecursiveOptionalArray1D(arr, arr + nElems, "odd"));
	printf("-> Sum of even elements from the array = [%d]\n", sumRecursiveOptionalArray1D(arr, arr + nElems, "even"));
	printf("-> Sum of prime elements from the array = [%d]\n", sumRecursiveOptionalArray1D(arr, arr + nElems, "prime"));
	printf("-> Sum of square elements from the array = [%d]\n", sumRecursiveOptionalArray1D(arr, arr + nElems, "square"));
}

void ex33(int *arr, int nElems) {
	printf("\n-----EXERCISE 33-----\n");
	printf("-> Recursively MAX element of the array = [%d]\n", maxRecursiveArray1D(arr, arr + nElems));
	printf("-> Recursively min element of the array = [%d]\n", minRecursiveArray1D(arr, arr + nElems));
}

void ex34(int *arr, int nElems) {
	printf("\n-----EXERCISE 34-----\n");
	int maxNegative = maxNegativeRecursively(arr, arr + nElems - 1, minArray1D(arr, nElems));
	int minPositive = minPositiveRecursively(arr, arr + nElems - 1, maxArray1D(arr, nElems));
	if (maxNegative < 0) {
		printf("-> Max negative of 1-dimensional array is <%d>\n", maxNegative);
	} else {
		printf("-> There's no max negative values in the array !\n");
	}
	if (minPositive > 0) {
		printf("-> Min positive of 1-dimensional array is <%d>\n", minPositive);
	} else {
		printf("-> There's no min positive values in the array !\n");
	}
}

int ex35(int *arr, int nElems, int x) {
	printf("\n-----EXERCISE 35-----\n");
	int occurrences = numRecursiveOccurrencesOf(arr, arr + nElems, x);
	printf("-> The recursive occurrences of x = <%d> is: <%d> times\n", x, occurrences);
	return occurrences;
}

void ex36(int *arr, int nElems) {
	printf("\n-----EXERCISE 36-----\n");
	if (isAscendingRecursively(arr, arr + nElems - 1)) {
		printf("-> The 1-dimensional array is recursively Ascending !\n");
	} else {
		printf("-> The 1-dimensional array is NOT recursively Ascending !\n");
	}
	if (isDescendingRecursively(arr, arr + nElems - 1)) {
		printf("-> The 1-dimensional array is recursively Descending !\n");
	} else {
		printf("-> The 1-dimensional array is NOT recursively Descending !\n");
	}
}

void ex37(int *arr, int nElems) {
	printf("\n-----EXERCISE 37-----\n");
	if (isNegativeElementRecursively(arr, arr + nElems)) {
		printf("-> There's at least 1 negative element recursively !\n");
	} else {
		printf("-> There's no negative element recursively !\n");
	}
}

void ex38(int *arr, int nElems) {
	printf("\n-----EXERCISE 38-----\n");
	if (isPalindromeRecursively(arr, arr + nElems - 1)) {
		printf("-> This array is palindrome recursively !\n");
	} else {
		printf("-> This array is NOT palindrome recursively !\n");
	}
}

void ex39(int *arr, int nElems) {
	printf("\n-----EXERCISE 39-----\n");
	int *newArr = cloneArray1D(arr, nElems);
	printf("-> Sorting in ascending order recursively !\n");
	ascendingRecursiveSort(newArr, nElems);
	print(newArr, nElems);
	printf("-> Sorting in descending order recursively !\n");
	descendingRecursiveSort(newArr, nElems);
	print(newArr, nElems);
}

int* ex40(int *arr, int nElems) {
	int i, *reversed = getIntArg(nElems);
	printf("\n-----EXERCISE 40-----\n");
	printf("-> Reversing the array !\n");
	reversed = reverseArrayRecursively(reversed, arr, 0, nElems);
	print(reversed, nElems);
	return reversed;
}

int main() {
	int nRows = 5, nColumns = 5; // Assuming all the matrix handling is square matrix !
	int **randomMatrix2D = ex01(nRows, nColumns, 1, 100);
	int **increaseMatrix2D = ex02(nRows, nColumns, 1, 100);
	ex03(randomMatrix2D, nRows, nColumns);
	ex04(randomMatrix2D, nRows, nColumns); // Fix bugs if value < 0 !
	ex05(randomMatrix2D, nRows);
	ex06(randomMatrix2D, nRows, nColumns);
	ex07(randomMatrix2D, nRows, nColumns, 92);
	ex08(randomMatrix2D, nRows, nColumns); // Fix bugs if value < 0 !
	ex09(randomMatrix2D, nRows, nColumns);
	ex10(randomMatrix2D, nRows, nColumns);
	ex11(randomMatrix2D, nRows, nColumns);
	ex12(randomMatrix2D, nRows, nColumns);
	ex13(randomMatrix2D, nRows, nColumns);
	ex14(randomMatrix2D, nRows, nColumns); // Fix bugs if value < 0 !
	ex15(randomMatrix2D, nRows, nColumns);
	ex16(randomMatrix2D, nRows, nColumns, 92);
	ex17(randomMatrix2D, nRows, nColumns);
	ex18(randomMatrix2D, nRows);
	ex19(randomMatrix2D, nRows);
	ex20(randomMatrix2D, nRows, nColumns, 92);
	ex21(randomMatrix2D, nRows, nColumns);
	ex22(randomMatrix2D, nRows, nColumns);
	ex23(randomMatrix2D, nRows);
	ex24(randomMatrix2D, nRows, nColumns); // Fix bugs if value < 0 !
	ex25(randomMatrix2D, nRows, nColumns);
	ex26(randomMatrix2D, nRows, nColumns);
	ex27(randomMatrix2D, nRows, nColumns);
	ex28(randomMatrix2D, nRows, nColumns);
	ex29(randomMatrix2D, nRows, nColumns);
	/* RECURSION ON 1 DIMENSIONAL ARRAY*/
	int numOfElements = 5;
	int *array1D = ex30(numOfElements);
	ex31(array1D, numOfElements);
	ex32(array1D, numOfElements);
	ex33(array1D, numOfElements);
	ex34(array1D, numOfElements);
	ex35(array1D, numOfElements, 1);
	ex36(array1D, numOfElements);
	ex37(array1D, numOfElements);
	ex38(array1D, numOfElements);
	ex39(array1D, numOfElements);
	ex40(array1D, numOfElements);
}


int main() {
	int number, i = 0, j;
	int array[2];
	printf("Enter numbers! Input character to exit\n");
	while ( scanf("%d", &number) ){
		if (number % 2 == 0) {
			array[i] = number;
			i++;
		} else {
			break;
		}
	}
	printf("The result is: \n");
	for (j = 0; j < i; j++) {
		printf("%d\t", array[j]);
	}
	
}


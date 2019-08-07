#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int x = 20; // Khai báo biên' bình thuong`
	int y = 5; // Khai báo biên' bình thuong`
	int *ip; // Biên' con tro?
	
	ip = &y; // Dia. chi? cua? y duoc. gán vào biên' con tro? @{ip}
	*ip = x; // Dereference @{ip}, ta duoc. ô giá tri. cua? biên' @{y} và thuc. hiên. phép gán @{y} = @{x} (= 20)
	
	printf("Dia. chi? cua? bie^n' con tro? la`: %d\n", &ip);
	printf("Bie^n' con tro? chua' dia. chi? cua? @{y} la`: %d\n", ip);
	printf("Bie^n' con tro? dang tro? toi' gia' tri. @{y} la`: %d\n", *ip);
	
	printf("Gia tri cua x: %d\n", x);
	printf("Gia tri cua y: %d\n", y);
}

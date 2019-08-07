#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int x = 20; // Khai b�o bi�n' b�nh thuong`
	int y = 5; // Khai b�o bi�n' b�nh thuong`
	int *ip; // Bi�n' con tro?
	
	ip = &y; // Dia. chi? cua? y duoc. g�n v�o bi�n' con tro? @{ip}
	*ip = x; // Dereference @{ip}, ta duoc. � gi� tri. cua? bi�n' @{y} v� thuc. hi�n. ph�p g�n @{y} = @{x} (= 20)
	
	printf("Dia. chi? cua? bie^n' con tro? la`: %d\n", &ip);
	printf("Bie^n' con tro? chua' dia. chi? cua? @{y} la`: %d\n", ip);
	printf("Bie^n' con tro? dang tro? toi' gia' tri. @{y} la`: %d\n", *ip);
	
	printf("Gia tri cua x: %d\n", x);
	printf("Gia tri cua y: %d\n", y);
}

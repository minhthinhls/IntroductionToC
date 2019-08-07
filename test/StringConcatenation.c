#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Nôi' @{xâu Moi'} vào @{xâu Cu~} và không tra? vê` gì hêt' */
void noiXauMoiVaoXauCu(char *xauCu, char *xauMoi) {
	while(*xauCu) {
		xauCu++;
	}
	while(*xauMoi) {
		*xauCu = *xauMoi;
		xauMoi++;
		xauCu++;
	}
	*xauCu = '\0';
}

/* Nôi' @{xâu Cu~} voi' môt. @{kí Tu. Moi'} và tra? vê` môt. @{Xâu Moi'} da~ duoc. nôi' xong */
char* noiKiTuVaoXau(const char *xauCu, const char kiTuMoi) {
    char *xauMoi; // Tao. biên' @{Xâu Moi'}
    if (asprintf(&xauMoi, "%s%c", xauCu, kiTuMoi) == -1) {
		xauMoi = NULL; // @{Xâu Moi'} khoi? tao. thât' bai.
	}
    return xauMoi; // Tra? vê` giá tri. @{Xâu Moi'}
}

int main() {
	char *canhCong = ""; // Tao. 1 xâu dê? nôi' kí tu.
	canhCong = noiKiTuVaoXau(canhCong, '1');
	char canhCong2[100] = "";
	noiXauMoiVaoXauCu(canhCong2, "canhCong2");
	printf("%s\n", canhCong);
	printf("%s\n", canhCong2);
}


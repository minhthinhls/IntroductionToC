#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* N�i' @{x�u Moi'} v�o @{x�u Cu~} v� kh�ng tra? v�` g� h�t' */
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

/* N�i' @{x�u Cu~} voi' m�t. @{k� Tu. Moi'} v� tra? v�` m�t. @{X�u Moi'} da~ duoc. n�i' xong */
char* noiKiTuVaoXau(const char *xauCu, const char kiTuMoi) {
    char *xauMoi; // Tao. bi�n' @{X�u Moi'}
    if (asprintf(&xauMoi, "%s%c", xauCu, kiTuMoi) == -1) {
		xauMoi = NULL; // @{X�u Moi'} khoi? tao. th�t' bai.
	}
    return xauMoi; // Tra? v�` gi� tri. @{X�u Moi'}
}

int main() {
	char *canhCong = ""; // Tao. 1 x�u d�? n�i' k� tu.
	canhCong = noiKiTuVaoXau(canhCong, '1');
	char canhCong2[100] = "";
	noiXauMoiVaoXauCu(canhCong2, "canhCong2");
	printf("%s\n", canhCong);
	printf("%s\n", canhCong2);
}


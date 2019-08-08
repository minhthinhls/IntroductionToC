#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doCsangdoF (float c) {
	printf("(1) %f do C = %f do F\n", c, c * 1.8 + 32);
}

void tienDienLuyTien(float KW) {
	if (KW < 0) {
		printf("(2) So KW phai la so duong! KW > 0\n");
		return; // N�u' KW < 0 th� tho�t khoi? h�m tienDienLuyTien(float).
	}
	float tongTienDien = 0;
	float kw = KW;
	if (KW > 400) {
		tongTienDien += (KW - 400) * 2600;
		KW = 400;
	}
	if (KW > 300) {
		tongTienDien += (KW - 300) * 2500;
		KW = 300;
	}
	if (KW > 200) {
		tongTienDien += (KW - 200) * 2200;
		KW = 200;
	}
	if (KW > 100) {
		tongTienDien += (KW - 100) * 1800;
		KW = 100;
	}
	if (KW > 50) {
		tongTienDien += (KW - 50) * 1500;
		KW = 50;
	}
	if (KW <= 50) {
		tongTienDien += KW * 1400;
		KW = 0;
	}
	printf("(2) Tong tien dien luy tien khi su dung %f KW la: %f VND\n", kw, tongTienDien);
}

void trungBinhDieuHoa(int n, float arr[]) {
	int i, j;
	float mauSo = 0; // M�u~ s�' cua? bi�u? thuc'
	for (i = 0; i < n; i++) {
		if (arr[i] == 0) {
			printf("Cac gia tri nhap vao phai khac 0 !\n");
			return;
		}
		mauSo += 1 / arr[i];
	}
	printf("(3) Trung binh dieu hoa cua %d so thuc ben tren la: %f\n", n, n / mauSo); // N l� tu? s�'.
}

char* inCanhCong(int n) { // In ra m�n h�nh c�nh c�ng? voi' chi�u` cao cua? c�ng? l� @{n}
	int i, j;
	char canhCong[1000000] = ""; // Tao. 1 x�u d�? n�i' k� tu.
	if (n <= 0) {
		printf("(4) Chieu cao N cua canh cong phai la so duong ! N > 0 !\n");
		return canhCong;
	}
	printf("(4) Canh cong voi chieu cao N = %d la:\n", n);
	/* V�ng lap. ngo�i d�? in s�' d�ng */
	for (i = 1; i <= n; i++) {
		/* V�ng lap. trong d�? in s�' c�t. */
		for (j = 1; j <= 2 * n; j++) {
			int gapSize = 2 * i - 2; // D�. r�ng. cua? c�ng? tai. m�i~ h�ng
			int rearSize = (2 * n - gapSize) / 2; // D�. d�y cua? r�a c�ng? 2 b�n h�ng
			if (rearSize < j && j <= 2 * n - rearSize) {
				printf(" ");
				strcat(canhCong, " "); /* N�i' x�u " " v�o x�u @{canhCong} v� kh�ng tra? v�` g� h�t' */
			} else {
				printf("*");
				strcat(canhCong, "*"); /* N�i' x�u "*" v�o x�u @{canhCong} v� kh�ng tra? v�` g� h�t' */
			}
		}
		printf("\n");
		strcat(canhCong, "\n"); /* N�i' x�u "\n" (xu�ng' d�ng) v�o x�u @{canhCong} v� kh�ng tra? v�` g� h�t' */
	}
	return canhCong; // Tra? v�` x�u c�nh c�ng? d�? luu k�t' qua? v�o file text
}

/* Vi�t' x�u c� h�nh dang. l� c�ng? v�o �? dia~ D */
void luuKetQuaCanhCong(char* cong) { // Tham s�' l� 1 X�u (String) t�n l� @cong.
	FILE *fp; // Tao. bi�n' @fp c� ki�u? du~ li�u. l� FILE d�? thuc. hi�n. ghi x�u.
	
	fp = fopen("D://cong.txt", "w++"); // Mo? ch�' d�. writer d�? ghi x�u v�o �? dia~ D:
	if (fp) {
		fputs(cong, fp); // Thuc. hi�n. ghi x�u v�o duong` d�n~ nam` trong bi�n' @fp
	} else {
		printf("Tao duong` d�n~ th�t' bai.\n"); // L�i~ kh�ng th�? mo? duong` d�n~ v�o �? D:
	}
}

int main() {
	int chucNang;
	int soPhanTu = 0; // S�' ph�n` tu? b�n trong mang? (C�u 3)
	float giaTriThucHien; // Gi� tri. c�n` thuc. hi�n. trong c�c y�u c�u`
	char* dummy; // Bi�n' thu gom r�c b�. nho' d�m.
	while(1) {
		printf("\n*Cac chuc nang ban co the nhap: {1, 2, 3, 4} !\n");
		printf("*Nhap {0} de thoat khoi chuong trinh !\n");
		printf("=> Hay nhap chuc nang: ");
		if(scanf("%d", &chucNang) < 1) { // Chuc' nang nh�p. v�o phai? l� 1 s�' nguy�n (int); N�u' ko se~ phai? l�m sach. b�. nho' d�m. 
			scanf("%s", &dummy); // Thu gom r�c b�. nho' d�m.
			fflush(stdin); // L�m sach. b�. nho' d�m.
			rewind(stdin); // L�m sach. b�. nho' d�m.
			continue; // Thuc. hi�n. v�ng while() loop kh�c d�? nh�p. lai. chuc' nang
		}
		
		if (chucNang == 0) {
			return;
		} else if (chucNang == 1) {
			printf("Nhap C: ");
			if(scanf("%f", &giaTriThucHien) < 1) { // Gi� tri. nh�p. v�o phai? l� 1 s�' thuc. (float); N�u' ko se~ phai? l�m sach. b�. nho' d�m.
				scanf("%s", &dummy); // Thu gom r�c b�. nho' d�m.
				fflush(stdin); // L�m sach. b�. nho' d�m.
				rewind(stdin); // L�m sach. b�. nho' d�m.
			} else {
				doCsangdoF(giaTriThucHien);
			}
		} else if (chucNang == 2) {
			printf("Nhap KW: ");
			if(scanf("%f", &giaTriThucHien) < 1) { // Gi� tri. nh�p. v�o phai? l� 1 s�' thuc. (float); N�u' ko se~ phai? l�m sach. b�. nho' d�m.
				scanf("%s", &dummy); // Thu gom r�c b�. nho' d�m.
				fflush(stdin); // L�m sach. b�. nho' d�m.
				rewind(stdin); // L�m sach. b�. nho' d�m.
			} else {
				tienDienLuyTien(giaTriThucHien);
			}
		} else if (chucNang == 3) {
			printf("Nhap so phan tu N: ");
			if(scanf("%d", &soPhanTu) < 1) { // Gi� tri. nh�p. v�o phai? l� 1 s�' nguy�n (int); N�u' ko se~ phai? l�m sach. b�. nho' d�m.
				scanf("%s", &dummy); // Thu gom r�c b�. nho' d�m.
				fflush(stdin); // L�m sach. b�. nho' d�m.
				rewind(stdin); // L�m sach. b�. nho' d�m.
			} else {
				int i;
				float arr[soPhanTu]; // Tao. 1 mang? voi' s�' ph�n` tu? nh�p. v�o b�n tr�n
				for (i = 0; i < soPhanTu; i++) {
					printf("A[%d] = ", i);
					if(scanf("%f", &arr[i]) < 1) { // Gi� tri. nh�p. v�o phai? l� 1 s�' thuc. (float); N�u' ko se~ phai? l�m sach. b�. nho' d�m.
						scanf("%s", &dummy); // Thu gom r�c b�. nho' d�m.
						fflush(stdin); // L�m sach. b�. nho' d�m.
						rewind(stdin); // L�m sach. b�. nho' d�m.
						arr[i] = 0; // Gi� tri. nh�p. sai th� xem nhu gi� tri. n�y = 0
						break; // Thuc. hi�n. v�ng while() loop kh�c d�? nh�p. lai. chuc' nang
					}
				}
				trungBinhDieuHoa(soPhanTu, arr);
			}
		} else if (chucNang == 4) {
			printf("Nhap N: ");
			if(scanf("%f", &giaTriThucHien) < 1) { // Gi� tri. nh�p. v�o phai? l� 1 s�' thuc. (float); N�u' ko se~ phai? l�m sach. b�. nho' d�m.
				scanf("%s", &dummy); // Thu gom r�c b�. nho' d�m.
				fflush(stdin); // L�m sach. b�. nho' d�m.
				rewind(stdin); // L�m sach. b�. nho' d�m.
			} else {
				luuKetQuaCanhCong(inCanhCong(giaTriThucHien));
			}
		} else {
			// Do nothing !
		}
		fflush(stdin); // L�m sach. b�. nho' d�m.
		rewind(stdin); // L�m sach. b�. nho' d�m.
	}
}


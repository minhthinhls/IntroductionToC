#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doCsangdoF (float c) {
	printf("(1) %f do C = %f do F\n", c, c * 1.8 + 32);
}

void tienDienLuyTien(float KW) {
	if (KW < 0) {
		printf("(2) So KW phai la so duong! KW > 0\n");
		return; // Nêu' KW < 0 thì thoát khoi? hàm tienDienLuyTien(float).
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
	float mauSo = 0; // Mâu~ sô' cua? biêu? thuc'
	for (i = 0; i < n; i++) {
		if (arr[i] == 0) {
			printf("Cac gia tri nhap vao phai khac 0 !\n");
			return;
		}
		mauSo += 1 / arr[i];
	}
	printf("(3) Trung binh dieu hoa cua %d so thuc ben tren la: %f\n", n, n / mauSo); // N là tu? sô'.
}

char* inCanhCong(int n) { // In ra màn hình cánh công? voi' chiêu` cao cua? công? là @{n}
	int i, j;
	char canhCong[1000000] = ""; // Tao. 1 xâu dê? nôi' kí tu.
	if (n <= 0) {
		printf("(4) Chieu cao N cua canh cong phai la so duong ! N > 0 !\n");
		return canhCong;
	}
	printf("(4) Canh cong voi chieu cao N = %d la:\n", n);
	/* Vòng lap. ngoài dê? in sô' dòng */
	for (i = 1; i <= n; i++) {
		/* Vòng lap. trong dê? in sô' côt. */
		for (j = 1; j <= 2 * n; j++) {
			int gapSize = 2 * i - 2; // Dô. rông. cua? công? tai. môi~ hàng
			int rearSize = (2 * n - gapSize) / 2; // Dô. dày cua? rìa công? 2 bên hông
			if (rearSize < j && j <= 2 * n - rearSize) {
				printf(" ");
				strcat(canhCong, " "); /* Nôi' xâu " " vào xâu @{canhCong} và không tra? vê` gì hêt' */
			} else {
				printf("*");
				strcat(canhCong, "*"); /* Nôi' xâu "*" vào xâu @{canhCong} và không tra? vê` gì hêt' */
			}
		}
		printf("\n");
		strcat(canhCong, "\n"); /* Nôi' xâu "\n" (xuông' dòng) vào xâu @{canhCong} và không tra? vê` gì hêt' */
	}
	return canhCong; // Tra? vê` xâu cánh công? dê? luu kêt' qua? vào file text
}

/* Viêt' xâu có hình dang. là công? vào ô? dia~ D */
void luuKetQuaCanhCong(char* cong) { // Tham sô' là 1 Xâu (String) tên là @cong.
	FILE *fp; // Tao. biên' @fp có kiêu? du~ liêu. là FILE dê? thuc. hiên. ghi xâu.
	
	fp = fopen("D://cong.txt", "w++"); // Mo? chê' dô. writer dê? ghi xâu vào ô? dia~ D:
	if (fp) {
		fputs(cong, fp); // Thuc. hiên. ghi xâu vào duong` dân~ nam` trong biên' @fp
	} else {
		printf("Tao duong` dân~ thât' bai.\n"); // Lôi~ không thê? mo? duong` dân~ vào ô? D:
	}
}

int main() {
	int chucNang;
	int soPhanTu = 0; // Sô' phân` tu? bên trong mang? (Câu 3)
	float giaTriThucHien; // Giá tri. cân` thuc. hiên. trong các yêu câu`
	char* dummy; // Biên' thu gom rác bô. nho' dêm.
	while(1) {
		printf("\n*Cac chuc nang ban co the nhap: {1, 2, 3, 4} !\n");
		printf("*Nhap {0} de thoat khoi chuong trinh !\n");
		printf("=> Hay nhap chuc nang: ");
		if(scanf("%d", &chucNang) < 1) { // Chuc' nang nhâp. vào phai? là 1 sô' nguyên (int); Nêu' ko se~ phai? làm sach. bô. nho' dêm. 
			scanf("%s", &dummy); // Thu gom rác bô. nho' dêm.
			fflush(stdin); // Làm sach. bô. nho' dêm.
			rewind(stdin); // Làm sach. bô. nho' dêm.
			continue; // Thuc. hiên. vòng while() loop khác dê? nhâp. lai. chuc' nang
		}
		
		if (chucNang == 0) {
			return;
		} else if (chucNang == 1) {
			printf("Nhap C: ");
			if(scanf("%f", &giaTriThucHien) < 1) { // Giá tri. nhâp. vào phai? là 1 sô' thuc. (float); Nêu' ko se~ phai? làm sach. bô. nho' dêm.
				scanf("%s", &dummy); // Thu gom rác bô. nho' dêm.
				fflush(stdin); // Làm sach. bô. nho' dêm.
				rewind(stdin); // Làm sach. bô. nho' dêm.
			} else {
				doCsangdoF(giaTriThucHien);
			}
		} else if (chucNang == 2) {
			printf("Nhap KW: ");
			if(scanf("%f", &giaTriThucHien) < 1) { // Giá tri. nhâp. vào phai? là 1 sô' thuc. (float); Nêu' ko se~ phai? làm sach. bô. nho' dêm.
				scanf("%s", &dummy); // Thu gom rác bô. nho' dêm.
				fflush(stdin); // Làm sach. bô. nho' dêm.
				rewind(stdin); // Làm sach. bô. nho' dêm.
			} else {
				tienDienLuyTien(giaTriThucHien);
			}
		} else if (chucNang == 3) {
			printf("Nhap so phan tu N: ");
			if(scanf("%d", &soPhanTu) < 1) { // Giá tri. nhâp. vào phai? là 1 sô' nguyên (int); Nêu' ko se~ phai? làm sach. bô. nho' dêm.
				scanf("%s", &dummy); // Thu gom rác bô. nho' dêm.
				fflush(stdin); // Làm sach. bô. nho' dêm.
				rewind(stdin); // Làm sach. bô. nho' dêm.
			} else {
				int i;
				float arr[soPhanTu]; // Tao. 1 mang? voi' sô' phân` tu? nhâp. vào bên trên
				for (i = 0; i < soPhanTu; i++) {
					printf("A[%d] = ", i);
					if(scanf("%f", &arr[i]) < 1) { // Giá tri. nhâp. vào phai? là 1 sô' thuc. (float); Nêu' ko se~ phai? làm sach. bô. nho' dêm.
						scanf("%s", &dummy); // Thu gom rác bô. nho' dêm.
						fflush(stdin); // Làm sach. bô. nho' dêm.
						rewind(stdin); // Làm sach. bô. nho' dêm.
						arr[i] = 0; // Giá tri. nhâp. sai thì xem nhu giá tri. này = 0
						break; // Thuc. hiên. vòng while() loop khác dê? nhâp. lai. chuc' nang
					}
				}
				trungBinhDieuHoa(soPhanTu, arr);
			}
		} else if (chucNang == 4) {
			printf("Nhap N: ");
			if(scanf("%f", &giaTriThucHien) < 1) { // Giá tri. nhâp. vào phai? là 1 sô' thuc. (float); Nêu' ko se~ phai? làm sach. bô. nho' dêm.
				scanf("%s", &dummy); // Thu gom rác bô. nho' dêm.
				fflush(stdin); // Làm sach. bô. nho' dêm.
				rewind(stdin); // Làm sach. bô. nho' dêm.
			} else {
				luuKetQuaCanhCong(inCanhCong(giaTriThucHien));
			}
		} else {
			// Do nothing !
		}
		fflush(stdin); // Làm sach. bô. nho' dêm.
		rewind(stdin); // Làm sach. bô. nho' dêm.
	}
}


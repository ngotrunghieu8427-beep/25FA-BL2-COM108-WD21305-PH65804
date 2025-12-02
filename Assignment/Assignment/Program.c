#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h> 

void chucNang1(); // Kiểm tra số nguyên
void chucNang2(); // UCLN va BCNN
void chucNang3(); // Tinh tien Karaoke
void chucNang4(); // Tinh tien dien
void chucNang5(); // Doi tien
void chucNang6(); // Lai suat ngan hang
void chucNang7(); // Vay tien mua xe
void chucNang8(); // Sap xep sinh vien
void chucNang9(); // Game FPOLY-LOTT
void chucNang10(); // Tinh toan phan so

void lapChucNang(int chonChucNang)
{
	int tiepTuc = 1;
	while (tiepTuc == 1)
	{
		switch (chonChucNang)
		{
		case 1: chucNang1(); break;
		case 2: chucNang2(); break;
		case 3: chucNang3(); break;
		case 4: chucNang4(); break;
		case 5: chucNang5(); break;
		case 6: chucNang6(); break;
		case 7: chucNang7(); break;
		case 8: chucNang8(); break;
		case 9: chucNang9(); break;
		case 10: chucNang10(); break;
		case 0: printf("Thoat chuong trinh!\n"); break;
		default:
			printf("Chon sai. Chuc nang hop le [0-10]\n");
			break;
		}

		if (chonChucNang != 0) {
			printf("\nTiep tuc thuc hien chuc nang nay? [1=Co | 0=Khong]: ");
			scanf("%d", &tiepTuc);
			system("cls"); 
		}
		else {
			tiepTuc = 0; 
		}
	}
}

int main()
{
	int chonChucNang;
	do
	{
		printf("\n|--- MENU ASSIGNMENT ---|\n");
		printf(" 1. Kiem tra so nguyen                           \n");
		printf(" 2. Tim UCLN va BCNN                             \n");
		printf(" 3. Tinh tien Karaoke                            \n");
		printf(" 4. Tinh tien dien                               \n");
		printf(" 5. Doi tien                                     \n");
		printf(" 6. Tinh lai suat vay ngan hang                  \n");
		printf(" 7. Vay tien mua xe                              \n");
		printf(" 8. Sap xep thong tin sinh vien                  \n");
		printf(" 9. Game FPOLY-LOTT (2/15)                       \n");
		printf(" 10. Tinh toan phan so                           \n");
		printf(" 0. Thoat                                        \n");
		printf("Hay chon chuc nang [0-10]: ");
		scanf("%d", &chonChucNang);

		lapChucNang(chonChucNang);

	} while (chonChucNang != 0);

	return 0;
}

void chucNang1() {
	float x;
	printf("--- 1. KIEM TRA SO NGUYEN ---\n");
	printf("Nhap so x: ");
	scanf("%f", &x);

	if (x == (int)x) {
		printf("%.0f la so nguyen\n", x);
		int n = (int)x;

		// Kiem tra so nguyen to
		int laNguyenTo = 1;
		if (n < 2) laNguyenTo = 0;
		for (int i = 2; i <= sqrt((float)n); i++) {
			if (n % i == 0) {
				laNguyenTo = 0;
				break;
			}
		}
		if (laNguyenTo) printf("%d la so nguyen to\n", n);
		else printf("%d khong phai so nguyen to\n", n);

		// Kiem tra so chinh phuong
		int can = (int)sqrt((float)n);
		if (can * can == n) printf("%d la so chinh phuong\n", n);
		else printf("%d khong phai so chinh phuong\n", n);
	}
	else {
		printf("%.2f khong phai so nguyen\n", x);
	}
}

void chucNang2() {
	int a, b;
	printf("--- 2. TIM UCLN VA BCNN ---\n");
	printf("Nhap so a: "); scanf("%d", &a);
	printf("Nhap so b: "); scanf("%d", &b);

	// Tim UCLN
	int x = abs(a);
	int y = abs(b);
	if (x == 0 || y == 0) {
		printf("Khong co UCLN, BCNN\n");
	}
	else {
		while (x != y) {
			if (x > y) x = x - y;
			else y = y - x;
		}
		printf("UCLN: %d\n", x);
		// BCNN = (a * b) / UCLN
		printf("BCNN: %d\n", abs(a * b) / x);
	}
}

void chucNang3() {
	int start, end;
	printf("--- 3. TINH TIEN KARAOKE ---\n");
	printf("Gio bat dau (12-23): "); scanf("%d", &start);
	printf("Gio ket thuc (12-23): "); scanf("%d", &end);

	if (start < 12 || end > 23 || start >= end) {
		printf("Gio khong hop le (Quan mo tu 12h den 23h)\n");
	}
	else {
		int soGio = end - start;
		float tien;
		if (soGio <= 3) {
			tien = soGio * 150000;
		}
		else {
			tien = 3 * 150000 + (soGio - 3) * 150000 * 0.7; // Giam 30% tu gio thu 4
		}

		if (start >= 14 && start < 17) {
			tien = tien * 0.9; // Giam them 10%
			printf("Giam gia 10%% khung gio vang!\n");
		}
		printf("Tong tien: %.0f VND\n", tien);
	}
}

void chucNang4() {
	float kwh, tien;
	printf("--- 4. TINH TIEN DIEN ---\n");
	printf("Nhap so kwh: "); scanf("%f", &kwh);

	if (kwh <= 0) {
		printf("So kwh phai > 0\n");
	}
	else {
		if (kwh <= 50) tien = kwh * 1678;
		else if (kwh <= 100) tien = 50 * 1678 + (kwh - 50) * 1734;
		else if (kwh <= 200) tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
		else if (kwh <= 300) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
		else if (kwh <= 400) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
		else tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;

		printf("Tien dien phai tra: %.0f VND\n", tien);
	}
}

void chucNang5() {
	int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
	int tien;
	printf("--- 5. DOI TIEN ---\n");
	printf("Nhap so tien can doi: "); scanf("%d", &tien);

	for (int i = 0; i < 9; i++) {
		int soTo = tien / menhGia[i];
		if (soTo > 0) {
			printf("%d to %d\n", soTo, menhGia[i]);
			tien = tien % menhGia[i];
		}
	}
}

void chucNang6() {
	double vay;
	printf("--- 6. LAI SUAT NGAN HANG ---\n");
	printf("Nhap so tien vay: "); scanf("%lf", &vay);

	double lai = 0.05;
	double gocTra = vay / 12;

	printf("Ky han \t Lai \t Goc \t Tong \t Con lai\n");
	for (int i = 1; i <= 12; i++) {
		double laiTra = vay * lai;
		double tong = laiTra + gocTra;
		vay -= gocTra;
		if (vay < 0) vay = 0;
		printf("%d \t %.0f \t %.0f \t %.0f \t %.0f\n", i, laiTra, gocTra, tong, vay);
	}
}

void chucNang7() {
	printf("--- 7. VAY MUA XE ---\n");
	double phanTram;
	double giaXe = 500000000;

	printf("Gia xe: 500 trieu. Vay bao nhieu %%: ");
	scanf("%lf", &phanTram);

	double vay = giaXe * (phanTram / 100);
	double traTruoc = giaXe - vay;
	double gocTra = vay / 288; // 24 nam = 288 thang
	double laiSuat = 0.006;    // 7.2% nam = 0.6% thang

	printf("Tra truoc: %.0f\n", traTruoc);
	printf("So tien vay: %.0f\n", vay);
	printf("Ky han \t Lai \t Goc \t Tong \t Con lai\n");

	// In 5 thang dau de xem thu thoi, in het dai lam
	for (int i = 1; i <= 288; i++) {
		double laiTra = vay * laiSuat;
		double tong = laiTra + gocTra;
		vay -= gocTra;
		if (i <= 10) { // Chi in 10 thang dau
			printf("%d \t %.0f \t %.0f \t %.0f \t %.0f\n", i, laiTra, gocTra, tong, vay);
		}
	}
}

void chucNang8() {
	printf("--- 8. SAP XEP SINH VIEN ---\n");
	int n;
	printf("Nhap so luong SV: ");
	scanf("%d", &n);

	char ten[100][50];
	float diem[100];

	// Nhap
	for (int i = 0; i < n; i++) {
		printf("\nSV thu %d:\n", i + 1);
		printf("Ho ten: ");
		while (getchar() != '\n'); // Xoa bo nho dem
		gets(ten[i]);
		printf("Diem: ");
		scanf("%f", &diem[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (diem[j] < diem[j + 1]) {
				// Doi diem
				float tempD = diem[j];
				diem[j] = diem[j + 1];
				diem[j + 1] = tempD;
				// Doi ten 
				char tempT[50];
				strcpy(tempT, ten[j]);
				strcpy(ten[j], ten[j + 1]);
				strcpy(ten[j + 1], tempT);
			}
		}
	}

	// Xuat
	printf("\n%-20s %-10s %-15s\n", "HO TEN", "DIEM", "HOC LUC");
	for (int i = 0; i < n; i++) {
		char hl[20];
		if (diem[i] >= 9) strcpy(hl, "Xuat sac");
		else if (diem[i] >= 8) strcpy(hl, "Gioi");
		else if (diem[i] >= 6.5) strcpy(hl, "Kha");
		else if (diem[i] >= 5) strcpy(hl, "Trung binh");
		else strcpy(hl, "Yeu");

		printf("%-20s %-10.1f %-15s\n", ten[i], diem[i], hl);
	}
}

void chucNang9() {
	printf("--- 9. GAME FPOLY-LOTT ---\n");
	int s1, s2;
	do {
		printf("Nhap so 1 (1-15): "); scanf("%d", &s1);
	} while (s1 < 1 || s1 > 15);
	do {
		printf("Nhap so 2 (1-15): "); scanf("%d", &s2);
	} while (s2 < 1 || s2 > 15);

	// Dung rand() mac dinh
	int kq1 = rand() % 15 + 1;
	int kq2 = rand() % 15 + 1;
	printf("Ket qua: %d - %d\n", kq1, kq2);

	int dem = 0;
	if (s1 == kq1 || s1 == kq2) dem++;
	if (s2 == kq1 || s2 == kq2) dem++;

	if (dem == 2) printf("Chuc mung! Trung giai NHAT!\n");
	else if (dem == 1) printf("Chuc mung! Trung giai NHI!\n");
	else printf("Chuc may man lan sau.\n");
}

void chucNang10() {
	printf("--- 10. TINH TOAN PHAN SO ---\n");
	int t1, m1, t2, m2;
	printf("Nhap tu1 mau1: "); scanf("%d %d", &t1, &m1);
	printf("Nhap tu2 mau2: "); scanf("%d %d", &t2, &m2);

	if (m1 == 0 || m2 == 0) {
		printf("Mau so phai khac 0\n");
	}
	else {
		printf("Tong: %d/%d\n", t1 * m2 + t2 * m1, m1 * m2);
		printf("Hieu: %d/%d\n", t1 * m2 - t2 * m1, m1 * m2);
		printf("Tich: %d/%d\n", t1 * t2, m1 * m2);
		if (t2 != 0) printf("Thuong: %d/%d\n", t1 * m2, m1 * t2);
		else printf("Khong the chia.\n");
	}
}
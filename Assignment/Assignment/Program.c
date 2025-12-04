#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 

void kiemTraSoNguyen() 
{
	float x;
	printf("Nhap so x: ");
	scanf("%f", &x);

	if (x == (int)x)
	{
		printf("%.0f la so nguyen\n", x);
		int n = (int)x;

		// Kiem tra so nguyen to 
		int i;
		int dem = 0;
		for (i = 1; i <= n; i++)
		{
			if (n % i == 0) 
			{
				dem++;
			}
		}
		if (dem == 2)
			printf("%d la so nguyen to\n", n);
		else 
			printf("%d khong phai so nguyen to\n", n);

		// Kiem tra so chinh phuong
		int can = sqrt(n);
		if (can * can == n) 
			printf("%d la so chinh phuong\n", n);
		else printf("%d khong phai so chinh phuong\n", n);
	}
	else 
	{
		printf("Day khong phai so nguyen\n");
	}
}

void timUCLN_BCNN()
{
	int a, b, i;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);

	// Tim UCLN 
	int ucln = 1;
	int min = a;
	if (a > b) min = b;

	for (i = min; i >= 1; i--) 
	{
		if (a % i == 0 && b % i == 0)
		{
			ucln = i;
			break;
		}
	}
	printf("UCLN: %d\n", ucln);
	printf("BCNN: %d\n", (a * b) / ucln);
}

void tinhTienKaraoke()
{
	int batDau, ketThuc;
	printf("Nhap gio bat dau: ");
	scanf("%d", &batDau);
	printf("Nhap gio ket thuc: "); 
	scanf("%d", &ketThuc);

	if (batDau < 12 || ketThuc > 23 || batDau >= ketThuc) 
	{
		printf("Gio khong hop le (quan mo 12h-23h)\n");
	}
	else 
	{
		float tien = 0;
		int soGio = ketThuc - batDau;

		if (soGio <= 3)
		{
			tien = soGio * 150000;
		}
		else
		{
			tien = 3 * 150000 + (soGio - 3) * 150000 * 0.7; // Giam 30% tu gio thu 4
		}

		if (batDau >= 14 && batDau < 17) 
		{
			tien = tien * 0.9; // Giam 10%
		}
		printf("Tong tien: %.0f VND\n", tien);
	}
}

void tinhTienDien() 
{
	float kwh, tien;
	printf("Nhap so kwh: "); 
	scanf("%f", &kwh);

	if (kwh <= 50) tien = kwh * 1678;
	else if (kwh <= 100) tien = 50 * 1678 + (kwh - 50) * 1734;
	else if (kwh <= 200) tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
	else if (kwh <= 300) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
	else if (kwh <= 400) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
	else tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;

	printf("Tien dien: %.0f VND\n", tien);
}

void doiTien() 
{
	int tien;
	printf("Nhap so tien: ");
	scanf("%d", &tien);

	// Mang chua cac menh gia
	int menhGia[9] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
	int i;

	for (i = 0; i < 9; i++) 
	{
		int soTo = tien / menhGia[i];
		if (soTo > 0)
		{
			printf("%d to %d\n", soTo, menhGia[i]);
			tien = tien % menhGia[i];
		}
	}
}

void tinhLaiSuatVay()
{
	double vay;
	printf("Nhap tien vay: ");
	scanf("%lf", &vay);

	double gocTra = vay / 12;
	int i;

	printf("Thang \t Lai \t Goc \t Tong \t Con lai\n");
	for (i = 1; i <= 12; i++)
	{
		double lai = vay * 0.05;
		double tong = lai + gocTra;
		vay = vay - gocTra;
		printf("%d \t %.0f \t %.0f \t %.0f \t %.0f\n", i, lai, gocTra, tong, vay);
	}
}

void vayTienMuaXe()
{
	double phanTram;
	printf("Gia xe 500 trieu. Vay bao nhieu %%: ");
	scanf("%lf", &phanTram);

	double vay = 500000000 * phanTram / 100;
	double traTruoc = 500000000 - vay;
	double gocTra = vay / 288; // 24 nam = 288 thang
	int i;

	printf("Tra truoc: %.0f\n", traTruoc);
	printf("Thang \t Lai \t Goc \t Tong \t Con lai\n");

	for (i = 1; i <= 288; i++) 
	{
		double lai = vay * 0.006;
		double tong = lai + gocTra;
		vay = vay - gocTra;
		if (i <= 5)
		{
			printf("%d \t %.0f \t %.0f \t %.0f \t %.0f\n", i, lai, gocTra, tong, vay);
		}
	}
}

void sapXepSinhVien() 
{
	int n, i, j;
	printf("Nhap so luong SV: "); 
	scanf("%d", &n);
    // Mang chuoi 
	char ten[100][50];
    // Mang so thuc 
	float diem[100];   

	// Nhap du lieu
	for (i = 0; i < n; i++)
	{
		printf("Sinh vien %d - Ten: ", i + 1);

		while (getchar() != '\n');
		fgets(ten[i], sizeof(ten[i]), stdin);

		ten[i][strlen(ten[i]) - 1] = '\0';

		printf("Diem: ");
		scanf("%f", &diem[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++) 
		{
			// Sap xep giam dan
			if (diem[i] < diem[j])
			{
				// Hoan doi diem
				float tamDiem = diem[i];
				diem[i] = diem[j];
				diem[j] = tamDiem;

				// Hoan doi ten 
				char tamTen[50];
				strcpy(tamTen, ten[i]);
				strcpy(ten[i], ten[j]);
				strcpy(ten[j], tamTen);
			}
		}
	}

	// Hien thi
	printf("\nTen \t Diem \t Hoc Luc\n");
	for (i = 0; i < n; i++) 
	{
		printf("%s \t %.1f \t ", ten[i], diem[i]);
		if (diem[i] >= 9)
			printf("Xuat sac\n");
		else if (diem[i] >= 8)
			printf("Gioi\n");
		else if (diem[i] >= 6.5)
			printf("Kha\n");
		else if (diem[i] >= 5)
			printf("TB\n");
		else
			printf("Yeu\n");
	}
}

void gameLott()
{
	int s1, s2;
	do 
	{
		printf("Nhap so 1 (1-15): ");
		scanf("%d", &s1);
	} while (s1 < 1 || s1 > 15);

	do
	{
		printf("Nhap so 2 (1-15): ");
		scanf("%d", &s2);
	} while (s2 < 1 || s2 > 15);

	int kq1 = rand() % 15 + 1;
	int kq2 = rand() % 15 + 1;
	printf("Ket qua: %d - %d\n", kq1, kq2);

	int dem = 0;
	if (s1 == kq1 || s1 == kq2) dem++;
	if (s2 == kq1 || s2 == kq2) dem++;

	if (dem == 2) printf("Trung giai NHAT!\n");
	else if (dem == 1) printf("Trung giai NHI!\n");
	else printf("Chuc may man lan sau\n");
}

void tinhToanPhanSo() 
{
	int t1, m1, t2, m2;
	printf("Nhap tu1 mau1: "); 
	scanf("%d %d", &t1, &m1);
	printf("Nhap tu2 mau2: ");
	scanf("%d %d", &t2, &m2);

	if (m1 == 0 || m2 == 0) 
	{
		printf("Mau so phai khac 0\n");
	}
	else
	{
		printf("Tong: %d/%d\n", t1 * m2 + t2 * m1, m1 * m2);
		printf("Hieu: %d/%d\n", t1 * m2 - t2 * m1, m1 * m2);
		printf("Tich: %d/%d\n", t1 * t2, m1 * m2);
		if (t2 != 0)
			printf("Thuong: %d/%d\n", t1 * m2, m1 * t2);
		else printf("Khong chia duoc\n");
	}
}


void kiemTraSoNguyen();
void timUCLN_BCNN();
void tinhTienKaraoke();
void tinhTienDien();
void doiTien();
void tinhLaiSuatVay();
void vayTienMuaXe();
void sapXepSinhVien();
void gameLott();
void tinhToanPhanSo();

void lapChucNang(int chonChucNang)
{
	int tiepTuc = 1;
	while (tiepTuc == 1)
	{
		switch (chonChucNang)
		{
		case 1:
			kiemTraSoNguyen();
			break;
		case 2:
			timUCLN_BCNN();
			break;
		case 3:
			tinhTienKaraoke();
			break;
		case 4:
			tinhTienDien();
			break;
		case 5:
			doiTien();
			break;
		case 6:
			tinhLaiSuatVay();
			break;
		case 7:
			vayTienMuaXe();
			break;
		case 8:
			sapXepSinhVien();
			break;
		case 9:
			gameLott();
			break;
		case 10:
			tinhToanPhanSo();
			break;
		default:
			printf("Chon sai. Chuc nang hop le [0-10]\n");
			break;
		}

		printf("\nTiep tuc thuc hien chuc nang nay? [1=Co | 0=Khong]: ");
		scanf("%d", &tiepTuc);
		system("cls");
	}
}

int main()
{
	int chonChucNang;
	do
	{
		printf("=== MENU ASSIGNMENT ===\n");
		printf("1. Kiem Tra So Nguyen\n");
		printf("2. Tim UCLN va BCNN\n");
		printf("3. Tinh Tien Karaoke\n");
		printf("4. Tinh Tien Dien\n");
		printf("5. Doi Tien\n");
		printf("6. Tinh Lai Suat Vay\n");
		printf("7. Vay Tien Mua Xe\n");
		printf("8. Sap Xep Sinh Vien\n");
		printf("9. Game FPOLY-LOTT\n");
		printf("10. Tinh Toan Phan So\n");
		printf("0. Thoat\n");
		printf("Hay chon chuc nang [0-10]: ");
		scanf("%d", &chonChucNang);

		if (chonChucNang != 0) {
			lapChucNang(chonChucNang);
		}

	} while (chonChucNang != 0);

	return 0;
}
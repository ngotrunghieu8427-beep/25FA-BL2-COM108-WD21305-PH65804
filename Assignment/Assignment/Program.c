#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 

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
		printf("8. Sap xep sinh vien \n");
		printf("9. Game Lott \n");
		printf("10. Tinh toan phan so \n");
		printf("0. Thoat\n");
		printf("Hay chon chuc nang [0-10]: ");
		scanf("%d", &chonChucNang);

		if (chonChucNang != 0) {
			lapChucNang(chonChucNang);
		}

	} while (chonChucNang != 0);

	return 0;
}

void kiemTraSoNguyen() {
	float x;
	printf("Nhap so x: ");
	scanf("%f", &x);
	if (x == (int)x)
	{
		printf("%.0f la so nguyen\n", x);
		int n = (int)x;
		int i, dem = 0;
		for (i = 1; i <= n; i++)
			if (n % i == 0)
			{
				dem++;
			}

		if (dem == 2)
		{
			printf("%d la so nguyen to\n", n);
		}
		else
		{
			printf("%d khong phai so nguyen to\n", n);
		}
		int can = sqrt(n);
		if (can * can == n)
		{
			printf("%d la so chinh phuong\n", n);
		}
		else
		{
			printf("%d khong phai so chinh phuong\n", n);
		}

	}
	else
	{
		printf("Day khong phai so nguyen\n");
	}
		
}

void timUCLN_BCNN() {
	int a, b, i, ucln = 1, min;
	printf("Nhap a, b: ");
	scanf("%d %d", &a, &b);
	min = (a > b) ? b : a;
	for (i = min; i >= 1; i--) 
	{
		if (a % i == 0 && b % i == 0)
		{
			ucln = i; break;
		}
	}
	printf("UCLN: %d, BCNN: %d\n", ucln, (a * b) / ucln);
}

void tinhTienKaraoke() 
{
	int bd, kt;
	printf("Nhap gio bat dau, ket thuc: ");
	scanf("%d %d", &bd, &kt);
	if (bd < 12 || kt > 23 || bd >= kt)
	{
		printf("Gio khong hop le\n");
	}
	else
	{
		float tien;
		int gio = kt - bd;
		if (gio <= 3)
		{
			tien = gio * 150000;
		}
		else
		{
			tien = 3 * 150000 + (gio - 3) * 150000 * 0.7;
		}
		if (bd >= 14 && bd < 17)
		{
			tien *= 0.9;
		}

		printf("Tong tien: %.0f VND\n", tien);
	}
}

void tinhTienDien() {
	float k, t;
	printf("Nhap so kwh: ");
	scanf("%f", &k);
	if (k <= 50)
	{
		t = k * 1678;
	}
	else if (k <= 100)
	{
		t = 50 * 1678 + (k - 50) * 1734;
	}
	else if (k <= 200)
	{
		t = 50 * 1678 + 50 * 1734 + (k - 100) * 2014;
	}
	else if (k <= 300)
	{
		t = 50 * 1678 + 50 * 1734 + 100 * 2014 + (k - 200) * 2536;
	}
	else if (k <= 400)
	{
		t = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (k - 300) * 2834;
	}
	else
	{
		t = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (k - 400) * 2927;
	}
	printf("Tien dien: %.0f VND\n", t);
}

void doiTien() {
	int tien, mg[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 }, i;
	printf("Nhap so tien: ");
	scanf("%d", &tien);
	for (i = 0; i < 9; i++) 
	{
		int so = tien / mg[i];
		if (so > 0)
		{
			printf("%d to %d\n", so, mg[i]); tien %= mg[i];
		}
	}
}

void tinhLaiSuatVay() {
	double vay, lai, tong;
	printf("Nhap tien vay: "); 
	scanf("%lf", &vay);
	double goc = vay / 12;
	printf("Thang \t Lai \t Goc \t Tong \t Con lai\n");
	for (int i = 1; i <= 12; i++) 
	{
		lai = vay * 0.05; tong = lai + goc; vay -= goc;
		printf("%d \t %.0f \t %.0f \t %.0f \t %.0f\n", i, lai, goc, tong, vay);
	}
}

void vayTienMuaXe() {
	double pt, vay, traTruoc, goc, lai, tong;
	printf("Vay bao nhieu %% (gia xe 500tr): ");
	scanf("%lf", &pt);
	vay = 500000000 * pt / 100;
	traTruoc = 500000000 - vay;
	goc = vay / 288;
	printf("Tra truoc: %.0f\nThang \t Lai \t Goc \t Tong \t Con lai\n", traTruoc);
	for (int i = 1; i <= 288; i++)
	{
		lai = vay * 0.006; tong = lai + goc; vay -= goc;
		if (i <= 5)
		{
			printf("%d \t %.0f \t %.0f \t %.0f \t %.0f\n", i, lai, goc, tong, vay);
		}	
	}
}

void sapXepSinhVien() 
{
	char s[100];
	printf("--CHUC NANG: DAO NGUOC CHUOI--\n");
	printf("Nhap chuoi: ");

	while(getchar() != '\n'); // Xoa bo nho dem 
	gets(s);       // Nhap chuoi

	_strrev(s);     // Dao nguoc
	printf("Ket qua: %s\n", s);
}

void gameLott() {
	char s[100];
	int c;
	printf("--CHUC NANG: DOI HOA/THUONG-- \n");
	printf("Nhap chuoi: ");

	while (getchar() != '\n'); // Xoa bo nho dem
	gets(s);

	printf("1. Hoa (strupr) | 2. Thuong (strlwr): ");
	scanf("%d", &c);

	if (c == 1) {
		_strupr(s); // Lenh chuyen chu hoa
		printf("Ket qua: %s\n", s);
	}
	else if (c == 2) 
    {
		_strlwr(s); // Lenh chuyen chu thuong
		printf("Ket qua: %s\n", s);
	}
}

void tinhToanPhanSo() {
	char s1[100], s2[50];
	char* p;

	printf("--CHUC NANG: TIM KIEM CHUOI-- \n");
	while (getchar() != '\n'); // Xoa bo nho dem

	printf("Nhap chuoi goc: ");
	gets(s1);
	printf("Nhap chuoi can tim: ");
	gets(s2);

	p = strstr(s1, s2); // Lenh tim kiem

	if (p != NULL)
	{
		printf("Tim thay '%s' trong chuoi!\n", s2);
	}
	else
	{
		printf("Khong tim thay '%s'!\n", s2);
	}
}
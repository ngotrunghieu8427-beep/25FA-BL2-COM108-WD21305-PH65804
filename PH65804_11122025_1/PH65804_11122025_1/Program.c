#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct thuCung
{
	char ten[50];
	char ma[30];
	int namSinh;
};

void thongTinThuCung()
{
	struct thuCung tuoi;
	int n = 3, i;

	for (int i = 0; i < 3; i++)
	{
		while (getchar() != '\n');
		fgets(tuoi.ten, sizeof(tuoi.ten), stdin);
		fgets(tuoi.ma, sizeof(tuoi.ma), stdin);
		scanf("%d", &tuoi.namSinh);

	}

	for (int i = 0; i < 3; i++)
	{
		put(tuoi.ten);
		put(tuoi.ma);
		printf("%d\n", tuoi.namSinh);
	}

	printf("Thong tin thu cung da nhap xong.\n");
	printf("Ten thu cung: %s", tuoi.ten);
	printf("Ma thu cung: %s", tuoi.ma);
	printf("Nam sinh thu cung: %d\n", tuoi.namSinh);
	printf("\n");
}

void soNguyen()
{
	int n, i, tong = 0;

	do
	{
		printf("Nhap mot so nguyen duong (n > 3): ");
		scanf("%d", &n);
		if (n <= 3)
		{
			printf("So nguyen duong phai lon hon 3\n");
			return;
		}
	} while (n <= 3);
	for (i = 0; i < n; i++)
	{
		if (i % 2 != 0)
		{
			tong = tong + i;
		}

	}
	printf("Tong cua cac so tu 1 den %d la: %d\n", n, tong);
	if (n % 5 == 0)
	{
		printf("%d chia het cho 5\n", n);
	}
	else
	{
		printf("%d khong chia het cho 5\n", n);
	}
}

void thongSoThuCung()
{
	int soLuong;
	int canNang[100];
	int tong = 0;
	int thapNhat;
	int trungBinh ;
	int soLuongDuoiTB = 0;

	printf("Nhap so luong thu cung: ");
	scanf("%d", &soLuong);

	for (int i = 0; i < soLuong; i++)
	{
		printf("Nhap can nang thu cung thu %d: ", i + 1);
		scanf("%d", &canNang[i]);

		tong = tong + canNang[i];
	}
	thapNhat = canNang[0];
	for (int i = 1; i < soLuong; i++)
	{
		if (canNang[i] < thapNhat)
		{
			thapNhat = canNang[i];
		}
	}
	trungBinh = tong / soLuong;
	for (int i = 0; i < soLuong; i++)
	{
		if (canNang[i] < trungBinh)
		{
			soLuongDuoiTB++;
		}
	}
	printf("Can nang thap nhat la: %d\n", thapNhat);
	printf("Can nang trung binh la: %d\n", tong / soLuong);
	printf("So luong thu cung co can nang duoi trung binh la: %d\n", soLuongDuoiTB);

			
}



void lapChucNang(int chonChucNang)
{
	int tiepTuc = 1;
	while (tiepTuc == 1)
	{
		printf("1. Nhap thong tin thu cung\n");
		printf("2. So nguyen chia het cho 5\n");
		printf("3. Thong so thu cung\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &tiepTuc);
		switch (tiepTuc)
		{
		case 1:
			thongTinThuCung();
			break;
		case 2:
			soNguyen();
			break;
		case 3:
			thongSoThuCung();
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
		printf("Ban co muon tiep tuc khong? (1: Co, 0: Khong): ");
		scanf("%d", &tiepTuc);
		system("cls");
	}
}
int main()
{
	int chonChucNang;
	do
	{
		printf("Menu:\n");
		printf("1. Thong tin thu cung\n");
		printf("2. So nguyen chia het cho 5\n");
		printf("3. Thong so thu cung\n");
		printf("0. Thoat\n");

	} while (chonChucNang != 0);
}

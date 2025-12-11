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
	int n, i;

	for (int i = 0; i < n; i++)
	{
		while (getchar() != '\n');
		fgets(tuoi.ten, sizeof(tuoi.ten), stdin);
		fgets(tuoi.ma, sizeof(tuoi.ma), stdin);
		scanf("%d", &tuoi.namSinh);

	}

	for (int i = 0; i < n; i++)
	{
		put(tuoi.ten);
		put(tuoi.ma);
		printf("%d\n", tuoi.namSinh);
	}

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
	int canNang;
	int tong = 0;
	int thapNhat;
	int soLuongDuoiTB = 0

		for (int i = 0; i < soLuong; i++

			for (int i = 0; i < soLuong; i++)
			{
				tong = tong + canNang[i];
				if (canNang[i] < thapNhat)
				{
					thapNhat = canNang[i];
				}
			}
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

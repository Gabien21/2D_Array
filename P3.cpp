//VCT nhập một ma trận cấp n gồm các số nguyên dương. Tính tổng các phần tử là:
//a)    số chính phương nằm trong nửa mảng vuông phía trên đường chéo chính.
//b)    số chính phương nằm trong nửa mảng vuông phía dưới đường chéo phụ.

#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 100;
typedef int  _2dArr[MAX][MAX];

//Ham kiem tra n co phai la so chinh phuong hay khong
bool SoChinhPhuong(int n)
{
    if (n == 1) return true; //1 la so chinh phuong
    //So chinh phuong la so ma can bac hai cua no la mot so nguyen
    for (int i = 1; i <= n / 2; i++)
        //Neu tim duoc i^2 = n thi tra ve true
        if (n == pow(i, 2)) return true;
    return false;   //Neu khong tim duoc i thi tra ve false
}

//Ham tinh tong cac phan tu la so chinh phuong nam phia tren duong cheo chinh
int TongChinhPhuongPhiaTrenCheoChinh(_2dArr a, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        //Phan tu nam tren duong cheo chinh neu j > i
        for (int j = n - 1; j > i; j--)
            if (SoChinhPhuong(a[i][j])) //Neu a[i][j] la so chinh phuong thi cong a[i][j] vao s
                s += a[i][j];
    return s;
}

//Ham tinh tong cac phan tu la so chinh phuong nam duoi duong cheo phu
int TongChinhPhuongDuoiCheoPhu(_2dArr a, int n)
{
    int s = 0;
    for (int i = n-1; i > 0; i--)
        //Phan tu nam duoi duong cheo phu neu j > n - 1 - i
        for (int j = n-1; j > n - 1 - i; j--)
            if (SoChinhPhuong(a[i][j])) //Neu a[i][j] la so chinh phuong thi cong a[i][j] vao s
                    s += a[i][j];
    return s;
}

//Ham nhap mang ma tran cap n
void NhapMaTran(_2dArr a, int& n)
{
    do
    {
        cout << "Nhap so cap cua ma tran: "; cin >> n;
        if (n <= 0 || n > MAX)   //neu so cap <= 0 hoac > MAX thi khong hop le
            cout << "So cot khong hop le!" << endl;
    } while (n <= 0 || n > MAX); //Nhap den khi nao so cap hop le

    cout << "Nhap vao mang " << n << " dong va " << n << " cot: " << endl;
    //Nhap tung phan tu vao mang 2 chieu
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}

//Ham xuat ma tran
void XuatMang(_2dArr a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    _2dArr a;
    int n;
    NhapMaTran(a, n);
    XuatMang(a, n);

    //Tinh tong cac phan tu la so chinh phuong nam phia tren duong cheo chinh cua ma tran
    cout << "Tong cac phan tu la so chinh phuong nam phia tren duong cheo chinh cua ma tran la: " << TongChinhPhuongPhiaTrenCheoChinh(a, 3) << endl;
    
    //Tinh tong cac phan tu la so chinh phuong nam phia duoi duong cheo phu cua ma tran
    cout << "Tong cac phan tu la so chinh phuong nam duoi duong cheo phu cua ma tran la: " << TongChinhPhuongDuoiCheoPhu(a, 3) << endl;
    return 0;
}

// 1 16 3 4 5 36 7 8 9

//VCT nhập một ma trận cấp n gồm các số nguyên, thực hiện:
//a)    Tìm số lớn nhất trên biên ma trận.
//b)    Tính tổng các phần tử là số dương đối xứng nằm trên đường chéo chính.
//c)     Đếm số lượng phần tử là số dương đối xứng nằm trên đường chéo phụ.

#include <iostream>
using namespace std;
const int MAX = 100;
typedef int  _2dArr[MAX][MAX];

//Ham tim phan tu lon nhat tren bien cua ma tran
int LonNhatTrenBien(_2dArr a, int n)
{
    int max = a[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && i < n - 1 && j > 0 && j < n - 1) //Neu a[i][j] khong nam tren bien thi xet den phan tu khac
                continue;
            if (a[i][j] > max) max = a[i][j];   //Neu a[i][j] > max thi gan max bang a[i][j]
        }
    return max;
}

//Ham tim so dao nguoc cua n
int soDaoNguoc(int n)
{
    int soDaoNguoc = 0;
    while (n > 0)   //Neu n > 0 thi tiep tuc vong lap
    {
        soDaoNguoc = soDaoNguoc * 10 + n % 10;		//Dao nguoc vi tri cac chu so cua so ban nhap vao
        n /= 10;									//Loai bo mot chu so hang don vi va tiep tuc vong lap
    }
    return soDaoNguoc;
}

//Ham kiem tra cac chu so cua n co doi xung hay khong
bool SoDoiXung(int n)
{
    if (n < 0) return false;    //Neu n la so nguyen am thi tra ve false
    //Neu so dao nguoc cua n bang chinh no thi n la so doi xung
    if (soDaoNguoc(n) == n) return true;
    else return false;
}

//Ham tinh tong cac phan tu la so duong doi xung nam tren duong cheo chinh cua ma tran
int TongDuongDoiXungCheoChinh(_2dArr a, int n)
{
    int s = 0;
    //Cac phan tu tren duong cheo chinh co dang a[i][i]
    for (int i = 0; i < n; i++)
        if (SoDoiXung(a[i][i])) //Neu phan tu a[i][i] la so doi xung thi cong phan tu do vao s
            s += a[i][i];
    return s;
}

//Ham dem so phan tu la so duong doi xung nam tren duong cheo phu cua ma tran
int SoDuongDoiXungCheoPhu(_2dArr a, int n)
{
    int dem = 0;
    //Cac phan tu tren duong cheo phu co dang a[i][n-1-i]
    for (int i = 0; i < n; i++)
        if (SoDoiXung(a[i][n - 1 - i])) //Neu phan tu a[i][n-1-i] la so doi xung thi tang bien dem them 1 don vi
            dem++;
    return dem;
}

//Ham nhap mang 2 chieu
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
    cout << "Mang vua nhap la: " << endl;
    XuatMang(a, n);

    //Tim phan tu lon nhat nam tren bien cua ma tran
    cout << "Phan tu lon nhat tren bien cua ma tran la: " << LonNhatTrenBien(a, n) << endl;

    //Tinh tong cac phan tu la so duong doi xung nen tren duong cheo chinh cua ma tran
    cout << "Tong cac phan tu la so duong doi xung tren duong cheo chinh cua ma tran la: " << TongDuongDoiXungCheoChinh(a, n) << endl;
    
    //Dem so phan tu la so duong doi xung nam tren duong cheo phu cua ma tran
    cout << "So phan tu la so duong doi xung tren duong cheo phu cua ma tran la: " << SoDuongDoiXungCheoPhu(a, n) << endl;
    return 0;
}

// 11 2 311 4 551 6 71 8 9

//VCT nhập mảng 2 chiều số nguyên có m dòng và n cột, thực hiện:
//a)    Tìm số dương nhỏ nhất trong mảng.
//b)    Tìm giá trị xuất hiện nhiều nhất trong mảng.
//c)     Liệt kê các dòng chứa toàn số chẵn trong mảng.

#include <iostream>
using namespace std;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;
typedef int  _2dArr[MAX_COLS][MAX_COLS];

//Ham tim so duong nho nhat trong mang
int DuongNhoNhat(_2dArr a, int nrow, int ncol)
{
    int min = a[0][0];
    //Xet den tat cac phan tu trong mang
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < ncol; j++)
        {
            if (a[i][j] > 0 && a[i][j] < min)   //Neu tim duoc phan tu nho hon min 
                min = a[i][j];  //Gan gia tri cua phan tu do cho min
        }
    return min;
}

//Ham dem so lan xuat hien cua mot phan tu trong mang
int DemSoLan(_2dArr a, int nrow, int ncol, int key)
{
    int dem = 0;
    //Xet den tat cac phan tu trong mang
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < ncol; j++)
            if (a[i][j] == key) //Neu tim duoc phan tu bang key thi tang bien dem them 1 don vi
                dem++;
    return dem;
}

//Ham tim phan tu xuat hien nhieu lan nhat trong mang
int XuatHienNhieuNhat(_2dArr a, int nrow, int ncol)
{
    int max = a[0][0];
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < ncol; j++)
            //Neu tim duoc phan tu nao co so lan xuat hien nhieu hon max thi truyen phan tu do cho max
            if (DemSoLan(a, nrow, ncol, a[i][j]) > DemSoLan(a, nrow, ncol, max))
                max = a[i][j];
    return max;
}

//Ham liet ke cac dong toan nhung phan tu chan trong mang
void DongToanChan(_2dArr a, int nrow, int ncol)
{
    cout << "Cac dong toan chan la: ";
    //Xet den tat cac phan tu trong mang
    for (int i = 0; i < nrow; i++)
    {
        int flag = true;
        for (int j = 0; j < ncol; j++)
        {
            //Neu xuat hien phan tu khong chia het cho 2 thi nhay qua xet dong khac
            if (a[i][j] % 2 != 0)   
            {
                flag = false;
                break;
            }
        }
        if (flag) cout << i + 1 << " ";
    }
}

//Ham nhap mang 2 chieu
void NhapMang(_2dArr a, int& nrow, int& ncol)
{
    do
    {
        cout << "Nhap so dong: "; cin >> nrow;
        if (nrow <= 0 || nrow > MAX_ROWS)   //neu so dong <= 0 hoac > MAX_ROWS thi khong hop le
            cout << "So hang khong hop le!" << endl;
    } while (nrow <= 0 || nrow > MAX_ROWS); //Nhap den khi nao so dong hop le

    do
    {
        cout << "Nhap so cot: "; cin >> ncol;
        if (ncol <= 0 || ncol > MAX_COLS)   //neu so cot <= 0 hoac > MAX_COLS thi khong hop le
            cout << "So cot khong hop le!" << endl;
    } while (ncol <= 0 || ncol > MAX_COLS); //Nhap den khi nao so cot hop le

    cout << "Nhap vao mang " << nrow << " dong va " << ncol << " cot: " << endl;
    //Nhap tung phan tu vao mang 2 chieu
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < ncol; j++)
            cin >> a[i][j];
}

int main()
{
    _2dArr a;
    int nrow, ncol;
    NhapMang(a, nrow, ncol);    //Nhap mang can xet

    //Tim so nguyen duong nho nhat trong mang
    cout << "So nguyen duong nho nhat trong mang la: ";
    cout << DuongNhoNhat(a,nrow,ncol) << endl;

    //Tim phan tu xuat hien nhieu nhat trong mang
    cout << "Phan tu xuat hien nhieu nhat trong mang la: ";
    cout << XuatHienNhieuNhat(a, nrow, ncol) << endl;

    //Xuat ra cac dong toan phan tu chan
    DongToanChan(a, nrow, ncol);
    return 0;
}

// 8 4 2 4 -5 6 4 8 10

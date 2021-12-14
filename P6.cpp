//VCT nhập mảng 2 chiều số nguyên có m dòng và n cột. Hãy sắp xếp các giá trị nằm trên biên của mảng tăng dần theo chiều kim đồng hồ.

#include <iostream>
using namespace std;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;
typedef int  _2dArr[MAX_COLS][MAX_COLS];

//Ham tim vi tri cua phan tu lon nhat trong mang
int TimMax(int a[], int n)
{
    int max = 0;
    //Xet den tung phan tu trong mang
    for (int i = 0; i < n; i++)
        if (a[i] > a[max])  //Neu tim duoc a[i] > a[max] thi gan max = i 
            max = i;
    return max;
}

//Ham tim vi tri cua phan tu nho nhat trong mang
int TimMin(int a[], int n)
{
    int min = 0;
    //Xet den tung phan tu trong mang
    for (int i = 0; i < n; i++)
        if (a[i] < a[min])  //Neu tim duoc a[i] < a[min] thi gan min = i 
            min = i;
    return min;
}

//Ham xoa mot phan tu khi biet vi tri
void XoaPhanTu(int a[], int& n, int viTri)
{
    //Tao vong lap thay doi cac gia tri trong mang voi i tu viTri
    for (int i = viTri; i < n; i++)
        //Gan gia tri cua phan tu sau cho phan tu truoc 
        //Nhu vay ta da cat bo duoc gia tri cua phan tu viTri
        a[i] = a[i + 1];
    n--;    //Vi xoa di mot phan tu nen n giam di mot don vi
}

void SapXep(_2dArr a, int nrow, int ncol)
{
    int b[100], nb = 0;
    //Truyen tat ca cac phan tu nam tren bien cua ma tran vao mang b
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < ncol; j++)
        {
            if (i > 0 && i < nrow - 1 && j > 0 && j < ncol - 1) //Neu phan tu khong nam tren bien cua ma tran thi bo qua
                continue;
            b[nb++] = a[i][j];
        }

    //Sap xep cac phan tu nam tren bien cua ma tran giam dan theo chieu kim dong ho 
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            if (i > 0 && i < nrow - 1 && j > 0 && j < ncol - 1) //Bo qua cac phan tu khong nam tren bien cua ma tran
                continue;
            if (i == 0) //Dong dau tien cua ma tran
            {
                //Lan luot gan cho a[i][j] phan tu lon nhat trong mang b
                int t = TimMax(b, nb);
                a[i][j] = b[t];
                XoaPhanTu(b, nb, t);    //Sau moi lan gan thi xoa di phan tu vua gan trong mang b
            }

            if (i > 0 && i < nrow - 1)  //Cac dong con lai cua ma tran
            {
                if (j == 0) //Cot dau tien
                {
                    //Gan cho a[i][j] phan tu lon nho trong mang b
                    int t = TimMin(b, nb);
                    a[i][j] = b[t];
                    XoaPhanTu(b, nb, t);    //Xoa di phan tu vua gan trong mang b
                }
                else    //Cot cuoi cung
                {
                    //Gan cho a[i][j] phan tu lon lon trong mang b
                    int t = TimMax(b, nb);
                    a[i][j] = b[t];
                    XoaPhanTu(b, nb, t);    //Xoa di phan tu vua gan trong mang b
                }
            }

            if (i == nrow - 1)  //Dong cuoi cung cua ma tran
            {
                //Lan luot gan cho a[i][j] phan tu nho nhat trong mang b
                int t = TimMin(b, nb);
                a[i][j] = b[t];
                XoaPhanTu(b, nb, t);    //Sau moi lan gan thi xoa di phan tu vua gan trong mang b
            }
        }
    }
    cout << "Mang 2 chieu sau khi sap xep cac phan tu nam tren bien giam dan theo chieu kim dong ho la: " << endl;
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

//Ham xuat ma tran
void XuatMang(_2dArr a, int nrow, int ncol)
{
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < ncol; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    _2dArr a;
    int nrow, ncol;
    NhapMang(a, nrow, ncol);
    cout << "Mang 2 chieu vua nhap la: " << endl;
    XuatMang(a, nrow, ncol);
    //Sap xep cac phan tu nam tren bien cua mang 2 chieu giam dan theo chieu kim dong ho
    SapXep(a, nrow, ncol);
    XuatMang(a, nrow, ncol);
    return 0;
}

// 1 2 3 10 4 5 6 11 7 8 9 12 13 14 15 16

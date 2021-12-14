//VCT nhập một ma trận cấp n gồm các số nguyên dương, thực hiện sắp xếp các phần tử trên đường chéo phụ theo thứ tự tăng dần từ dưới hướng lên.

#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 100;
typedef int  _2dArr[MAX][MAX];

//Ham hoan doi gia tri cua hai so
void HoanDoi(int& a, int& b)
{
    double temp = a;   //Gan gia tri cua a vao bien phu temp
    a = b;  //Gan gia tri cua b vao a
    b = temp;   //Gan gia tri cua bien phu temp vao b
}

//Ham sap xep cac phan tu tren duong cheo phu cua ma tran tang dan tu duoi len
void SapTangCheoPhu(_2dArr a, int n)
{
    for (int i = 0; i < n; i++)
        //Cac phan tu nam tren duong cheo phu co i = n-1-j
        for (int t = i + 1; t < n; t++) //Lan luot so sanh cac phan tu tren duong cheo phu voi nhau
            if (a[i][n-1-i] < a[t][n-1-t])  //Neu tim duoc a[t][n-1-t] > a[i][n-1-i] thi hoan doi hai phan tu do voi nhau
                HoanDoi(a[i][n - 1 - i], a[t][n - 1 - t]);
    cout << "Ma tran sau khi sap xep tang dan cac phan tu nam tren duong duong cheo phu tu duoi len la: " << endl;
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
void XuatMaTran(_2dArr a, int n)
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
    cout << "Ma tran vua nhap la: " << endl;
    XuatMaTran(a, n);
    //Sap xep cac phan tu nam tren duong cheo phu tang dan tu duoi len
    SapTangCheoPhu(a, n);
    XuatMaTran(a,n);
    return 0;
}

// 11 2 3 4 9 6 7 8 5

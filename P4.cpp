//VCT nhập một ma trận cấp n gồm các số nguyên dương, thực hiện:
//a)    Đếm số lượng giá trị “Yên ngựa” trên ma trận. Một phần tử được gọi là “yên  ngựa” khi nó lớn nhất trên dòng và nhỏ nhất trên cột.
//b)    Đếm số lượng giá trị “Hoàng hậu” trên ma trận. Một phần tử được gọi là “hoàng hậu” khi nó lớn nhất trên dòng, trên cột và hai đường chéo đi qua nó.
//c)     Tính tổng các phần tử cực trị trong ma trận. Một phần tử gọi là cực trị khi nó lớn hơn các phần tử xung quanh hoặc nhỏ hơn các phần tử xung quanh.

#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 100;
typedef int  _2dArr[MAX][MAX];

//Ham tim phan tu lon nhat tren dong
int MaxTrenDong(_2dArr a, int row, int n)
{
    int max = a[row][0];
    for (int i = 1; i < n; i++)  //Xet tung phan tu tren dong
        if (a[row][i] > max)    //Neu phat hien phan tu a[row][i] > max thi gan a[row][i] cho max
            max = a[row][i];
    return max;
}

//Ham tim phan tu nho nhat tren cot
int MinTrenCot(_2dArr a, int n, int col)
{
    int min = a[0][col];
    for (int i = 1; i < n; i++)  //Xet tung phan tu tren cot
        if (a[i][col] < min)    //Neu phat hien phan tu a[row][i] < min thi gan a[row][i] cho min
            min = a[i][col];
    return min;
}

//Ham dem so yen ngua trong mang
int SoYenNgua(_2dArr a, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        int maxRow = MaxTrenDong(a, i, n);   //Tim gia tri lon nhat tren dong
        for (int j = 0; j < n; j++)
        {
            int min = MinTrenCot(a, n, j);    //Tim gia tri nho nhat tren cot
            if (maxRow == min)   //Neu phan tu do vua lon nhat tren dong vua nho nhat tren cot
                dem++;  //Tang bien dem them 1 don vi
        }
    }
    return dem;
}

//Ham kiem tra phan tu nhap vao co phai la hoang hau khong
bool KiemTraHoangHau(_2dArr a, int n, int row, int col)
{
    int x = a[row][col];
    //Kiem tra lon nhat tren cot
    for (int i = 0; i < n; i++)
        if (a[i][col] > x)  //neu co phan tu lon hon x thi tra ve false
            return false;
    //Kiem tra lon nhat tren hang
    for (int i = 0; i < n; i++)
        if (a[row][i] > x)  //neu co phan tu lon hon x thi tra ve false
            return false;
    //Kiem tra duong cheo thu nhat
    //Kiem tra cheo xuong duoi
    int row1 = row + 1;
    int col1 = col + 1;
    while (col1 + 1 < n && row1 < row)
    {
        if (a[row1][col1] > x)  //neu co phan tu lon hon x thi tra ve false
            return false;
        row1++;
        col1++;
    }
    //Kiem tra cheo len tren
    row1 = row - 1;
    col1 = col - 1;
    while (col1 - 1 >= 0 && row1 >= 0)
    {
        if (a[row1][col1] > x)  //neu co phan tu lon hon x thi tra ve false
            return false;
        row1--;
        col1--;
    }
    //Kiem tra duong cheo thu hai
    //Kiem tra cheo len tren
    row1 = row - 1;
    col1 = col + 1;
    while (col1 + 1 > n && row1 >= 0)
    {
        if (a[row1][col1] > x)  //neu co phan tu lon hon x thi tra ve false
            return false;
        row1--;
        col1++;
    }
    //Kiem tra cheo xuong duoi
    row1 = row + 1;
    col1 = col - 1;
    while (col1 - 1 >= 0 && row1 < n)
    {
        if (a[row1][col1] > x)  //neu co phan tu lon hon x thi tra ve false
            return false;
        row1++;
        col1--;
    }
    return true;
}

//Ham dem so luong hoang hau trong mang
int DemHoangHau(_2dArr a, int n)
{
    int dem = 0;
    //Xet tung phan tu trong ma tran
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (KiemTraHoangHau(a, n, i, j))    //Neu phan tu a[i][j] la hoang hau
                dem++;  //Tang bien dem them 1 don vi
    return dem;
}

//Ham kiem tra phan tu nhap vao co phai la cuc tri hay khong
bool KiemTraCucTri(_2dArr a, int n, int row, int col)
{
    int x = a[row][col];
    //Xet dong dau tien
    if (row == 0)  
    {
        if (col == 0)   //Xet cot dau tien
            if ((a[0][1] < x && a[1][0] < x && a[1][1] < x) || (a[0][1] > x && a[1][0] > x && a[1][1] > x))
                return true;
        if (col == n - 1)   //Xet cot cuoi cung
            if ((a[0][col - 1] < x && a[1][col] < x && a[1][col - 1] < x) || (a[0][col - 1] > x && a[1][col] > x && a[1][col - 1] > x))
                return true;
        //Xet cac cot con lai
        if ((a[0][col - 1] < x && a[0][col + 1] < x && a[1][col] < x && a[1][col - 1] < x && a[1][col + 1] < x) || (a[0][col - 1] > x && a[0][col + 1] > x && a[1][col] > x && a[1][col - 1] > x && a[1][col + 1] > x))
            return true;
    }
    //Xet dong cuoi cung
    if (row == n - 1)
    {
        if (col == 0)   //Xet cot dau tien
            if ((a[row][1] < x && a[row - 1][0] < x && a[row - 1][1] < x) || (a[row][1] > x && a[row - 1][0] > x && a[row - 1][1] > x))
                return true;
        if (col == n - 1)   //Xet cot cuoi cung
            if ((a[row][col - 1] < x && a[row - 1][col] < x && a[row - 1][col - 1] < x) || (a[row][col - 1] > x && a[row - 1][col] > x && a[row - 1][col - 1] > x))
                return true;
        //Xet cac cot con lai
        if ((a[row][col - 1] < x && a[row][col + 1] < x && a[row - 1][col] < x && a[row - 1][col - 1] < x && a[row - 1][col + 1] < x) || (a[row][col - 1] > x && a[row][col + 1] > x && a[row - 1][col] > x && a[row - 1][col - 1] > x && a[row - 1][col + 1] > x))
            return true;
    }
    //Xet cot dau tien
    if (col == 0)
        if ((a[row - 1][col] < x && a[row + 1][col] < x && a[row][col + 1] < x && a[row + 1][col + 1] < x && a[row - 1][col + 1] < x) || (a[row - 1][col] > x && a[row + 1][col] > x && a[row][col + 1] > x && a[row + 1][col + 1] > x && a[row - 1][col + 1] > x))
            return true;
    //Xet cot cuoi cung
    if (col == n - 1)
        if ((a[row - 1][col] < x && a[row + 1][col] < x && a[row][col - 1] < x && a[row + 1][col - 1] < x && a[row - 1][col - 1] < x) || (a[row - 1][col] > x && a[row + 1][col] > x && a[row][col - 1] > x && a[row + 1][col - 1] > x && a[row - 1][col - 1] > x))
            return true;
    //Xet cac phan tu con lai khong nam tren bien cua ma tran
    if ((a[row][col + 1] < x && a[row][col - 1] < x && a[row + 1][col] < x && a[row + 1][col + 1] < x && a[row + 1][col - 1] < x && a[row - 1][col] < x && a[row - 1][col + 1] < x && a[row - 1][col - 1] < x) || (a[row][col + 1] > x && a[row][col - 1] > x && a[row + 1][col] > x && a[row + 1][col + 1] > x && a[row + 1][col - 1] > x && a[row - 1][col] > x && a[row - 1][col + 1] > x && a[row - 1][col - 1] > x))
        return true;
    return false;
}

//Ham dem so luong cuc tri trong mang
int DemCucTri(_2dArr a, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (KiemTraCucTri(a, n, i, j))  //Neu a[i][j] la cuc tri thi cong a[i][j] vao s
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
    cout << "So phan tu la yen ngua trong ma tran la: " << SoYenNgua(a, n) << endl;
    cout << "So phan tu la hoang hau trong ma tran la: " << DemHoangHau(a, n) << endl;
    cout << "Tong cac phan tu la cuc tri trong ma tran la: " << DemCucTri(a, n) << endl; 
    return 0;
}

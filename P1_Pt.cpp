//Viết chương trình nhập mảng 2 chiều m x n gồm các phần tử là số nguyên dương, thực hiện:
//1. Tính tổng các phần tử dương trong ma trận.
//2. Đếm số lượng số nguyên tố trong ma trận.
//3. Liệt kê các dòng có chứa giá trị âm trong ma trận.
//4. Tìm phần tử lớn nhất trên đường chéo chính.
//5. Tìm phần tử nhỏ nhất trên đường chéo phụ.
//6. Sắp xếp các phần tử trên đường chéo chính giảm dần.

#include <iostream>
using namespace std;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;
typedef int _2dArr[MAX_ROWS][MAX_COLS];

//Ham nhap ma tran
void NhapMang(_2dArr a, int& nrow, int& ncol)
{
    do
    {
        cout << "Nhap so dong: "; cin >> nrow;
        if (nrow <= 0 || nrow > MAX_ROWS)   //So dong phai >0 va <= MAX
            cout << "So hang khong hop le!" << endl;
    } while (nrow <= 0 || nrow > MAX_ROWS); //Nhap den khi so dong hop le

    do
    {
        cout << "Nhap so cot: "; cin >> ncol;
        if (ncol <= 0 || ncol > MAX_COLS)   //So cot phai >0 va <= MAX
            cout << "So cot khong hop le!" << endl;
    } while (ncol <= 0 || ncol > MAX_COLS); //Nhap den khi so cot hop le

    cout << "Nhap ma tran: " << endl;
    for (int i = 0; i < nrow; i++)  //Nhung tung phan tu trong ma tran
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

//Ham tinh tong cac phan tu duong trong ma tran
int TongDuong(_2dArr a, int nrow, int ncol)
{
    int s = 0;
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            if (a[i][j] > 0)    //Neu phan tu do la so duong thi cong vao s
                s += a[i][j];
        }
    }
    return s;
}

//Ham kiem tra n co phai la so nguyen to hay khong
bool NguyenTo(int n)
{
    if (n <= 1) return false;    //Neu n <= 1 thi n khong phai la so nguyen to
    //So nguyen to la so chi chia het cho 1 va chinh no
    for (int i = 2; i <= n / 2; i++)	//Tao vong lap voi i chay tu 2 den n/2
        if (n % i == 0) return false;	//Neu co gia tri i nao chia het cho n thi tra ve false
    return true;    //Neu khong tim duoc so nao chia het cho n thi tra ve true
}

//Ham dem so nguyen to trong ma tran
int SoNguyenTo(_2dArr a, int nrow, int ncol)
{
    int dem = 0;
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < ncol; j++)
            if (NguyenTo(a[i][j]))  //Neu phan tu do la so nguyen to thi tang bien dem them 1 
                dem++;
    return dem;
}

//Ham liet ke cac dong co phan tu am trong ma tran
void LietKeDongAm(_2dArr a, int nrow, int ncol)
{
    cout << "Dong co gia tri am trong ma tran la: ";
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < ncol; j++)
            if (a[i][j] < 0)    //Neu co phan tu mang gia tri am
            {
                cout << i + 1 << " ";   //Xuat ra so dong va chuyen sang xet dong tiep theo
                break;
            }
    cout << endl;
}

//Ham tim phan tu lon nhat tren duong cheo chinh trong ma tran
int LonNhatCheoChinh(_2dArr a, int n)
{
    int max = a[0][0];
    //Cac phan tu tren duong cheo chinh co dang a[i][i]
    for (int i = 1; i < n; i++)
        if (a[i][i] > max) max = a[i][i];   //Neu co phan tu lon hon max thi truyen phan tu do vao max
    return max;
}

//ham tim phan tu nho nhat tren duong cheo phu
int NhoNhatCheoPhu(_2dArr a, int n)
{
    int min = a[0][n - 1];
    //Cac phan tu tren duong cheo phu co dang a[i][n-1-i]
    for (int i = 1; i < n; i++)
        if (a[i][n - 1 - i] < min) 
            min = a[i][n - 1 - i]; //Neu co phan tu nho hon min thi truyen phan tu do vao min
    return min;
}

//Ham hoan doi gia tri cua hai so
void HoanDoi(int& a, int& b)
{
    double temp = a;   //Gan gia tri cua a vao bien phu temp
    a = b;  //Gan gia tri cua b vao a
    b = temp;   //Gan gia tri cua bien phu temp vao b
}

//ham sap xep cac phan tu tren duong cheo chinh theo thu tu giam dan
void SapXepGiamCheoChinh(_2dArr a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int max = a[i][i];       //So sanh max với các phần tử sau nó
            if (a[j][j] > max)  //neu tim duoc phan tu lon hon max thi hoan doi gia tri cua a[i][i] va a[j][j]
                HoanDoi(a[i][i], a[j][j]);
        }
    }
    cout << "Ma tran sau khi sap xep giam dan cac phan tu tren duong cheo chinh la: " << endl;
}

int main()
{
    _2dArr a;
    int nrow, ncol;
    NhapMang(a, nrow, ncol);

    //tinh tong cac phan tu duong trong ma tran
    cout << "Tong phan tu duong trong ma tran la: " << TongDuong(a, nrow, ncol) << endl;

    //dem so nguyen to trong ma tran
    cout << "So luong so nguyen to trong ma tran la: " << SoNguyenTo(a, nrow, ncol) << endl;

    //liet ke cac dong co phan tu am trong ma tran
    LietKeDongAm(a, nrow, ncol);

    if (ncol == nrow)   //Neu ma tran vua nhap la ma tran vuong
    {
        //phan tu lon nhat tren duong cheo chinh trong ma tran
        cout << "Phan tu lon nhat tren duong cheo chinh la: " << LonNhatCheoChinh(a, nrow) << endl;

        //phan tu nho nhat tren duong cheo phu
        cout << "Phan tu nho nhat tren duong cheo phu la: " << NhoNhatCheoPhu(a, nrow) << endl;

        //sap xep cac phan tu tren duong cheo chinh theo thu tu giam dan
        SapXepGiamCheoChinh(a, nrow);
        XuatMang(a, nrow, ncol);
    }
    else
        cout << "Mang ban vua nhap khong phai la mang vuong nen khong co duong cheo chinh va duong cheo phu!" << endl;
    
    return 0;
}

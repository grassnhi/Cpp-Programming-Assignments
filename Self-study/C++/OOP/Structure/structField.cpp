// The type of the fields of this struct are another struct
// Cấu trúc này có vùng tin thuộc kiểu cấu trúc khác

struct StructA
{
    /* data */
};

struct StructB
{
    // vùng tin
    ...

    // vùng tin thuộc kiểu StructA
    StructA field_name;

    // Hàm thành phần
    ...

    // Hàm tạo
    structure_name(...):field_name(...){
        . . .
    }
};

// => Example:

#include<iostream>
using namespace std;

struct NgayThang
{
    public:
        int Ngay, Thang, Nam;

    // Constructor:
    NgayThang(int dd, int mm, int yy){
        Ngay = dd;
        Thang = mm;
        Nam = yy;
    }

    // Default constructor:
    NgayThang(){
        Ngay = 12;
        Thang = 2;
        Nam = 2003;
    }

    ~ NgayThang(){
        cout << "Done!" << endl;
    }
};


struct SinhVien
{
    // Các vùng tin
    int MaSV;
    string HoTen;

    // Vùng tin kiểu cấu trúc NgayThang:
    NgayThang NgaySinh;

    // The first Constructor:
    SinhVien(int n, string ht, NgayThang ngSinh):NgaySinh(ngSinh.Ngay, ngSinh.Thang, ngSinh.Nam){
        MaSV = n;
        HoTen = ht;
    }

    // The second Constructor: (The structure NgayThang must have the default constructor)
    SinhVien(int n, string ht){
        MaSV = n;
        HoTen = ht;
    }

    // Hàm thành phần:
    void Display(){
        cout << "MSSV: " << MaSV << endl;
        cout << "Ho va ten: " << HoTen << endl; 
        cout << "Ngay sinh: " << NgaySinh.Ngay << "/" << NgaySinh.Thang << "/" << NgaySinh.Nam << endl;
    }

    // Hàm hủy:
    ~ SinhVien(){
        cout << "End!" << endl;
    }
};

int main(){
    SinhVien sv1(1, "NDDH");
    sv1.NgaySinh.Ngay = 16;
    sv1.NgaySinh.Thang = 2;
    sv1.NgaySinh.Nam = 2003;
    sv1.Display();

    NgayThang ngSinh(12, 2, 2003);
    SinhVien sv2(2, "NTTN", ngSinh);
    sv2.Display();

    return 0;
}
class ClassA{
    // Attributes:
    . . .

    // Methods:
    . . .

    // Constructor:
    public: ClassA(...){
        . . .
    }
};

class ClassB{
    // Attributes:
    . . .

    // Methods:
    . . .

    // Constructor:
    public: ClassB(...){
        . . .
    }
};

class ClassC{
    // Attributes:
    . . .

    // Has-a relatrionship or Composition:
    [access_specifier:] ClassA AttributeA; 
                        // khi khởi tạo object c của classC phải khỏi tạo object a của classA
    [access_specifier:] ClassB AttributeB;

    // Methods:
    . . .

    // Constructor:
    public: ClassC(...): AttributeA(...), AttributeB(...){
        . . .
    }
};

// => Example:

#include<iostream>
using namespace std;

class NgayThang{
    public:
        int Ngay, Thang, Nam;

        NgayThang(){
            Ngay = 12;
            Thang = 2;
            Nam = 2003;
        }

        NgayThang(int dd, int mm, int yy){
            Ngay = dd;
            Thang = mm;
            Nam = yy;
        }
};

class ThoiGian{
    public:
        int Gio, Phut, Giay;

        ThoiGian(){
            Gio = 0;
            Phut = 0;
            Giay = 0;
        }

        ThoiGian(int hh, int mm, int ss){
            Gio = hh;
            Phut = mm;
            Giay = ss;
        }
};

class SinhVien{
    private:
        int MaSV;
        string HoTen;

    public:
        NgayThang NgaySinh;

        ThoiGian GioSinh;

        SinhVien(int n, string ht){
            MaSV = n;
            HoTen = ht;
        }

        SinhVien(int n, string ht, NgayThang ngaySinh, ThoiGian gioSinh)
        :NgaySinh(ngaySinh.Ngay, ngaySinh.Thang, ngaySinh.Nam), 
         GioSinh(gioSinh.Gio, gioSinh.Phut, gioSinh.Giay){
            MaSV = n;
            HoTen = ht;
        }

        void Display(){
            cout << "MSSV: " << MaSV << endl;
            cout << "Ho va ten: " << HoTen << endl;
            cout << "Ngay sinh: " << NgaySinh.Ngay << "/" << NgaySinh.Thang << "/" << NgaySinh.Nam << endl;
            cout << "Gio sinh: " << GioSinh.Gio << ":" << GioSinh.Phut << ":" << GioSinh.Giay << endl;
        }

        ~ SinhVien(){
            cout << "Delete!" << endl;
        }
};

int main(){
    SinhVien sv1(1, "NDDH");
    sv1.NgaySinh.Ngay = 16;
    sv1.NgaySinh.Thang = 2;
    sv1.NgaySinh.Nam = 2003;
    sv1.GioSinh.Gio = 20;
    sv1.GioSinh.Phut = 30;
    sv1.GioSinh.Giay = 00;
    sv1.Display();

    NgayThang ngaySinh(12, 2, 2003);
    ThoiGian gioSinh(8, 30, 15);
    SinhVien sv2(2, "NTTN", ngaySinh, gioSinh);
    sv2.Display();

    return 0;
}

// Another example:

#include<iostream>
using namespace std;

class NgayThang{
    public:
        int Ngay, Thang, Nam;

        NgayThang(int dd, int mm, int yy){
            Ngay = dd;
            Thang = mm;
            Nam = yy;
        }

        NgayThang(const NgayThang& ngayThang){
            Ngay = ngayThang.Ngay;
            Thang = ngayThang.Thang;
            Nam = ngayThang.Nam;
        }

        ~ NgayThang(){
            cout << "Delete NT." << endl;
        }
};

class ThoiGian{
    public:
        int Gio, Phut, Giay;

        ThoiGian(int hh, int mm, int ss){
            Gio = hh;
            Phut = mm;
            Giay = ss;
        }

        ThoiGian(const ThoiGian* thoiGian){
            Gio = thoiGian->Gio;
            Phut = thoiGian->Phut;
            Giay = thoiGian->Giay;
        }

        ~ ThoiGian(){
            cout << "Delete GS." << endl;
        }
};

class SinhVien{
    public:
        int MaSV;
        string HoTen;

        NgayThang NgaySinh;
        
        ThoiGian GioSinh;

        SinhVien(int n, string ht, NgayThang ngaySinh, ThoiGian gioSinh)
        :NgaySinh(ngaySinh), GioSinh(gioSinh){
            MaSV = n;
            HoTen = ht;
        }

        void Display(){
            cout << "MSSV: " << MaSV << endl;
            cout << "Ho va ten: " << HoTen << endl;
            cout << "Ngay sinh: " << NgaySinh.Ngay << "/" << NgaySinh.Thang << "/" << NgaySinh.Nam << endl;
            cout << "Gio sinh: " << GioSinh.Gio << ":" << GioSinh.Phut << ":" << GioSinh.Giay << endl;
        }

        ~ SinhVien(){
            cout << "Done!" << endl;
        }
};

int main(){
    NgayThang ngaySinh(12, 2, 2003);
    ThoiGian gioSinh(8, 30, 15);
    SinhVien sv(2, "NTTN", ngaySinh, gioSinh);
    sv.Display();

    SinhVien sv1(1, "NDDH", )

    return 0;
}
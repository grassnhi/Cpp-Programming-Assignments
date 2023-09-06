// Abstract class -> abstract method (virtual method) -> method signature
// Base class -> Abstract Base Class ==> Derived class -> discrete class

// Pure virtual method/function (phương thức ảo thuần túy) => Pure Abstract Base Class (Pure ABC)

virtual return_type method_name([list_of_formal_parameters]) = 0;

// = 0 is pure specifier (chỉ định thuần túy)

#include<iostream>
using namespace std;

const double PI = 3.1415926535;

class HinhDang{
    virtual double DienTich() = 0; // khong co than phuong thuc

    public:
        string TenHinh;

        void Display(){
            cout << TenHinh << endl;
        }
};

class HinhTron: public HinhDang{
    public:
        double BanKinh;

        HinhTron(string ten, double bk){
            TenHinh = ten;
            BanKinh = bk;
        }

        virtual double DienTich(){
            double dt = PI * BanKinh * BanKinh;

            return dt;
        }
};

class HinhVuong: public HinhDang{
    public:
        double CanhVuong;

        HinhVuong(string ten, double canh){
            TenHinh = ten;
            CanhVuong = canh;
        }

        double DienTich(){
            double dt = CanhVuong * CanhVuong;

            return dt;
        }
};

int main(){
    double a = 5;

    HinhTron hTron("HT", a);
    hTron.Display();
    cout << hTron.TenHinh << " - " << hTron.DienTich() << endl;

    HinhVuong hVuong("HV", a);
    hVuong.Display();
    cout << hVuong.TenHinh << " - " << hVuong.DienTich() << endl;

    return 0;
}

// Abstract class:


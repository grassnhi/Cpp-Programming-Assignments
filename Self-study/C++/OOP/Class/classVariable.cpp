// Class variable ~ member variable but tồn tại độc lập # instance variable của object

// static data_type class_variable;

// // Gán giá trị ban đầu ngoài định nghĩa lớp (không gán trong khi khai báo)

// data_type class_name::class_variable = initial_value;

// => Example:

#include<iostream>
using namespace std;

class SinhVien{
    public:
        static int count; // gán value bên ngoài định nghĩa

        int MaSV;  // khong the gán value 
        string HoTen;

        SinhVien(string ht);

        void Display();
};

int SinhVien::count = 0;

SinhVien::SinhVien(string ht){
    ++count;

    MaSV = count;
    HoTen = ht;
}

void SinhVien::Display(){
    cout << "MSSV: " << MaSV << endl;
    cout << "Ho va ten: " << HoTen << endl;
}

int main(){
    SinhVien sv1("NTTH");
    sv1.Display();

    SinhVien sv2("NTTN");
    sv2.Display();

    cout << "Number: " << SinhVien::count << endl; //inhVien::count -> truy xuất biến lớp

    return 0;
}

// Không thể gán giá trị ban đầu cho instance variable nếu không là class variable
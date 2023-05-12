// Constant object: -> only call const method or const member function

const class_name object_name;
const class_name object_name(list_of_arguments);

// Constant method:

return_type method_name([list_of_parameters]) const {
    . . .
}

// Prototype (Mẫu phương thức hằng) -> phải có từ khóa const:

return_type method_name([list_of_parameters]) const;

// Constructor cannot be const method.


// => Example:

#include<iostream>
using namespace std;

class SinhVien{
    public:
        int MaSV;
        string HoTen;

        SinhVien(int n, string ht){
            MaSV = n;
            HoTen = ht;
        }

        void Display() const{
            cout << "MSSV: " << MaSV << endl;
            cout << "Ho va ten: " << HoTen << endl;
        }

        void SetMaSV(int n){ // khong the const vi thay doi value của attribute
            MaSV = n;
        }
};

int main(){
    SinhVien sv1(1, "NDDH");

    sv1.MaSV = 3;
    sv1.Display();

    sv1.SetMaSV(5);
    sv1.Display();

    const SinhVien sv2(2, "NTTN");
    sv2.Display();

    // vi sv2 là const nen khong the thay doi value của atrribute của object sv2

    return 0;
}

// Hoat tai phuong thuc

#include<iostream>
using namespace std;

class SinhVien{
    public:
        int MaSV;
        string HoTen;
        int Tuoi;

        SinhVien(int n, string ht, int t){
            MaSV = n;
            HoTen = ht;
            Tuoi = t;
        }

        int GetInfor() const{
            return Tuoi;
        }

        int GetInfor(){
            return MaSV;
        }
};

int main(){
    SinhVien sv1(1, "NDDH", 20);
    cout << "MSSV: " << sv1.GetInfor() << endl;

    const SinhVien sv2(2, "NTTN", 20);
    cout << "Tuoi: " << sv2.GetInfor() << endl;

    return 0;
}
//Khai báo và khởi tạo đối tượng (object) thuộc kiểu lớp (class)

class_name object_name([list_of_arguments]);

// Truy xuất:

object_name.member_variable;
object_name.method_name([list of arguments]);

// => Example:

#include<iostream>
using namespace std;

class SinhVien
{
    public:
        int MaSV;
        string HoTen;

    void Display(){
        cout << "MSSV: " << MaSV << endl;
        cout << "Ho va ten: " << HoTen << endl;
    }
};

int main(){
    SinhVien sv;
    sv.MaSV = 1;
    sv.HoTen = "NDDH";
    sv.Display();

    return 0;
}

// Private attributes need constructor to access

#include<iostream>
using namespace std;

class SinhVien
{
private:
    int MaSV;
    string HoTen;

public:
    // Create a method (constructor) to access private attribute
    SinhVien(int n, string ht){
        MaSV = n;
        HoTen = ht;
    }
    
    void Display(){
        cout << "MSSV: " << MaSV << endl;
        cout << "Ho va ten: " << HoTen << endl;
    }
};

int main(){
    SinhVien sv(2, "NTTN");
    sv.Display();

    return 0;
}


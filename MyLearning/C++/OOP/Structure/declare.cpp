// Khai báo và khỏi tạo biến cấu trúc => Structure Variable

struct structure_name
{
    . . . 
} list_of_structure_variables;

// => Example:

#include<iostream>
using namespace std;

struct SinhVien
{
    // Các vùng tin
    int MaSV;
    string HoTen;

    // Hàm thành phần:
    void Display(){
        cout << "MSSV: " << MaSV << endl;
        cout << "Ho va ten: " << HoTen << endl; 
    }
} sv1; // sv1: global variable

int main(){
    SinhVien sv2; // sv2: local variable

    // Assign value:
    sv1.MaSV = 1;
    sv1.HoTen = "NDH";

    sv2.MaSV = 2;
    sv2.HoTen = "NTTN";

    //Call function:
    sv1.Display();
    sv2.Display();

    return 0;
}

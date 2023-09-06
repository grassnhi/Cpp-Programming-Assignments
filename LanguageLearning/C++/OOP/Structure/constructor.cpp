// Define:

structure_name([list_of_parameters]){
    . . .
}

// Declare:

structure_name variable_name([list_of_argumants]);

// => Example:

#include<iostream>
using namespace std;

// Define
struct SinhVien
{
    int MaSV;
    string HoTen;

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
    // Declare:
    SinhVien sv(1, "NDDH");

    sv.Display();

    return 0;
}
// Define:

// ~ structure_name(){
//     . . .
// }

// Declare:

#include<iostream>
using namespace std;

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

    ~ SinhVien(){
        cout << "Done!" << endl;
    }
};

int main(){
    SinhVien sv(1, "NDDH");
    sv.Display();

    return 0;
}

#include<iostream>
using namespace std;

struct SinhVien
{
    int MaSV;
    string HoTen;
    string KyNang[10];
};

int main(){
    SinhVien sv[10];

    sv[0].MaSV = 1;
    sv[0].HoTen = "NTTH";
    sv[0].KyNang[0] = "An";
    sv[0].KyNang[1] = "Ngu";
    sv[0].KyNang[2] = "Choi";

    cout << sv[0].HoTen << " - " << sv[0].MaSV << " - " << sv[0].KyNang[2] << endl;

    return 0;
}


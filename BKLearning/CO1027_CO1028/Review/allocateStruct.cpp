#include<iostream>

using namespace std;

struct Date
{
    int Day;
    int Month;
    int Year;
};

struct SinhVien
{
    int Masv;
    string HoTen;
    
    void Display(){
        cout << Masv << " " << HoTen << endl;
    }
} svien;


int main(){
    int* p = new int;
    *p = 10;
    delete p;

    Date* q;
    q = new Date;
    q->Day = 20;
    q->Month = 11;
    q->Year = 2022;
    cout << q->Day << "/" << q->Month << "/" << q->Year <<endl;
    delete q;

    int* pointer = new int[3];
    pointer[1] = 10;
    delete[] pointer;

    SinhVien* sv = new SinhVien[5];
    sv[0].Masv = 1;
    sv[0].HoTen = "Thao Nhi";
    cout << sv[0].Masv << ". " << sv[0].HoTen << endl;
    sv[0].Display();
    delete[] sv;

    svien.Masv = 0;
    svien.HoTen = "Nhi";
    svien.Display();

    Date* sn = new Date[3];
    sn[0].Day = 12;
    sn[0].Month = 2;
    sn[0].Year = 2003;
    cout << sn[0].Day << "/" << sn[0].Month << "/" << sn[0].Year << endl;
    delete[] sn;

    return 0;
}
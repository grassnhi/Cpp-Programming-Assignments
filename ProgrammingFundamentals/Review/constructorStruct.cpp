#include<iostream>

using namespace std;

struct Date
{
    int Day;
    int Month;
    int Year;

    Date(int Day, int Month, int Year){
        this->Day = Day;
        this->Month = Month;
        this->Year = Year;
    }

    Date(){
        Day = 2;
        Month = 9;
        Year = 2010;
    }
};

struct SinhVien
{
    int Masv;
    string HoTen;
    Date born;

    SinhVien(int Masv, string HoTen, Date bornDate) : born(bornDate.Day, bornDate.Month, bornDate.Year) {
        this->Masv = Masv;
        this->HoTen = HoTen;
    }

    SinhVien(int Masv, string HoTen){
        this->Masv = Masv;
        this->HoTen = HoTen;
    }

    void Display(){
        cout << Masv << " " << HoTen << endl;
        cout << born.Day << "/" << born.Month << "/" << born.Year << endl;
    }

    ~SinhVien(){
        cout << "End!" << endl;
    }
};

void Test(){
    SinhVien sv(1, "Thao Nhi");
    sv.Display();

    
}

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

    Date* sn = new Date[3];
    sn[0].Day = 12;
    sn[0].Month = 2;
    sn[0].Year = 2003;
    cout << sn[0].Day << "/" << sn[0].Month << "/" << sn[0].Year << endl;
    delete[] sn;

    Test();
    
    return 0;
}
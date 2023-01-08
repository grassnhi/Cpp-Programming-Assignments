#include<iostream>
#include<vector>
using namespace std;

class HinhDang{
    public: virtual void Display() = 0;
};

class HinhVuong : public HinhDang{
    public:
        void Display(){
            cout << "HV1" << endl;
        }
};

class HinhTron : public HinhDang{
    public:
        void Display(){
            cout << "HT2" << endl;
        }
};

class HinhChuNhat : public HinhDang{
    public:
        void Display(){
            cout << "HCN3" << endl;
        }
};

void ViaPointer(HinhDang* hinh){
    hinh->Display();
}

void ViaReference(HinhDang& hinh){
    hinh.Display();
}

int main(){
    HinhVuong dt1;
    HinhTron dt2;
    HinhChuNhat dt3;

    dt1.Display();
    dt2.Display();
    dt3.Display();

    cout << endl;

    int n = 3;
    vector <HinhDang*> cacHinh(n);
    cacHinh[0] = &dt1;
    cacHinh[1] = &dt2;
    cacHinh[2] = &dt3;

    cout << endl;

    for(int i = 0; i < n; i++){
        ViaPointer(cacHinh[i]);
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        ViaReference(*cacHinh[i]);
    }

    return 0;
}
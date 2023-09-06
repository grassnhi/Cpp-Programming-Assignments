// Operator overloading -> part of polymorphism

public: return_type operator symbol([list_of_parameters]){
    . . .
}

// Unary operator (Toán tử một ngôi) => có 1 toán hạng
// ++, --, -, !

#include<iostream>
using namespace std;

class SoPhuc{
    public:
        double PhanThuc;
        double PhanAo;

    SoPhuc(double thuc, double ao){
        PhanThuc = thuc;
        PhanAo = ao;
    }

    void Display(){
        if(PhanAo > 0)
            cout << PhanThuc << "+ i * " << PhanAo;
        else
            cout << PhanThuc << "- i * " << PhanAo;
    }

    SoPhuc operator - (){ // số đối của số phức
        SoPhuc kq(0, 0);
        kq.PhanThuc = - this->PhanThuc;
        kq.PhanAo = - this->PhanAo;

        return kq;
    }
};

int main(){
    double x, y;
    x = 10;

    y = -x;

    cout << "y = " << y << endl;

    SoPhuc a(1, 2);

    SoPhuc b = -a;

    cout << "So phuc a = " << endl;
    a.Display();

    cout << "So phuc b = " << endl;
    b.Display();

    return 0;
}

// Binary operator (Toán tử hai ngôi) có 2 toán hạng
// +, -, *, /

#include<iostream>
using namespace std;

class SoPhuc{
    public:
        double PhanThuc, PhanAo;

        SoPhuc(double thuc, double ao){
            PhanThuc = thuc;
            PhanAo = ao;
        }

        void Display(){
            if(PhanAo > 0){
                cout << PhanThuc << " + i * " << PhanAo << endl;
            }else
                cout << PhanThuc << " - i * " << - PhanAo << endl;
        }

        SoPhuc operator + (const SoPhuc& b){
            SoPhuc kq(this->PhanThuc + b.PhanThuc, this->PhanAo + b.PhanAo);

            return kq;
        }
};

int main(){
    double x, y, z;

    x = 10;
    y = 20;
    z = x + y;

    cout << x << " + " << y << " = " << z << endl;

    SoPhuc a(1, 2);
    SoPhuc b(5, 7);
    SoPhuc c = a + b;

    cout << "So phuc a = ";
    a.Display();

    cout << "So phuc b = ";
    b.Display();

    cout << "So phuc c = ";
    c.Display();

    return 0;
}

// Comparison operator (Toán tử so sánh) có 2 toán hạng
// <, <=, >, >=, ==, !=

#include<iostream>
using namespace std;

class HocLuc{
    public:
        double DiemTB;
        int SoMon;

        HocLuc(double diem, int SoMon){
            DiemTB = diem;
            SoMon = SoMon;
        }

        bool operator < (const HocLuc& b){
            bool kq;

            if(DiemTB < b.DiemTB)
                kq = true;
            else if((DiemTB == b.DiemTB) && (SoMon < b.SoMon))
                kq = true;
            else
                kq = false;
            
            return kq;
        }
};

int main(){
    double x, y;
    x = 10;
    y = 20;

    if(x < y)
        cout << "x < y" << endl;
    else 
        cout << "x >= y" << endl;

    HocLuc a(7.5, 5);
    HocLuc b(6.0, 10);
    HocLuc c(7.5, 8);

    if (a < b) 
        cout << "a < b" << endl;
    else
        cout << "a >= b" << endl;

    if (a < c) 
        cout << "a < c" << endl;
    else
        cout << "a >= c" << endl;

    return 0;
}

// ++

#include<iostream>
using namespace std;

class ThoiGian{
    private:
        int Gio;
        int Phut;

    public:
        ThoiGian(int hh, int mm){
            Gio = hh;
            Phut = mm;
        }

        void Display(){
            cout << Gio << ":" << Phut << endl;
        }

        ThoiGian operator ++ (){
            ++Phut;
            if(Phut >= 60){
                ++Gio;
                Phut = 0;
            }

            return ThoiGian(Gio, Phut);
        }

        ThoiGian operator ++ (int){ // tăng hậu tố
            ThoiGian t(Gio, Phut); // lưu và trả về thời gian ban đầu khi chưa tăng

            ++Phut;
            if(Phut >= 60){
                ++Gio;
                Phut = 0;
            }

            return t;
        }
};

int main(){
    int i = 1;
    ++i;
    cout << "i = " << i << endl;

    ThoiGian t1(11, 59);
    ThoiGian t2(10, 40);

    cout << "t1 = ";
    t1.Display();

    ThoiGian tt1 = ++t1;
    cout << "tt1 = ";
    tt1.Display();
    cout << "t1 = ";
    t1.Display();

    ++t1;
    cout << "t1 = ";
    t1.Display();

    cout << "t2 = ";
    t2.Display();

    ThoiGian tt2 = t2++;
    cout << "tt2 = ";
    tt2.Display();
    cout << "t2 = ";
    t2.Display();

    t2++;
    cout << "t2 = ";
    t2.Display();

    return 0;
}

// Function call operator -> () -> (Toán tử gọi hàm)

#include<iostream>
using namespace std;

class SoPhuc{
    public:
        double PhanThuc;
        double PhanAo;

        SoPhuc(double thuc, double ao){
            PhanThuc = thuc;
            PhanAo = ao;
        }

        void Display(){
            cout << PhanThuc << " + i * " << PhanAo << endl;
        }

        SoPhuc operator () (double x){
            SoPhuc kq(PhanThuc + x, PhanAo + x);

            return kq;
        }
};

int main(){
    SoPhuc a(1, 2);

    SoPhuc b = a(10); // a: object, () -> operator

    cout << "a = ";
    a.Display();

    cout << "b = ";
    b.Display();

    return 0;
}

// =

#include<iostream>
using namespace std;

class SoPhuc{
    public:
        double PhanThuc;
        double PhanAo;

        SoPhuc(double thuc, double ao){
            PhanThuc = thuc;
            PhanAo = ao;
        }
        
        void Display(){
            cout << PhanThuc << " + i * " << PhanAo << endl;
        }

        void operator = (const SoPhuc& a){
            PhanThuc = a.PhanThuc;
            PhanAo = a.PhanAo;
        }
};

int main(){
    SoPhuc a(1, 2);
    SoPhuc b(5, 7);

    cout << "a = ";
    a.Display();

    cout << "b = ";
    b.Display();

    b = a;
    b.Display();

    return 0;
}

// Subscript operator [] (Toán tử chỉ số) => mở rộng tính năng mảng

#include<iostream>
using namespace std;

const int N = 5;

class Mang{
    public:
        int Arr[N];

        Mang(){
            for(int i = 0; i < N; i++){
                Arr[i] = i;
            }
        }

        int& operator [] (int i){
            if((Arr[i] != NULL) && (i >= 0) && (i < N))
                return Arr[i];
            else{
                //cout << "i outside the array." << endl;

                return Arr[0];
            }
        }
};

int main(){
    Mang a;

    cout << "a[1] = " << a.Arr[1] << endl;

    a[2] = 12;
    cout << "a[2] = " << a[2] << endl;

    a.Arr[4] = 1202;
    cout << "a[4] = " << a[4] << endl;

    cout << "a[6] = " << a[6] << endl;

    return 0;
}
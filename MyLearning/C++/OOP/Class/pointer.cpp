// New => tạo object được tham khảo bằng pointer
// -> => toán tử tham khảo

class_name* pointer_name;
pointer_name = new class_name([list_of_arguments]);

// Hoặc:

class_name* pointer_name = new class_name([list_of_arguments]);

// delete => hủy object được tham khảo bằng pointer

delete pointer_name;

/*
Nếu p => pointer
    *p => object
    &p => address
    p->A => attribute A of object
    (*p).A => attribute A of object
    p[i] => object thứ (i+1) của mảng mà p trở đến 
*/

// => Example:

#include<iostream>
using namespace std;

class NgayThang{
    public:
        int Ngay, Thang, Nam;

        NgayThang(int dd, int mm, int yy);

        void Display();
};

void NgayThang::Display(){
    cout << Ngay << "/" << Thang << "/" << Nam << endl;
}

NgayThang::NgayThang(int dd, int mm, int yy){
    Ngay = dd;
    Thang = mm;
    Nam = yy;
}

int main(){
    NgayThang ngth(12, 2, 2003);

    NgayThang* p = new NgayThang(15, 07, 2007);

    // Truy xuất:
    cout << "Ngay: " << (*p).Ngay << endl;
    cout << "Thang: " << p->Thang << endl;
    cout << "Nam: " << p[0].Nam << endl; // Object thứ (0+1) = 1, attribute Nam = 2003

    cout << "Dia chi: " << &p << endl;

    *p = ngth;
    p->Display();

    return 0;
}
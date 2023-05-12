#include<iostream>
using namespace std;

class NgayThang{
    private:
        int Ngay;
        int Thang;
        int Nam;
    
    public:
        NgayThang(int dd, int mm, int yy){
            Ngay = dd;
            Thang = mm;
            Nam = yy;
        }

        NgayThang(NgayThang & ngay){ // tham khảo đến đối tượng kiểu NgayThang
            Ngay = ngay.Ngay; // truy xuất phần private của đối tượng
            Thang = ngay.Thang;
            Nam = ngay.Nam;
        }

        void Display(){
            cout << Ngay << "/" << Thang << "/" << Nam << endl;
        }
};

int main(){
    NgayThang ngay1(12, 2, 2003);
    ngay1.Display();

    NgayThang ngay2(ngay1);
    ngay2.Display();

    return 0;
}
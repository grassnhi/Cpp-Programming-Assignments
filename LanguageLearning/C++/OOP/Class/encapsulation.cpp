class class_name{
    public: // => interface
        public_members // có thể sử dụng bên ngoài class mà không qua method
    protected:
        protected_members 
    private: // => internal data
        private_members // method của lớp và lớp bạn mới có thể truy xuất
}

// => Example:

#include<iostream>
using namespace std;

class SinhVien{
    private:
        int MaSV;
        string HoTen;
    public:
        SinhVien(int n, string ht);
        void Display();
        // method set => assign value for private member => mutator method (phương thức hiệu chỉnh)
        void setHoTen(string ht); 
        // get => accessor method (phương thức truy xuất) => collect value of private data members
        string getHoTen();
};

SinhVien::SinhVien(int n, string ht){
    MaSV = n;
    HoTen = ht;
}

void SinhVien::setHoTen(string ht){
    HoTen = ht;
}

string SinhVien::getHoTen(){
    return HoTen;
}

void SinhVien::Display(){
    cout << "MSSV: " << MaSV << endl;
    cout << "Ho va ten: " << HoTen << endl;
}

int main(){
    SinhVien sv(1, "NDDH");
    sv.Display();

    sv.setHoTen("NTTN");

    cout << "Ho va ten: " << sv.getHoTen() << endl;

    sv.Display();

    return 0;
}
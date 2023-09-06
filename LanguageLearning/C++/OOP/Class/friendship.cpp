// Truy xuất private, protected, public

class ClassA{
    friend class ClassB;
    friend class ClassC;
    . . .
};

class ClassB{
    . . .
};

class ClassC{
    . . .
};

// => Example:

#include<iostream>
using namespace std;

class NhanVien{
    friend class KhachHang;
    friend class NhaCungCap;

    private:
        int MaNV;
        string HoTen;

    public:
        NhanVien(int n, string ht){
            MaNV = n;
            HoTen = ht;
        }
};

class KhachHang{
    public:
        int MaKH;
        string TenKH;
        int MaNV;

        KhachHang(int n, string ten, NhanVien nv){
            MaKH = n;
            TenKH = ten;
            MaNV = nv.MaNV;
        }
};

class NhaCungCap{
    public:
        int MaNCC;
        string TenNCC;
        int MaNV;

        NhaCungCap(int n, string ten, NhanVien nv){
            MaNCC = n;
            TenNCC = ten;
            MaNV = nv.MaNV;
        }
};

int main(){
    NhanVien nv(1, "NTTH");
    KhachHang kh(11, "NTTN", nv);
    NhaCungCap ncc(0, "NDDH", nv);

    cout << "KH: " << kh.MaKH << " - NV: " << kh.MaNV << endl;
    cout << "NCC: " << ncc.MaNCC << " - NV: " << ncc.MaNV << endl;

    return 0;
}
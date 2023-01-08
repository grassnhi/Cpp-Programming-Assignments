// Define:

class derivedclass_name:[access_specifier] baseclass_name{
    // Attribute:
    . . .

    // Methods:
    . . .
} [list_of_objects];

// Single Inheritance: 1 lớp dẫn xuất thừa kế từ 1 base class

#include<iostream>
using namespace std;

class DaGiac{
    protected:
        double ChieuDai;
        double ChieuCao;
    
    public:
        void Set(double dai, double cao){
            ChieuDai = dai;
            ChieuCao = cao;
        }
};

class ChuNhat: public DaGiac{
    public:
        double DienTich(){
            double dt = ChieuDai*ChieuCao;
            return dt;
        }
};

class TamGiac: public DaGiac{
    public:
        double DienTich(){
            double dt = (ChieuDai*ChieuCao) / 2;
            return dt;
        }
};

int main(){
    ChuNhat hcn;
    hcn.Set(8, 4);

    TamGiac htg;
    htg.Set(8, 4);

    double dthcn = hcn.DienTich();
    cout << "S_hcn = " << dthcn << endl;

    double dthtg = htg.DienTich();
    cout << "S_htg = " << dthtg << endl;

    return 0;
}

/*
Public inheritance: 
    - Thừa kế: public => public && protected => protected
    - Truy xuất private gián tiếp qua public/ protected method của base class

Protected inheritance:
    - Thừa kế: public + protected => protected

Private inheritance:
    - Thừa kế: public + protected => private

Cannot inheritance:
    - Constructor & Destructor & Copy constructor
    - Operator overloading
    - Friend function
*/

// Proctected:

#include<iostream>
using namespace std;

class NhanVien{
    protected:
        int MaNV;
        string HoTen;

        NhanVien(int ma, string ht){
            MaNV = ma;
            HoTen = ht;
        }
        
    public:
        int GetMaNV(){
            return MaNV;
        }

        string GetHoTen(){
            return HoTen;
        }

        string LoaiNV(){
            return "Nhan vien.";
        }
};

class GiangVien:public NhanVien{
    protected:
        string BoMon;

        GiangVien(int ma, string ht, string bm):NhanVien(ma, ht){
            BoMon = bm;
        }

        string LoaiGV(){
            return "GV.";
        }

    public:
        string GetBoMon(){
            return BoMon;
        }
};

class CBQLGV:public GiangVien{
    public:
        string PhongBan;

        CBQLGV(int ma, string ht, string bm, string pb):GiangVien(ma, ht, bm){
            PhongBan = pb;
        }

        string LoaiCBQL(){
            return "CBQL.";
        }
};

int main(){
    CBQLGV cbgv(1, "NTTH", "KHMT", "MT");

    cout << "MNV: " << cbgv.GetMaNV() << endl;
    cout << "Ho ten: " << cbgv.GetHoTen() << endl;
    cout << "Bo mon: " << cbgv.GetBoMon() << endl;
    cout << "Phong ban: " << cbgv.PhongBan << endl;

    return 0;
}

// Private:

#include<iostream>
using namespace std;

class NhanVien{
    protected:
        int MaNV;
        string HoTen;

    private:
        int Tuoi;

    public:
        NhanVien(int ma, string ht, int t){
            MaNV = ma;
            HoTen = ht;
            SetTuoi(t);
        }

        void SetTuoi(int t){
            if(t < 0){
                Tuoi = 0;
            }else
                Tuoi = t;
        }

        int GetTuoi(){
            return Tuoi;
        }
};

class GiangVien:public NhanVien{
    public:
        int MaBM;

        GiangVien(int ma, string ht, int bm, int t):NhanVien(ma, ht, t){
            MaBM = bm;
        }
};

int main(){
    GiangVien gv(1, "NTTN", 10, 10);

    return 0;
}

// Multiple inheritance: 1 lớp dẫn xuất thừa kế từ 2 or nhiều base class

class derivedclass_name:[access_speticifier] baseclass_name, 
                        [access_specifier] baseclass_name, ...{
    // Attributes:
    . . .

    // Methods:
    . . .
};

// => Example:

#include<iostream>
using namespace std;

class DaGiac{
    protected:
        double ChieuDai;
        double ChieuRong;

    public:
        void Set(double dai, double rong){
            ChieuDai = dai;
            ChieuRong = rong;
        }
};

class ChiPhi{
    public:
        double TienCong(double dienTich){
            double tien = dienTich * 100;
            return tien;
        }
};

class ChuNhat: public DaGiac, public ChiPhi{
    public:
        double DienTich(){
            double dt = ChieuDai * ChieuRong;

            return dt;
        }
};

int main(){
    ChuNhat matTuong;

    matTuong.Set(3,8);

    double dt = matTuong.DienTich();
    cout << "S = " << dt << endl;

    double tienCong = matTuong.TienCong(dt);
    cout << "M = " << tienCong << endl;

    return 0;
}

// Constructor cannot inheritance => Call baseclass-constructor: declare public

derivedclass_constructor(...):baseclass_constructor(...){
    . . .
}

// => Example:

#include<iostream>
using namespace std;

class NhanVien{
    private:
        int MaNV;
        string HoTen;

    public:
        NhanVien(int ma, string ht){
            MaNV = n;
            HoTen = ht;
        }

        void DisplayNV(){
            cout << "MNV: " << MaNV << endl;
            cout << "Ten: " << HoTen << endl;
        }
};

class CanBo: public NhanVien{
    private:
        int PhuCap;

    public:
        CanBo(int ma, string ht, int pcap):NhanVien(ma, ht){
            PhuCap = pcap;
        }

        void DisplayCB(){
            DisplayNV();
            cout << "Phu cap: " << PhuCap << endl;
        }
};

int main(){
    NhanVien nv(1, "NTTH");
    nv.DisplayNV();

    CanBo cb(2, "NTTN", 500);
    cb.DisplayCB();

    return 0;
}
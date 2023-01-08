// Redefine method: derived class redefine method của base class

derived_object.baseclass_name::method_name(...)

// => Example:

#include<iostream>
using namespace std;

class NhanVien{
    public:
        int MaNV;
        string HoTen;

        NhanVien(int ma, string ht){
            MaNV = ma;
            HoTen = ht;
        }

        string Type(){
            return "NV.";
        }

        void DisplayNV(){
            cout << "MSNV: " << MaNV << endl;
            cout << "Ten: " << HoTen << endl;
        }
};

class GiangVien: public NhanVien{
    public:
        int GioDay;

        GiangVien(int ma, string ht, int gday): NhanVien(ma, ht){
            GioDay = gday;
        }

        // Redefine method Type:
        string Type(){
            return "GV.";
        }

        void DisplayGV(){
            DisplayNV();
            cout << "So gio: " << GioDay << endl;
        }
};

class CBQLGV: public GiangVien{
    public:
        int GioTruc;

        CBQLGV(int ma, string ht, int gday, int gtruc): GiangVien(ma, ht, gday){
            GioTruc = gtruc;
        }

        // Redefine method Type:
        string Type(){
            return "CBQL.";
        }

        void DisplayCBQLGV(){
            DisplayGV();
            cout << "Truc: " << GioTruc << endl;
        }
};

int main(){
    NhanVien nv(1, "NTTH");
    GiangVien gv(2, "NTTN", 12);
    CBQLGV cbgv(3, "NDDH", 16, 2);

    nv.DisplayNV();
    cout << nv.Type() << endl;

    gv.DisplayGV();
    cout << gv.Type() << " ss " << gv.NhanVien::Type() << endl;

    cbgv.DisplayCBQLGV();
    cout << cbgv.Type() << " - " << cbgv.GiangVien::Type() << " - " << cbgv.NhanVien::Type() << endl;

    nv = cbgv;
    cout << nv.Type() << endl;

    NhanVien& nv1 = gv;
    cout << nv1.Type() << endl;
    nv1.HoTen = "NHI";
    gv.DisplayGV();

    GiangVien* gv2 = &cbgv;
    gv2->DisplayGV();
    cout << gv2->Type() << endl;
    cbgv.DisplayCBQLGV();

    return 0;
}

// Virtual method or virtual function => method overriden in base class by method signature

public: virtual return_type method_name(...){
    . . .
};

// Overriden base class virtual method => virtual

#include<iostream>
using namespace std;

class NhanVien{
    
}

// => Example:

#include<iostream>
using namespace std;

class NhanVien{
    public:
        int MaNV;
        string HoTen;

        NhanVien(int ma, string ht){
            MaNV = ma;
            HoTen = ht;
        }

        virtual string Type(){
            return "NV!";
        }

        void Display(){
            cout << "MSNV: " << MaNV << endl;
            cout << "Ten: " << HoTen << endl;
        }
};

class GiangVien: public NhanVien{
    public:
        GiangVien(int ma, string ht):NhanVien(ma, ht){}

        virtual string Type(){
            return "GV!";
        }
};

int main(){
    GiangVien gv(1, "NTTH");
    gv.Display();

    NhanVien nv = gv;
    nv.Display();
    cout << "Type: " << nv.Type() << endl;

    return 0;
}

// if not override base class virtual method => inheritance 

#include<iostream>
using namespace std;

class NhanVien{
    public:
        int MaNV;
        string HoTen;

        NhanVien(int ma, string ht){
            MaNV = ma;
            HoTen = ht;
        }

        virtual string Type(){
            return "NV!";
        }

        void Display(){
            cout << "MSNV: " << MaNV << endl;
            cout << "Ten: " << HoTen << endl;
        }
};

class GiangVien: public NhanVien{
    public:
        GiangVien(int ma, string ht):NhanVien(ma, ht){ }
};

class GVThucHanh: public GiangVien{
    public:
        GVThucHanh(int ma, string ht): GiangVien(ma, ht){ }
        
        virtual string Type(){
            return "GVTH";
        }
};

int main(){
    GiangVien gv(1, "NTTH");
    gv.Display();
    cout << "Type: " << gv.Type() << endl;

    GVThucHanh gvth(2, "NTTN");
    gvth.Display();
    cout << "Type: " << gvth.Type() << endl;

    return 0;
}

// Static bingding (gán base = devired => call base's) and dynamic bingding (=> call derived's)

#include<iostream>
using namespace std;

class NhanVien{
    public:
        int MaNV;
        string HoTen;

        NhanVien(int ma, string ht){
            MaNV = ma;
            HoTen = ht;
        }

        virtual string Type(){
            return "NV!";
        }

        void Display(){
            cout << "MSNV: " << MaNV << endl;
            cout << "Ten: " << HoTen << endl;
        }
};

class GiangVien: public NhanVien{
    public:
        GiangVien(int ma, string ht): NhanVien(ma, ht){ }

        virtual string Type(){
            return "GV!";
        }
};

class GVThucHanh: public GiangVien{
    public:
        GVThucHanh(int ma, string ht): GiangVien(ma, ht){}

        virtual string Type(){
            return "GVTH!";
        }
};

int main(){
    GVThucHanh gvth(1, "NTTH");

    NhanVien nv = gvth; // Gán object => tĩnh
    nv.Display();
    cout << "Type: " << nv.Type() << endl;

    NhanVien& nv2 = gvth; // Gán reference => gắn kết động
    nv2.Display();
    cout << nv2.Type() << endl;

    NhanVien* pnv = &gvth; // Gán pointer => Động
    pnv->Display();
    cout << pnv->Type() << endl;

    return 0;
}

// & baseclassO = a => call A's virtual ?? & baseclassO = b => call A's virtual
// * baseclassO = a => call A's virtual ?? * baseclassO = b => call A's virtual
// Tham khao không thể bị thay đổi, pointer có thể bị thay đổi

#include<iostream>
using namespace std;

class NhanVien{
    public:
        int MaNV;
        string HoTen;

        NhanVien(int ma, string ht){
            MaNV = ma;
            HoTen = ht;
        }

        virtual string Type(){
            return "NV";
        }

        void Display(){
            cout << "MSNV: " << MaNV << endl;
            cout << "Ten: " << HoTen << endl;
        }
};

class GiangVien: public NhanVien{
    public:
        GiangVien(int ma, string ht): NhanVien(ma, ht){ }

        virtual string Type(){
            return "GV";
        }
};

class GVThucHanh: public GiangVien{
    public:
        GVThucHanh(int ma, string ht): GiangVien(ma, ht){ }

        virtual string Type(){
            return "GVTH";
        }
};

int main(){
    GiangVien gv(1, "NTTH");

    GVThucHanh gvth(2, "NTTN");

    NhanVien& nv = gvth;
    nv.Display();
    cout << nv.Type() << endl;

    nv = gv;
    nv.Display();
    cout << nv.Type() << endl;

    GVThucHanh gvth2(3, "NDDH");

    NhanVien* pnv = &gvth2;
    pnv->Display();
    cout << pnv->Type() << endl;

    pnv = &gv;
    pnv->Display();
    cout << pnv->Type() << endl;

    return 0;
}
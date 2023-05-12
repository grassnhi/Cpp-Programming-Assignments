#include<iostream>
using namespace std;

class SinhVien
{
public:
    int MaSV;
    string HoTen;

    SinhVien(){
        MaSV = 0;
        HoTen = "";
    }

    void Set(int n, string ht){
        MaSV = n;
        HoTen = ht;
    }

    void Display(){
        cout << "MSSV: " << MaSV << endl;
        cout << "Ho va ten: " << HoTen << endl;
    }
};

class DanhSach{
    static const int SoSV = 5;

    public:
        SinhVien DSSV[SoSV]; // array

        SinhVien FindSV(int n){ 
            //Find sv have mssv: n or not => object type class SinhVien or object have mssv 0
            SinhVien kq;

            bool found = 0;

            int i = 0;

            while ((i < SoSV) && (!found)) // !found means found == 0
            {
                if(DSSV[i].MaSV == n){
                    found = true;
                    kq = DSSV[i];
                }
                else
                    i++;
            }
            
            return kq;
        }
        
        // Find a sv, object sv have type class SinhVien
        bool Finding(const SinhVien sv){
            bool found = false;

            int i = 0;
            while ((i < SoSV) && (!found))
            {
                if(DSSV[i].MaSV == sv.MaSV){
                    found = true;
                }
                else 
                    i++;
            }

            return found;
        }
};


int main(){
    DanhSach ds; // Create ds

    // Class ds have the method class SinhVien named DSSV => access => assign
    // Class SinhVien have the method Set => access and assign there
    ds.DSSV[0].Set(1, "NDDH");
    ds.DSSV[1].Set(2, "NTTN");
    ds.DSSV[2].Set(3, "NTTH");

    int n = 3;

    // Find sv have mssv = n
    SinhVien sv = ds.FindSV(n);

    if(sv.MaSV == 0)
        cout << "Cannot find!" << endl;
    else
        sv.Display();

    // Sssgignment:
    sv.Set(2, "NTTN");

    //Find whether sv in the ds
    bool found = ds.Finding(sv);

    if(found)
        cout << "Found!" << endl;
    else
        cout << "Cannot find!" << endl;

    return 0;
}



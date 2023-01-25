// Giải thuật đệ quy vs Vòng+Chồng

// Đệ quy:
#include<iostream>
using namespace std;

void DiChuyen(int n, int bd, int tg, int kt){
    // n = số tầng
    if(n == 1)
        cout << bd << "->" << kt << endl;
    else{
        DiChuyen(n-1, bd, kt, tg);
        DiChuyen(1, bd, tg, kt);
        DiChuyen(n-1, tg, bd, kt);
    }
}

int main(){
    int n = 3;

    DiChuyen(n, 1, 2, 3);

    return 0;
}

// Lặp vòng + Chồng
#include<iostream>
using namespace std;

struct Item{
    int SoTang, BatDau, TrungGian, KetThuc;
    ptr Link;
};

void Init(ptr& sp){
    sp = NULL;
}

bool IsEmpty(ptr sp){
    return sp == NULL;
}

void Push(ptr& sp, int n, int bd, int tg, int kt){
    ptr q = new Item;
    q->SoTang = n;
    q->BatDau = bd;
    q->TrungGian = tg;
    q->KetThuc = kt;

    q->Link = sp;
    sp = q;
}

void Pop(ptr& sp, int n, int bd, int tgm int kt){
    ptr p = sp;

    n = p->SoTang;
    bd = p->BatDau;
    tg = p->TrungGian;
    kt = p->KetThuc;

    sp = p->Link;
    delete p;
}

int main(){
    ptr sp;
    Init(sp);

    int n = 3;
    int bd, tg, kt;

    Push(sp, n, 1, 2, 3);

    while (!IsEmPty(sp))
    {
        Pop(sp, n, bd, tg, kt);

        if(n == 1)
            cout << bd << "->" << kt << endl;
        else{
            Push(sp, n-1, tg, bd, kt);
            Push(sp, 1, bd, tg, kt);
            Push(sp, n-1, bd, kt, tg);
        }
    }
    
    return 0;
}
// Constructor and Destructor:
// Define:

public: class_name([list_of_parameters]){
    . . .
}

~ class_name(){
    . . .
}

// Declare:

class_name object_name[([list_of_arguments])];

// For the default constructor:

class_name object_name;

/*
Object of A Constructor = aninstance
Attribute of A Constructor = member variable # class variable
*/

// => Example and 2 of these are the same:

NgayThang::NgayThang(int dd, int mm, int yy){
    Ngay = dd;
    Thang = mm;
    Nam = yy;
    cout << "Ngay: " << Ngay << "/" << Thang << "/" << Nam << endl;
}

NgayThang::NgayThang(int dd, int mm, int yy):Ngay(dd), Thang(mm), Nam(yy){
    cout << "Ngay: " << Ngay << "/" << Thang << "/" << Nam << endl;
}

// Full example:

#include<iostream>
using namespace std;

class NgayThang{
    private:
        int Ngay, Thang, Nam;

    public:
        NgayThang(int dd, int mm, int yy);
        ~ NgayThang();
        
        void Display();
};

// Constructor:
NgayThang::NgayThang(int dd, int mm, int yy){
    Ngay = dd;
    Thang = mm;
    Nam = yy;
}

// Destructor:
NgayThang::~NgayThang(){
    cout << "Done!" << endl;
}

// Method Display:
void NgayThang::Display(){
    cout << "Ngay: " << Ngay << "/" << Thang << "/" << Nam << endl;
}

int main(){
    NgayThang ngth(12, 2, 2003);
    ngth.Display();

    return 0;
}
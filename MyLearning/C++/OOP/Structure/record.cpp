// Define: -> struct -> định nghĩa kiểu bản ghi

struct record_name
{
    field_type field_name;
    . . .
};

struct record_name
{
    field_type field_name;
    . . .
} variable_name_1, variable_name_2 ... ;

// Truy xuất:

variable_name.field_name;

// => Example:

#include<iostream>
using namespace std;

struct SinhVien
{
    int MaSV;
    string HoTen;
};

int main(){
    SinhVien sv;
    sv.MaSV = 1;
    sv.HoTen = "NTTH";

    cout << sv.HoTen << " - " << sv.MaSV;

    return 0;
}
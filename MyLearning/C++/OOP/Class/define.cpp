class class_name
{
    // Các thuộc tính (attributes => data members): 
    [access_specifier(access modifier):] attribute_type attribute_name;
    . . .

    // Các phương thức (methods):
    [access_specifier:] return_type method_name([lists_of_formal_parameters]){
        . . .
    };
    . . .

    // Các phương thức tạo (Constructor):
    class_name([lists_of_formal_parameters]){
        . . .
    };
    . . .

    // Phương thức hủy (Destructor):
    ~ class_name(){
        . . .
    };
}[list_of_objects];

// => Example:

class SinhVien
{

public:
    int MaSV;
    string HoTen;

    void Display(){
        cout << "MSSV: " << MaSV << endl;
        cout << "Ho va ten: " << HoTen << endl;
    }
};


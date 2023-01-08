struct structure_name
{
    //Các vùng tin (fields)
    [access_specifier: (private:/ protected:/ public:)] field_type field_name;
    . . . 

    // Các hàm thành phần
    [access_specifier:] return_type function_name([list_of_parameters]){
        . . . 
    }
    . . .

    // Các hàm tạo (Constructors)
    structure_name([list_of_parameters]){
        . . .
    } 
    . . .

    // Hàm hủy (Destructure)
    ~ structure_name();
};


// => Example:

struct SinhVien
{
    // Các vùng tin
    public:
        int MaSV;
        string HoTen;

    // Hàm thành phần:
    void Display(){
        cout << "MSSV: " << MaSV << endl;
        cout << "Ho va ten: " << HoTen << endl; 
    }

    // Hàm tạo:
    SinhVien(int n, string ht){
        MaSV = n;
        HoTen = ht;
    }

    // Hàm hủy:
    ~ SinhVien();
};


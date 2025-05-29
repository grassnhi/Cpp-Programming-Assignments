/*
Viết hàm void threeChars(string fileName) đọc vào các hàng từ một file có đuôi txt, mỗi hàng chứa một chuỗi có 3 kí tự. Xác định xem 3 ký tự trên mỗi hàng có đúng thứ tự bảng chữ cái (ASCII) hay không, nếu đúng xuất ra "true", ngược lại xuất ra "false". Chương trình sẽ lặp cho đến khi 3 ký tự đọc vào là "***".

Đầu vào:

Biến fileName là tên file chứa dữ liệu cần đọc vào.

Đầu ra:

"true" hoặc "false", theo sau bởi dấu xuống dòng, trừ trường hợp đọc vào "***" thì kết thúc chương trình.



Write a function void threeChars(string fileName) that reads in rows from a txt file, each row containing a string of 3 characters. Determines if 3 characters per row are in correct alphabetical order (ASCII), if true output "true", otherwise "false". The program will loop until 3 characters read in is "***".

Input:

The variable "fileName" is the name of the file containing the input data.

Output:

"true" or "false", followed by a newline, unless reading "***" ends the program.



For example:

Test	Input	Result
1
123
abc
aab
***
true
true
true

*/

void threeChars(string fileName)   {
    // TODO
    ifstream fin(fileName);
    string line;

    if(fin.is_open()){
        while(getline(fin, line)){
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
        
            if(line == "***"){
                break;
            }
            
            if(line.length() != 3){
                cout << "false" << endl;
                continue;
            }
            
            if (line[0] <= line[1] && line[1] <= line[2]){
                cout << "true" << endl;
            }else{
                cout << "false" << endl;
            }
        }
        fin.close();
    }

}
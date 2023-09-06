/*
Cho template của class PrinterQueue có 2 phương thức bắt buộc:

1. addNewRequest(int priority, string fileName)
Phương thức đầu tiên sẽ thêm 1 file vào danh sách hàng đợi của máy in (bao gồm độ ưu tiên và tên file). Test case sẽ có tối đa 100 file cùng lúc trong hàng đợi

2. print()
Phương thức thứ hai sẽ in tên file kèm xuống dòng và xóa nó ra khỏi hàng đợi. Nếu không có file nào trong hàng đợi, phương thức sẽ in ra "No file to print" kèm xuống dòng.

PrinterQueue tuân theo các quy tắc sau:

fileName có độ ưu tiên cao nhất sẽ được in trước.
Các fileName có cùng độ ưu tiên sẽ in theo thứ tự FIFO (First In First Out) order.
Nhiệm vụ của bạn là hiện thực class PrinterQueue thỏa mãn các yêu cầu dữ liệu trên

Lưu ý: Bạn có thể thay đổi mọi thứ, thêm thư viện cần thiết ngoại trừ thay đổi tên class, prototype của 2 public method bắt buộc.

Giải thích testcase 1: File goodbye.pdf có độ ưu tiên là 2 và được thêm vào sớm hơn file goodnight.pdf (độ ưu tiên = 2) nên sẽ được in trước, sau đó đến file goodnight.pdf và cuối cùng là hello.pdf có độ ưu tiên thấp nhất (1)

For example:

Test	Result
PrinterQueue* myPrinterQueue = new PrinterQueue();
myPrinterQueue->addNewRequest(1, "hello.pdf");
myPrinterQueue->addNewRequest(2, "goodbye.pdf");
myPrinterQueue->addNewRequest(2, "goodnight.pdf");
myPrinterQueue->print();
myPrinterQueue->print();
myPrinterQueue->print();
goodbye.pdf
goodnight.pdf
hello.pdf
PrinterQueue* myPrinterQueue = new PrinterQueue();
myPrinterQueue->addNewRequest(1, "hello.pdf");
myPrinterQueue->print();
myPrinterQueue->print();
myPrinterQueue->print();
hello.pdf
No file to print
No file to print

*/

#include<map>
#include<deque>

class PrinterQueue
{
    // your attributes
public:
    // your methods
    map<int, deque<string>> mp;
    void addNewRequest(int priority, string fileName)
    {
        // your code here
        mp[-1*priority].push_back(fileName);
    }

    void print()
    {
        if(mp.size() == 0) cout << "No file to print" << endl;
        else{
            map<int, deque<string>>::iterator it = mp.begin();
            cout << it->second[0] << endl;
            it->second.pop_front();
            if(it->second.size() == 0) mp.erase(it->first);
        }
        // your code here
        // After some logic code, you have to print fileName with endline 
    }
};
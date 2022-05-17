/*
Cho lớp Screen mô phỏng hiện thực của một màn hình với chức năng là xuất dữ liệu gồm các thuộc tính:
    width, height lần lượt là kích thước màn hình.
    buffer là một con trỏ của mảng hai chiều đại diện cho nội dung lưu tạm mà màn hình sẽ xuất ra.
            class Screen {
                private:
                    int width;
                    int height;
                    int** buffer;
                }
Hãy hiện thực một số hàm sau:
    Hàm khởi tạo nhận tham số là kích thước màn hình.

    Hàm in nội dung buffer ra màn hình. 
        Hàm này sẽ in ra các phần tử trong buffer ra màn hình (tham khảo ví dụ). Cụ thể:
            Các phần tử cách nhau một khoảng trắng
            Không được dư xuống dòng ở dòng cuối cùng
            Không được dư khoảng trắng cuối cùng dòng

    Hàm thay đổi kích thước màn hình. 
        Hàm này sẽ gán lại tất cả phần tử trong buffer về 0. 
        Nếu width hoặc height nhỏ hơn hoặc bằng 0 thì buffer sẽ được gán về null và width, height đều được set về 0.

    Hàm thay đổi nội dung buffer tại vị trí xác định. Hàm sẽ trả về true nếu việc set là thành công 
    (w và h lần lượt nằm trong khoảng của [0, width) và [0,height)). Ngược lại, trả về false.

Given a Screen class that simulates the implementaion of a screen operation. 
The class contains som attributes such as: width, height represent for the screen size.
buffer represent for a pointer of a two-demensional array of screen content.
                class Screen {
                private:
                    int width;
                    int height;
                    int** buffer;
                }
Student is required to implement some class methods such as:
    A constructor that get screen size as parameters.
    A function that output the buffer to the screen.
    This function will print the elements in the buffer to the screen (refer to the example).
     Specifically:
            Elements separated by a space
            No carriage return on the last line
            No extra spaces at the end of the line
A function that change the size of the current screen. 
This function will assign all the element in buffer to 0. If the width or height is less than 0, 
the buffer will be set to null and width, height will also be add to null..
A function that change the buffer content.
Input:
Screen scr(5, 3);
scr.print();
cout << endl;
scr.resize(9, 9);
scr.setBuffer(7, 7, 2);
scr.setBuffer(0, 0, 2);
scr.print();
Output: 
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
2 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2 0
0 0 0 0 0 0 0 0 0



*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

/// BEGIN  <STUDENT ANSWER>
class Screen {
private:
    int height;
    int width;
    int** buffer;

public:
    Screen(int height, int width){
        this->height = height;
        this->width = width;

        buffer = new int *[width];
        for (int i = 0; i < width; i++) {
            buffer[i] = new int[height];
            for (int j = 0; j < height; j++) {
                buffer[i][j] = 0;
            }
        }
        
    };
    bool setBuffer(int w, int h, int val){
        if (w >= this->width || w < 0 || h >= this->height || h < 0) return false;
        else this->buffer[w][h] = val;
        return true;
    };
    void print(){  
        for (int i = 0; i < this->height; i++){
            for (int j = 0; j < this->width; j++){
                cout << this->buffer[i][j];
                if (j < this->width-1) cout << " ";
            }
            if (i < this->height) cout << endl;
        } 
    };
    void resize(int height, int width){    
        if (height <= 0 || width <= 0){
            buffer = NULL;
            this->height = 0;
            this->width = 0;
        }
        else {
            buffer = new int*[height];
            for (int i = 0; i < height; i++){
                buffer[i] = new int[width] {0};
            }
        }
    };
    ~Screen() {
        if (buffer != nullptr) {
            for (int i  = 0; i < height; i++) {
                delete[] this->buffer[i];
            }
        }
        delete[] this->buffer;
    }
};
/// END  <STUDENT ANSWER>

int main() {
    /// BEGIN  <TEST CODE>
Screen scr(5, 3);
scr.print();
scr.resize(9, 9);
scr.print();
scr.setBuffer(7, 7, 2);
scr.setBuffer(0, 0, 2);
scr.print();

    /// END  <TEST CODE>

    return 0;
}
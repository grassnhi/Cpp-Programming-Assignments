/*
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
    A function that output the buffer to te screen.
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
    };
    bool setBuffer(int h, int w, int value){
    };
    void print(){   
    };
    void resize(int height, int width){      
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
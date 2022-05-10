/*
Given a Screen class that simulates the implementaion of a screen operation. 
The class contains som attributes such as:
        width, height represent for the screen size.
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

using namespace std;

class Screen{
private:
    int width;
    int height;
    int** buffer;

public:
    Screen(int width, int height){
        this->width = width;
        this->height = height;
        buffer = new int*[width];
        for (int i = 0; i < width; i++){
            buffer[i] = new int[height] {0};
        }
    }

    void print(){
        for (int i = 0; i < this->width; i++){
            for (int j = 0; j < this->height; j++){
                cout << this->buffer[i][j];
                if (j < this->height-1) cout << " ";
            }
            if (i < this->width) cout << endl;
        }
    }

    void resize(int newWidth, int newHeight){
        if 
        buffer = new int*[newWidth];
        for (int i = 0; i < newWidth; i++){
            buffer[i] = new int[newHeight] {0};
        }
    }

    bool setBuffer(int w, int h, int val){
        if (w >= this->width || w < 0 || h >= this->height || h < 0) return false;
        else this->buffer[w][h] = val;
        return true;
    }


};

int main(){
    Screen scr(5, 3);
    scr.print();
    cout << endl;
    scr.resize(9, 9);
    scr.setBuffer(7, 7, 2);
    scr.setBuffer(0, 0, 2);
    scr.print();
    return 0;
}
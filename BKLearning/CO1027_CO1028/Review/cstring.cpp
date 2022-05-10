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
        for (int i = 0; i < width; i++){
            buffer[i] = new int[height] {0};
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
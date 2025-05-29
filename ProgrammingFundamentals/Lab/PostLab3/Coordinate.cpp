/*
Xây dựng một class Coordinate có hai thành phần là x và y (kiểu float) là hai tọa độ trong hệ tọa độ Oxy. 

Hiện thực constructor nhận vào hai số x, y lần lượt và gán giá trị cho thành phần x, y tương ứng.
Hiện thực phương thức setX(), setY(), getX(), getY() cho class này. Sinh viên chọn kiểu trả về phù hợp.
Hiện thực phương thức distanceTo(Coordinate&) để tính khoảng cách Manhattan từ tọa độ này đến tọa độ được truyền vào. (Khoảng cách Manhattan được tính theo: d = abs(x1 – x2) + abs(y1 - y2))
[English]

Implement class Coordinate that contains 2 attributes x and y of type int. x, y are two coordinates in Oxy.
Implement constructor that takes two parameters x, y and assigns them to corresponding attributes x, y.
Implement methods: setX, setY, getX, getY. Students should choose the appropriate returned type for these methods.
Implement method distanceTo(Coordinate&) to calculate the Manhattan distance from this coordinate to the passed one. The Manhattan distance is calculated by: d = abs(x1-x2) + abs(y1-y2).


For example:

Test	Input	Result
1
2.3 4.5 .314 12
2
13.886
13.886
13.886

*/

#include <iostream>

using namespace std;

//TODO
class Coordinate {
private:
    float x, y;

public:
    Coordinate(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setX(float x) { 
        this->x = x; 
    }
    void setY(float y) { 
        this->y = y; 
    }

    float getX() { 
        return x; 
    }
    float getY() { 
        return y; 
    }

    float distanceTo(Coordinate& other) {
        return abs(this->x - other.x) + abs(this->y - other.y);
    }
};

int main () {
    float Xa, Xb, Ya, Yb;
    cin >> Xa >> Xb >> Ya >> Yb;
    Coordinate a(1,2);
    Coordinate b(0,1);
    cout << a.distanceTo(b) << endl;
    a.setX(Xa); a.setY(Ya);
    b.setX(Xb); b.setY(Yb);
    cout << abs(a.getX() - b.getX()) + abs(a.getY() - b.getY()) << endl;
    cout << a.distanceTo(b) << endl;
    cout << abs(Xa - Xb) + abs(Ya - Yb);
    return 0;
}
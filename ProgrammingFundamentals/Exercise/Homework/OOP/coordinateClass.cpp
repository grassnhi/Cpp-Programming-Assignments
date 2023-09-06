/*
Implement class Coordinate that contains 2 attributes x and y of type int. x, y are two coordinates in Oxy.
Implement constructor that takes two parameters x, y and assigns them to corresponding attributes x, y.
Implement methods: setX, setY, getX, getY. Students should choose the appropriate returned type for these methods.
Implement method distanceTo(Coordinate&) to calculate the Manhattan distance from this coordinate to the passed one. The Manhattan distance is calculated by: d = abs(x1-x2) + abs(y1-y2).
*/

#include <iostream>

using namespace std;

//TODO
class Coordinate{
    private:
        float x;
        float y;
    public:
        Coordinate(float x, float y){
            this->x = x;
            this->y = y;
        }
        void setX(float x){
            this->x = x;
        }
        void setY(float y){
            this->y = y;
        }
        float getX(){
            this->x = x;
            return x;
        }
        float getY(){
            this->y = y;
            return y;
        }
        float distanceTo(const Coordinate& p) const{
            return (abs(this->x - p.x) + abs(this->y - p.y));
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
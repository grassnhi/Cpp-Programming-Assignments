#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0);
    string toString() const;

    int distanceTo(const Point & otherPoint) const;
};

int main(int argc, const char * argv[]) {
    // Point: simple test
    Point p1(0, 5);
    cout << p1.toString() << endl;
    Point p2(9, 3);
    cout << p2.toString() << endl;

    return 0;
}
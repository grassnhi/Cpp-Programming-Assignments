/*
In this exercise, you can use implemented functions in previous question (if needed) and 
implement these following functions.

bool containsPoint(const Point point){}

bool containsTriangle(const Point pointA, const Point pointB, const Point pointC){}

*/

#include<iostream>
#include<vector>

using namespace std;

class Point
{
    /*  
     * STUDENT ANSWER   
     * TODO: using code template in previous question
     */
private:
    int x;
    int y;
public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        /*  
         * STUDENT ANSWER
         */
        this-> center = Point(0, 0);
        this-> radius = 0;
    }

    Circle(Point center, double radius)
    {
        /*  
         * STUDENT ANSWER
         */
        this->center = center;
        this->radius = radius;
    }

    bool containsPoint(const Point point)
    {
        /*  
         * STUDENT ANSWER 
         * TODO: check if a given point is entirely within the circle (does not count if the point lies on the circle).  
                 If contain, return true.
         */
        double distance = sqrt(pow(point.getX() - center.getX(), 2) + pow(point.getY() - center.getY(), 2));
        return distance < radius;
    }

    bool containsTriangle(const Point pointA, const Point pointB, const Point pointC)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: check if a given triangle ABC (A, B, C are not on the same line) is entirely within the circle (does not count if any point of the triangle lies on the circle).  
                 If contain, return true.
         */
        return containsPoint(pointA) && containsPoint(pointB) && containsPoint(pointC);
    }
};

int main(){
    Point pointO(0, 2);
    Point point1(1, 2);
    Circle A = Circle(pointO, 2);
    cout << A.containsPoint(point1);
}
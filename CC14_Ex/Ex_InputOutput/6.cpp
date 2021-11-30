/*
There are many ways to calculate the distance between A and B.
Below are 2 ways to calculate the distance between point A and point B
Manhattan distance: |xA−xB|+|yA−yB|
Euclidean distance: √((xA−xB)^2+(yA−yB)^2)
Write and run a program that reads the coordinate of 2 points, A and B, from the keyboard 
and then displays the distance between A and B in 2 ways: Manhattan distance and Euclidean distance.
*/
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main()
{
    int a, b, x, y, M;
    float E;

    cin >> a >> b >> x >> y;

    E = sqrt(pow(x - a, 2) + pow(y - b, 2));
    M = abs(x-a) + abs( y-b);
    
    cout << "Manhattan distance: " << M << endl;
    cout<<fixed<<setprecision(2)<< "Euclidean distance: " << E;

    return 0;
}
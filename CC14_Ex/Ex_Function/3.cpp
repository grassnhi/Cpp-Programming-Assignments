/*
Viết một chương trình C++ dùng để tính đường kính, chu vi và diện tích của một hình tròn.

Đầu vào:
Bán kính là một biến radius kiểu double

Đầu ra:
Các hàm getDiameter, getCircumference, getArea lần lượt trả về đường kính, chu vi, 
và diện tích của đường tròn ứng với bán kính vừa cho

Lưu ý:
Sinh viên chỉ hiện thực getDiameter, getCircumference, getArea . 
Sinh viên có thể hiện thực thêm các hàm khác để hỗ trợ. Cho PI =3.14
*/

#include <iostream>
#include <math.h>
using namespace std;

double getDiameter(double radius)
{   
    return radius*2;
}

double getCircumference(double radius)
{
   return radius*2*3.14;
}

double getArea(double radius)
{
    return radius*radius*3.14;
}

int main()
{
    double radius, diameter, circle, area;
    cin>>radius;

    diameter = getDiameter(radius); // Calling getDiameter function
    circle = getCircumference(radius); // Calling getCircumference function
    area = getArea(radius); // Calling getArea function

    cout<<"Diameter of the circle: "<<diameter <<" units"<<endl;
    cout<<"Circumference of the circle: "<< circle<<" units"<<endl;
    cout<<"Area of the circle:"<< area<<" sq. units"<<endl;
    
    return 0;
}
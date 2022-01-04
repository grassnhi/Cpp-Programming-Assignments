/*
Write and run a program that reads the name, age, sex, height and weight of a student
and displays with proper heading for each variable.
*/

#include<iostream>
using namespace std;

int main()
{
    string name ,sex;
    int age,weight;
    float height;

    cin >> name >> age >> sex >> height >> weight;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Sex: " << sex << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;

    return 0;
}

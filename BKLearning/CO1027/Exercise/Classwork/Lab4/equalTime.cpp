/*
Given the class definition:

        class clockType
        {
        public:
            void setTime(int, int, int);
            bool equalTime(const clockType&) const;
            clockType(int, int, int);
            clockType();
        private:
            int hr;
            int min;
            int sec;
        };
        
Consider the commands:

        if (myClock.equalTime(yourClock)) 
        cout << "Both times are equal." << endl;
        else 
        cout << "The two times are not equal." << endl;

The if-else conditional expression compares myClock and yourClock object. 
If the time of 2 clocks including (hr, min, sec) is the same, return true, otherwise, return false.

Requirement: 
    Student implements the equalTime method for it to do as described above.
*/

#include<iostream>

using namespace std;

class ClockType
{
public:
    void setTime(int, int, int);
    bool equalTime(const ClockType& myClock) const{
        if(hr == myClock.hr && min == myClock.min && sec == myClock.sec)
            return true;
        else return false;
    }
    ClockType(int, int, int);
    ClockType();

private:
    int hr;
    int min;
    int sec;
};

// TODO

int main(){
    ClockType yourClock;
    ClockType myClock(5,2,30); 
    if (myClock.equalTime(yourClock))
        cout << "Both times are equal."<< endl;
    else
        cout << "The two times are not equal." << endl;
}
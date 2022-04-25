/*
Given the class ClockType as following:

        class ClockType
        {
        public:
            void printTime() const;
            void incrementSeconds();
            void incrementMinutes();
            void incrementHours();
            clockType(int, int, int);
            clockType();
        private:
            int hr;
            int min;
            int sec;
        };

Consider the statement:

        myClock.incrementSeconds();

This statement increments the variable sec by 1 unit.

Let's implement 3 methods

    incrementHours:     increase hr by 1 unit. 
                        After incrementing, if hr = 24 then we reset hr = 0.

    incrementMinutes:   increase min by 1 unit. After increment, 
                        if min = 60 then we reset min = 0 and increase hr by 1 unit accordingly.

    incrementSeconds:   Increases sec by 1 unit. After increment, 
                        if sec = 60 then we reset sec = 0 and increase min by 1 unit accordingly.

*/

#include<iostream>

using namespace std;

class ClockType
{
   public:
      void setTime(int, int, int);
      void printTime() const;
      void incrementSeconds( ){
        this->sec = sec;
        sec++;
        if(sec == 60){ 
            sec = 0;
            incrementMinutes();
        
        }
    }
      void incrementMinutes(){
        this->min = min;
        min++;
        if(min == 60){ 
            min = 0;
            incrementHours();
        }
    }
      void incrementHours(){
        this->hr = hr;
        hr++;
        if(hr == 24) hr = 0;
    }
      ClockType(int, int, int);
      ClockType();

   private:
      int hr;
      int min;
      int sec;
};

void ClockType::printTime() const
{
   if (hr < 10)
      cout << "0";
   cout << hr << ":";
   if (min < 10)
      cout << "0";
   cout << min << ":";
   if (sec < 10)
      cout << "0";
   cout << sec;
}

// TODO

int main(){
    ClockType myClock(5,2,30);
    myClock.incrementSeconds();
    myClock.printTime();
}
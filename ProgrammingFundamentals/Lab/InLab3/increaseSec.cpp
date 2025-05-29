/*
Cho class ClockType như sau:

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

Hãy xem xét câu lệnh: 

myClock.incrementSeconds();

Câu lệnh này tăng biến sec thêm 1 đơn vị.

Hãy hiện thực 3 phương thức 

incrementHours: tăng hr thêm 1 đơn vị. Sau khi tăng, nếu hr = 24 thì ta đặt lại hr = 0.
incrementMinutes: tăng min thêm 1 đơn vị. Sau khi tăng, nếu min = 60 thì ta đặt lại min = 0 và tăng hr thêm 1 đơn vị bằng cách phù hợp.
incrementSeconds: tăng sec thêm 1 đơn vị. Sau khi tăng, nếu sec = 60 thì ta đặt lại sec = 0 và tăng min thêm 1 đơn vị bằng cách phù hợp.
[English]
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

incrementHours: increase hr by 1 unit. After incrementing, if hr = 24 then we reset hr = 0.
incrementMinutes: increase min by 1 unit. After increment, if min = 60 then we reset min = 0 and increase hr by 1 unit accordingly.
incrementSeconds: Increases sec by 1 unit. After increment, if sec = 60 then we reset sec = 0 and increase min by 1 unit accordingly.


For example:

Test	Result
ClockType myClock(5,2,30);
myClock.incrementSeconds();
myClock.printTime();
05:02:31

*/

class ClockType
{
   public:
      void setTime(int, int, int);
      void printTime() const;
      void incrementSeconds();
      void incrementMinutes();
      void incrementHours();
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
void ClockType::incrementSeconds(){
    this->sec++;
    if(this->sec == 60){
        this->sec = 0;
        incrementMinutes();
    }
}
void ClockType::incrementMinutes(){
    this->min++;
    if(this->min == 60){
        this->min = 0;
        incrementHours();
    }
}
void ClockType::incrementHours(){
    this->hr ++;
    if(this->hr == 24){
        this->hr = 0;
    }
}

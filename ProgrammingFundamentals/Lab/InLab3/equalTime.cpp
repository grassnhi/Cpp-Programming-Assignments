/*
Cho định nghĩa class:

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
Hãy xem xét câu lệnh: 

if (myClock.equalTime(yourClock)) 
cout << "Both times are equal." << endl;
else 
cout << "The two times are not equal." << endl;
Biểu thức kiểm tra điều kiện if-else so sánh myClock và yourClock. Nếu thời gian của 2 clock gồm (hr, min, sec) là giống nhau thì trả về true, ngược lại sẽ trả về false.

Yêu cầu: SV hiện thực phương thức equalTime để thực hiện như mô tả trên.

[English]
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
The if-else conditional expression compares myClock and yourClock object. If the time of 2 clocks including (hr, min, sec) is the same, return true, otherwise, return false.

Requirement: Student implements the equalTime method for it to do as described above.


For example:

Test	Result
ClockType yourClock;
ClockType myClock(5,2,30); 
if (myClock.equalTime(yourClock))
      cout << "Both times are equal."<< endl;
else
      cout << "The two times are not equal." << endl;
The two times are not equal.

*/

class ClockType
{
public:
    void setTime(int, int, int);
    bool equalTime(const ClockType&) const;
    ClockType(int, int, int);
    ClockType();

private:
    int hr;
    int min;
    int sec;
};

// TODO
bool ClockType::equalTime(const ClockType& ct) const{
    if(this->hr == ct.hr && this->min == ct.min && this->sec == ct.sec){
        return true;
    }
    return false;
}
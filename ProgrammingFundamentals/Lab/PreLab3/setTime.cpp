/*
Cho định nghĩa class:

class ClockType
{
   public:
      ClockType();
      void setTime(int, int, int);
      void printTime() const;
   private:
      int hr;
      int min;
      int sec;
};
Cho câu lệnh:

myClock.setTime(5, 2, 30);
Trong câu lệnh myClock.setTime (5, 2, 30); phương thức setTime được thực thi. Các giá trị 5, 2 và 30 được chuyển dưới dạng tham số cho hàm setTime và hàm sử dụng các giá trị này để đặt giá trị của ba biến thành viên hr, min và sec của đối tượng myClock thành 5, 2 và 30, tương ứng.

Yêu cầu: SV hiện thực phương thức setTime để nó thực hiện được mô tả trên.

Lưu ý: hr, min, sec cần thoả mãn các điều kiện sau. Nếu tham số đầu vào không thoả mãn điều kiện bên dưới thì ta gán giá trị 0 cho biến thành viên tương ứng.

0 <= hr < 24
0 <= min < 60
0 <= sec < 60
[English]

Given the class definition:

class ClockType
{
    public:
       ClockType();
       void setTime(int, int, int);
       void printTime() const;
    private:
       int hr;
       int min;
       int sec;
};
And the following command:

myClock.setTime(5, 2, 30);
In the statement myClock.setTime(5, 2, 30); the method setTime is executed. The values 5, 2, and 30 are passed as parameters to the function setTime, and the function uses these values to set the values of the three member variables hr, min, and sec of object myClock to 5, 2, and 30, respectively.

Requirement: Student implements the setTime method for it to do as described above.
Note: hr, min, sec need to satisfy the following conditions. If the input parameter does not satisfy the condition below, we assign the value 0 to the corresponding member variable:

0 <= hr < 24
0 <= min < 60
0 <= sec < 60






For example:

Test	Result
ClockType myClock;
myClock.setTime(5, 4, 30);
myClock.printTime();
05:04:30

*/

class ClockType
{
public:
    ClockType();
      
    void setTime(int, int, int);
    void printTime() const;

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
void ClockType::setTime(int hr, int min, int sec){
    if(hr < 0 || hr >= 24){
        this->hr = 0;
    }else{
        this->hr = hr;
    }
    
    if(min < 0 || min >= 60){
        this->min = 0;
    }else{
        this->min = min;
    }
    
    if(sec < 0 || sec >= 60){
        this->sec = 0;
    }else{
        this->sec = sec;
    }
}
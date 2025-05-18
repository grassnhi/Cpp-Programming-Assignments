/*
Trong thân hàm main(), hãy viết chương trình chính tạo ra một mảng các đối tượng thuộc class Course có n phần tử (n được nhập từ người sử dụng – sử dụng kỹ thuật tạo mảng động bằng lệnh new). Sau đó nhập và hiển thị dữ liệu cho n đối tượng này bằng hai phương thức getinfo() và disinfo() đã được hiện thực sẵn.

[English]

In main, write a program that creates an array of Course objects with n elements (n is input from user). The array is created using dynamic allocation with operator new.

Then input and display data for each element of array using two implemented methods: getinfo and disinfo.


For example:

Test	Input	Result
1
2
1 2 3 4
1 3 4 5
ID: Number of Students: Number of Teachers: Number of TAs: ID: Number of Students: Number of Teachers: Number of TAs: 
CourseID = 1
Number of student = 2
Number of teacher = 3
Number of TA = 4

CourseID = 1
Number of student = 3
Number of teacher = 4
Number of TA = 5
*/

#include<iostream>

using namespace std;

class Course {
    private:
        int ID;
        int numOfStudent;
        int numOfTeacher;
        int numOfTA;
    public:
        void getinfo();
        void disinfo();
};

void Course::getinfo() {
   cout << "ID: ";
   cin >> ID;
   cout << "Number of Students: ";
   cin >> numOfStudent;
   cout << "Number of Teachers: ";
   cin >> numOfTeacher;
   cout << "Number of TAs: ";
   cin >> numOfTA;
}

void Course::disinfo()
{
   cout<<endl;
   cout<< "CourseID = "<< ID << endl;
   cout<< "Number of student = " << numOfStudent << endl;
   cout<< "Number of teacher = " << numOfTeacher << endl;
   cout<< "Number of TA = " << numOfTA<< endl;
}


int main() {
    //TODO
    int n;
    cin >> n;
    
    Course* courses = new Course[n];
    for(int i = 0; i < n; i++){
        courses[i].getinfo();
    }
    
    for(int i = 0; i < n; i++){
        courses[i].disinfo();
    }
    
    delete[] courses;
    
    return 0;
}
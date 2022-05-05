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
   cin >> ID;
   cin >> numOfStudent;
   cin >> numOfTeacher;
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
    int n;
    Course* cour = new Course[n];

    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "ID: " << "Number of Students: " <<  "Number of Teachers: " << "Number of TAs: ";
    }
    for(int i = 0; i < n; i++){
        cour[i].getinfo();
        cour[i].disinfo();
    }

    delete[] cour;
    return 0;
}
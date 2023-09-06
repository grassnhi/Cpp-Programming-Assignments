#include <string>
#include <array>
#include <iostream>
#include <iomanip> // parameterized stream manipulators

using namespace std;

// GradeBook class definition (that uses an array to store test grades)
class GradeBook{

public:
    // constant number of students who took the test
    static const size_t students{10}; // note public data

    GradeBook(const string& name, const array<int, students>& gradesArray)
    : courseName{name}, grades{gradesArray}{ }

    // function to set the course name 
    void setCourseName(const string& name){
        courseName = name; // store the course name 
    }

    // function to retrieve the course name
    const string& getCourseName() const{
        return courseName;
    }

    // display a welcome message to the GradeBook user 
    void displayMessage() const{
        // call getCourseName to get the name of this GradeBook's course
        cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
    }

    // perform various operations on the data (none modify the data) 
    void processGrades() const{
        outputGrades(); // output grades array

        // call function getAverage to calculate the average grade 
        cout << setprecision(2) << fixed;
        cout << "\nClass average is " << getAverage() << endl;

        // call functions getMinimum and getMaximum 
        cout << "Lowest grade is " << getMinimum() << "\nHighest grade is " << getMaximum() << endl;

        outputBarChart(); // display grade distribution chart
    }

    // find minimum grade 
    int getMinimum() const{
        int lowGrade{100}; // assume lowest grade is 100

        // loop through grades array 
        for (int grade : grades){
            // if current grade lower than lowGrade, assign it to lowGrade
            if (grade < lowGrade){
                lowGrade = grade; // new lowest grade
            }
        }

        return lowGrade; // return lowest grade
    }

    // find maximum grade 
    int getMaximum() const{
        int highGrade{0}; // assume highest grade is 0

        // loop through grades array
        for (int grade : grades){
            // if current grade higher than highGrade, assign it to highGrade
            if (grade > highGrade){
                highGrade = grade; // new highest grade
            }
        }

        return highGrade; // return highest grade
    }

    // determine average grade for test
    double getAverage() const{
        int total{0}; // initialize total 

        // sum grades in array 
        for (int grade : grades){
            total += grade;
        }

        // return average of grades
        return static_cast<double>(total) / grades.size(); 
    }

    // output bar chart displaying grade distribution
    void outputBarChart() const{
        cout << "\nGrade distribution:" << endl;

        // stores frequency of grades in each range of 10 grades
        const size_t frequencySize{11};
        array<unsigned int, frequencySize> frequency{}; // init to 0s 

        // for each grade, increment the appropriate frequency 
        for (int grade : grades){
            ++frequency[grade / 10];
        }

        // for each grade frequency, print bar in chart
        for (size_t count{0}; count < frequencySize; ++count){
            // output bar labels ("0-9:", ..., "90-99:", "100:")
            if (0 == count){
                cout << "  0-9: ";
            }
            else if(10 == count){
                cout << "  100: ";
            }
            else{
                cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            }
            
            // print bar of asterisks
            for (unsigned int stars{0}; stars < frequency[count]; ++stars){
                cout << '*';
            }
            
            cout << endl; // start a new line of output
        }
    }

    // output the contents of the grades array
    void outputGrades() const{
        cout << "\nThe grades are:\n\n";
        
        // output each student's grade
        for (size_t student{0}; student < grades.size(); ++student){
            cout << "Student " << setw(2) << student + 1 << ": " << setw(3) << grades[student] << endl;
        }
    } 

private: 
    string courseName; // course name for this grade book 
    array<int, students> grades; // array of student grades

};

int main(){
    // array of student grades 
    const array<int, GradeBook::students> grades{87, 68, 94, 100, 83, 78, 85, 91, 76, 87};
    string courseName{"CS101 Introduction to C++ Programming"};

    GradeBook myGradeBook(courseName, grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();

    return 0;
}
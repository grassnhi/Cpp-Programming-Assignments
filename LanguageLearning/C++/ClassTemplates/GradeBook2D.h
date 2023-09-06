#include <string>
#include <array>
#include <iostream>
#include <iomanip> // parameterized stream manipulators

using namespace std;

// GradeBook class definition (that uses an array to store test grades)
class GradeBook{
public: 
    // constants 
    static const size_t students{10}; // number of students 
    static const size_t tests{3}; // number of tests

    // two-argument constructor initializes courseName and grades array 
    GradeBook(const string& name, array<array<int, tests>, students>& gradesArray) : courseName(name), grades(gradesArray){ }

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
        // call getCourseName to get this GradeBook’s course name
        cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
    }

    // perform various operations on the data
    void processGrades() const{
        outputGrades(); // output grades array

        // call functions getMinimum and getMaximum
        cout << "\nLowest grade in the grade book is " << getMinimum() 
             << "\nHighest grade in the grade book is " << getMaximum() << endl;
        
        outputBarChart(); // display grade distribution chart 
    }

    // find minimum grade in the entire gradebook
    int getMinimum() const{
        int lowGrade{100}; // assume lowest grade is 100 
        
        // loop through rows of grades array
        for (auto const& student : grades){
            // loop through columns of current row 
            for (auto const& grade : student){
                if (grade < lowGrade){ // if grade is lower than lowGrade 
                    lowGrade = grade; // grade is new lowest grade 
                }
            }
        }

        return lowGrade; // return lowest grade    
    } 

    // find maximum grade in the entire gradebook 
    int getMaximum() const{
        int highGrade{0}; // assume highest grade is 0
        
        // loop through rows of grades array
        for (auto const& student : grades){
            // loop through columns of current row 
            for (auto const& grade : student){ 
                if (grade > highGrade) { // if grade is higher than highGrade
                    highGrade = grade; // grade is new highest grade 
                }
            }
        } 
        
        return highGrade; // return highest grade   
    }

    // determine average grade for particular set of grades 
    double getAverage(const array<int, tests>& setOfGrades) const{
        int total{0}; // initialize total 

        // sum grades in array
        for (int grade : setOfGrades){
            total += grade;
        }
        
        // return average of grades
        return static_cast<double>(total) / setOfGrades.size();   
    } 

    // output bar chart displaying grade distribution
    void outputBarChart() const{ 
        cout << "\nOverall grade distribution:" << endl;
        
        // stores frequency of grades in each range of 10 grades
        const size_t frequencySize{11};
        array<unsigned int, frequencySize> frequency{}; // init to 0s
        
        // for each grade, increment the appropriate frequency
        for (auto const& student : grades){
            for (auto const& test : student){ 
                ++frequency[test / 10];
            }
        }
        
        // for each grade frequency, print bar in chart
        for (size_t count{0}; count < frequencySize; ++count){
            // output bar label ("0-9:", ..., "90-99:", "100:")
            if (0 == count){
                cout << "  0-9: ";
            }
            else if (10 == count){
                cout << "  100: ";
            }
            else{
                cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            }
            
            // print bar of asterisks
            for (unsigned int stars{0}; stars < frequency[count]; ++stars) 
                cout << '*';
            
            cout << endl; // start a new line of output 
        }  
    } 

    // output the contents of the grades array
    void outputGrades() const{
        cout << "\nThe grades are:\n\n";
        cout << "            "; // align column heads 
        
        // create a column heading for each of the tests
        for (size_t test{0}; test < tests; ++test){
            cout << "Test " << test + 1 << "  ";
        }
        
        cout << "Average" << endl;
        
        // create rows/columns of text representing array grades
        for (size_t student{0}; student < grades.size(); ++student){
            cout << "Student " << setw(2) << student + 1;
            
            // output student's grades
            for (size_t test{0}; test < grades[student].size(); ++test){ 
                cout << setw(8) << grades[student][test];
            }
            
            // call member function getAverage to calculate student's
            // average; pass one row of grades as the argument
            double average{getAverage(grades[student])};
            cout << setw(9) << setprecision(2) << fixed << average << endl;
        }
    }
private:
    string courseName; // course name for this grade book
    array<array<int, tests>, students> grades; // 2D array
};
/*
Write a function void studendGrading(string fileName) that reads a txt file, 
the first line consists of a positive integer N, N lines follow each line containing 4 real numbers, 
respectively, the scores of the subjects NMDT, KTLT, DSA and PPL of N students.

The student's grade point average (GPA) will be the average of the above 4 score columns. 
Students will be graded based on the following scores:

Grade A if the test score is >= 8 and no subject is below 5.
Grade B if 8 > GPA >= 6.5 and no subject below 5.
Grade C if 6.5 > GPA >= 5 and no subject below 5.
Grade D for the remaining cases.

Determine the number of students of each category and output the results to the screen.

Input:
    The variable "fileName" is the file name that contains information about the student's score.

Output:
    The number of students in each category is recorded on the screen.
*/

#include <iostream>
#include <fstream>

using namespace std

void studentGrading(string fileName){
    fstream myFile;

    myFile.open(fileName, ios::in);

    string myText;
    int N, n;

    int count = 0;
    int a = 0, b = 0, c = 0, d = 0;

    unsigned long long int sum = 0;

    if (myFile.is_open()){
        myFile >> N;
        for(int i = 0;  i < N; i++){
            for(int j = 0; j < 4; j++){
                myFile >> n;
                
                sum += n;
                if(n >= 5){
                    count++;
                }
            }

            float avg = sum *1.0 / 4;

            if(avg >= 8 && count == 4) a++;
            else if(avg >= 6.5 && count == 4) b++;
                else if(avg >= 5 && count == 4) c++;
                    else d++;

            sum = 0;
            count = 0;
        }

        cout << "A " << a << endl;
        cout << "B " << b << endl;
        cout << "C " << c << endl;
        cout << "D " << d << endl;

        myFile.close();
    }
}

int main(){
    string fileName = "fileName.txt";
    cout << studentGrading(fileName);

}
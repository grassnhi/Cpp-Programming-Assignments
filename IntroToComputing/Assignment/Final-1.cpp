/* Write an appropriate function (from //BEGIN TODO to //END TODO) in the code below 
to produce the required result:

#include <iostream>
#include <string>
using namespace std; 
string studentNames [4] = {"S A", "SB", "S C", "S D"};

//BEGIN TODO

//END TODO

int main() { displayStudents (studentNames, 4); 
return 0;

}

Required Result: a function that takes an array of student names (array of strings) 
                and its size as input. This function uses a for loop to display 
                on the screen the list of all students' names, one name per line. 
                The declaration of the global studentNames array is shown below.

                string studentNames[4] = {"S A", "SB", "S C", "S D"};

Note: main() function and libraries are provided. 
    Define the function void displayStudents(...) to meet the demand.
*/
#include <iostream>
#include <string>
using namespace std; 
string studentNames [4] = {"S A", "SB", "S C", "S D"};

//BEGIN TODO
void displayStudents( string array[], int sizeofArray ) { 
    for (int i=0; i< sizeofArray; i++){
        cout << array[i] << endl;
    }
}
//END TODO

int main() { 
    displayStudents (studentNames, 4); 
    
    return 0;
}

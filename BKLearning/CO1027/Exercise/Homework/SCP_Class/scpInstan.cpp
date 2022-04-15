/*
Struct SCP used to store information about paranormal objects is declared as below:

struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

Implement the function with the following prototype:

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums);

The function returns a new instance of struct SCP with the passed parameters.

Note: 
    Libraries iostream and string have been imported, and namespace std has been used.
*/

#include <iostream>

using namespace std;

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums) {
    // Student answer
    SCP s = {id, objClass, speConProcedures, description, addendums, numAddendums};
    return s;
}

/*
SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums) {
    // Student answer
    SCP obj;
    obj.id = id;
    obj.objClass = objClass;
    obj.speConProcedures = speConProcedures;
    obj.description = description;
    obj.addendums = addendums;
    obj.numAddendums = numAddendums;
    return obj;
}

*/

int main(){
    string* addendums = new string[2];
    
    addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
    addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

    SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

    for (int i = 0; i < 2; i++) cout << obj.addendums[i] << "\n";

    delete [] addendums;
}
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

The paranormal object SCP-038 has the ability to clone other objects, such as SCP-500 (panacea). 
The clone is independent of the original, and the clone will remain the same 
whether the original is destroyed or modified.

Implement the function with the following prototype:
        SCP* cloneSCP(SCP* original);

The function returns a pointer of the new cloned instance of the original object original. 
Choose the appropriate copy method.

Note: 
    Libraries iostream and string have been imported, and namespace std has been used.
*/
 
#include <iostream>

using namespace std;

SCP* cloneSCP(SCP* original) {
    // Student answer
    SCP* clone = new SCP {original -> id, original -> objClass, original -> speConProcedures, original -> description, NULL, original -> numAddendums};
    
    clone->addendums = new string[2];

    for (int i = 0; i < original->numAddendums; i++){
        clone->addendums[i] = original->addendums[i];
    }

    return clone;
}

int main(){
    string* addendums = new string[2];
    
    addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
    addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

    SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

    SCP* newObj = cloneSCP(obj);

    obj->id = 1;
    cout << obj->id << " " << newObj->id << "\n";

    delete [] obj->addendums;
    delete obj;

    delete [] newObj->addendums;
    delete newObj;
}
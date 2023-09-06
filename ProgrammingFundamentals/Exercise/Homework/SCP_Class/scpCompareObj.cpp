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

The objClass of each object indicates how difficult an object is to contain. 
The higher the value, the more resources and budget are needed to contain the object.

            int compareObjectClass(const SCP &objA, const SCP &objB);

The function returns    -1 if objA is easier to be contained than objB, 
                        1 if objA is more difficult to be contained than objB, 
                        or 0 if the difficulties in containing two objects are equivalent.

Note: 
    Libraries iostream and string have been imported, and namespace std has been used.
*/

#include <iostream>

using namespace std;

int compareObjectClass(const SCP &objA, const SCP &objB) {
    // Student answer
    if(objA.objClass < objB.objClass) return -1;
    else if(objA.objClass > objB.objClass) return 1;
    else return 0;
}

int main(){
    SCP objA {2, 1, "SCP-002 is to remain connected to a suitable power supply at all times.", "SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.", nullptr, 0};
    SCP objB {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", nullptr, 0};
    cout << compareObjectClass(objA, objB);
}
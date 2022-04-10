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

string convertToString(SCP obj);

The function returns a string with the following format:

Item #: SCP-<Item number, zero-left-padded until it has 3 or more digits.>
Object Class: <Safe if objClass is 0, Euclid if 1, Keter if 2>
Special Containment Procedures: <The specification of the object's special containment procedures.>
Description: <The object's description.>
<Addendum 0>
<Addendum 1>
...
<Addendum n>

Refer to the example to understand the format.

Note: Libraries iostream and string have been imported, and namespace std has been used.
*/

#include <iostream>

using namespace std;

string convertToString(SCP obj) {
    // Student answer
    string item = "Item #: SCP-";
    string itemNo = to_string(obj.id);
    while (itemNo.length() < 3){
        itemNo = "0" + itemNo;
    }
    
    item = item + itemNo;
    
    string objectClass = "Object Class: ";
    if (obj.objClass == 0 )   
        objectClass = objectClass + "Safe";
    else if (obj.objClass == 1 )   
        objectClass = objectClass + "Euclid";
        else  
            objectClass = objectClass + "Keter";
    
    string speConPro = "Special Containment Procedures: " + obj.speConProcedures;
    string descript = "Description: " + obj.description;
    string result = item + "\n" + objectClass + "\n" + speConPro + "\n" + descript + "\n";
    for ( int i = 0; i < obj.numAddendums; i++ )
         result = result + obj.addendums[i] + "\n";
    return result;
}

int main(){
    string* addendums = new string[2];
    addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
    addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

    SCP obj {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

    cout << convertToString(obj);

    delete [] addendums;
}


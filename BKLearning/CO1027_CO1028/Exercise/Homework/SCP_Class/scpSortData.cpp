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

SCP Foundation's classified archives are stored as a dynamic allocated array. 
However, because of some specific reason, the array is not sorted in any order.

Implement the function with the following prototype:

            SCP** sortDatabase(SCP** arr, int n);

Where arr is the array of SCP typed pointers, n is the length of the array. 
The function returns the sorted array in item number (id) increasing order.

Note: 
    Libraries iostream and string have been imported, and namespace std has been used.
*/

#include <iostream>

using namespace std;

SCP** sortDatabase(SCP** arr, int n) {
    // Student answer
    SCP* sortData = new SCP {};
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i]->id > arr[j]->id){
                sortData = arr[i];
                arr[i] = arr[j];
                arr[j] = sortData;
            }
        }
    }
    SCP** data = new SCP* [n];
    for(int i = 0; i < n; i++){
        data[i] = new SCP{};
        data[i] = arr[i];
    }
    return data;
}

int main(){
    int n = 3;
    SCP** data = new SCP* [n];
    data[0] = new SCP {2, 1, "SCP-002 is to remain connected to a suitable power supply at all times.", "SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.", nullptr, 0};
    data[1] = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", nullptr, 0};
    data[2] = new SCP {49, 1, "SCP-049 is contained within a Standard Secure Humanoid Containment Cell in Research Sector-02 at Site-19.", "SCP-049 is a humanoid entity, roughly 1.9 meters in height, which bears the appearance of a medieval plague doctor.", nullptr, 0};

    data = sortDatabase(data, n);

    for (int i = 0; i < n; i++) cout << data[i]->id << " ";

    for (int i = 0; i < n; i++) {
        delete [] data[i]->addendums;
        delete data[i];
    }
    delete [] data;
}
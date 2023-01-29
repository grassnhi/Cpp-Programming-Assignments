#include<iostream>
#include<iomanip>
#include<array> //contains the definition of class template array.

using namespace std;

int main(){
    const size_t arraySize{5}; // must initialize in declaration

    array<int, arraySize> values;

    for(size_t i{0}; i < values.size(); ++i){
        values[i] = 2 + 2*i;
    }

    cout << "Element" << setw(10) << "Value" << endl;

    // Output
    for (size_t j{0}; j < values.size(); ++j){
        cout << setw(7) << j << setw(10) << values[j] << endl; 
    }

    return 0;
}
#include<iostream>
#include<iomanip>
#include<array> //contains the definition of class template array.

using namespace std;

int main(){
    array<int, 5> n;

    //Initialize element
    for(size_t i{0}; i < n.size(); ++i){
        n[i] = 0;
    } // size_t rep-resents an unsigned integral type. (#include <cstddef>)

    cout << "Element" << setw(10) << "Value" << endl;

    // Output
    for (size_t j{0}; j < n.size(); ++j){
        cout << setw(7) << j << setw(10) << n[j] << endl; 
    }

    return 0;
}
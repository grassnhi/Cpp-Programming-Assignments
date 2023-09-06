#include<iostream>
#include<iomanip>
#include<array> //contains the definition of class template array.

using namespace std;

int main(){
    array<int, 5> n{32, 27, 64, 18, 95}; //list initializer

    cout << "Element" << setw(10) << "Value" << endl;

    // Output
    for (size_t j{0}; j < n.size(); ++j){
        cout << setw(7) << j << setw(10) << n[j] << endl; 
    }

    return 0;
}
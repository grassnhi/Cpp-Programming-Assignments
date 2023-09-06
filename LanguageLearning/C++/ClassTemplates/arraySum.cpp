#include <iostream>
#include <array>

using namespace std;

int main(){
    const size_t arraySize{4};

    array<int, arraySize> a;

    for (size_t j{0}; j < a.size(); ++j) {
        cin >> a[j]; 
    } 

    int total{0};

    // sum contents of array 
    for (size_t i{0}; i < a.size(); ++i){
        total += a[i];
    }

    cout << "Total of array elements: " << total << endl; 

    return 0;
}
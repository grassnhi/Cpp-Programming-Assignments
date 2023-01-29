#include <iostream>
#include <iomanip>
#include <array> 

using namespace std;

int main(){
    // define array sizes
    const size_t responseSize{20}; // size of array responses
    const size_t frequencySize{6}; // size of array frequency
    
    // place survey responses in array responses 
    const array<unsigned int, responseSize> responses{ 
        1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5};
        
    // initialize frequency counters to 0
    array<unsigned int, frequencySize> frequency{};

    // for each answer, select responses element and use that value 
    // as frequency subscript to determine element to increment 
    for (size_t answer{0}; answer < responses.size(); ++answer){
        ++frequency[responses[answer]];
    }
    
    cout << "Rating" << setw(12) << "Frequency" << endl;
    
    // output each array element's value
    for (size_t rating{1}; rating < frequency.size(); ++rating){
        cout << setw(6) << rating << setw(12) << frequency[rating] << endl;
    }

    return 0;
}

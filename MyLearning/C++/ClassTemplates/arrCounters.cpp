#include<iostream>
#include<iomanip>
#include<array>
#include<random>
#include<ctime>

using namespace std;

int main(){
    default_random_engine engine(static_cast<unsigned int>(time(0)));
    // use the default random-number generation engine to 
    // produce uniformly distributed pseudorandom int values from 1 to 6 
    uniform_int_distribution<unsigned int> randomInt(1, 6);

    const size_t arraySize{7}; //ignore element 0

    array<unsigned int, arraySize> frequency{}; // initialize to 0s (frequency=0)
    //array frequency to count the occurrences of die value

    // Roll
    for(unsigned int roll{1}; roll <= 60000000; ++roll){
        ++frequency[randomInt(engine)];
        // uses a random value to determine which frequency element to increment
    }

    cout << "Face" << setw(13) << "Frequency" << endl; 

    // output each array element's value
    for (size_t face{1}; face < frequency.size(); ++face){
        cout << setw(4) << face << setw(13) << frequency[face] << endl;
    }

    return 0;
}
#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <functional> // greater<T> 
using namespace std; 

template<class T> 
void printVector(char *s, const vector<T>& v){
    cout << s << " = (";

    if (v.size() == 0){
        cout << ")\n";
        return;
    }
    
    typename vector<T>::const_iterator i = v.begin(); 
    for( ; i != v.end()–1; i++)
        cout << *i << ' ';    
    cout << *i << ")\n"; 
}

bool f1(int n){
    return n < 4;
} 

int main(){
    int a[] = {1,2,3,4,5};

    vector<int>  v1;      // v1 is empty, size = 0, capacity = 0
    printVector("v1",v1);

    for (int j = 1; j <= 5; j++)
        v1.push_back(j);  // v1 = (1 2 3 4 5), size = 5, capacity = 8
    
    vector<int>  v2(3,7); // v2 = (7 7 7)
    vector<int> ::iterator i1 = v1.begin()+1;
    vector<int>  v3(i1,i1+2);   // v3 = (2 3), size = 2, capacity = 2
    vector<int>  v4(v1); // v4 = (1 2 3 4 5), size = 5, capacity = 5
    vector<int>  v5(5);  // v5 = (0 0 0 0 0)

    v5[1] = v5.at(3) = 9;// v5 = (0 9 0 9 0)
    v3.reserve(6);       // v3 = (2 3), size = 2, capacity = 6
    v4.resize(7);        // v4 = (1 2 3 4 5 0 0), size = 7, capacity = 10
    v4.resize(3);        // v4 = (1 2 3), size = 3, capacity = 10
    v4.clear();          // v4 is empty, size = 0, capacity = 10 (!)

    v4.insert(v4.end(),v3[1]);    // v4 = (3)
    v4.insert(v4.end(),v3.at(1));    // v4 = (3 3) 
    v4.insert(v4.end(),2,4);         // v4 = (3 3 4 4)
    v4.insert(v4.end(),v1.begin()+1,v1.end()-1);  // v4 = (3 3 4 4 2 3 4)
    v4.erase(v4.end()-2);             // v4 = (3 3 4 4 2 4)
    v4.erase(v4.begin(), v4.begin()+4);  // v4 = (2 4)
    v4.assign(3,8);                      // v4 = (8 8 8)
    v4.assign(a,a+3);                 // v4 = (1 2 3)

    vector<int>::reverse_iterator i3 = v4.rbegin();
    for ( ; i3 != v4.rend(); i3++)
        cout << *i3 << ' ';       // print: 3 2 1
    cout << endl; //  algorithms

    v5[0] = 3;  // v5 = (3 9 0 9 0)
    replace_if(v5.begin(),v5.end(),f1,7);  // v5 = (7 9 7 9 7)

    v5[0] = 3; 
    v5[2] = v5[4] = 0;           // v5 = (3 9 0 9 0)
    replace(v5.begin(),v5.end(),0,7);    // v5 = (3 9 7 9 7)
    sort(v5.begin(),v5.end());          // v5 = (3 7 7 9 9)
    sort(v5.begin(),v5.end(),greater<int> ()); // v5 = (9 9 7 7 3)
    v5.front() = 2;                     // v5 = (2 9 7 7 3)
    
    return 0; 
}

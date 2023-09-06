#include <iostream>
using namespace std;

int main(){

    int a[] = { 5, 16, 7, 89, 100, 70 };
    int* p = &a[2];
    // cout << "*(--p):" << *(--p) << endl;
    // cout << "*(p--):" << *(p--) << endl;
    // cout << "*(++p):" << *(++p) << endl;
    // cout << "*(p++):" << *(p++) << endl;
    // cout << "++(*p):" << ++(*p) << endl;
    cout << "(*p)++:" << (*p)++ << endl;
    
	return 0;
}

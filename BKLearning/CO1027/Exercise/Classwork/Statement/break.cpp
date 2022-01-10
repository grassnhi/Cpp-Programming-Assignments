#include <iostream>
using namespace std;

int main() {
    int count;
    
    for (count = 1; count <= 10; count++) {
        if (count == 5)
		    break;
        cout << count << " ";
    }

    cout << "\nBroke out of loop at count = " << count << endl;
    
    return 0;
}

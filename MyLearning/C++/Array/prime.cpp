#include<iostream>
#include<math.h>

using namespace std;

bool check(int a) {
    if (a <= 1) 
        return false;

    for (int i = 2; i <= sqrt(a); i++){
        if (a % i == 0)
            return false;
    }

    return true;
}

int count(int a[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (check(a[i]) == true)
            count++;
    }

    return count;
}

int main() {
    int a[1000];
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << count(a, n) << endl;

    return 0;
}
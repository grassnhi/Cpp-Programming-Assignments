/*
A nice number is a positive integer that contains only 2's and 5's.
Some nice numbers are: 2, 5, 22, 25, 52, 55, ...
Number 2 is the first nice number.
Given an integer N, return the Nth nice number.
Note: iostream, vector, queue are already included for you.

Constraint:
1 <= n <= 10^6

Example 1:
Input:
n = 5
Output:
52

Explanation:
The sequence of nice numbers is 2, 5, 22, 25, 52, 55, ...
The 5th number in this sequence is 52

Example 2:
Input:
n = 10000
Output:
2255522252225

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long nthNiceNumber(int n) {
    if (n <= 0) {
        return -1;
    }

    queue<long long> q;
    vector<long long> res;
    q.push(2);
    q.push(5);
    while (res.size() < n) {
        long long curr = q.front();
        res.push_back(curr);
        q.pop();
        
        long long next2 = curr * 10 + 2;
        long long next5 = curr * 10 + 5;
     
        q.push(next2);
        q.push(next5);
    }
    return res[n-1];
}





int main() {
    int n;
    cin >> n;
    cout << nthNiceNumber(n) << endl;
    return 0;
}


/*
Test	Input	Result
int n;
cin >> n;
cout << nthNiceNumber(n) << endl;
5
52
int n;
cin >> n;
cout << nthNiceNumber(n) << endl;
10000
2255522252225

*/
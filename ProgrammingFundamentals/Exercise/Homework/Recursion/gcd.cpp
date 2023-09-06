/*
A function that finds the greatest common divisor of two positive integers can be written 
through simple recursion and looping. 
You write the function gcdRecursion to perform the greatest common divisor 
by recursion and the function gcdIteration to find the greatest common divisor by loop.

Input:
    Two integers p, q respectively (1 ≤ p,q < 109).

Output:
    The gcdRecursion and gcdIteration functions return the greatest common divisor of p, q, respectively.
*/

#include<iostream>
#include<string>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int gcdRecursion(int p, int q){
     // BEGIN YOUR IMPLEMENTATION [1]
     if (p == 0)
       return q;
       
    if (q == 0)
       return p;
  
    if (q == p)
        return p;
  
    if (p > q)
        return gcdRecursion(p -q, q);
        
    return gcdRecursion(q, q - p);
    // END YOUR EMPLEMENTATION [1]
}

int gcdIteration(int p, int q){
    // BEGIN YOUR IMPLEMENTATION [2]
    if (q != 0)
        return gcdRecursion(q, p % q);
    else
        return p;
    // END YOUR EMPLEMENTATION [2]
}

int main(){
    //hiddenCheck();

    int p,q;
    cin >> p >> q;

    cout<< gcdRecursion(p, q) << " " << gcdIteration(p, q);

    return 0;
}
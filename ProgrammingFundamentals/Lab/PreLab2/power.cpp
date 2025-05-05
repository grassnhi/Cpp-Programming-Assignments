/*
Given integer n and positive integer e, where n is the base and e is the exponent. Write a recursive function

int calculate_power(int n, int e){} 
 
to calculate the value of n^e.

Please note that you can't using key work for, while, goto (even in variable names, comment).

For this exercise, we have #include <iostream> and using namespace std;

For example:

Test	
int n = 2;
int e = 3;
cout << calculate_power(n ,e);

Result: 8
*/

int calculate_power(int n, int e) 
{ 
    /*  
     * STUDENT ANSWER
     */
    
    if(e == 1){
        return n;
    }
    return n * calculate_power(n, e - 1); 
}
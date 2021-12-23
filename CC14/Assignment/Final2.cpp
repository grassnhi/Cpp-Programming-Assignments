/*
1. Introduction
A vehicle Arduino robot moves in a plane starting from the origin (0,0). 
The vehicle can move UP, DOWN, TURN LEFT, and TURN RIGHT with a certain number of steps. 
Write a program to calculate the distance from the current point after a series of 
movements to the origin? Then, check the distance to know if it is a perfect square or 
a prime number?
Note: If the distance is FLOAT, only the nearest integer Int (INT) is required.

2. Input data
The input data of the program is stored in test cases. These files contain the types 
of character in the following format: direction, steps
- direction: This value indicates the direction of the Arduino vehicle on the plane 
and is denoted as follows: U (going up), D (going down), L (turn left), R (turn right)
- steps: This value indicates the number of steps that the vehicle has moved on the plane

3. Output data
The program will extract directly to the screen the distance the vehicle has moved 
and check if this value is a prime number or a square number.
Assume that the program will be entered with sequential values listed below:

U5D3L3R2

The program will execute and extract to the screen a result as follows:
- The distance the vehicle has moved from the origin to the current point is 2
- Number 2 is a prime number
*/

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * Support Functions: these functions below are optional. If you want your code
                      to be clearer, you can implement them. However if you
                      dont know how to use funtion in programming, dont worry, 
                      you dont have to implement them, and you just add a comment 
                      in each of them.
*******************************************************************************/

int move(string moves)
{
    int x, y;
	x = y = 0;

    for (size_t i = 0; i < moves.length()-1; i=i+2 ){
    	if (moves[i] == 'U') 
            y = y + int((int)moves[i+1] - '0');

    	if (moves[i] == 'D') 
            y = y - int((int)moves[i+1] - '0');

		if (moves[i] == 'L') 
            x = x - int((int)moves[i+1] - '0');
            
		if (moves[i] == 'R') 
            x = x + int((int)moves[i+1] - '0');
	}

	int t = round(sqrt(x*x + y*y));
	return t;   
}

bool isPrime(int n)
{
    int i;

    for (i = 2; i <= n-1; i++){
    	if (n%i == 0) break;
    	else continue;
	}

	if (i == n) return true;
	else return false;
    
}

bool isSquared(int n)
{
    if (int(sqrt(n))*int(sqrt(n)) == n) 
        return true;
    else return false;
}

int main()
{
    string moves;
    int distance;
    bool primality, squared;

    /// =======================================================
    /*
        The following code initializes variable `moves`
    */
    /// BEGIN   TESTCASE

    cin >> moves;

    /// END     TESTCASE
    /*---------------------------------
        * Calculate the distance
        * Remember to assign calculated value to variable `distance`
    */
    
    distance = move(moves);
    
    /*---------------------------------*/

    cout << "The distance the vehicle has moved from the origin to the current point is: "<< distance << '\n';

    /*---------------------------------
        * Check if distance is prime
        * Remember to assign appropriate value to variable `primality`
    */
    
    primality = isPrime(distance);
    
    /*---------------------------------*/
    /*---------------------------------
        * Check if distance is squared
        * Remember to assign appropriate value to variable `squared`
    */
    
    squared = isSquared(distance);

    /*---------------------------------*/

    if (primality) {
        cout << "Number " << distance << " is prime number\n";
    }

    if (squared) {
        cout << "Number " << distance << " is square number\n";
    }

    return 0;
}
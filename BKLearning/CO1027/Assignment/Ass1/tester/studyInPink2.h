/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream note1(ntb1, ifstream::in);
    string ans = "";
    int num;
    
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if(note1.is_open()){
        string N1;
        note1 >> N1;
        string number;
               
        for(int i = 11; i < 14; i++){ 
            if(!isdigit(N1[i])){
                note1.close();
                return "0000000000";
            }else
            number[i-11] = N1[i];
        }
        num = stoi(number);
//cout << num << endl;
        int line2[num];

        for (int i = 0; i < num; i++){
            note1 >> line2[i];
            count[line2[i]] = (count[line2[i]]+1)%10;
        }

// for(int i = 0; i < 10; i++){
//     cout << count[i] << " ";
// }
        for (int i = 0; i < 10; i++){
            ans += to_string(count[i]);
        }  
    
    }
    
    note1.close();
    return ans;
}

string notebook2(string ntb2) {
    ifstream note2(ntb2, ifstream::in);
    string N2;
    int cntP = 0;
    if(note2.is_open()){
        getline(note2, N2);

        for(int i = 0; i < N2.length(); i++){
            if(N2[i] < '0' || N2[i] > '9'){
                note2.close();
                return "1111111111";
            }
        }
        int n2 = stoi(N2);
        string finding, time;
        if(n2 >= 5 && n2 <= 500){
            for(int i = 0; i < n2; i++){
                getline(note2, finding);  
                for(int j = 0; j < finding.length(); j++){
                    if (j == finding.find("pink", j)){
                        cntP++;
                        j = finding.find("pink", j);
                    }
                    else if (j == finding.find("Pink", j)){
                        cntP++;
                        j = finding.find("Pink", j);
                    }
                }  
//cout << cntP << " ";
                }
//cout << cntP << endl;
            if(cntP < 10000)
                cntP = cntP * cntP;
//cout << cntP << endl;
            if(cntP < 10000000000){
                time = to_string(cntP);
//cout << time << endl;
//cout << time.length() << endl;
                int len = time.length();
                for(int k = 0; k < 10 - len; k++){
                    time += "9";
//cout << time << " ";
                }
                return time;
            }
            
        }
        else{
            note2.close();
            return "1111111111";
        }
    
    
    }else{
        note2.close();
        return "000000000";
    }
}

bool isPrime(int n)
{
	// Base cases
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	// For all the remaining numbers, check if
	// any number is a factor if the number
	// or not
	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	// If none of the above numbers are the
	// factors for the number, then the
	// given number is prime
	return true;
}

int findSmallest(int N)
{

	// Base case
	if (N == 0)
		return 2;
	if (N == 1)
		return 1;

	int prime = N, counter = 0;
	bool found = false;

	// Loop continuously until isPrime returns
	// true for a number greater than n
	while (!found) {
		if (isPrime(prime))
			found = true;
		else {

			// If the number is not a prime, then
			// increment the number by 1 and the
			// counter which stores the number
			// to be added
			prime++;
			counter++;
		}
	}

	return counter;
}

int nearestFibonacci(int num)
{
	// Base Case
	if (num == 0) {
		return 0;
	}

	// Initialize the first & second
	// terms of the Fibonacci series
	int first = 0, second = 1;

	// Store the third term
	int third = first + second;

	// Iterate until the third term
	// is less than or equal to num
	while (third < num) {

		// Update the first
		first = second;

		// Update the second
		second = third;

		// Update the third
		third = first + second;
	}

	// Store the Fibonacci number
	int ans = third;

	// Print the result
	return ans;
}

void swap(int &a, int &b){
    int max = a;
        a = b;
        b = max;
}

string notebook3(string ntb3) {
    ifstream note3(ntb3, ifstream::in);
    
    int N3[10][10], i = 0, j = 0;
    string str;

    if(note3.is_open()){
        while(getline(note3, str)){
            string get = "";
            int length = str.length();
            for(int k = 0; k < length; k++){
                if(str[k] != '|'){
                    get += str[k];
                }
                else{
                    N3[i][j] = abs(stoi(get));
                    j++;
                    get = "";
                }
            }
            N3[i][j] = abs(stoi(get));
            i++;
            j = 0;
        }
    note3.close();
    }

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(i < j){
                N3[i][j] += findSmallest(N3[i][j]);
            }
            else if(i > j){
                N3[i][j] = nearestFibonacci(N3[i][j]);
            }
        }
    }
    for(i = 0; i < 10; i++){
        if(N3[i][7] > N3[i][8])     swap(N3[i][7], N3[i][8]);
        if(N3[i][8] > N3[i][9])     swap(N3[i][8], N3[i][9]);
        if(N3[i][7] > N3[i][8])     swap(N3[i][7], N3[i][8]);
    }
    string maxEls = "";
    for(i = 0; i < 10; i++){
        int max = N3[i][0], maxIndex = 0;
        for(j = 0; j < 10; j++){
            if(N3[i][j] >= max){
                max = N3[i][j];
                maxIndex = j;
            }
        }
        maxEls += to_string(maxIndex);
    }

// for(i = 0; i < 10; i++){
//     for(j = 0; j < 10; j++){
//         cout << N3[i][j] << " ";
//     }
//     cout << endl;
// }
return maxEls;
}

string match(string s1, string s2){
    string s;
    int n = 0, r = 0;
    for(int i = 0; i < s1.length(); i++){
        n = (s1[i] - '0') + (s2[i] - '0') + r;

        r = n / 10;
        n = n % 10;
        
        s += n + '0';
    }
// 0101000002;1219999999;9931333333;1310000002;9042333335;0250333333;0351333335;0351333335;0452333337

    return s;
}

string generateListPasswords(string pwd1, string pwd2, string pwd3){
    string m1 = match(pwd1, pwd2);
    string m2 = match(pwd1, pwd3);
    string m3 = match(pwd2, pwd3);
    string passList = pwd1 + ";" + pwd2 + ";" + pwd3 + ";" + m1 + ";" + m2 + ";" + m3 + ";" 
                            + match(m1, pwd3) + ";" + match(pwd1, m3) + ";" + match(m1, m2);
    return passList;

}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++)
            arr[i][j] = -9;
    }
    arr[0][0] = 0;

    int location = 0, row = 0, col = 0;
    for(int i = 0; i < moves.length(); i++){
        char step = moves[i];
        switch(step){   
            case 'U':
                if(row - 1 > 0) {
                    arr[--row][col] = location + 9;
                    location = arr[row][col];
                }
                break;
            case 'D':
                if(row + 1 < 100) {
                    arr[++row][col] = location + 9;
                    location = arr[row][col];
                }
                break;
            case 'R':
                if(col + 1 < 100) {
                    arr[row][++col] = location + 9;
                    location = arr[row][col];
                }
                break;
            case 'L':
                if(col - 1 > 0) {
                    arr[row][--col] = location + 9;
                    location = arr[row][col];
                } 
                break;
        }
    }
    bool caught = false;
    int prePosition[2] = {0 , 0}, currPosition[2] = {0, 0};
    int preTime = 0, currTime = 0;
    while(points != "\0"){
        int start = points.find("("), mid = points.find(","), end = points.find(")");
//cout << start << " " << mid << " " << end << endl;
        string point = points.substr(start + 1, mid - start - 1);
        int x = stoi(point);
//cout << x << endl;
        //points = points.substr(mid + 1);
//cout << points << endl;
        point = points.substr(mid + 1, end - mid - 1);
        int y = stoi(point);
//cout << y << endl;
        currPosition[0] = x; 
        currPosition[1] = y;
//cout << currPosition[0] << " " << currPosition[1] << endl;

        currTime = 14*(abs(currPosition[0] - prePosition[0]) + abs(currPosition[1] - prePosition[1])) + preTime;
//cout << currTime << endl;  
        if(arr[x][y] != -9 && arr[x][y] >= currTime && !caught){
            caught = true;
            outTimes += (to_string(currTime) + ";");
            outCatchUps += ("Y;");
        }
        else if(!caught){
            outTimes += (to_string(currTime) + ";");
            outCatchUps += ("N;");
        }else{
            outTimes += ("-;");
            outCatchUps += ("-;");
        }
        prePosition[0] = currPosition[0]; 
        prePosition[1] = currPosition[1]; 
        preTime = currTime; 
        points = points.substr(end + 1);
    }
    outTimes.pop_back();
    outCatchUps.pop_back();
    return caught;
}

string enterLaptop(string tag, string message) {
    ifstream pass(tag, ifstream::in);
    string email, address, N3 = "", password;
    if(pass.is_open()){
        getline(pass, email);
        getline(pass, address);
//cout << email << " " << address << endl;
        if(isdigit(address[10])){
            for (int i = 9; i < 11; i++){
                N3 += address[i];
//cout << N3 << " ";
            } 
        }else
            N3 = address[9];
//cout << N3 << " ";      
        int n3 = stoi(N3);
//cout << n3 << endl;
        string temp = message;
        for(int i = 1; i < n3; i++){
            message += temp;
//cout << message << endl;
        }

        password = email.substr(7) + ";" + message;       
        pass.close();
    }
    return password;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */

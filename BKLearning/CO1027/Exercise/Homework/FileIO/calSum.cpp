/*
Write a function void calSum(string fileName) to calculate the sum of non-negative integers 
read from a txt file (numbers in a row separated by a space).

Input: The variable "fileName" is a data file name containing non-negative integers 
        (numbers in 1 row separated by a space).

Output: An integer is the sum of the input integers.
*/

#include <fstream>
#include <iostream>

using namespace std;
void calSum(const string& fileName){
    //cout << fileName << endl;

    fstream my_file;

    my_file.open(fileName, ios::in);

    string myText;

    int a = 0;
    int sum = 0;

    if (my_file.is_open()){
        //cout << "reading" << endl;
        getline(my_file, myText);

        my_file.close();
    }

    if(myText.length() == 0) 
        return;
    
    for(unsigned int i = 0; i < myText.length(); i++){
       // cout << "i: " << i << " "  << "text: " <<myText[i] << endl;

        if(myText[i] >= '0' && myText[i] <= '9') 
            a = a * 10 + (myText[i] % 16);
        else{
            //cout << a <<endl;
            sum = sum + a;
            //cout << sum << endl;
            a = 0;
        }
    }

    if(a != 0 )
        sum = sum + a;

    cout << sum;
}

int main(){
	string fileName = "fileName.txt";

	calSum(fileName);
    
	return 0;
}

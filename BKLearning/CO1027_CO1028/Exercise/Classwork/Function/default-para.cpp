#include<iostream>
using namespace std;

// declare a function
int computeBoxVolume(int length = 1, int width = 2, int height = 3);
                        //default value of the 1st para is 1
                                    //default value of the 2nd para is 2
                                                    //default value of the 3rd para is 3

int main() {
	cout << "The default box volume : " << computeBoxVolume(1,2,3) <<endl;
                                        // = 1*2*3
	cout << "The default box volume : " << computeBoxVolume() <<endl; 
                                        // = 1*2*3
	cout << "The second box volume : " << computeBoxVolume(10) << endl;
                                        // = 10*2*3 -> similar to computeBoxVolume(10, 2, 3)
                            // => 10 is pass to the first and the last two value is the default value.
   cout << "The third box volume : " << computeBoxVolume(10, 3) << endl;
                                        // = 10*3*3
}
int computeBoxVolume(int length, int width, int height) {
	return length * width * height;
}

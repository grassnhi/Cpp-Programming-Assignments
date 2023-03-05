/*
Given an array of integers.
Your task is to implement a function with following prototype:
bool consecutiveOnes(vector<int>& nums);
The function returns if all the 1s appear consecutively in nums.

Note:
- The iostream and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.
*/

#include<iostream>
#include<vector>

using namespace std;

bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1 && nums[i+1] == 1){
            return true;
        }
    }
    return false;
}



int main(){
    vector<int> nums {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums);
}
/*
Given an array of integers.
Your task is to implement a function with following prototype:
int sumOfMaxSubarray(vector<int>& nums, int k);
The function returns the sum of the maximum value of every subarray of nums with fixed length k.

Note:
- The iostream, vector, queue and deque libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions and classes.

*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    deque<int> qu;
    qu.push_back(0);
    for(int i = 1; i < k; i++){
        while(!qu.empty() && nums[qu.back()] < nums[i]){
            qu.pop_back();
        }
        qu.push_back(i);
    }
    int sum = nums[qu.front()];
    int n = nums.size();
    int  i = k;
    while(i != n){
        if(i - qu.front() == k){
            qu.pop_front();
        }
        while(!qu.empty() && nums[qu.back()] < nums[i]){
            qu.pop_back();
        }
        qu.push_back(i);
        sum+=nums[qu.front()];
        i++;
    }
    return sum;
}

int main() {
    vector<int> nums {1, 2, 4, 3, 6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k) << endl; // 14
    return 0;
}


/*
Test	Result
vector<int> nums {1, 2, 4, 3, 6};
int k = 3;
cout << sumOfMaxSubarray(nums, k);
14
*/
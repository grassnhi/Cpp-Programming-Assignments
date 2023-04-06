#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    deque<int> dq;
    dq.push_back(0);
    for(int i = 1; i < k; i++){
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    int sum = nums[dq.front()];
    for(int i = k; i < nums.size(); i++){
        if(i - dq.front() == k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        sum += nums[dq.front()];
    }
    return sum;
}


int main() {
    vector<int> nums {1, 2, 4, 3, 6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k) << endl; // 14
    return 0;
}
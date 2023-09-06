/*
Given an array of non-negative integers. Each time, we can take the smallest integer out of the array, multiply it by 2, and push it back to the array.

Request: Implement function:

int leastAfter(vector<int>& nums, int k);
Where nums is the given array (the length of the array is between 1 and 100000). This function returns the smallest integer in the array after performing the operation k times (k is between 1 and 100000).

Example:

Given nums = [2, 3, 5, 7].

In the 1st operation, we take 2 out and push back 4. The array is now nums = [3, 4, 5, 7].

In the 2nd operation, we take 3 out and push back 6. The array is now nums = [4, 5, 6, 7].

In the 3rd operation, we take 4 out and push back 8. The array is now nums = [5, 6, 7, 8].

With k = 3, the result would be 5.

Note:

In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.

For example:

Test	Result
vector<int> nums {2, 3, 5, 7};
int k = 3;
cout << leastAfter(nums, k);
5

*/

int leastAfter(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int n = nums.size();
    vector<int> vc;
    for(int i =0; i < n;i++){
        vc.push_back(-1*nums[i]);
    }
    make_heap(vc.begin(), vc.end());
    for(int i = 0; i < k; i++){
        int t = vc[0];
        pop_heap(vc.begin(),vc.end());
        vc.pop_back();
        vc.push_back(2*t);
        push_heap(vc.begin(), vc.end());
    }
    return -1*vc[0];
}
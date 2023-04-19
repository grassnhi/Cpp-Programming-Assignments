/*
Given an integer array nums. In each operation, two numbers are removed from array, and their sum is pushed back to the array. The cost of the operation is the sum of the two removed numbers.

Request: Implement function:

int reduceSum(vector<int>& nums);
Where nums is the mentioned array (the number of elements is between 1 and 100000). This function returns the minimum sum of cost after repeating the operation until the array is reduced to one element.

Example:

Given the array: [1, 2, 3, 4]

In the first operation, 1 and 2 are removed, and their sum is pushed back to the array. The cost of the operation is 3. After the first operation, the array is: [3, 3, 4].

Repeat the process, the minimum total cost should be 19.

Note:

In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and class. Importing other libraries is allowed, but not encouraged.

For example:

Test	Result
vector<int> nums {1, 2, 3, 4};
cout << reduceSum(nums);
19

*/

int reduceSum(vector<int>& nums) {
    // STUDENT ANSWER
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int> > pq;
    int sum = 0;
    for (int i = 0; i < n; i++)
        pq.push(nums[i]);
    
    while (pq.size() > 1)
    {
        int min = pq.top();
        pq.pop();
        int secondMin = pq.top();
        pq.pop();
        sum += (min + secondMin);
        pq.push(min + secondMin);
    }
    return sum;
}
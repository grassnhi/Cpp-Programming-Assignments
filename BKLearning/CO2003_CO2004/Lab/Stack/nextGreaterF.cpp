#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    stack<int> s;
    vector<int> result(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++) {
        s.push(arr[i]);
        if(!s.empty() && [i] > arr[i-1]){
            result[i-1] = s.top();
        }
    }
    return result;
}



int main() {
    vector<int> nums = {15, 2, 1, 10}; // -1 4 10 -1
    vector<int> result = nextGreaterElement(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    nums = {1, 4, 6, 9, 6};
    result = nextGreaterElement(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

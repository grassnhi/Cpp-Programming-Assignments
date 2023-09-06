/*

Given an array of integers.
Your task is to implement a function with following prototype:
int sumOfMinSubarray(vector<int>& nums);
The function returns the sum of the minimum value of every subarray of nums. The sum may be too large, so the result should mod 10000.

Note:
- The iostream, vector and stack libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.

*/

int sumOfMinSubarray(vector<int>& nums) {
    const int mod = 10000;
    stack<int> stk;
    int n = nums.size();
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && nums[stk.top()] >= nums[i]) {
            stk.pop();
        }
        left[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    stk = stack<int>();
    for (int i = n-1; i >= 0; i--) {
        while (!stk.empty() && nums[stk.top()] >= nums[i]) {
            stk.pop();
        }
        right[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = (result + nums[i] * (i-left[i]) * (right[i]-i)) % mod;
    }
    return result;
}


// iostream, stack and vector are included

vector<int> nextSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> vt(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        if(st.empty()){
            st.push(i);
        }else{
            while(!st.empty()){
                if(arr[st.top()] < arr[i]){
                    vt[i] = st.top();
                    st.push(i);
                    break;
                }else{
                    st.pop();
                }
            }
            if(st.empty()){
                st.push(i);
            }
        }
    }
    return vt;
}
int sumOfMinSubarray(vector<int>& nums) {
    // STUDENT ANSWER
    long long int sum = 0;
    int n = nums.size();
    vector<int> vc = nextSmaller(nums);
    
    for(int i = 0 ;i < n;i++){
        int j = i;
        while(vc[j] != -1){
            sum+= (vc[j] - j)*nums[j];
            j = vc[j];
        }
        sum+= (n - j)*nums[j];
    }
    sum = sum %10000;
    return sum;
}

/*
Test	Result
vector<int> nums {1, 2, 4, 3};
cout << sumOfMinSubarray(nums);
20
*/
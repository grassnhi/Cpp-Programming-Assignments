/*
Implement function

int interpolationSearch(int arr[], int left, int right, int x)
to search for value x in array arr using recursion.
After traverse to an index in array, before returning the index or passing it as argument to recursive function, we print out this index using cout << "We traverse on index: " << index << endl;

Please note that you can't using key work for, while, goto (even in variable names, comment).


For example:

Test	Result
int arr[] = { 1,2,3,4,5,6,7,8,9 };
int n = sizeof(arr) / sizeof(arr[0]);
int x = 3;
int result = interpolationSearch(arr, 0, n - 1, x);
(result == -1) ? cout << "Element is not present in array"
               : cout << "Element is present at index " << result;
We traverse on index: 2
Element is present at index 2
int arr[] = { 1,2,3,4,5,6,7,8,9 };
int n = sizeof(arr) / sizeof(arr[0]);
int x = 0;
int result = interpolationSearch(arr, 0, n - 1, x);
(result == -1) ? cout << "Element is not present in array"
               : cout << "Element is present at index " << result;
Element is not present in array
*/

int interpolationSearch(int arr[], int left, int right, int x)
{
    if (left > right || arr[left] > x || arr[right] < x) return -1;
    int mid= left + ((x-arr[left])*(right-left))/(arr[right] - arr[left]);
    if (mid<left) return -1;
    if (mid>right) return -1;
    
        if(arr[mid] == x){
            cout<<"We traverse on index: "<<mid <<endl;
            return  mid ;
        }
        else if(arr[mid] < x) {
            cout<<"We traverse on index: "<<mid <<endl;
            left=mid + 1  ;
        }
        else {
            cout<<"We traverse on index: "<<mid <<endl;
            right=mid-1 ;
        }
        return interpolationSearch(arr, left, right, x);
}
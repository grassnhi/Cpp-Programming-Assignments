/*
Implement function

int binarySearch(int arr[], int left, int right, int x)
to search for value x in array arr using recursion.
After traverse an index in array, we print out this index using cout << "We traverse on index: " << index << endl;

Note that middle of left and right is floor((right-left)/2) 

For example:

Test	Result
int arr[] = {1,2,3,4,5,6,7,8,9,10};
int x = 10;
int n = sizeof(arr) / sizeof(arr[0]);
int result = binarySearch(arr, 0, n - 1, x);
(result == -1) ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
We traverse on index: 4
We traverse on index: 7
We traverse on index: 8
We traverse on index: 9
Element is present at index 9

*/
int binarySearch(int arr[], int left, int right, int x)
{
    if (left > right) return -1;
    int mid = (right + left) / 2;
    if (arr[mid] == x){
        cout << "We traverse on index: " << mid << endl;
        return mid;
    }
    else if(arr[mid] < x) {
        cout << "We traverse on index: " << mid << endl;
        left = mid + 1;
    }
    else {
        cout << "We traverse on index: " << mid << endl;
        right = mid -1;
    }
    return binarySearch(arr, left, right, x);
}
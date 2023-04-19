/*
In computer science, a jump search or block search refers to a search algorithm for ordered lists. The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps or skipping some elements in place of searching all elements. For example, suppose we have an array arr[] of size n and block (to be jumped) size m. Then we search at the indexes arr[0], arr[m], arr[2m]…..arr[km] and so on. Once we find the interval (arr[km] < x < arr[(k+1)m]), we perform a linear search operation from the index km to find the element x. The optimal value of m is √n, where n is the length of the list.



In this question, we need to implement function jumpSearch with step √n to search for value x in array arr. After searching at an index, we should print that index until we find the index of value x in array or until we determine that the value is not in the array.


int jumpSearch(int arr[], int x, int n)
For example:

Test	Result
int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
int x = 55;
int n = sizeof(arr) / sizeof(arr[0]);
int index = jumpSearch(arr, x, n);

if (index != -1) {
    cout << "\nNumber " << x << " is at index " << index;
}
else {
    cout << "\n" << x << " is not in array!";
}
0 4 8 12 9 10
Number 55 is at index 10
int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
int x = 144;
int n = sizeof(arr) / sizeof(arr[0]);
int index = jumpSearch(arr, x, n);

if (index != -1) {
    cout << "\nNumber " << x << " is at index " << index;
}
else {
    cout << "\n" << x << " is not in array!";
}
0 4 8 12
Number 144 is at index 12

*/

int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = sqrt(n);
    int prev = 0;
    int i;
    for (i = 0; i < n; i += step) {
        if (arr[i] <= x) prev = i;
        if (arr[i] == x) {
            cout << i;
            return i;
        }
        cout << i << " ";
        if (arr[i] > x) break;
    }
    if (prev > n - 1) return -1;
    else {
        for (int j = prev; j < i; j++) {
            if (arr[j] == x) {
                cout << j;
                return j;
            }
            if (j != prev) cout << j << " ";
            if (arr[j] > x) break;
        }
    }
    return -1;
}
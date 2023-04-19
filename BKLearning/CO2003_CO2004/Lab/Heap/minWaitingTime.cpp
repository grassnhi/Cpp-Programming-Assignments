/*
In a fast food restaurant, a customer is served by following the first-come, first-served rule. The manager wants to minimize the total waiting time of his customers. So he gets to decide who is served first, regardless of how sooner or later a person comes.


Different kinds of food take different amounts of time to cook. And he can't cook food for two customers at the same time, which means when he start cooking for customer A, he has to finish A 's order before cooking for customer B. For example, if there are 3 customers and they come at time 0, 1, 2 respectively, the time needed to cook their food is 3, 9, 6 respectively. If the manager uses first-come, first-served rule to serve his customer, the total waiting time will be 3 + 11 + 16 = 30. In case the manager serves his customer in order 1, 3, 2, the total waiting time will be 3 + 7 + 17 = 27.  



Note: The manager does not know about the future orders.


In this question, you should implement function minWaitingTime to help the customer find minimum total waiting time to serve all his customers. You are also encouraged to use data structure Heap to complete this question. You can use your own code of Heap, or use functions related to Heap in library <algorithm>.






For example:

Test	Result
int n = 3; 
int arrvalTime[] = { 0, 1, 2 };
int completeTime[] = { 3, 9, 6 };

cout << minWaitingTime(n, arrvalTime, completeTime);
27
int n = 4; 
int arrvalTime[] = { 0, 4, 2, 5 };
int completeTime[] = { 4, 2, 3, 4 };

cout << minWaitingTime(n, arrvalTime, completeTime);
21

*/

#include <iostream>
using namespace std;

void heapify(int *arr, int n, int i);
void buildHeap(int *arr, int n);
void insert(int *arr, int &n, int val);
int extractMax(int *arr, int &n);

int minWaitingTime(int n, int* arrivalTime, int* cookTime);

int main() {
    // Test case 1
    int n = 3;
    int arrvalTime[] = {0, 1, 2};
    int completeTime[] = {3, 9, 6};

    cout << "Test case 1: " << minWaitingTime(n, arrvalTime, completeTime) << "\n";

    // Test case 2
    n = 4;
    int arrvalTime2[] = {0, 4, 2, 5};
    int completeTime2[] = {4, 2, 3, 4};

    cout << "Test case 2: " << minWaitingTime(n, arrvalTime2, completeTime2) << "\n";

    return 0;
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int *arr, int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void insert(int *arr, int &n, int val) {
    arr[n++] = val;
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int extractMax(int *arr, int &n) {
    int maxVal = arr[0];
    arr[0] = arr[--n];
    heapify(arr, n, 0);
    return maxVal;
}

int minWaitingTime(int n, int* arrivalTime, int* cookTime) {
    // Calculate the completion times for each customer's order
    int *completeTime = new int[n];
    completeTime[0] = arrivalTime[0] + cookTime[0];
    for (int i = 1; i < n; i++) {
        completeTime[i] = max(completeTime[i-1], arrivalTime[i]) + cookTime[i];
    }

    // Use a heap to track the completion times of orders
    int *heap = new int[n];
    int heapSize = 0;

    // Insert the first completion time into the heap
    insert(heap, heapSize, completeTime[0]);

    int waitTime = 0;

    for (int i = 1; i < n; i++) {
        // Extract the minimum completion time from the heap
        int minTime = extractMax(heap, heapSize);

        // Calculate the wait time and add it to the total wait time
        waitTime += max(0, minTime - arrivalTime[i]);

        // Add the current customer's completion time to the heap
        insert(heap, heapSize, completeTime[i]);
    }

    delete[] completeTime;
    delete[] heap;

    return waitTime;
}

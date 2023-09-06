#include <bits/stdc++.h>
using namespace std;

// ex 1
int foldShift(long long key, int addressSize)
{
    long long int multiple = pow(10, addressSize);
    string str = to_string(key);
    string temp = "";
    int ans = 0;
    for (unsigned int i = 0; i < (to_string(key).length()) / addressSize; i++)
    {
        temp = "";
        for (int j = 0; j < addressSize; j++)
        {
            temp += str[0];
            str.erase(0, 1);
        }
        ans += stoi(temp);
    }
    if (str.length() != 0)
        ans += stoi(str);
    return (ans) % multiple;
}

int rotation(long long key, int addressSize)
{
    string str = to_string(key);
    long long int ans;
    int temp = key % 10;
    key = key / 10;
    ans = pow(10, str.length() - 1) * temp + key;
    return foldShift(ans, addressSize);
}

// ex 2
long int midSquare(long int seed)
{
    string ans = to_string(seed * seed);
    long int num = stoi(ans);
    num = num / 100;
    num = num % 10000;
    return num;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}
long int digitExtraction(long int seed, int *extractDigits, int size)
{
    string str = to_string(seed);
    string ans = "";
    for (int i = 0; i < size; i++)
        ans += str[extractDigits[i]];
    return stoi(ans);
}

// ex 3
int pairMatching(vector<int> &nums, int target)
{
    int count = 0;
    unordered_map<int, int> mapX;
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        if (mapX.count(nums[i]))
            mapX[nums[i]]++;
        else
            mapX.insert(make_pair(nums[i], 1));
    }
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        int value = target - nums[i];
        if (mapX.count(value) && mapX.count(nums[i]))
        {
            if ((value == nums[i] && mapX[nums[i]] > 1) || value != nums[i])
            {
                mapX[value]--;
                if (mapX[value] == 0)
                    mapX.erase(value);
                mapX[nums[i]]--;
                if (mapX[nums[i]] == 0)
                    mapX.erase(nums[i]);
                count++;
            }
        }
        else
            mapX.erase(nums[i]);
    }
    return count;
}

// ex 4
int binarySearch(int arr[], int left, int right, int x)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    cout << "We traverse on index: " << mid << endl;
    if (x > arr[mid])
        return binarySearch(arr, mid + 1, right, x);
    else if (x < arr[mid])
        return binarySearch(arr, left, mid - 1, x);
    else
        return mid;
}

// ex 5
bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
    // Create a map to store sum of each pair
    map<int, pair<int, int>> mp;

    // Iterate over all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate the sum of the current pair
            int sum = arr[i] + arr[j];

            // Check if the sum is already in the map
            if (mp.find(sum) != mp.end()) {
                // Retrieve the other pair
                pair<int, int> other_pair = mp[sum];

                // Check if all the elements are distinct
                if (arr[i] != other_pair.first && arr[i] != other_pair.second
                   && arr[j] != other_pair.first && arr[j] != other_pair.second) {
                    // Found a match
                    pair1 = make_pair(arr[i], arr[j]);
                    pair2 = other_pair;
                    return true;
                }
            } else {
                // If the sum is not in the map, add the current pair to the map
                mp[sum] = make_pair(arr[i], arr[j]);
            } 
        }
    }
    // If no match is found, return false
    return false;
}


// ex 6
int interpolationSearch(int arr[], int left, int right, int x)
{
    if (left > right)
    {
        return -1; // Value not found
    }

    int mid = left + double((right - left)) / (arr[right] - arr[left]) * (x - arr[left]);
    if (mid < left || mid > right)
        return -1; // Value not found
    if (x < arr[left] || x > arr[right])
        return -1;
    cout << "We traverse on index: " << mid << endl;

    if (arr[mid] == x)
    {
        return mid; // Value found
    }
    else if (arr[mid] < x)
    {
        return interpolationSearch(arr, mid + 1, right, x);
    }
    else
    {
        return interpolationSearch(arr, left, mid - 1, x);
    }
}
// ex 7
int jumpSearch(int arr[], int x, int n)
{
    // TODO: print the traversed indexes and return the index of value x in array if x is fo
    int dis = sqrt(n);
    int i = 0;
    for (; i < n; i = i + dis)
    {
        cout << i << " ";
        if (arr[i] >= x)
        {
            if (arr[i] == x)
                return i;
            for (int j = i - dis + 1; j < i; j++)
            {
                cout << j << " ";
                if (arr[j] == x)
                    return j;
            }
            return -1;
        }
    }
    if (i != n - 1)
    {
        i = i - dis + 1;
        for (; i < n; i++)
        {
            cout << i << " ";
            if (arr[i] == x)
                return i;
        }
        cout << i << " ";
    }
    return -1;
}
// ex 8
template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    // Helping functions go here
    static void heapify(T *start, T *end, int idx)
    {
        int size = end - start;
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (left < size && start[left] > start[largest])
            largest = left;
        if (right < size && start[right] > start[largest])
            largest = right;
        if (largest != idx)
        {
            swap(start[idx], start[largest]);
            heapify(start, end, largest);
        }
    }
    static void heapSort(T *start, T *end)
    {
        // TODO
        int size = end - start;
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(start, end, i);
        for (int i = size - 1; i > 0; i--)
        {
            swap(start[0], start[i]);
            heapify(start, start + i, 0);
        }
        Sorting<T>::printArray(start, end);
    }
};

// ex 9
bool cmp1(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int minWaitingTime(int n, int arrvalTime[], int completeTime[])
{
    // YOUR CODE HERE
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    map<int, int> mapX;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
        arr.push_back(make_pair(arrvalTime[i], completeTime[i]));
    sort(arr.begin(), arr.end(), cmp1);
    int count = 0;
    int currTime = arr[0].first;
    int totalTime = 0;
    int idx = 0;
    while (idx < n)
    {
        while (count < n && arr[count].first <= currTime)
        {
            pq.push(make_pair(arr[count].first, arr[count].second));
            count++;
        }
        if ((count < n && !(arr[count].first <= currTime)) && pq.empty())
        {
            currTime = arr[count].first;
            while (count < n && arr[count].first <= currTime)
            {
                pq.push(make_pair(arr[count].first, arr[count].second));
                count++;
            }
        }
        totalTime += (currTime + pq.top().second - pq.top().first);
        currTime += pq.top().second;
        pq.pop();
        idx++;
    }
    return totalTime;
}

// ex 11
class PrinterQueue
{
    // your attributes
public:
    // your methods
    class request;
    struct cmp
    {
        bool operator()(request a, request b)
        {
            if (a.levelPri == b.levelPri)
            {
                return a.order > b.order;
            }
            return a.levelPri < b.levelPri;
        }
    };

    int count;
    priority_queue<request, vector<request>, cmp> resQueue;

    PrinterQueue()
    {
        this->count = 0;
    }
    void addNewRequest(int priority, string fileName)
    {
        // your code here
        request temp_rq(priority, fileName, this->count);
        this->resQueue.push(temp_rq);
        this->count++;
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline
        if (this->count == 0)
            cout << "No file to print\n";
        else
        {
            cout << this->resQueue.top().fileName << endl;
            this->resQueue.pop();
            this->count--;
        }
    }
    class request
    {
    public:
        int levelPri;
        string fileName;
        int order;
        request(int priority, string fileName, int count)
        {
            this->order = count;
            this->levelPri = priority;
            this->fileName = fileName;
        }
    };
};

// ex 13
int reduceSum(vector<int> &nums)
{
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> pq;
    for (unsigned int i = 0; i < nums.size(); i++)
        pq.push(nums[i]);
    int sum = 0;
    while (pq.size() > 1)
    {
        int temp_sum = pq.top();
        pq.pop();
        temp_sum += pq.top();
        pq.pop();
        sum += temp_sum;
        pq.push(temp_sum);
    }
    return sum;
}

// ex 15
template <class T>
class Heap
{
protected:
    T *elements;
    int capacity;
    int count;

public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[] elements;
    }
    void push(T item);
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }

private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

template <class T>
int Heap<T>::getItem(T item)
{
    // TODO: return the index of item in heap
    for (int i = 0; i < this->count; i++)
    {
        if (item == this->elements[i])
            return i;
    }
    return -1;
}

template <class T>
void Heap<T>::remove(T item)
{
    // TODO: remove the element with value equal to item
    while (true)
    {
        int idx = getItem(item);
        if (idx == this->count || idx == -1)
            return;
        swap(elements[idx], elements[this->count - 1]);
        this->count--;
        if (idx == 0 || elements[idx] <= elements[(idx - 1) / 2])
            reheapDown(idx);
        else
            reheapUp(idx);
    }
}

template <class T>
void Heap<T>::clear()
{
    // TODO: delete all elements in heap
    this->count = 0;
}

// ex 10
template <class T>
int Heap<T>::size()
{
    return this->count;
}

template <class T>
bool Heap<T>::isEmpty()
{
    return this->count == 0;
}

template <class T>
T Heap<T>::peek()
{
    if (this->count != 0)
        return this->elements[0];
    return -1;
}

template <class T>
bool Heap<T>::contains(T item)
{
    for (int i = 0; i < this->count - 1; i++)
        if (this->elements[i] == item)
            return true;
    return false;
}

template <class T>
bool Heap<T>::pop()
{
    if (this->count == 0)
        return false;
    elements[0] = elements[this->count - 1];
    this->count--;
    this->reheapDown(0);
    return true;
}

// ex 12
template <class T>
void Heap<T>::push(T item)
{
    this->ensureCapacity(this->count + 1);
    this->elements[count] = item;
    this->count++;
    this->reheapUp(this->count - 1);
}

template <class T>
void Heap<T>::ensureCapacity(int minCapacity)
{
    int old_cap = this->capacity;
    if (minCapacity >= capacity)

        this->capacity = old_cap + (old_cap >> 2);
    T *new_ele = new T[this->capacity];
    for (int i = 0; i < old_cap; i++)
        new_ele[i] = this->elements[i];
    delete[] this->elements;
    this->elements = new_ele;
}

template <class T>
void Heap<T>::reheapUp(int position)
{
    if (position <= 0)
        return;
    int parent = (position - 1) / 2;
    if (this->elements[position] > this->elements[parent])
    {
        swap(this->elements[position], this->elements[parent]);
        reheapUp(parent);
    }
}
// ex 14
void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;
    if (left < numberOfElements && maxHeap[left] > maxHeap[largest])
        largest = left;
    if (right < numberOfElements && maxHeap[right] > maxHeap[largest])
        largest = right;
    if (largest != index)
    {
        swap(maxHeap[largest], maxHeap[index]);
        reheapDown(maxHeap, numberOfElements, largest);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if (index >= numberOfElements)
        return;
    int parent = (index - 1) / 2;
    if (maxHeap[parent] < maxHeap[index])
    {
        swap(maxHeap[parent], maxHeap[index]);
        reheapUp(maxHeap, numberOfElements, parent);
    }
}

// ex 16
int leastAfter(vector<int> &nums, int k)
{
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> pq;
    for (unsigned int i = 0; i < nums.size(); i++)
        pq.push(nums[i]);
    for (int i = 0; i < k; i++)
    {
        int temp = pq.top();
        pq.pop();
        pq.push(temp * 2);
    }
    return pq.top();
}
int main()
{
	
    int n = 4;
    int arrvalTime[] = { 5, 5, 10, 20 };
    int completeTime[] = {2, 4, 3, 1};

    cout << minWaitingTime(n, arrvalTime, completeTime);
    return 0;
}
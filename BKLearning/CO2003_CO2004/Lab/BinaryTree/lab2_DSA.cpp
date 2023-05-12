#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

// ex 2
vector<int> nextGreater(vector<int> &arr)
{
    vector<int> ans(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}
// ex 3
string reverse(string s, int firstIdx)
{
    string ans = s;
    int j = 0;
    for (unsigned int i = firstIdx; i <= (firstIdx + ans.length() - 1 - 1) / 2; i++, j++)
        swap(ans[i], ans[ans.length() - 1 - j]);
    return ans;
}
string parenthesesReversal(string s)
{
    // STUDENT ANSWER
    // stack<char> temp;
    stack<int> sign;
    string ans = "";
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            sign.push(ans.length());
        else if (s[i] == ')')
        {
            int temp = sign.top();
            sign.pop();
            ans = reverse(ans, temp);
        }
        else
            ans += s[i];
    }
    return ans;
}

// ex 4
string removeDuplicates(string S)
{
    /*TODO*/
    stack<char> temp;
    temp.push(S[0]);
    for (unsigned int i = 1; i < S.length(); i++)
    {
        if (!temp.empty() && S[i] == temp.top())
        {
            i--;
            S.erase(i, 2);
            temp.pop();
            i--;
        }
        else
            temp.push(S[i]);
    }
    return S;
}

// ex 5
string deleteDuplicate(string s, int k)
{
    stack<char> temp;
    stack<int> countStack;
    temp.push(s[0]);
    countStack.push(1);
    for (unsigned int i = 1; i < s.length(); i++)
    {
        if (!temp.empty() && s[i] == temp.top())
        {
            int count = 0;
            int j = i;
            while (s[j] == temp.top())
            {
                count++;
                j++;
            }
            if ((count + countStack.top()) >= k)
            {
                i -= countStack.top();
                s.erase(i, k);
                i--;
                temp.pop();
                countStack.pop();
            }
            else
            {
                countStack.top() += count;
                i += count - 1;
            }
        }
        else
        {
            temp.push(s[i]);
            countStack.push(1);
        }
    }
    return s;
}

// ex 6
int sumOfMinSubarray(vector<int> &nums)
{
    // STUDENT ANSWER
    long long int ans = 0;
    vector<int> temp;
    int min = 100000;
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        ans += nums[i];
        if (nums[i] < min)
            min = nums[i];
        ans += i * min;
    }
    return ans % 100000007;
}

// ex 7
bool isValidParentheses(string s)
{
    /*TODO*/
    stack<char> sign;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            sign.push(s[i]);
        else
        {
            if (!sign.empty())
            {
                if (s[i] == ')' && sign.top() == '(')
                    sign.pop();
                else if (s[i] == ']' && sign.top() == '[')
                    sign.pop();
                else if (s[i] == '}' && sign.top() == '{')
                    sign.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (!sign.empty())
        return false;
    return true;
}

// ex 8

// void push(T item) {
//     // TODO: Push new element into the end of the queue
//     list.add(item);
// }

// T pop() {
//     // TODO: Remove an element in the head of the queue
//     return list.removeAt(0);
// }

// T top() {
//     // TODO: Get value of the element in the head of the queue
//     return list.get(0);
// }

// bool empty() {
//     // TODO: Determine if the queue is empty
//     return list.empty();
// }

// int size() {
//     // TODO: Get the size of the queue
//     return list.size();
// }

// void clear() {
//     // TODO: Clear all elements of the queue
//     list.clear();
// }

// ex 9
long long nthNiceNumber(int n)
{
    int count = 0;
    queue<long long int> temp;
    temp.push(0);
    int k = temp.back();
    while (count != n)
    {
        temp.push(temp.front() * 10 + 2);
        count++;
        if (count == n)
            break;
        temp.push(temp.front() * 10 + 5);
        count++;
        temp.pop();
    }
    return temp.back();
}

// ex 10
int numberOfTheWinner(int N, int k)
{
    int count = N;
    queue<int> temp;
    for (int i = 1; i <= N; i++)
        temp.push(i);
    while (count != 1)
    {
        for (int i = 1; i < k; i++)
        {
            temp.push(temp.front());
            temp.pop();
        }
        temp.pop();
        count--;
    }
    return temp.front();
}

// ex 11
int sumOfMaxSubarray(vector<int> &nums, int k)
{
    // STUDENT ANSWER
    vector<int> temp;
    for (int i = 0; i < k - 1; i++)
        temp.push_back(nums[i]);
    int ans = 0;
    for (unsigned int i = k - 1; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        ans += *max_element(temp.begin(), temp.end());
        temp.erase(temp.begin());
    }
    return ans;
}

// ex 12
template <class T>
class SLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = 0;
        }
        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort();
};

template <class T>
void SLinkedList<T>::bubbleSort()
{
    for (int i = 0; i < this->size() - 1; i++)
    {
        for (Node *k = this->head; k->next != nullptr; k = k->next)
        {
            if (k->data > k->next->data)
                swap(k->data, k->next->data);
        }
        this->printList();
    }
}

// ex 13
template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void oddEvenSort(T *start, T *end);
    static void selectionSort(T *start, T *end);
    static T *Partition(T *start, T *end);
    static void insertionSort(T *start, T *end);
    static void hybridQuickSort(T *start, T *end, int min_size);

    // ex 15

    static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total)
    {
        // TODO
        int size = end - start;
        int current = segment_idx;
        int walker;
        while (current < size)
        {
            walker = current + cur_segment_total;
            while (walker < size)
            {
                if (start[walker] < start[current])
                    swap(start[walker], start[current]);
                walker += cur_segment_total;
            }
            current += cur_segment_total;
        }
    }

    static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases)
    {
        // TODO
        // Note: You must print out the array after sorting segments to check whether your algorithm is true.
        for (int k = num_phases - 1; k >= 0; k--)
        {
            int nsegment = num_segment_list[k];
            cout << nsegment << " "
                 << "segments: ";
            for (int i = 0; i < nsegment; i++)
                sortSegment(start, end, i, nsegment);
            printArray(start, end);
        }
    }
};

// ex 13
template <class T>

T *Sorting<T>::Partition(T *start, T *end)

{
    int len = end - start;
    T pivot = start[0];
    int left = 1, right = len - 1;
    while (true)

    {
        while (left <= right && start[left] < pivot)
        {
            left++;
        }
        while (right >= left && pivot < start[right])
        {
            right--;
        }

        if (left >= right)

        {
            break;
        }
        swap(start[left], start[right]);
        left++;
        right--;
    }
    swap(start[0], start[right]);
    return start + right;
}

template <class T>

void Sorting<T>::insertionSort(T *start, T *end)

{
    int len = end - start;
    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        T temp = start[i];
        while (j >= 0 && temp < start[j])
        {
            start[j + 1] = start[j];
            j--;
        }
        start[j + 1] = temp;
    }
}

template <class T>

void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)

{
    cout << end - start;
    int len = end - start;

    if (len < min_size)

    {

        cout << "Insertion sort: ";

        Sorting::printArray(start, end);

        insertionSort(start, end);

        return;
    }

    else

    {

        cout << "Quick sort: ";

        Sorting::printArray(start, end);

        T *pivot = Partition(start, end);

        if (pivot != start)

        {

            hybridQuickSort(start, pivot, min_size);
        }

        if (pivot != end - 1)

        {

            hybridQuickSort(pivot + 1, end, min_size);
        }
    }
}

// ex 14
template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    /*TODO*/
    bool isSwap = false;
    while (isSwap == false)
    {
        isSwap = true;
        for (int i = 0; i < (end - start) - 1; i += 2)
        {
            if (start[i] > start[i + 1])
            {
                swap(start[i], start[i + 1]);
                isSwap = false;
            }
        }
        for (int i = 1; i < (end - start) - 1; i += 2)
        {
            if (start[i] > start[i + 1])
            {
                swap(start[i], start[i + 1]);
                isSwap = false;
            }
        }
        printArray(start, end);
    }
}

// ex 16
template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int minIdx = 0;
    for (int i = 0; i < end - start - 1; i++)
    {
        minIdx = i;
        for (int j = i + 1; j < end - start; j++)
        {
            if (start[j] < start[minIdx])
                minIdx = j;
        }
        swap(start[i], start[minIdx]);
        printArray(start, end);
    }
}

//////////////////////////////////// BINARY TREE ////////////////////////////////////

// ex1
template <class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node *walker = this->root;
        int l = (int)posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // Helping functions
    int getHeight(Node *root)
    {
        if (root == nullptr)
            return 0;
        int leftHeight = getHeight(root->pLeft);
        int rightHeight = getHeight(root->pRight);
        return 1 + max(leftHeight, rightHeight);
    }

    // ex 1
    int getDiameter(Node *root)
    {
        // TODO
        if (root == nullptr)
            return 0;
        int leftHeight = getHeight(root->pLeft);
        int rightHeight = getHeight(root->pRight);

        int dia1 = leftHeight + rightHeight + 1;
        int dia2 = getDiameter(root->pLeft);
        int dia3 = getDiameter(root->pRight);

        return max(dia1, max(dia2, dia3));
    }

    int getDiameter()
    {
        return getDiameter(this->root);
    }
    // ex 2 + 12
    // using recursion

    int getHeight()
    {
        return getHeight(this->root);
    }
    // ex 12
    void preOrderHelper(Node *node, stringstream &ss)
    {
        if (node != nullptr)
        {
            ss << node->value << " ";
            preOrderHelper(node->pLeft, ss);
            preOrderHelper(node->pRight, ss);
        }
    }

    void inOrderHelper(Node *node, stringstream &ss)
    {
        if (node != nullptr)
        {
            inOrderHelper(node->pLeft, ss);
            ss << node->value << " ";
            inOrderHelper(node->pRight, ss);
        }
    }

    void postOrderHelper(Node *node, stringstream &ss)
    {
        if (node != nullptr)
        {
            postOrderHelper(node->pLeft, ss);
            postOrderHelper(node->pRight, ss);
            ss << node->value << " ";
        }
    }

    string preOrder()
    {
        stringstream ss;
        preOrderHelper(root, ss);
        return ss.str();
    }

    string inOrder()
    {
        stringstream ss;
        inOrderHelper(root, ss);
        return ss.str();
    }

    string postOrder()
    {
        stringstream ss;
        postOrderHelper(root, ss);
        return ss.str();
    }
    void printLevel(Node *root, int level)
    {
        if (root == nullptr)
            return;
        if (level == 1)
            cout << root->value << " ";
        else
        {
            printLevel(root->pLeft, level - 1);
            printLevel(root->pRight, level - 1);
        }
    }
    // ex 2
    // void BFS()
    // {
    //     int h = getHeight(this->root);
    //     for (int i = 1; i <= h; i++)
    //         printLevel(this->root, i);
    // }
    // using queue
    void BFS()
    {
        queue<Node *> temp;
        temp.push(this->root);
        while (!temp.empty())
        {
            if (temp.front()->pLeft != nullptr)
                temp.push(temp.front()->pLeft);
            if (temp.front()->pRight != nullptr)
                temp.push(temp.front()->pRight);
            cout << temp.front()->value << " ";
            temp.pop();
        }
    }
    // ex 11
    int count2ChildNode(Node *root)
    {
        if (root == nullptr)
            return 0;
        if (root->pLeft == nullptr || root->pRight == nullptr)
            return 0;
        return 1 + count2ChildNode(root->pLeft) + count2ChildNode(root->pRight);
    }
    int countTwoChildrenNode()
    {
        return count2ChildNode(this->root);
    }

    // ex 13
    int sumLeafs(Node *root)
    {
        if (root == nullptr)
            return 0;
        if (root->pLeft == nullptr && root->pRight == nullptr)
            return root->value;
        return sumLeafs(root->pLeft) + sumLeafs(root->pRight);
    }
    int sumOfLeafs()
    {
        // TODO
        return sumLeafs(this->root);
    }

    // ex 13 way 2
    //  int sumLeafs(Node *root)
    //  {
    //      if (root == nullptr)
    //          return 0;
    //      int sumLeft = sumLeafs(root->pLeft);
    //      int sumRight = sumLeafs(root->pRight);
    //      if (root->pLeft == nullptr && root->pRight == nullptr)
    //          return root->value + sumLeft + sumRight;
    //      else
    //          return sumLeft + sumRight;
    //  }
    //  int sumOfLeafs(){
    //      //TODO
    //      return sumLeafs(this->root);
    //  }
};

// ex 4
class BTNode
{
public:
    int val;
    BTNode *left;
    BTNode *right;
    BTNode()
    {
        this->left = this->right = NULL;
    }
    BTNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
    BTNode(int val, BTNode *&left, BTNode *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};
bool checkGreatAncestor(BTNode *root, int rootVal)
{
    if (root == nullptr)
        return true;
    if (root->val > rootVal)
        return false;
    else
        return true && checkGreatAncestor(root->left, rootVal) && checkGreatAncestor(root->right, rootVal);
}
int greatAncestor(BTNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    int sumLeft = greatAncestor(root->left);
    int sumRight = greatAncestor(root->right);
    if (checkGreatAncestor(root, root->val))
        return 1 + sumLeft + sumRight;
    else
        return sumLeft + sumRight;
}

// ex3
int absoluteval(int val);
int sumofSubtree(BTNode *root)
{
    if (root == nullptr)
        return 0;
    return root->val + sumofSubtree(root->left) + sumofSubtree(root->right);
}

int diffOfSubtree(BTNode *root)
{
    if (root == nullptr)
        return 0;
    return absoluteval(sumofSubtree(root->left) - sumofSubtree(root->right));
}
int distinctParities(BTNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr || root->right == nullptr)
        return distinctParities(root->left) + distinctParities(root->right);
    if (diffOfSubtree(root) % 2 == 1)
        return 1 + distinctParities(root->left) + distinctParities(root->right);
    else
        return distinctParities(root->left) + distinctParities(root->right);
}

// ex 5
int absoluteval(int val)
{
    if (val >= 0)
        return val;
    return -val;
}
int maxDiffWithDescendant(BTNode *root, int rootVal)
{
    if (root == nullptr)
        return 0;
    int maxDiff = absoluteval(root->val - rootVal);

    int diffLeft = maxDiffWithDescendant(root->left, rootVal);
    int diffRight = maxDiffWithDescendant(root->right, rootVal);

    if (diffLeft > maxDiff)
        maxDiff = diffLeft;
    if (diffRight > maxDiff)
        maxDiff = diffRight;
    return maxDiff;
}
int largestDiff(BTNode *root)
{
    if (root == nullptr)
        return 0;

    int largeDiff = maxDiffWithDescendant(root, root->val);

    int largeLeft = largestDiff(root->left);
    int largeRight = largestDiff(root->right);

    if (largeDiff < largeLeft)
        largeDiff = largeLeft;

    if (largeDiff < largeRight)
        largeDiff = largeRight;

    return largeDiff;
}

// ex 6
void longestPathSumHelper(BTNode *root, int sum_so_far, int len_so_far, int &longest_sum, int &longest_len)
{
    if (root == nullptr)
        return;
    sum_so_far += root->val;
    len_so_far++;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (len_so_far > longest_len || (len_so_far == longest_len && sum_so_far > longest_sum))
        {
            longest_sum = sum_so_far;
            longest_len = len_so_far;
        }
    }
    else
    {
        longestPathSumHelper(root->left, sum_so_far, len_so_far, longest_sum, longest_len);
        longestPathSumHelper(root->right, sum_so_far, len_so_far, longest_sum, longest_len);
    }
}

int longestPathSum(BTNode *root)
{
    if (root == nullptr)
        return 0;
    int longest_sum = root->val;
    int longest_len = 1;
    longestPathSumHelper(root->left, root->val, 1, longest_sum, longest_len);
    longestPathSumHelper(root->right, root->val, 1, longest_sum, longest_len);
    return longest_sum;
}
// ex 7

int lowestAncestor(BTNode *root, int a, int b)
{
    if (root == nullptr)
        return -1;
    if (root->val == a || root->val == b)
        return root->val;
    int leftVal = lowestAncestor(root->left, a, b);
    int rightVal = lowestAncestor(root->right, a, b);

    if (leftVal != -1 && rightVal != -1)
        return root->val;
    else
        return leftVal != -1 ? leftVal : rightVal;
}

// ex 8
vector<int> ans;
int sumOfsubTree(BTNode *root)
{
    if (root == nullptr)
        return 0;
    int res = root->val + sumOfsubTree(root->left) + sumOfsubTree(root->right);
    ans.push_back(res);
    return res;
}
int maximizeProduct(BTNode *root)
{
    sumOfsubTree(root);
    int result = 0;
    int totalSum = sumOfsubTree(root);
    for (unsigned int i = 0; i < ans.size(); i++)
        result = max(result, (totalSum - ans[i]) * ans[i]);
    return result;
}

// ex 9

int secondDeepest(BTNode *root)
{
    if (root == nullptr)
        return 0;
    queue<BTNode *> temp;
    queue<int> totalDepth;
    temp.push(root);
    queue<int> depth;
    depth.push(0);
    while (!temp.empty())
    {
        if (temp.front()->left == nullptr && temp.front()->right == nullptr)
            totalDepth.push(depth.front());
        else
        {
            if (temp.front()->left != nullptr)
            {
                temp.push(temp.front()->left);
                depth.push(depth.front() + 1);
            }
            if (temp.front()->right != nullptr)
            {
                temp.push(temp.front()->right);
                depth.push(depth.front() + 1);
            }
        }
        temp.pop();
        depth.pop();
    }
    int maxdepth = 0;
    queue<int> maxD = totalDepth;
    int size = totalDepth.size();
    for (int i = 0; i < size; i++)
    {
        maxdepth = max(maxdepth, maxD.front());
        maxD.pop();
    }
    int secondepth = -1;
    for (int i = 0; i < size; i++)
    {
        if (totalDepth.front() != maxdepth && totalDepth.front() > secondepth)
            secondepth = totalDepth.front();
        totalDepth.pop();
    }
    return secondepth;
}

// ex10
int sdp(BTNode *root, int num)
{
    if (root == nullptr)
        return 0;
    num = (num * 10 + root->val) % 27022001;
    if (root->left == nullptr && root->right == nullptr)
        return num;
    // int leftSum = sdp(root->left, num);
    // int rightSum = sdp(root->right, num);
    return (sdp(root->left, num) + sdp(root->right, num)) % 27022001;
}
int sumDigitPath(BTNode *root)
{
    return sdp(root, 0) % 27022001;
}

int main()
{
    int array[] = {1, 2, 6, 4, 7, 8, 5, 3};
    int min_size = 4;
    Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
    system("pause");
    return 0;
}
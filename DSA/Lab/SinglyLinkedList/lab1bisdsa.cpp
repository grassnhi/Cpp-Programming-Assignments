#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
/////////////////// singly ///////////////////
//ex1
LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    LLNode *i = l0;
    LLNode *j = l1;
    LLNode *ans = nullptr;
    LLNode *tail = nullptr;
    int carry = 0;
    for (; (i != nullptr && j != nullptr); i = i->next, j = j->next)
    {
        LLNode *temp = new LLNode((i->val + j->val + carry) % 10, nullptr);
        carry = (i->val + j->val + carry) / 10;
        if (ans == nullptr)
            ans = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    while (i != nullptr)
    {
        LLNode *temp = new LLNode((i->val + carry) % 10, nullptr);
        carry = (i->val + carry) / 10;
        tail->next = temp;
        tail = temp;
        i = i->next;
    }
    while (j != nullptr)
    {
        LLNode *temp = new LLNode((j->val + carry) % 10, nullptr);
        carry = (j->val + carry) / 10;
        tail->next = temp;
        tail = temp;
        j = j->next;
    }
    if (carry != 0)
    {
        LLNode *temp = new LLNode(carry, nullptr);
        tail->next =temp;
        tail = temp;
    }
    return ans;
}
//ex2
void LinkedList::partition(int k) {
    class Node *smallerHead = nullptr, *smallerTail = nullptr;
    class Node *equalHead = nullptr, *equalTail = nullptr;
    class Node *greaterHead = nullptr, *greaterTail = nullptr;
    class Node *temp = this->head;
    while (temp != nullptr)
    {
        if (temp->value < k)
        {
            if (smallerHead == nullptr)
                smallerHead = smallerTail = temp;
            else
            {
                smallerTail->next = temp;
                smallerTail = smallerTail->next; 
            }
        }
        else if (temp->value == k)
        {
            if (equalHead == nullptr)
                equalHead = equalTail = temp;
            else
            {
                equalTail->next = temp;
                equalTail = equalTail->next;
            }
        }
        else
        {
            if (greaterHead == nullptr)
                greaterHead = greaterTail = temp;
            else
            {
                greaterTail->next = temp;
                greaterTail = greaterTail->next;
            }
        }
        temp = temp->next;
    }
    if (greaterTail != nullptr)
        greaterTail->next = nullptr;
    if (equalTail != nullptr)
        equalTail->next = nullptr;
    if (smallerTail != nullptr)
        smallerTail->next = nullptr;
    if (smallerHead == nullptr)
    {
        if (equalHead == nullptr)
        {
            this->head = greaterHead;
            this->tail = greaterTail;
        }
        else if (greaterTail == nullptr)
        {
            this->head = equalHead;
            this->tail = equalTail;
        }
        else
        {
            this->head = equalHead;
            equalHead->next = greaterHead;
            this->tail = greaterTail;
        }
    }
    else if (equalHead == nullptr)
    {
        if  (smallerHead == nullptr)
        {
            this->head = greaterHead;
            this->tail = greaterTail;
        }
        else if (greaterHead == nullptr)
        {
            this->head = smallerHead;
            this->tail = smallerTail;
        }
        else
        {
            this->head = smallerHead;
            smallerTail->next = greaterHead;
            this->tail = greaterTail;
        }
    }
    else if (greaterHead == nullptr)
    {
        if (smallerHead == nullptr)
        {
            this->head = equalHead;
            this->tail = equalTail;
        }
        else if (equalHead == nullptr)
        {
            this->head = smallerHead;
            this->tail = smallerTail;
        }
        else
        {
            this->head = smallerHead;
            smallerTail->next = equalHead;
            this->tail = equalTail;
        }
    }
    else
    {
        this->head = smallerHead;
        smallerTail->next = equalHead;
        equalTail->next = greaterHead;
        this->tail = greaterTail;
    }
}
//ex3
void reduceDuplicate(Node* root)
{
    int temp = root->getData();
    Node *pre = root;
    for (Node *i = root->getNext(); i != nullptr; i = i->getNext())
    {
        if (i->getData() == temp)
        {
            Node *p = i;
            i = i->getNext();
            pre->setNext(i);
            i = pre;
            delete p;
        }
        else
            temp = i->getData();
        pre = i;
    }
}
//ex4
template <class T>
void SLinkedList<T>::add(const T &e)
{
    /* Insert an element into the end of the list. */
    Node *temp = new Node(e, nullptr);
    if (this->head == nullptr)
        this->head = this->tail = temp;
    else
    {
        this->tail->next = temp;
        this->tail = temp;
    }
    this->count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
    /* Insert an element into the list at given index. */
    int temp = 1;
    Node *i = this->head;
    if (index == 0)
    {
        Node *p = new Node(e, nullptr);
        if (this->head == nullptr)
            this->head = this->tail = p;
        else
        {
            p->next = head;
            head = p;
        }
        this->count++;
        return;
    }
    else
    {
        for (; i->next != nullptr; i = i->next, temp++)
        {
            if (temp == index)
            {
                Node *p = new Node(e, i->next);
                i->next = p;
                this->count++;
                break;
            }
        }
    }
    if (i->next == nullptr)
        this->add(e);
}

template <class T>
int SLinkedList<T>::size()
{
    /* Return the length (size) of list */
    int sizeList = 0;
    for (Node *i = this->head; i != nullptr; i = i->next)
        sizeList++;
    return sizeList;
}
//ex5
template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    int temp = 0;
    for (Node *i = this->head; i != nullptr; i = i->next)
    {
        if (temp == index)
            return i->data;
        else
            temp++;
    }
    return -1;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    int temp = 0;
    for (Node *i = this->head; i != nullptr; i = i->next)
    {
        if (temp == index)
        {
            i->data = e;
            break;
        }
        else
            temp++;
    }
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (this->head == nullptr)
        return true;
    return false;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int temp = 0;
    for(Node *i = this->head; i != nullptr; i = i->next)
    {
        if (i->data == item)
            return temp;
        else
            temp++;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    for (Node *i = this->head; i != nullptr; i = i->next)
    {
        if (i->data == item)
            return true;
    }
    return false;
}
//ex6
template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    int temp = 1;
    T val;
    if (index == 0)
    {
        Node *p = this->head;
        this->head = p->next;
        val = p->data;
        //p->next = nullptr;
        delete p;
        if (this->head == nullptr)
            this->tail = nullptr;
        this->count--;
        return val;
    }
    else
    {
        for (Node *i = this->head; i->next != nullptr; i = i->next)
        {
            if (temp == index)
            {
                Node *p = i->next;
                i->next = p->next;
                if (i->next == nullptr)
                    this->tail = i;
                val = p->data;
                //p->next = nullptr;
                delete p;
                this->count--;
                return val;
            }
            temp++;
        }
    }
    return -1;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int temp = 0;
    //T temp1;
    for (Node *i = this->head; i != nullptr; i = i->next)
    {
        if (i->data == item)
        {
            this->removeAt(temp);
            return true;
        }
        temp++;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (this->head != nullptr)
    {
        Node *temp = this->head;
        this->head = this->head->next;
        //temp->next = nullptr;
        this->count--;
        delete temp;
    }
    this->tail = nullptr;
}
//ex7
LLNode* foldLinkedList(LLNode* head) {
    // STUDENT ANSWER
    if (head == nullptr)
        return nullptr;
    int len = 0;
    class LLNode *foldList = new LLNode();
    class LLNode *temp = foldList;
    for (LLNode *i = head; i != nullptr; i = i->next)
    {
        len++;
    }
    int count = 0;
    int count2 = (len + 1) / 2;
    int arr[count2];
    for (int i = 0; i < count2; i++)
        arr[i] = 0;
    for (LLNode *i = head; i != nullptr; i = i->next)
    {
        if (count < len / 2)
        {
            arr[count] = i->val;
            count++;
        }
        else
        {
            if (count2 == (len + 1) / 2)
                temp->val = arr[count2 - 1] + i->val;
            else
            {
                LLNode *p = new LLNode(arr[count2 - 1] + i->val, nullptr);
                temp->next = p;
                temp = temp->next;
            }
            count2--;
        }
    }
    return foldList;
}


// ex8
LLNode* replaceFirstGreater(LLNode* head) {
    // STUDENT ANSWER
    //class LLNode *temp = head;
    int greater = 0;
    for (LLNode *i = head; i != nullptr; i = i->next)
    {
        greater = i->val;
        for (LLNode *k = i; k != nullptr; k = k->next)
        {
            if (k->val > greater)
            {
                greater = k->val;
                break;
            }
        }
        if (greater == i->val)
            i->val = 0;
        else
            i->val = greater;
    }
    return head;
}


//ex9
LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    LLNode *current = head;
    LLNode *prev = nullptr;
    LLNode *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


//ex10
void rotatedList(LLNode *head)
{
    LLNode *pre = nullptr;
    for (LLNode *i = head; i != nullptr; i = i->next)
    {
        if (i->next == nullptr)
        {
            i->next = head;
            pre->next = nullptr;
            head = i;
            break;
        }
        pre = i;
    }
}
LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    for (int i = 0; i < k; i++)
    {
        LLNode *pre = nullptr;
        for (LLNode *i = head; i != nullptr; i = i->next)
        {
            if (i->next == nullptr)
            {
                i->next = head;
                pre->next = nullptr;
                head = i;
                break;
            }
            pre = i;
        }
    }
    return head;
}


//ex11
void LinkedList::replace(LinkedList *linked_list, int low, int high)
{
    //if (low > high || high < 0)
        //return;
    // if (this->head == nullptr)
    // {
    //     this->head = linked_list->head;
    //     this->tail = linked_list->tail;
    //     return;
    // }
    int count = 0;
    Node *i = this->head;
    Node *pNext = i->next;
    if (low - 1 < 0)// && linked_list->head != nullptr)
    {
        linked_list->tail->next = this->head;
        this->head = linked_list->head;
        i = linked_list->tail;
        pNext = i->next;
        count = -1;
    }
    if (high >= this->size)
        high = this->size - 1;
    while (count < high)
    {
        if (count >= low - 1)
        {
            i->next = pNext->next;
            delete pNext;
        }
        else
            i = i->next;
        pNext = i->next;
        count++;
    }
    if (low - 1 >= 0)// && linked_list->head != nullptr)
    {
        linked_list->tail->next = pNext;
        i->next = linked_list->head;
    }
    if (high == this->size - 1)
        this->tail = linked_list->tail;
}
/////////////////////////////////////////////////////
///////////////// doubly /////////////////////////////
//ex1
Deque::Deque() {
    this->head = nullptr;
    this->tail = nullptr;
}

Deque::~Deque() {
    while (this->head != nullptr)
    {
        Node *p = this->head;
        this->head = p->right;
        delete p;
    }
    this->tail = nullptr;
}

void Deque::clear() {
    while (this->head != nullptr)
    {
        Node *p = this->head;
        this->head = p->right;
        delete p;
    }
    this->tail = nullptr;
}

int Deque::getSize() {
    int temp = 0;
    for (Node *i = this->head; i != nullptr; i = i->right)
        temp++;
    return temp;
}

void Deque::pushFront(int i) {
    Node *p = new Node(i, nullptr, nullptr);
    if (this->head != nullptr)
    {
        this->head->left = p;
        p->right = this->head;
        this->head = p;
    }
    else
        this->tail = this->head = p;
}

void Deque::pushBack(int i) {
    Node *p = new Node(i, nullptr, nullptr);
    if (this->head != nullptr)
    {
        this->tail->right = p;
        p->left = this->tail;
        this->tail = p;
    }
    else
        this->tail = this->head = p;
}

int Deque::popFront() {
    if (this->head == nullptr)
        return -1;
    int val = this->head->value;
    if (this->head->right != nullptr)
    {
        this->head = this->head->right;
        delete this->head->left;
        this->head->left = nullptr;
    }
    else
    {
        delete this->head;
        this->head = this->tail = nullptr;
    }
    return val;
}

int Deque::popBack() {
    if (this->head == nullptr)
        return -1;
    int val = this->tail->value;
    if (this->tail->left != nullptr)
    {
        this->tail = this->tail->left;
        delete this->tail->right;
        this->tail->right = nullptr;
    }
    else
    {
        delete this->tail;
        this->tail = this->head = nullptr;
    }
    return val;
}

void Deque::printDequeReverse() {
    for (Node *i = this->tail; i != nullptr; i = i->left)
        cout << i->value << " ";
    cout << endl;
}

void Deque::printDeque() {
    for (Node *i = this->head; i != nullptr; i = i->right)
        cout << i->value << " ";
    cout << endl;
}
//ex2
template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node *p = new Node(e);
    if (this->head != nullptr)
    {
        this->tail->next = p;
        p->previous = this->tail;
        this->tail = p;
    }
    else
        this->head = this->tail = p;
    this->count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
    /* Insert an element into the list at given index. */
    Node *p = new Node(e);
    int temp = 1;
    if (index == 0)
    {
        if (this->head == nullptr)
            this->head = this->tail = p;
        else
        {
            p->next = this->head;
            this->head->previous = p;
            this->head = p;
        }
        this->count++;
    }
    else
    {
        Node *i = this->head->next;
        for (; i != nullptr; i = i->next, temp++)
        {
            if (temp == index)
            {
                i->previous->next = p;
                p->previous = i->previous;
                i->previous = p;
                p->next = i;
                this->count++;
                break;
            }
        }
        if (i == nullptr)
            add(e);
    }
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */
    int lenList = 0;
    for (Node *i = this->head; i != nullptr; i = i->next)
        lenList++;
    return lenList;
}
//ex3
template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    int temp = 0;
    for (Node *i = this->head; i != nullptr; i = i->next, temp++)
    {
        if (temp == index)
            return i->data;
    }
    return -1;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    int temp = 0;
    for (Node *i = this->head; i != nullptr; i = i->next, temp++)
    {
        if (index == temp)
        {
            i->data = e;
            break;
        }
    }
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (this->head == nullptr)
        return true;
    return false;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int temp = 0;
    for (Node *i = this->head; i != nullptr; i = i->next, temp++)
    {
        if (i->data == item)
            return temp;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    for (Node *i = this->head; i != nullptr; i = i->next)
    {
        if (i->data == item)
            return true;
    }
    return false;
}
//ex4
template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    int temp = 1;
    T val = -1;
    if (index == 0)
    {
        Node *deleteNode = this->head;
        this->head = this->head->next;
        val = deleteNode->data;
        delete deleteNode;
        if (this->head == nullptr)
            this->tail = nullptr;
        else
            this->head->previous = nullptr;
        this->count--;
    }
    else
    {
        for (Node *i = this->head->next; i != nullptr; i = i->next, temp++)
        {
            if (index == temp)
            {
                if (i->next == nullptr)
                {
                    this->tail = this->tail->previous;
                    this->tail->next = nullptr;
                    val = i->data;
                    delete i;
                    this->count--;
                    return val;
                }
                else{
                    i->previous->next = i->next;
                    i->next->previous = i->previous;
                    val = i->data;
                    delete i;
                    this->count--;
                    return val;
                }
            }
        }
    }
    return val;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int temp = 0;
    for (Node *i = this->head; i != nullptr; i = i->next, temp++)
    {
        if (i->data == item)
        {
            this->removeAt(temp);
            return true;
        }
    }
    return false;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (this->head != nullptr)
        this->removeAt(0);
    this->count = 0;
}
//ex5
DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
     logList.push_back(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
     logList.push_back(data);
     currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
     *currentState += number;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
     *currentState -= number;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
     list<int>::iterator cur = currentState;
     cur++;
     int i = 0;
     while (cur != logList.end()) {
         i++;
         cur++;
     }
     int j = 0;
     while (j < i) {
         logList.pop_back();
         ++j;
     }
     logList.push_back(*currentState);
     currentState++;
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
     if (currentState != logList.begin()) {
         currentState--;
     }
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
      list<int>::iterator cur = currentState;
     cur++;
     if(cur != logList.end())
         currentState++;
}
//ex7
/*
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};
*/

ListNode* reverse(ListNode* head, int a, int b) {
    //To Do
    //int len = b - a + 1;
    ListNode *head1 = head;
    for (int i = 2; i <= a; i++) 
        head1 = head1->right;
    ListNode *tail1 = head1;
    for (int i = a + 1; i <= b; i++) 
        tail1 = tail1->right;
    ListNode *curr = head1;
    ListNode *temp = nullptr;
    for (int i = a; i <= b; i++)
    {
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        curr = curr->left;
    }
    temp = head1->right;
    curr = tail1->left;

    head1->right = curr;
    tail1->left = temp;
    if (temp == nullptr)
        head = tail1;
    else
        temp->right = tail1;
    if (curr != nullptr)
        curr->left = head1;
    return head;  
}


int main()
{
    	
int size;
    system("pause");
    return 0;
}
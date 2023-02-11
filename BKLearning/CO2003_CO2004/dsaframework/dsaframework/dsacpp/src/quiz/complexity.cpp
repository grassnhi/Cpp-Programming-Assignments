#include <iostream>
#include <iomanip>
#include "geom/Point3D.h"

using namespace std;

void quiz_1(int* ptr, int n){
    for(int idx=0; idx > n; idx -= 2){
        cout << setw(3) << ptr[idx] << " ";
    }
}

void quiz_2(int* ptr, int n){
    for(int idx=0; idx < n; idx += 2){
        cout << setw(3) << ptr[idx] << " ";
    }
}
void quiz_3(int* ptr, int n){
    for(int idx=0; idx < n; idx += n/2){
        cout << setw(3) << ptr[idx] << " ";
    }
}
void quiz_4(int* ptr, int n){
    for(int idx = 0; idx < n*n; idx += n/2)
        cout << setw(3) << ptr[idx % n] << " "; 
  
}
void quiz_5(int* ptr, int n){
    for(int idx = 0; idx < n*n; idx += 2)
        cout << setw(3) << ptr[idx % n] << " "; 
  
}
int quiz_6(int n){
    int values[5] = {0, 1, 2, 3, 4};
    for(int r=0; r < n; r += 2)
        for(int c=n-1; c>0; c -=2)
            values[r*c % 5] += r*c;
    return values[0];
}
void quiz_7(int* ptr, int n){
    for(int idx = 0; idx < n; idx *= 2)
        cout << setw(3) << ptr[idx] << " "; 
  
}

void quiz_8(int* ptr, int n){
    for(int idx = 1; idx < n; idx *= 2)
        cout << setw(3) << ptr[idx-1] << " "; 
}

void quiz_9(int* ptr, int n){
    for(int idx = 1; idx < n; idx *= 5)
        cout << setw(3) << ptr[idx] << " "; 
}

/*
 IterationIdx               idx        updated after the current iteration
 1                          (n-1)    -> idx %= 3 -> (n-1) % 3 => [0,1,2}
 2                          case 1: 2 => 
 */
void quiz_10(int* ptr, int n){
    for(int idx = n-1; idx > 0; idx %= 3)
        cout << setw(3) << ptr[idx] << " "; 
}

void quiz_11(int* ptr, int n){
    for(int idx = n-1; idx >= 0; idx %= 3)
        cout << setw(3) << ptr[idx] << " "; 
}

void quiz_12(int* ptr, int n){
    for(int r=0; r < n; r += n/2)
        for(int c = 1; c < n; c *= 2)
            cout << setw(3) << ptr[(r + c) % n] << " "; 
}
void quiz_13(int* ptr, int n){
    for(int r=0; r < n; r += 2)
        for(int c = 1; c < n; c *= 2)
            cout << setw(3) << ptr[(r + c) % n] << " "; 
}

void quiz_15(int* ptr, int n){
    int *table = new int[n*n];
    for(int r=0; r < n; r += 1)
        for(int c = 0; c < n; c +=1)
            table[r * n + c] = r*c;
    for(int idx=0; idx < n; idx++) cout << table[idx* n + idx] << " ";
    delete []table;
}

int quiz_16(int* A, int * B, int *total, int n){
    int sum = 0;
    for(int idx =0; idx < n; idx++){
        total[idx] = A[idx] + B[idx];
        sum += total[idx];
    }
    return sum;
}

//O(nA*nB)
int quiz_17(int* A, int nA, int* B, int nB){
    int largest = A[0]*B[0];
    for(int aIdx=0; aIdx < nA; aIdx++)
        for(int bIdx =0; bIdx < nB; bIdx++)
            if(A[aIdx]*B[bIdx] > largest) largest = A[aIdx]*B[bIdx] > largest;
    return largest;
}

struct Node{
    int value;
    Node* next;
    Node(int value, Node* next){
        this->value = value; this->next = next;
    }
};




Node* array2chain(int* ptr, int size){
    Node* head = NULL;
    for(int idx = size-1; idx >= 0; idx--) head = new Node(ptr[idx], head);
    return head;
}
void print_chain(Node* head){
    Node* cursor = head;
    while(cursor != NULL){
        cout << cursor->value << " ";
        cursor = cursor->next;
    }
}
void delete_chain(Node* head){
    Node* cursor = head;
    while(cursor != NULL){
        head = head->next;
        delete cursor;
        cursor = head;
    }
}


//Worse case = unlucky case
int arrayAt(int* ptr, int atIDX){
    return ptr[atIDX];
}
int chainAt(Node* head, int atIDX){
    int cursor_idx = 0;
    Node* cursor = head;
    while(cursor_idx < atIDX){
        cursor = cursor->next;
        cursor_idx += 1;
    }
    return cursor->value;
}


void dump_array(int* head, int size){
    for(int idx=0; idx < size; idx++){
        int value = arrayAt(head, idx);
        cout << value << " ";
    }
}
void dump_chain(Node* head, int size){
    for(int idx=0; idx < size; idx++){
        int value = chainAt(head, idx);
        cout << value << " ";
    }
}
void demo_array_vs_chain(){
    int array[] = {0,1,2,3,4,5};
    dump_array(array, 5);
    Node* head = array2chain(array, 5);
    dump_chain(head, 5);
}

int main(int argc, char** argv){
    int array[] = {0,1,2,3,4};
    demo_array_vs_chain();
    return 0;
}


//Space complexity: how much memory (in term of #data items)\


/*
 pass into foo:
    (1) array of n items; each item of type: Point3D
    (2) number of items: n
  Data passed to foo: Space complexity: O(n)
 Temporary data: O(n^2)
 
 * => total: O(n^2) + O(n) = O(n^2) 
 
 * Wrong if write: O(n^2 + n) DO NOT USE THIS FORM
 
 */
void foo(Point3D* ptr, int n){
    float *dist = new float[n*n]; //temporary data
    //tasks
    
    
    //delete:
    delete []dist;
}
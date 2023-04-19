/*
Given an array which the elements in it are random. Now we want to build a Max heap from this array. Implement functions Reheap up and Reheap down to heapify element at index position. We will use it to build a heap in next question.

To keep things simple, this question will separate the heap array, not store it in the class heap

void reheapDown(int maxHeap[], int numberOfElements, int index);
void reheapUp(int maxHeap[], int numberOfElements, int index);



For example:

Test	Result
int arr[] = {1,2,3,4,5,6,7,8};
int size = sizeof(arr)/sizeof(arr[0]);
reheapDown(arr,size,0);
cout << "[ ";
for(int i=0;i<size;i++)
    cout << arr[i] << " ";
cout << "]";
[ 3 2 7 4 5 6 1 8 ]
int arr[] = {1,2,3,4,5,6,7,8};
int size = sizeof(arr)/sizeof(arr[0]);
reheapUp(arr,size,7);
cout << "[ ";
for(int i=0;i<size;i++)
    cout << arr[i] << " ";
cout << "]";
[ 8 1 3 2 5 6 7 4 ]

*/

void swap(int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    if(index > (numberOfElements)/2 || index<0)   return;
    int i= index;
    int largest_e=0;
        if((2*i + 1) < numberOfElements){
            int left_e= 2*i +1;        
            if((2*i +2) < numberOfElements){
                int right_e= 2*i +2;
                if(maxHeap[left_e] > maxHeap[right_e])    largest_e= left_e;
                else    largest_e= right_e;
            }
            else    largest_e= left_e;
        }
        else    return;
        if(maxHeap[i] < maxHeap[largest_e]){
            swap(maxHeap[i], maxHeap[largest_e]);
            reheapDown(maxHeap, numberOfElements, largest_e);
            //break;
        }
    return;
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if(index<=0 || index >= numberOfElements)   return;
    int parent_i= (index-1)/2;
    if(maxHeap[parent_i] < maxHeap[index]){
        swap(maxHeap[parent_i], maxHeap[index]);
        reheapUp(maxHeap, numberOfElements, parent_i);
    }
    return;
}
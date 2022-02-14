#include<iostream>
using namespace std;

int binSearch(const int data[], // input: array
             int first,        // input: lower bound
             int last,        // input: upper bound
             int value         // input: value to find
        ) {// output: index if found,  otherwise return –1
	 int middle = (first + last) / 2;
   if (data[middle] == value)
      return middle;
   else if (first >= last)
      return -1;
   else if (value < data[middle])
      return binSearch(data, first, middle-1, value);
   else
      return binSearch(data, middle+1, last, value);
}
int main() {
	  const int array_size = 8;
    int list[array_size]={1, 2, 3, 5, 7, 10, 14, 17};
    int search_value;
    cout 	<< "Enter search value: ";
    cin 	>> search_value;
    cout 	<< binSearch(list,0,array_size-1,search_value) << endl;
    
    return 0;	
}

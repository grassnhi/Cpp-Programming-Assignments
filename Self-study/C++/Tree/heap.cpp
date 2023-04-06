template<class T> 
void moveDown (T data[], int first, int last) {
    int largest = 2*first + 1;
    while (largest <= last) {
        if (largest < last && // first has two children (at 2*first+1 and
                data[largest] < data[largest+1]) // 2*first+2) and the second
            largest++;                       // is larger than the first;
        if (data[first] < data[largest]) {    // if necessary,
            swap(data[first],data[largest]); // swap child and parent,
            first = largest;                 // and move down;
            largest = 2*first+1;
        }else largest = last+1;  // to exit the loop: the heap property
    }                           // isn’t violated by data[first]; 
}

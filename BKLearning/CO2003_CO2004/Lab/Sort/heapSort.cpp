template <class T>
class Sorting {
public:
    // Function to print an array
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    //Helping functions go here
    static void heapify(T arr[], int n, int i)
    {
        int largest = i;    // Initialize largest as root
        int l = 2*i + 1;    // left = 2*i + 1
        int r = 2*i + 2;    // right = 2*i + 2

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }


    static void heapSort(T* start, T* end){
        //TODO
        int n = end - start;
        
        for (int i = n / 2 - 1; i >= 0; i--)
                heapify(start, n, i);

            // One by one extract an element from heap
            for (int i = n-1; i >= 0; i--) {
                // Move current root to end
                swap(start[0], start[i]);

                // call max heapify on the reduced heap
                heapify(start, i, 0);
            }
        Sorting<T>::printArray(start,end);
    }
};

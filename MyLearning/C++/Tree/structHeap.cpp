typedef int* ptrHeap;

struct Heap
{
    ptrHeap;
    int Size;
    int Count;
};

// Tạo đống rỗng
void Init(Heap& heap, int theSize){
    heap.Arr = new int[theSize];
    heap.Size = theSize;
    heap.Count = 0;
}

// check empty
bool IsEmpty(Heap heap){
    bool result = heap.Count == 0;
    return result;
}

// check full
bool IsFull(Heap heap){
    bool result = heap.Count == heap.Size;
    return result;
}

// Tạo đống từ mảng
void Copy(Heap& heap, int a[], int n){
    delete[] heap.Arr;
    heap.Arr = new int[n];
    for(int i = 0; i < n; i++){
        heap.Arr[i] =  a[i];
    }
    heap.Count = n;
    heap.Size = n;
} // chép array vào heap
void ShiftUp(Heap& heap, int i){
    int parent;
    int theKey = heap.Arr[i];
    bool cont = true;
    while ((i > 0) && cont)
    {
        parent = (i - 2) / 2;
        if(heap.Arr[parent] < theKey){
            heap.Arr[i] = heap.Arr[parent];
            i = (i - 1) / 2;
        }
    }else{
        cont = false;
    }
    heap.Arr[i] = theKey;
} // shiftUp lặp
void Swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
void ShiftUp(Heap& heap, int i){
    if(i > 0){
        int parent = (i - 1) / 2;
        if(heap.Arr[parent] < heap.Arr[i]){
            Swap(heap.Arr[i], heap.Arr[parent]);
            ShiftUp(heap, parent);
        }
    }
}// shiftUp đệ quy
void CreateHeap(Heap& heap){
    for(int i = 1; i < heap.Count; i++){
        ShiftUp(heap, i);
    }
} // tạo heap đệ quy từ nút i dến nút gốc
void ShiftDown(Heap& heap, int p, int q){
    int i = p;
    int theKey = heap.Arr[i];
    int j = 2 * i + 1;
    bool cont = true;
    while ((j <= q) && cont)
    {
        if(j < q){
            if(heap.Arr[i] < heap.Arr[j+1]){
                j = j + 1;
            }
        }
        if(theKey < heap.Arr[j]){
            heap.Arr[i] = heap.Arr[j];
            i = j;
            j = j * 2 + 1;
        }else{
            cont = false;
        }
    }
    heap.Arr[i] = theKey;
} // ShiftDown vòng lặp
void CreateHeap(Heap& heap){
    int  k = (heap.Count / 2) - 1;
    for (int i = k; i >= 0; i--)
    {
        ShiftDown(heap, i, heap.Count - 1);
    } 
} // tạo heap dùng ShiftDown

// Thêm khóa vào đống
void Insert(Heap& heap, int theKey, bool& error){
    if(IsFull(heap)){
        error = true;
    }else{
        error = false;
        heap.Arr[heap.Count] = theKey;
        ShiftUp(heap, heap.Count);
        heap.Count++;
    }
}

// lấy khóa max từ đống
int Remove(Heap& heap, bool& error){
    int theKey;
    if(IsEmpty(heap)){
        error = true;
        theKey = 0;
    }else{
        error = false;
        theKey = heap.Arr[0];
        heap.Arr[0] = heap.Arr[heap.Count - 1];
        heap.Count--;
        CreateHeap(heap);
    }
    return theKey;
}

// Xem khóa lớn thứ k
int Peek(Heap& heap, int k, bool& error){
    int theKey;
    if(IsEmpty(heap) || k < 0 || k > Count){
        error = true;
        theKey = 0;
    }else{
        error = false;
        int[] a = new int[Count];
        int n = 0;
        for(int i = 1; i <= k; i++){
            a[n] = Remove(out error);
            n++;
        }
        for(int i = 0; i < n; i++){
            Insert(a[i], out error);
        }
        theKey = a[n-1];
    }
    return theKey;
}

// Hiển thị đống
void Display(Heap heap){
    if(IsEmpty(heap)){
        cout << "Empty" << endl;
    }else{
        for(int i = 0; i < heap.Count; i++){
            cout << heap.Arr[i] << " ";
        }
        cout << endl;
        cout << heap.Count << " - " << heap.Size << endl;
    }
}

// Hủy bỏ đống
void Clear(Heap& heap){
    delete[] heap.Arr;
    heap.Size = 0;
    heap.Count = 0;
}
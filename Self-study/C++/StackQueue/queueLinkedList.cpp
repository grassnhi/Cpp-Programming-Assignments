struct Item;
typedef Item* ptrItem;

struct Item
{
    int Info;
    ptrItem Next;
};

struct Queue
{
    ptrItem Front;
    ptrItem Rear;
    int Count;
};

// Tạo queue rỗng
void Init(Queue& queue){
    queue.Front = nullptr;
    queue.Rear = nullptr;
    queue.Count = 0;
}

// Kiểm tra rỗng
bool IsEmpty(Queue queue){
    bool result = queue.Front == nullptr;
    return result;
}

// Thêm khóa
void Enqueue(Queue& queue, int theInfo){
    ptrItem p = new Item;
    p->Info = theInfo;
    p->Next = nullptr;
    if(queue.Front = nullptr){
        queue.Front = p;
    }else{
        queue.Rear->Next = p;
    }
    queue.Rear = p;
    queue.Count++;
}

// Lấy khóa từ queue
int Dequeue(Queue& queue, bool& error){
    int result;
    if(IsEmpty(queue)){
        error = true;
        result = 0;
    }else{
        error = false;
        ptrItem p = queue.Front;
        result = p->Info;
        if(queue.Front == queue.Rear){
            queue.Rear = nullptr;
        }
        queue.Front = p->Next;
        delete p;
        queue.Count--;
    }
    return result;
}

// Xem khóa đầu ra
int Peek(Queue& queue, bool& error){
    int result;
    if(IsEmpty(queue)){
        error = true;
        result = 0;
    }else{
        error = false;
        result = queue.Front->Info;
    }
    return result;
}

// Hiển thị queue
void Display(Queue queue){
    if(IsEmpty(queue)){
        cout << "Empty" << endl;
    }else{
        ptrItem p = queue.Front;
        while (p != nullptr)
        {
            cout << p->Info << endl;
            p = p->Next;
        }
        cout << "Count: " << queue.Count << endl;
    }
}

// Hủy bỏ queue
void Clear(Queue& queue){
    ptrItem p;
    while (queue.Front != nullptr)
    {
        p = queue.Front;
        queue.Front = p->Next;
        delete p;
    }
    queue.Rear = nullptr;
    queue.Count = 0;
}
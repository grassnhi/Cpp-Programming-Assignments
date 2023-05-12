typedef int* ptrQueue;

struct Queue
{
    ptrQueue QueueArray;
    int Front;
    int Rear;
    int Size;
    int Count;
};

// Tạo queue rỗng
void Init(Queue& queue, int theSize){
    queue.QueueArray = new int[theSize];
    queue.Front = -1;
    queue.Rear = -1;
    queue.Size = theSize;
    queue.Count = 0;
}

// Check queue rỗng
bool IsEmpty(Queue queue){
    bool result = queue.Front == -1;
    return result;
}

// kiểm tra đầy
bool IsFull(Queue queue){
    bool result = (queue.Rear - queue.Front + 1 == queue.Size) || (queue.Rear - queue.Front + 1 == 0);
    return result;
}

// Thêm đẩu mảng tịnh tiến
void Enqueue(Queue& queue, int theInfo, bool& error){
    if(IsFull(queue)){
        error = true;
    }else{
        error = false;
        if(IsEmpty(queue)){
            queue.Front = 0;
        }else if(queue.Rear == queue.Size - 1){
            for(int i = queue.Front; i <= queue.Rear; i++){
                queue.QueueArray[i-queue.Front] = queue.QueueArray[i];
            }
            queue.Rear = queue.Rear - queue.Front;
            queue.Front = 0;
        }
        queue.Rear++;
        queue.QueueArray[queue.Rear] = theInfo;
        queue.Count++;
    }
}

// Thêm đầu mảng di chuyển vòng
void Enqueue(Queue& queue, int theInfo, bool& error){
    if(IsFull(stack)){
        error = true;
    }else{
        error = false;
        if(IsEmpty(queue)){
            queue.Front = 0;
        }
        queue.Rear++;
        queue.Rear = queue.Rear % queue.Size;
        queue.QueueArray[queue.Rear] = theInfo;
        queue.Count++;
    }
}

// Lấy khóa từ queue tịnh tiến
int Dequeue(Queue& queue, bool& error){
    int result;
    if(IsEmpty(queue)){
        error = true;
        result = 0;
    }else{
        error = false;
        result = queue.QueueArray[queue.Front];
        if(queue.Front == queue.Rear){
            queue.Front = -1;
            queue.Rear = -1;
        }else{
            queue.Front++;
            queue.Count--;
        }
        return result;
    }
}

// Lấy khóa dịch vòng
int Dequeue(Queue& queue, bool& error){
    int result;
    if(IsEmpty(queue)){
        error = true;
        result = 0;
    }else{
        error = false;
        result = queue.QueueArray[queue.Front];
        if(queue.Front == queue.Rear){
            queue.Front = -1;
            queue.Rear = -1;
        }else{
            queue.Front++;
            queue.Front = queue.Front % queue.Size;
        }
        queue.Count--;
    }
    return result;
}

// Xem khóa của đầu ra
int Peek(Queue queue, bool& error){
    int result;
    if(IsEmpty(queue)){
        error = true;
        result = 0;
    }else{
        result = queue.QueueArray[queue.Front];
    }
    return result;
}

// Hiển thị queue
void Display(Queue queue){
    if(IsEmpty(queue)){
        cout << "Empty" << endl;
    }else{
        bool i = queue.Front;
        bool cont = true;
        while (cont)
        {
            cout << queue.QueueArray[i] << endl;
            if(i == queue.Rear){
                cont = false;
            }else{
                i++;
                i = i % queue.Size;
            }
        }
        cout << queue.Count << " " << queue.Size << endl;
    }
}

// Hủy bỏ queue
void Clear(Queue& queue){
    queue.Front = -1;
    queue.Rear = -1;
    queue.Count = 0;
}
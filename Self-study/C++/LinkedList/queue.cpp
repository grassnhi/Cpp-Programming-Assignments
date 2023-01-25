// Queue: First In First Out & Last-In Last-Out
// Con trỏ input Rear, đầu ra Front


// Khai báo cấu trúc phần tử
typedef struct Item* ptr;

struct Item
{
    int Info;
    ptr Link;
};

// Cầu trúc queue
struct CQueue
{
    ptr Front;
    ptr Rear;
};

// Khởi tạo queue rỗng
void Init(CQueue q){
    q.Front = NULL;
    q.Rear = NULL;
}

// Check
bool IsEmpty(CQueue q){
    bool kq = q.Front == NULL;
    return kq;
}

// Add nội dung vào đầu Rear
void Enqueue(CQueue& q, int x){
    ptr p = new Item;
    p->Info = x;
    p->Link = NULL;

    if(q.Front == NULL)
        q.Front = p; // queue rỗng -> add vào Front
    else
        q.Rear->Link = p ;

    q.Rear = p;
}

// Lấy nội dung (đầu Front) -> đk queue khác rỗng
int Dequeue(CQueue& q){
    ptr p = q.Front;
    int x = p->Info;

    if(q.Front == q.Rear) // queue có 1 ptu
        q.Rear = NULL;
    
    q.Front = p->Link;

    delete p;
    return x;
}

// Xem nội dung tại Front: đk khác rỗng
int Peek(CQueue q){
    int x = q.Front->Info;
    return x;
}

// hủy bỏ queue
void Clear(CQueue& q){
    ptr p = q.Front;
    
    while (p != NULL)
    {
        q.Front = p->Link;
        delete p;
        p = q.Front;
    }
    
    q.Rear = NULL
}
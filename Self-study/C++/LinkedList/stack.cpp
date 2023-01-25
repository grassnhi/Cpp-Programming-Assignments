// Stack => Last In First Out & First In Last Out


// Khai báo cấu trúc stack

typedef struct Item* ptr;

struct Item
{
    int Info;
    ptr Link;
};

// Khởi tạo stack rỗng
void Init(ptr& sp){
    sp = NULL;
}

// Check stack rỗng
bool IsEmpty(ptr sp){
    bool kq = sp == NULL;
    return kq;
}

// Add vào đỉnh stack
void Push(ptr& sp, int x){
    ptr p = new Item;

    p->Info = x;
    p->Link = sp;

    sp = p;
}

// Lấy nội dung từ đỉnh stack
int Pop(ptr& sp){
    ptr p = sp;

    int x = p->Info;

    sp = p->Link;
    delete p;

    return x;
}
//-> Đk để lấy ptu là stack khác rỗng
int x;
if(!IsEmpty(sp))
    x = Pop(sp);

// Xem nội dung ở đỉnh stack: Đk stack khác rông
int Peek(ptr sp){
    int x = sp->Info;

    return x;
}

// Hủy bỏ stack
void Clear(ptr& sp){
    ptr p = sp;

    while (p != NULL)
    {
        sp = p->Link;
        delete p;
        p = sp;
    } 
}
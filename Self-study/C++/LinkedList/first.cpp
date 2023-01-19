// Khai báo cấu trúc

struct Item* ptr
{
    int Info;
    ptr Link;
};

// Tạo ds rỗng

void Init(ptr& first){
    first = NULL;
}

// Check

bool IsEmpty{ptr first}{
    bool kq = first == NULL;

    return kq;
}

// Add phần tử vào đầu ds

void InsertFirst(ptr& first, int x){
    ptr q = new Item;

    q->Info = x;
    q->Link = first;

    first = q;
}

// If ds có thứ tự increase

void InsertOrder(ptr& first, int x){
    ptr tp;
    ptr p = first;

    bool cont = true;

    while ((p != NULL) && cont)
    {
        if(p->Info < x){
            tp = p;
            p = p->Link;
        }else
            cont = false;
    }
    
    ptr q = new Item;
    q->Info = x;

    if(p == first){
        q->Link = first;
        first = q;
    }else{
        tp->Link = q;
        q->Link = p;
    }
}

// Find phần tử của ds

ptr Find(ptr first, int x){
    ptr p = first;
    bool found = false;

    while ((p != NULL) && !found)
    {
        if(p->Info == x)
            found = true;
        else
            p = p->Link;

        return p;
    }   
}

// Find khi ds có ordered

ptr FindOrder(ptr first, int x){
    ptr p = first;
    bool = false;
    
    while ((p != NULL) && !found)
    {
        if(p->Info < x){
            p = p->Link;
        }else if(p->Info == x)
            found = true;
        else 
            p = NULL;
    }

    return p;
}

// Loại bỏ phần tử đầu tiên trong ds

void Remove(ptr& first, int x){
    ptr tp;
    ptr p = first;
    bool found = false;

    while ((p != NULL) && !found)
    {
        if(p->Info == x)
            found = true;
        else{
            tp = p;
            p = p->Link;
        }
    }
    
    if(found){
        if(p == first)
            first = p->Link;
        else
            tp->Link = p->Link;
            
        delete p;
    }
}

// Loai x trong ds tăng dần

void RemoveOrder(ptr& first, int x){
    ptr tp;
    ptr p = first;
    bool found = false;

    while ((p != NULL) && !found)
    {
        if(p->Info < x){
            tp = p;
            p = p->Link;
        }
        else if(p->Info == x)
            found = true;
        else
            p = NULL;
    }
    
    if(found){
        if(p == first)
            first = p->Link;
        else
            tp->Link = p->Link;

        delete p;
    }
}

// Duyệt ds

void Display(ptr first){
    ptr p = first;

    while (p != NULL)
    {
        cout << p->Info << " ";
        p = p->Link;
    }

    cout << endl;
}

// Hủy ds

void Clear(ptr& first){
    ptr p = first;

    while (p != NULL)
    {
        first = p->Link;

        delete p;

        p = first;
    }  
}
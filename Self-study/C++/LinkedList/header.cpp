// Tạo ds rỗng -> tạo phần tử header -> con trỏ NULL

void Init(ptr& header){
    header = new Item;
    header->Link = NULL;
}

// Check

bool IsEmpty(ptr header){
    bool kq = header->Link == NULL;
    return kq;
}

// Thêm phần tử vào đầu ds (con trỏ header không đổi value) -> phần tử mới sau header (thứ 2)

void InsertHeader(ptr header, int x){
    ptr q = new Item;
    p->Info = x;

    q->Link = header->Link;
    header->Link = q;
}

// Thêm vào ds thứ tự tăng dần

void InsertOrder(ptr header, int x){
    ptr tp = header;
    ptr p = header->Link;
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

    q->Link = p;
    tp->Link = q;
}

// Find ds

ptr Find(ptr header, int x){
    ptr p = header->Link;
    bool found = false;

    while ((p != NULL) && !found)
    {
        if(p->Info == x)
            found = true;
        else
            p = p->Link;
    }
    
    ptr q = new Item;
    q->Info = x;
    q->Link = p;
    tp->Link = q;
}

// Find phan tu trong ds có ordered

ptr FindOrder(ptr header, int x){
    ptr p = header->Link;
    bool found = false;

    while ((p != NULL) && !found)
    {
        if(p->Info < x)
            p = p->Link;
        else if(p->Info == x)
            found = true;
        else
            p = NULL;
    }
    
    return p;
}

// Loại bỏ phần tử ds

void Remove(ptr header, int x){
    ptr tp = header;
    ptr p = header->Link;
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
        tp->Link = p->Link;
        delete p;
    }
}

// Ds có thứ tự

void RemoveOrder(ptr header, int x){
    ptr tp = header;
    ptr p = header->Link;

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
        tp->Link = p->Link;
        delete p;
    }
}

// Duyet ds

void Display(ptr header){
    ptr p = header->Link;

    while (p != NULL)
    {
        cout << p->Info << " ";
        p = p->Link;
    }

    cout << endl;
}

// Hủy bỏ ds

void Clear(ptr header){
    ptr p = header->Link;

    while (p != NULL)
    {
        header->Link = p->Link;

        delete p;

        p = header->Link;
    }
}


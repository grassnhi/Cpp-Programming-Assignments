// Header vòng, phần con trỏ khác null

// Tạo ds rỗng: tạo 1 phần tử header, con trỏ tham khảo chính nó
void Init(ptr &header){
    header = new Item;
    header->Link = header;
}

// Check ds có rỗng ko
bool IsEmpty(ptr header){
    bool kq = header->Link == header;
    return kq;
}

// Thêm phần từ vào đầu ds
void InsertHeader(ptr header, int x){
    ptr q = new Item;
    q->Info = x;

    q->Link = header->Link;
    header->Link = q;
}

// Thêm vào đầu ds có thứ tự
void InsertOrder(ptr header, int x){
    ptr tp = header;
    ptr p = header->Link;

    bool cont = true;

    while ((p != header) && cont)
    {
        if(p->Info < x){
            tp = p;
            p = p->Link;
        }
        else
            cont = false;
    }

    ptr q = new Item;
    q->Info = x;

    tp->Link = q;
    q->Link = p;
}

// Find phần tử ds 
ptr Find(ptr header, int x){
    ptr p = header->Link;

    bool found = false;
    while ((p != header) && !found)
    {
        if(p->Info == x)
            found = true;
        else
            p = p->Link;
    }
    
    return p;
}

// Find phần tử ds có order
ptr FindOrder(ptr header, int x){
    ptr p = header->Link;

    bool found = false;
    while ((p != header) && !found)
    {
        if(p->Info < x)
            p = p->Link;
        else if(p->Info == x)
            found = true;
        else
            p = header;
    }
    
    return p;
}

// Loại bỏ phần tử ds
void Remove(ptr header, int x){
    ptr tp = header;
    ptr p = header->Link;

    bool found = false;
    while ((p != header) && !found)
    {
        if(p->Infp == x)
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

// Loại bỏ ptu đâu ds có order
void RemoveOrder(ptr header, int x){
    ptr tp = header;
    ptr p = heade->Link;

    bool found = false;
    while ((p != header) && !found)
    {
        if(p->Info < x){
            tp = p;
            p = p->Link;
        }
        else if(p->Info == x)
            found = true;
        else
            p = header;
    }
    
    if(found){
        tp->Link = p->Link;

        delete p;
    }
}

// Duyet ds
void Display(ptr header){
    ptr p = header->Link;

    while ((p != header))
    {
        cout << p->Info << " ";
        p = p->Link;
    }
    cout << endl;
}

// Hủy bỏ ds
void Clear(ptr header){
    ptr p = header->Link;
    while (p != header)
    {
        header->Link = p->Link;

        delete p;

        p = header->Link;
    }
}
struct Item;
typedef Item* ptrItem;

struct Item
{
    int Info;
    ptrItem Next;
};

struct Stack
{
    ptrItem Sp;
    int Count;
};

// Khởi tạo chồng rỗng
void Init(Stack& stack){
    stack.Sp = nullptr;
    stack.Count = 0;
}

// Kiểm tra chồng rỗng
bool IsEmpty(Stack stack){
    bool result = stack.Sp == nullptr;
    return result;
}

// Thêm khóa vào chồng
void Push(Stack& stack, int theInfo){
    ptrItem p = new Item;
    p->Info = theInfo;

    p->Next = stack.Sp;
    stack.Sp = p;
    stack.Count++;
}

// Lấy khóa từ chồng
int Pop(Stack& stack, bool& error){
    int result;
    if(IsEmpty(stack)){
        error = true;
        result = 0;
    }else{
        error = false;
        ptrItem p = stack.Sp;
        result = p->Info;
        stack.Sp = p->Next;
        delete p;
        stack.Count--;
    }
    return result;
}

// Xem khóa tại đỉnh
int Peek(Stack stack, bool& error){
    int result;
    if(IsEmpty(stack)){
        error = true;
        result = 0;
    }else{
        error = false;
        result = stack.Sp->Info;
    }
    return result;
}

// Hiển thị chồng
void Display(Stack stack){
    if(IsEmpty(stack)){
        cout << "Empty" << endl;
    }else{
        ptrItem p = stack.Sp;
        while (p != nullptr)
        {
            cout << p->Info << endl;
            p = p->Next;
        }
        cout << "Count: " << stack.Count << endl;
    }
}

// Hủy bỏ chồng
void Clear(Stack& stack){
    ptrItem p;
    while (stack.Sp != nullptr)
    {
        p = stack.Sp;
        stack.Sp = p->Next;
        delete p;
    }
    stack.Count = 0;
}

//Main program

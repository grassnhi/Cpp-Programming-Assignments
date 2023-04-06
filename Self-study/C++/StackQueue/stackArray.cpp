struct Stack
{
    int* StackArray;
    int Sp; // Đỉnh chồng
    int Size; // kích cỡ chồng
    int Count; // Số phần tử trong chồng
};

// Tạo chồng rỗng
void Init(Stack& stack, int TheSize){
    stack.StackArray = new int[TheSize];
    stack.Sp = -1;
    stack.Size = TheSize;
    stack.Count = 0;
}

// kiểm tra chồng rỗng
bool IsEmpty(Stack stack){
    bool result = stack.Sp == -1;
    return result;
}

// Kiểm tra chồng bị đầy
bool IsFull(Stack stack){
    bool result = stack.Sp == stack.Size - 1;
    return result;
}

// Thêm từ khóa vào chồng
void Push(Stack& stack, int theInfo, bool& error){
    if(IsFull(stack)){
        error = true;
    }else{
        error = false;
        stack.Sp++;
        stack.StackArray[stack.Sp] = theInfo;
        stack.Count++;
    }
}

// Lấy từ khóa từ chồng
int Pop(Stack& stack, bool& error){
    int result;
    if(IsEmpty(stack)){
        error = true;
        result = 0;
    }else{
        error = false;
        result = stack.StackArray[stack.Sp];
        stack.Sp--;
        stack.Count--;
    }
    return result;
}

// Xem khóa của đỉnh chồng
int Peek(Stack stack, bool& error){
    int result;
    if(IsEmpty(stack)){
        error = true;
        result = 0;
    }else{
        error = false;
        result = stack.StackArray[stack.Sp];
    }
    return result;
}

// Hiển thị chồng
void Display(Stack stack){
    if(IsEmpty(stack)){
        cout << "Stack rong . . . " << endl;
    }else{
        for(int i = stack.Sp; i >= 0; i--){
            cout << stack.StackArray[i] << endl;
        }
        cout << stack.Count << " " << stack.Size << endl;
    }
}

// Hủy bỏ chồng
void Clear(Stack& stack){
    stack.Sp = -1;
    stack.Count = 0;
}

// Main Program
int main(){
    int theSize;
    cout << "Enter theSize: " << endl;
    cin >> theSize;

    Stack stack;
    Init(stack, theSize);

    int option = 0;
    do{
        system("cls");
        cout << "1. IsEmpty?" << endl;
        cout << "2. Add key?" << endl;
        cout << "3. Get key?" << endl;
        cout << "4. Read sp key?" << endl;
        cout << "5. Display?" << endl;
        cout << "6. Clear?" << endl;
        cout << "0. End." << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            if(IsEmpty(stack)){
                cout << "Empty" << endl;
            }else{
                cout << "Not empty" << endl;
            }
            system("pause");
            break;
        case 2:
            int theInfo;
            cout << "Enter key: " << endl;
            cin >> theInfo;

            bool error;
            Push(stack, theInfo, error);

            if(error){
                cout << "Overflow" << endl;
                system("pause");
            }
            break;
        case 3:
            if (IsEmpty(stack))
            {
                cout << "Empty" << endl;
            }else{
                bool error;
                int theInfo = Pop(stack, error);
                cout << theInfo << endl;
            }
            system("pause");
            break;
        case 4:
            if(IsEmpty(stack)){
                cout << "Empty" << endl;
            }else{
                bool error;
                int theInfo = Peek(stack, error);
                cout << theInfo << endl;
            }
            system("pause");
            break;
        case 5:
            Display(stack);
            system("pause");
            break;
        case 6:
            Clear(stack);
            break;
        }
    }while(option != 0);
    return 0;
}
struct Node;
typedef Node* ptrNode;

struct Node
{
    int Info;
    ptrNode Left;
    ptrNode Right;
};

// Khởi tạo cây rỗng
void Init(ptrNode& root){
    root = nullptr;
}

// Kiểm tra cây rỗng
bool IsEmpty(ptrNode root){
    bool result = root == nullptr;
    return result;
}

// Duyệt cây đệ quy NLR
void NLR(ptrNode p, int n){
    for(int i = 1; i <= n; i++){
        cout << " ";
        if(p != nullptr){
            cout << p->Info << endl;
            NLR(p->Left, n+3);
            NLR(p->Right, n+3);
        }else{
            cout << "0" << endl;
        }
    }
}
void TraversalNLR(ptrNode root){
    NLR(root, 0);
}

// Duyệt cây vòng lặp stack NLR
void TraversalNLR(ptrNode p){
    if(p != nullptr){
        ptrItem stack;
        InitStack(stack); // stack rỗng
        Push(stack, p); // thêm nút p vào stack
        while (!IsEmptyStack(stack))
        {
            p = Pop(stack);
            cout << p->Info << endl;
            if(p->Right != nullptr){
                Push(stack, p->Right);
            }
            if(p->Left != nullptr){
                Push(stack, p->Left);
            }
        }
    }
}

// Duyệt câu LNR đệ quy
void TraversalLNR(ptrNode p){
    if(p != nullptr){
        TraversalLNR(p->Left);
        cout << p->Info << endl;
        TraversalLNR(p->Right);
    }
}

// Duyệt cây LNR stack
void TraversalLNR(ptrNode p){
    ptrItem stack;
    InitStack(stack); // stack rỗng
    while (!IsEmptyStack(stack) || p != nullptr)
    {
        if(p != nullptr){
            Push(stack, p);
            p = p->Left;
        }else{
            p = Pop(stack);
            cout << p->Info << endl;
            p = p->Right;
        }
    } 
}

// Duyệt cây đệ quy LRN
void TraversalLRN(ptrNode p){
    TraversalLRN(p->Left);
    TraversalLRN(p->Right);
    cout << p->Info << endl;
}

// Duyệt cây stack LRN
void TraversalLRN(ptrNode p){
    ptrItem stack;
    InitStack(stack);
    ptrNode lastNode = nullptr;
    while (!IsEmptyStack(stack) || p != nullptr)
    {
        if(p != nullptr){
            Push(stack, p);
            p = p->Left;
        }else{
            ptrNode q = Peek(stack);
            if(q->Right != nullptr && lastNode != q->Right){
                p = q->Right;
            }else{
                cout << q->Info << endl;
                lastNode = Pop(stack);
            }
        }
    }
}

// Tạo cây từ mảng
ptrNode CreateTreeNLR(int a[], int& i){
    ptrNode p;
    if(a[i] == 0){
        p = nullptr;
    }else{
        p = new Node;
        p->Info = a[i];
        i++;
        p->Left = CreateTreeNLR(a, i);
        i++;
        p->Right = CreateTreeNLR(a, i);
    }
    return p;
}
ptrNode CreateTree(int a[]){
    int i = 0;
    ptrNode p = CreateTreeNLR(a, i);
    return p;
}

// Tính height
int ComputeHeight(ptrNode p){
    int height;
    if(p == nullptr){
        height = 0;
    }else{
        int leftHeight = ComputeHeight(p->Left);
        int rightHeight = ComputeHeight(p->Right);
        if(leftHeight > rightHeight){
            height = leftHeight + 1;
        }else{
            height = rightHeight + 1;
        }
    }
    return height;
}

// Tính số nút cây
int ComputeNodes(ptrNode p){
    int n;
    if(p == nullptr){
        n = 0;
    }else{
        n = ComputeNodes(p->Left) + ComputeNodes(p->Right) + 1;
    }
    return n;
}

// Tính số nút lá
int ComputeNumberOfLeaves(ptrNode p){
    int n;
    if(p == nullptr){
        n = 0;
    }else if(p->Left == nullptr && p->Right == nullptr){
        n = 1;
    }else{
        n = ComputeNumberOfLeaves(p->Left) + ComputeNumberOfLeaves(p->Right);
    }
    return n;
}
int ComputeLeaves(ptrNode root){
    int n = 0;
    if(root != nullptr){
        if(root->Left != nullptr || root->Right != nullptr){
            n = ComputeNumberOfLeaves(root);
        }
    }
    return n;
}

// Tính nút trung gian
int ComputeNumberOfInteriors(ptrNode p){
    int n;
    if(p == nullptr){
        n = 0;
    }else if(p->Left == nullptr && p->Right == nullptr){
        n = 0;
    }else{
        n = ComputeNumberOfInteriors(p->Left) + ComputeNumberOfInteriors(p->Right) + 1;
    }
    return n;
}
int ComputeInteriors(ptrNode root){
    int n = ComputeNumberOfInteriors(root);
    if(n > 0){
        n--;
    }
    return n;
}

// Duyệt cây theo heigth
void TraversalHeights(ptrNode root){
    if(!IsEmpty(root)){
        Queue queue;
        Init(queue);
        Enqueue(queue, root);
        while (!IsEmpty(queue))
        {
            ptrNode p = Dequeue(queue);
            cout << p->Info << endl;
            if(p->Left != nullptr){
                Enqueue(queue, p->Left);
            }
            if(p->Right != nullptr){
                Enqueue(queue, p->Right);
            }
        }
    }
}

// Hủy bỏ cây
void Clear(ptrNode& p){
    if(p != nullptr){
        Clear(p->Left);
        Clear(p->Right);
        delete p;
        p = nullptr;
    }
}
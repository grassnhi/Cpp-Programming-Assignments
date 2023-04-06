// Khai báo cấu trúc nút

typedef struct Node* ptr;

struct Node
{
    int Info;
    ptr Left;
    ptr Right;
};

// Khởi tạo cây rỗng
void Init(ptr& root){
    root = nullptr;
}

// Khởi tạo cây từ 1 mảng đk: a[i] = 0 => cây rỗng
void CreateNLR(ptr& p, int a[], int& i){
    if(a[i] == 0){
        p = nullptr;
    }else{
        p = new Node;
        p->Info = a[i]
        i++;
        CreateNLR(p->Left, a, i);
        i++;
        CreateNLR(p->Right, a, i);
    }
}
void CreateTree(ptr& root, int a[]){
    int i = 0;
    CreateNLR(root, a, i);
}

// Kiểm tra cây rỗng
bool IsEmpty(ptr root){
    bool kq = root == nullptr;
    return kq;
}

// Duyệt cây
void NLR(ptr p, int n){
    for(int i = 0; i <= n; i++){
        cout << " ";
    }
    if(p == nullptr){
        cout << "0" << endl;
    }else{
        cout << p->Info << endl;
        NLR(p->Left, n + 2);
        NLR(p->Right, n + 2);
    }
}
void TraversalNLR(ptr p){
    NLR(p, 1);
}

// Hủy bỏ cây
void Clear(ptr& root){
    if(p != nullptr){
        Clear(p->Left);
        Clear(p->Right);
        delete p;
        p = nullptr;
    }
}

// Tính số nút của cây
int Nodes(ptr p){
    int kq;
    if(p == nullptr){
        kq = 0
    }else{
        kq = Nodes(p->Left) + Nodes(p->Right) + 1;
        //      L                   R           N
    }
    return kq;
}

// Tính chiều cao cây
int Height(ptr p){
    int kq;
    if(p == nullptr){
        kq = 0;
    }else{
        int hl = Height(p->Left);
        int hr = Height(p->Right);
        if(hl > hr){
            kq = hl + 1;
        }else{
            kq = hr + 1;
        }
    }
    return kq;
}

// Tính số nút lá của cây
int TreeLeaves(ptr p){
    int kq; 
    if(p == nullptr){
        kq = 0;
    }else if((p->Left == nullptr) && (p->Right == nullptr)){
        kq = 1;
    }else{
        kq = TreeLeaves(p->Left) + TreeLeaves(p->Right);
    }
    return kq;
}
int Leaves(ptr root){
    int kq = 0;
    if(root != nullptr){
        if(root->Left != nullptr || root->Right != nullptr){
            kq = TreeLeaves(root);
        }
    }
    return kq;
}

// Tính số nút trung gian của cây
int TreeInteriors(ptr p){
    int kq;
    if(p == nullptr){
        kq = 0;
    }else if(p->Left == nullptr && p->Right == nullptr){
        kq = 0;
    }else{
        kq = TreeInteriors(p->Left) + TreeInteriors(p->Right) + 1;
    }
    return kq;
}
int Interiors(ptr root){
    int kq = TreeInteriors(root);
    if(kq > 0){
        kq--;
    }
    return kq;
}
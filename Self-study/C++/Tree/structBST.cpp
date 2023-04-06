/*
- Key: chứa khóa nút, không trùng
- Count: số lần xuất hiện (int)
- Left: con trỏ nút con trái
- Right: con trở nút con phải
*/

struct Node;
typedef Node* ptrNode;

struct Node
{
    int Key;
    int Count;
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

// Thêm khóa vào cây đệ quy
void Insert(ptrNode& p, int theKey){
    if(p == nullptr){
        p = new Node;
        p->Key = theKey;
        p->Count = 1;
        p->Left = nullptr;
        p->Right = nullptr;
    }else if(theKey < p->Key){
        Insert(p->Left, theKey);
    }else if(p->Key == theKey){
        p->Count = p->Count + 1;
    }else{
        Insert(p->Right, theKey);
    }
}

// Thêm khóa vào cây vòng lặp
void Insert(ptrNode& root, int theKey){
    ptrNode q = new Node;
    q->Key = theKey;
    q->Count = 1;
    q->Left = nullptr;
    q->Right = nullptr;
    if(root == nullptr){
        root = q;
    }else{
        ptrNode parent;
        ptrNode p = root;
        while (p != nullptr)
        {
            parent = p;
            if(theKey < p->Key){
                p = p->Left;
            }else if(theKey > p->Key){
                p = p->Right;
            }else{
                p->Count = p->Count + 1;
            }
        }
        if(theKey < parent->Key){
            parent->Left = q;
        }else{
            parent->Right = q;
        }
    }
}

// Tìm kiếm khóa vòng lặp
ptrNode Find(ptrNode p, int theKey){
    bool found = false;
    while (p != nullptr && !found)
    {
        if(theKey < p->Key){
            p = p->Left;
        }else if(theKey == p->Key){
            found = true;
        }else{
            p = p->Right;
        }
    }
    return p;
}

// Tìm kiếm đệ quy
ptrNode Find(ptrNode p, int theKey){
    ptrNode results;
    if(p == nullptr){
        results = nullptr;
    }else{
        if(theKey < p->Key){
            results = Find(p->Left, theKey);
        }else if(theKey == p->Key){
            results = p;
        }else{
            results = Find(p->Right, theKey);
        }
    }
    return results;
}

// Loại bỏ nút cực phải đệ quy
void RemoveRightmostNode(ptrNode& r, ptrNode& q){
    if(r->Right != nullptr){
        RemoveRightmostNode(r->Right, q);
    }else{
        q->Key = r->Key;
        q->Count = r->Count;
        q = r;
        r = r->Left;
    }
}

// Loại bỏ khóa theKey
void Remove(ptrNode& p, int theKey, bool& error){
    error = true;
    if(p != nullptr){
        if(theKey < p->Key){
            Remove(p->Left, theKey, error);
        }else if(theKey > p->Key){
            Remove(p->Right, theKey, error);
        }else{
            error = false;
            ptrNode q = p;
            if(p->Left == nullptr && p->Right == nullptr){
                p = nullptr;
            }else if(p->Left != nullptr && p->Right == nullptr){
                p = p->Left;
            }else if(p->Left == nullptr && p->Right != nullptr){
                p = p->Right;
            }else{
                RemoveRightmostNode(p->Left, q);
            }
            delete q;
        }
    }
}

// Loại bỏ theKey vòng lặp
void Remove(ptrNode& root, int theKey, bool& error){
    error = true;
    bool found = false;
    bool isLeftChild = false;
    ptrNode parent;
    ptrNode p = root;
    while (p != nullptr && !found)
    {
        if(theKey == p->Key){
            found = true;
        }else if(theKey < p->Key){
            parent = p;
            p = p->Left;
            isLeftChild = true;
        }else{
            parent = p;
            p = p->Right;
            isLeftChild = true;
        }
    }
    if(found){
        error = false;
        if(p->Left == nullptr && p->Right == nullptr){
            if(p == root){
                root = nullptr;
            }else if(isLeftChild){
                parent->Left = nullptr;
            }else{
                parent->Right = nullptr;
            }
        }else if(p->Left != nullptr && p->Right == nullptr){
            if(p == root){
                root = p->Left;
            }else if(isLeftChild){
                parent->Left = p->Left;
            }else{
                parent->Right = p->Left;
            }
        }else if(p->Left == nullptr && p->Right != nullptr){
            if(p == root){
                root = p->Right;
            }else if(isLeftChild){
                parent->Left = p->Right;
            }else{
                parent->Right = p->Right;
            }
        }else{
            ptrNode r = p->Left;
            while (r->Right != nullptr)
            {
                parent = r;
                r = r->Right;
            }
            p->Key = r->Key;
            p->Count = r->Count;
            if(r == p->Left){
                p->Left = r->Left;
            }else{
                parent->Right = p->Left
            }
            p = r;
        }
        delete p;
    }
}

// Duyệt cây NLR
void DisplayNode(ptrNode p){
    cout << p->Key << ":" << p->Height << endl;
}
void NLR(ptrNode p, int n){
    for(int i = 1, i <= n; i++){
        cout << " ";
        if(p != nullptr){
            DisplayNode(p);
            NLR(p->Left, n+3);
            NLR(p->Right, n+3);
        }
    }else{
        cout << "0:0" << endl;
    }
}
void TraversalNLR(ptrNode root){
    if(IsEmpty(root)){
        cout << "Empty" << endl;
    }else{
        NLR(root, 0);
    }
}

// Tạo cây từ mảng NLR
void Create(ptrNode& p, int a[], int& i){
    if(a[i] == 0){
        p = nullptr;
    }else{
        p = new Node;
        p->Key = a[i];
        i++;
        Create(p->Left, a, i);
        i++;
        Create(p->Right, a, i);
    }
}

// kiểm tra BST
bool IsBSTTree(ptrNode p, int& key, bool& firstTime){
    bool isBST = true;
    if(p != nullptr){
        isBST = IsBSTTree(p->Left, key, firstTime);
        if(isBST){
            if(firstTime){
                firstTime = false;
            }else if(key >= p->Key){
                isBST = false;
            }
            key = p->Key;
        }
        if(isBST){
            isBST = IsBSTTree(p->Right, key, firstTime);
        }
    }
    return isBST;
}
bool IsBST(ptrNode p){
    int key;
    bool firstTime = true;
    bool result = IsBSTTree(p, key, firstTime);
    return result;
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
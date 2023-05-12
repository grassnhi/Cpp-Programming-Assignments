/*
- Key: chứa khóa nút
- Count: Số lần xuất hiện
- Height: Chiều cao nút
- Left: con trỏ nút con trái
- Right: con trỏ nút con phải
*/

struct Node;
typedef Node* ptrNode;

struct Node
{
    int Key;
    int Count;
    int Height;
    ptrNode Left;
    ptrNode Right;
};

ptrNode root;

// Tạo cây rỗng
void Init(ptrNode& root){
    root = nullptr;
}

// Kiểm tra cây rỗng
bool IsEmpty(ptrNode root){
    bool result = root == nullptr;
    return result;
}

// Thêm khóa, quay cây con trái
void SingleWithLeftChild(ptrNode& p){
    ptrNode q = p->Left;
    p->Left = q->Right;
    q->Right = p;
    ComputeHeight(p);
    ComputeHeight(q);
    p = q;
} // Phép quay đơn
void DoubleWithLeftChild(ptrNode& p){
    ptrNode q = p->Left;
    ptrNode r = q->Right;
    q->Right = r->Left;
    p->Left = q;
    r->Right = p;
    ComputeHeight(q);
    ComputeHeight(p);
    ComputeHeight(r);
    p =  r;
} // Phép quay kép
int GetHeight(ptrNode p){
    int height;
    if(p == nullptr){
        height = 0;
    }else{
        height = p->Height;
    }
    return height;
}
void ComputeHeight(ptrNode p){
    int hl = GetHeight(p->Left);
    int hr = GetHeight(p->Right);
    if(hl >= hr){
        p->Height = hl + 1;
    }else{
        p->Height = hr + 1;
    }
} // Tính height
void RotateWithLeftChild(ptrNode& p){
    ptrNode q = p->Left;
    if(GetHeight(q->Left) >= GetHeight(q->Right)){
        SingleWithLeftChild(p);
    }else{
        DoubleWithLeftChild(p);
    }
} // Phép quay cây con trái

// Thêm khóa, quay cây con phải
void SingleWithRightChild(ptrNode& p){
    ptrNode q = p->Right;
    p->Right = q->Left;
    q->Left = p;
    ComputeHeight(p);
    ComputeHeight(q);
    p = q;
} // Phép quay đơn
void DoubleWithRightChild(ptrNode& p){
    ptrNode q = p->Right;
    ptrNode r = q->Left;
    q->Left = r->Right;
    p->Right = r->Left;
    r->Left = p;
    r->Right = q;
    ComputeHeight(q);
    ComputeHeight(p);
    ComputeHeight(r);
    p = r;
} // Phép quay kép
void RotateWithRightChild(ptrNode& p){
    ptrNode q = p->Right;
    if(GetHeight(q->Right) >= GetHeight(q->Left)){
        SingleWithRightChild(p);
    }else{
        DoubleWithRightChild(p);
    }
}

// Them khóa
void Insert(ptrNode& p, int theKey){
    if(p == nullptr){
        p = new Node;
        p->Key = theKey;
        p->Height = 1;
        p->Count = 1;
        p->Left = nullptr;
        p->Right = nullptr;
    }else if(theKey < p->Key){
        Insert(p->Left, theKey);
        if(GetHeight(p->Left) - GetHeight(p->Right) == 2){
            RotateWithLeftChild(p);
        }
        ComputeHeight(p);
    }else if(p->Key == theKey){
        p->Count = p->Count + 1;
    }else{
        Insert(p->Right, theKey);
        if(GetHeight(p->Right) -  GetHeight(p->Left) == 2){
            RotateWithRightChild(p);
        }
        ComputeHeight(p);
    }
}

// tìm kiếm khóa vòng lặp
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

// Loại bỏ khóa
void RemoveRigntmostNode(ptrNode& r, ptrNode& q){
    if(r->Right != nullptr){
        RemoveRigntmostNode(r->Right, q);
        ComputeHeight(r);
    }else{
        q->Key = r->Key;
        q->Count = r->Count;
        q = r;
        r = r->Left;
    }
} // Loại bỏ nút cực phải
void Remove(ptrNode& p, int theKey, bool& error){
    error = true;
    if(p != nullptr){
        if(theKey < p->Key){
            Remove(p->Left, theKey, error);
            if(GetHeight(p->Right) - GetHeight(p->Left) == 2){
                RotateWithRightChild(p);
            }
            ComputeHeight(p);
        }else if(theKey == p->Key){
            error = false;
            ptrNode q = p;
            if(p->Left == nullptr && p->Right == nullptr){
                p = nullptr;
            }else if(p->Left != nullptr && p->Right == nullptr){
                p = p->Left;
            }else if(p->Left == nullptr && p->Right != nullptr){
                p = p->Right;
            }else{
                RemoveRigntmostNode(p->Left, q);
                if(GetHeight(p->Right) - GetHeight(p->Left) == 2){
                    RotateWithRightChild(p);
                }
            ComputeHeight(p);
            }
        }
        delete q;
    }else{
        Remove(p->Right, theKey, error);
        if(GetHeight(p->Left) - GetHeight(p->Right) == 2){
            RotateWithRightChild(p);
        }
        ComputeHeight(p);
    }
}

// Hiển thị nút
void DisplayNode(ptrNode p){
    cout << p->Key << ":" << p->Height << endl;
}

// Duyệt cây NLR
void TraversalNLR(ptrNode p, int n){
    for(int i = 1; i <= n; i++){
        cout << " ";
        if(p != nullptr){
            DisplayNode(p);
            TraversalNLR(p->Left, n+3);
            TraversalNLR(p->Right, n+3);
        }else{
            cout << "0:0" << endl;
        }
    }
}
void Traverse(ptrNode root){
    if(IsEmpty(root)){
        cout << "Empty" << endl;
    }else{
        TraversalNLR(root, 0);
    }
}

// Kiểm tra tính cân bằng
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
bool IsBalanced(ptrNode p, int& height){
    bool avl;
    if(p == nullptr){
        avl = true;
        height = 0;
    }else{
        int leftHeight, rightHeight;
        avl = IsBalanced(p->Left, leftHeight);
        if(avl){
            if(leftHeight == rightHeight + 2 || rightHeight == leftHeight + 2){
                avl = false;
            }else{
                if(leftHeight > rightHeight){
                    height = leftHeight + 1;
                }else{
                    height = rightHeight + 1;
                }
            }
        }
    }
    return  avl;
}

// Hủy bỏ cây
void Clear(ptrNode& p){
    Clear(p->Left);
    Clear(p->Right);
    delete p;
    p = nullptr;
}
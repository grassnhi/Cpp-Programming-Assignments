/*
B-tree: multiway tree -> n cấp
- mỗi trang max 2n khóa, min n khóa, gốc 1 khóa
- Hoặc trang lá hoặc m+1 trang con, m = số khóa
- Tất cả trang lá cùng mức
CTDL của khóa
- Key: chứa khóa của phần tử
- Next: con trở trang con phải
CTDL của trang
- P0: con trỏ trang con đầu
- KeyItem: mảng chứa phần tử khóa của trang
- KeyNum: số khóa hiện tại của trang
*/

const int M = 5;
const int M2 = M /2;

struct Item;
typedef Item* ptrItem;

struct Page;
typedef Page* ptrPage;

struct Item
{
    int Key;
    ptrPage Next;
};

struct Page
{
    Item KeyItem[M];
    ptrPage P0;
    int KeyNum;
};

ptrPage root;

// Khởi tạo cây rỗng
void Init(ptrPage& root){
    root = nullptr;
}

// kiểm tra rỗng
bool IsEmpty(ptrPage root){
    return root == nullptr;
}

// Tìm kiếm khóa
void FindPage(ptrPage p, int theKey, bool& found, int& pos){
    found = false;
    int k;
    int i = 0;
    int j = p->KeyNum - 1;
    while (i <= j && !found)
    {
        k = (i+j) / 2;
        if(theKey < p->KeyItem[k].Key){
            j = k - 1;
        }else if(theKey == p->KeyItem[k].Key){
            found = true;
        }else{
            i = k + 1;
        }
    }
    if(found){
        pos = k;
    }else{
        pos = j;
    }
}
void FindBTree(ptrPage p, int theKey, bool& found, int& pos){
    if(p == nullptr){
        found = false;
        pos = -1;
    }else{
        FindPage(p, theKey, found, pos);
        if(!found){
            if(pos == -1){
                FindBTree(p->P0, theKey, found, pos);
            }else{
                FindBTree(p->KeyItem[pos].Next, theKey, found, pos);
            }
        }
    }
}
bool Find(ptrPage root, int theKey){
    bool found;
    int pos;
    FindBTree(root, theKey, found, pos);
    return found;
}

// Thêm khóa vào cây
void InsertPage(ptrPage& p, int pos, int theKey, ptrPage r, bool& overflow, int& overflowKey, ptrPage& overflowPage){
    overflow = false;
    overflowKey = theKey;
    overflowPage = nullptr;
    for(int i = p->KeyNum - 1; i > pos; i--){
        p->KeyItem[i+1].Key = p->KeyItem[i].Key;
        p->KeyItem[i+1].Next = p->KeyItem[i].Next;
    }
    p->KeyItem[pos+1].Key = theKey;
    p->KeyItem[pos+1].Next = r;
    p->KeyNum++;
    if(p->KeyNum == M){
        overflow = true;
        overflowKey = p->KeyItem[M2].Key;
        overflowPage = new Page;
        overflowPage->KeyNum = M2;
        int k = 0;
        for(int i = M2 + 1; i < p->KeyNum; i++){
            overflowPage->KeyItem[k].Key = p->KeyItem[i].Key;
            overflowPage->KeyItem[k].Next = p->KeyItem[i].Next;
            k++;
        }
        overflowPage->P0 = p->KeyItem[M2].Next;
        p->KeyNum = M2;
    }
}
void InsertBTree(ptrPage& p, int theKey, bool& overflow, int& overflowKey, ptrPage& overflowPage){
    overflowKey = theKey;
    overflowPage = nullptr;
    if(p == nullptr){
        overflow = true;
    }else{
        overflow = false;
        bool found;
        int pos;
        FindPage(p, theKey, found, pos);
        if(!found){
            ptrPage q;
            if(pos == -1){
                q = p->P0;
            }else{
                q = p->KeyItem[pos].Next;
            }
            InsertBTree(q, theKey, overflow, overflowKey, overflowPage);
            if(overflow){
                int theKey2 = overflowKey;
                ptrPage r = overflowPage;
                InsertPage(p, pos, theKey2, r, overflow, overflowKey, overflowPage);
                if(overflow){
                    if(p == root){
                        CreatePage(q);
                        q->P0 = p;
                        q->KeyItem[0].Key = overflowKey;
                        q->KeyItem[0].Next = overflowPage;
                        q->KeyNum = 1;
                        root = q;
                        overflow = false;
                    }
                }
            }
        }
    }
}
void Insert(ptrPage& root, int theKey){
    if(root == nullptr){
        CreatePage(root);
        root->KeyItem[0].Key = theKey;
        root->KeyNum = 1;
    }else{
        bool overflow;
        int overflowKey;
        ptrPage overflowPage;
        InsertBTree(root, theKey, overflow, overflowKey, overflowPage);
    }
}

// Loại bỏ khóa
void RemoveKey(ptrPage p, int pos){
    for(int i = pos, i < p->KeyNum; i++){
        p->KeyItem[i].Key = p->KeyItem[i+1].Key;
        p->KeyItem[i].Next = p->KeyItem[i+1].Next;
    }
    p->KeyNum--;
}
void MergePage(ptrPage p, ptrPage parent, int pos, ptrPage q){
    int n = p->KeyNum;
    p->KeyItem[n].Key = parent->KeyItem[pos].Key;
    p->KeyItem[n].Next = q->P0;
    n++;
    for(int i = 0; i < q->KeyNum; i++){
        p->KeyItem[i+1].Key = q->KeyItem[i].Key;
        p->KeyItem[i+1].Next = q->KeyItem[i].Next;
    }
    p->KeyNum = M - 1;
    for(int i = pos; i < parent->KeyNum; i++){
        parent->KeyItem[i+1].Key = parent->KeyItem[i].Key;
        parent->KeyItem[i+1].Next = parent->KeyItem[i].Next;
    }
    parent->KeyNum--;
    if(parent == root && parent->KeyNum == 0){
        root = p;
    }
    delete q;
}
void RetrieveRightPage(ptrPage p, ptrPage parent, int pos, ptrPage q){
    p->KeyItem[p->KeyNum].Key = parent->KeyItem[pos].Key;
    p->KeyItem[p->KeyNum].Next = q->P0;
    p->KeyNum++;

    parent->KeyItem[pos].Key = q->KeyItem[0].Key;
    q->P0 = q->KeyItem[0].Next;
    for(int i = 1; i < q->KeyNum; i++){
        parent->KeyItem[i-1].Key = parent->KeyItem[i].Key;
        parent->KeyItem[i-1].Next = parent->KeyItem[i].Next;
    }
    q->KeyNum--;
}
void RetrieveLeftPage(ptrPage p, ptrPage parent, int pos, ptrPage q){
    for(int i = p->KeyNum - 1; i >= 0; i--){
        p->KeyItem[i+1].Key = p->KeyItem[i].Key;
        p->KeyItem[i+1].Next = p->KeyItem[i].Next;
    }
    p->KeyItem[0].Key = parent->KeyItem[pos].Key;
    p->KeyItem[0].Next = p->P0;
    p->P0 = q->KeyItem[q->KeyNum-1].Next;
    p->KeyNum++;
    parent->KeyItem[pos].Key = q->KeyItem[q->KeyNum-1].Key;
    q->KeyNum--;
}
void UnderflowRightPage(ptrPage p, ptrPage parent, int pos){
    ptrPage rightPage = parent->KeyItem[pos].Next;
    if(rightPage->KeyNum > M2){
        RetrieveRightPage(p, parent, pos, rightPage);
    }else{
        MergePage(p, parent, pos, rightPage);
    }
}
void UnderflowLeftPage(ptrPage& p, ptrPage parent, int pos){
    ptrPage leftPage = parent->KeyItem[pos-1].Next;
    if(leftPage->KeyNum > M2){
        RetrieveRightPage(p, parent, pos, leftPage);
    }else{
        MergePage(leftPage, parent, pos, p);
        p = leftPage;
    }
}
void Underflow(ptrPage& p, ptrPage parent, int pos){
    ptrPage leftPage;
    ptrPage rightPage;
    if(pos == -1){
        leftPage = nullptr;
    }else if(pos == 0){
        leftPage = parent->P0;
    }else{
        leftPage = parent->KeyItem[pos-1].Next;
    }
    if(pos == parent->KeyNum - 1){
        rightPage = nullptr;
    }else{
        rightPage = parent->KeyItem[pos+1].Next;
    }
    if(leftPage == nullptr){
        UnderflowRightPage(p, parent, pos+1);
    }else if(rightPage == nullptr){
        UnderflowLeftPage(p, parent, pos);
    }else{
        if(rightPage->KeyNum > M2){
            RetrieveRightPage(p, parent, pos+1, rightPage);
        }else{
            if(leftPage->KeyNum > M2){
                RetrieveLeftPage(p, parent, pos, leftPage);
            }else{
                MergePage(p, parent, pos+1, rightPage);
            }
        }
    }
}
void RemoveRightmostNode(ptrPage& q, ptrPage parent, int pos, Item& element){
    int n = q->KeyNum - 1;
    if(q->KeyItem[n].Next != nullptr){
        RemoveRightmostNode(q->KeyItem[n].Next, q, n, element);
        if(q->KeyNum < M2){
            Underflow(q, parent, pos);
        }
    }else{
        element.Key = q->KeyItem[n].Key;
        q->KeyNum--;
        if(q->KeyNum < M2){
            Underflow(q, parent, pos);
        }
    }
}
void RemoveBTree(ptrPage& p, int theKey, ptrPage parent, int pos, bool& error){
    error = true;
    bool found;
    ptrPage q;
    int posKey;
    if(p != nullptr){
        FindPage(p, theKey, found, posKey);
        if(found){
            error = false;
            if(posKey != -1){
                if(p->P0 == nullptr){
                    RemoveKey(p, posKey);
                    if(p->KeyNum < M2){
                        if(p == root){
                            if(p->KeyNum == 0){
                                delete p;
                                root == nullptr;
                            }
                        }else{
                            Underflow(p, parent, pos);
                        }
                    }
                }else{
                    int position;
                    if(posKey == 0){
                        q = p->P0;
                        position = -1;
                    }else{
                        q = p->KeyItem[posKey-1].Next;
                        position = posKey - 1;
                    }
                    RemoveRightmostNode(q, p, position, p->KeyItem[posKey]);
                    if(p != root){
                        if(p->KeyNum < M2){
                            Underflow(p, parent, pos);
                        }
                    }
                }
            }
        }else{
            if(p->P0 != nullptr){
                if(posKey == -1){
                    q = p->P0;
                }else{
                    q = p->KeyItem[posKey].Next;
                }
                RemoveBTree(q, theKey, p, posKey, error);
                if(p != root){
                    if(p->KeyNum < M2){
                        Underflow(p, parent, pos);
                    }
                }
            }
        }
    }
}
void Remove(ptrPage& root, int theKey, bool& error){
    ptrPage parent = nullptr;
    int pos = -2;
    RemoveBTree(root, theKey, parent, pos, error);
}

// Hiển thị trang
void DisplayPage(ptrPage p){
    for(int i = 0; i < p->KeyNum; i++){
        cout << p->KeyItem[i].Key << " ";
    }
    cout << endl;
}

// Hiển thị cây p
void DisplayTree(ptrPage p, int k){
    for(int i = 1; i <= k; i++){
        cout << " ";
    }
    DisplayPage(p);
    if(p->P0 != nullptr){
        DisplayTree(p->P0, k+2);
    }
    for(int i = 0; i < p->KeyNum; i++){
        if(p->KeyItem[i].Next != nullptr){
            DisplayTree(p->KeyItem[i].Next, k+2);
        }
    }
}
// Hiển thị cây root
void DisplayBTree(ptrPage root){
    if(root == nullptr){
        cout << "Empty" << endl;
    }else{
        DisplayTree(root, 0);
    }
}

// Hủy bỏ cây
void ClearLRN(ptrPage& p){
    if(p != nullptr){
        if(p->P0 != nullptr){
            ClearLRN(p->P0);
        }
        for (int i = 0; i < p->KeyNum; i++)
        {
            if(p->KeyItem[i].Next != nullptr){
                ClearLRN(p->KeyItem[i].Next);
            }
        }
        delete p;
        p = nullptr;
    }
}
void Clear(ptrPage& root){
    ClearLRN(root);
}
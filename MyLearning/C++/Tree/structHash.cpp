PHƯƠNG PHÁP KẾT NỐI

/* Phương pháp kết nối trực tiếp: linked list, tree */

/*
CTDL nút
- Key: khóa nút
- Count: số lần key xuất hiện
- Left: con trỏ nút con trái
- Right: con trở nút con phải
CTDL bảng băm
- Mảng M phần tử, con trỏ đến nút gốc BST
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

struct HashTable
{
    ptrNode* Arr;
    int M;
};

int HashFunc(int m, int theKey){
    return theKey % m;
}

// Thêm khóa
void InsertBST(ptrNode& p, int theKey){
    if(p == nullptr){
        p = new Node;
        p->Key = theKey;
        p->Count = 1;
        p->Left = nullptr;
        p->Right = nullptr;
    }else{
        if(theKey < p->Key){
            InsertBST(p->Left, theKey);
        }else if(theKey == p->Key){
            p->Count++;
        }else{
            InsertBST(p->Right, theKey);
        }
    }
}
void Insert(HashTable& hashTable, int theKey){
    int address = HashFunc(hashTable.M, theKey);
    InsertBST(hashTable.Arr[address], theKey);
}

// tìm kiếm khóa
ptrNode FindBST(ptrNode p, int theKey){
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
ptrNode Find(HashTable hashTable, int theKey){
    int address = HashFunc(hashTable.M, theKey);
    ptrNode result = FindBST(hashTable.Arr[address], theKey);
    return result;
}

// Loại bỏ khóa
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
void RemoveBST(ptrNode& p, int theKey, bool& error){
    error = true;
    if(p != nullptr){
        if(theKey < p->Key){
            RemoveBST(p->Left, theKey, error);
        }else if(theKey > p->Key){
            RemoveBST(p->Right, theKey, error);
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
void Remove(HashTable& hashTable, int theKey, bool& error){
    int address = HashFunc(hashTable.M, theKey);
   RemoveBST(hashTable.Arr[address], theKey, error);
}

// Hiển thị bảng băm
void TraverseLNR(ptrNode p){
    if(p != nullptr){
        TraverseLNR(p->Left);
        cout << p->Key << " ";
        TraverseLNR(p->Right);
    }
}
void Display(HashTable hashTable){
    for(int i = 0; i < hashTable.M; i++){
        TraverseLNR(hashTable.Arr[i]);
        cout << endl;
    }
}

// Hủy bỏ bảng băm
void ClearLRN(ptrNode& p){
    if(p != nullptr){
        ClearLRN(p->Left);
        ClearLRN(p->Right);
        delete p;
        p = nullptr;
    }
}
void Clear(HashTable& hashTable){
    for(int i = 0; i < M; i++){
        ClearLRN(hashTable.Arr[i]);
    }
}

/* Phương pháp kết nối hợp nhất */

/*
CTDL phần tử
- Key: chứa khóa
- Next: chỉ số phần tử kế
*/

const int FREE = -1;
struct Item;
typedef Item* ptrItem;

struct Item
{
    int Key;
    int Next;
};

struct HashTable
{
    Item* Arr;
    int Count;
    int M;
};

int HashFunc(int m, int theKey){
    return key % m;
}

// khởi tạo
void Init(HashTable& hashTable, int m){
    hashTable.Arr = new Item[m];
    for(int i = 0; i < M; i++){
        hashTable.Arr[i].Key = FREE;
        hashTable.Arr[i].Next = FREE;
    }
    hashTable.Count = 0;
    hashTable.M = m;
}

// Thêm khóa
void Insert(HashTable& hashTable, int theKey, bool& error){
    if(hashTable.Count == hashTable.M){
        error = true;
    }else{
        error = false;
        int address = HashFunc(hashTable.M, theKey);
        if(hashTable.Arr[address].Key == FREE){
            hashTable.Arr[address].Key == theKey;
        }else{
            int i = hashTable.M - 1;
            while (hashTable.Arr[i].Key != FREE)
            {
                i--;
            }
            hashTable.Arr[i].Key = theKey;
            int k = address;
            while (hashTable.Arr[k].Next != FREE)
            {
                k = hashTable.Arr[k].Next;
            }
            hashTable.Arr[k].Next = i;
        }
        hashTable.Count++;
    }
}

// Tìm kiếm khóa
int Find(HashTable& hashTable, int theKey){
    int result;
    int address = HashFunc(hashTable.M, theKey);
    if(hashTable.Arr[address].Key == FREE){
        result = -1;
    }else{
        bool found =  false;
        int i = address;
        while (i != FREE && !found)
        {
            if(hashTable.Arr[i].Key == theKey){
                found = true;
            }else{
                i = hashTable.Arr[i].Next;
            }
        }
        result = i;
    }
    return result;
}

// Loại bỏ khóa
void Remove(HashTable& hashTable, int theKey, bool& error){
    error = true;
    int i = HashFunc(hashTable.M, theKey);
    bool found = false;
    while (i != FREE && !found)
    {
        if(hashTable.Arr[i].Key == theKey){
            found = true;
        }else{
            i = hashTable.Arr[i].Next;
        }
    }
    if(found){
        error = false;
        int before = FREE;
        int k;
        while (hashTable.Arr[i].Next != FREE)
        {
            k = hashTable.Arr[i].Next;
            hashTable.Arr[i].Key = hashTable.Arr[k].Key;
            before = i;
            i = k;
        }
        if(before != FREE){
            hashTable.Arr[before].Next = FREE;
        }
        hashTable.Count--;
    }
}

// Hiển thị bảng băm
void Display(HashTable hashTable){
    for(int i = 0; i < hashTable.M; i++){
        cout << hashTable.Arr[i].Key << "->" << hashTable.Arr[i].Next << endl;
    }
    cout << "Count: " << hashTable.Count << endl;
}

// Hủy bỏ bảng băm
void Clear(HashTable& hashTable){
    for(int i = 0; i < hashTable.M; i++){
        hashTable.Arr[i].Key = FREE;
        hashTable.Arr[i].Next = FREE;
    }
    hashTable.Count = 0;
}


PHƯƠNG PHÁP ĐỊA CHỈ MỞ

/* Phương pháp thử tuyến tính */

const int FREE = -1;

struct HashTable
{
    int* Arr;
    int Count;
    int M;
};

int HashFunc(int m, int theKey){
    return theKey % m;
}

// Khởi tạo bảng băm
void Init(HashTable& hashTable, int m){
    hashTable.Arr = new Item[m];
    for(int i = 0; i < M; i++){
        hashTable.Arr[i].Key = FREE;
        hashTable.Arr[i].Next = FREE;
    }
    hashTable.Count = 0;
    hashTable.M = m;
}

// Thêm khóa
void Insert(HashTable& hashTable, int theKey, bool& error){
    if(hashTable.Count == hashTable.M - 1){
        error = true;
    }else{
        error = false;
        int i = HashFunc(hashTable.M, theKey);
        while (hashTable.Arr[i].Key != FREE)
        {
            i++;
            i = i % hashTable.M;
            hashTable.Arr[i].Key = theKey;
        }
        hashTable.Arr[i] = theKey;
        hashTable.Count++;
    }
}

// Tìm kiếm khóa
int Find(HashTable hashTable, int theKey){
    int i = HashFunc(hashTable.M, theKey);
    bool found = false;
    while (hashTable.Arr[i] != FREE && !found)
    {
        if(hashTable.Arr[i] == theKey){
            found = true;
        }else{
            i++;
            i = i % hashTable.M;
        }
    }
    if(!found){
        i = -1;
    }
    return i;
}

// Loại bỏ khóa
void RemovePosition(HashTable& hashTable, int i){
    bool cont = true;
    bool inside = true;
    do{
        hashTable.Arr[i] = FREE;
        int j = i;
        do{
            i++;
            i = i % hashTable.M;
            if(hashTable.Arr[i] == FREE){
                cont = false;
            }else{
                int r = HashFunc(hashTable.Arr[i]);
                inside = ((j < r) && (r <= i)) || ((r <= i) && (i < j) || (i < j) && (j < r));
            }
        }while(cont && inside);
        if(cont){
            hashTable.Arr[j] = hashTable.Arr[i];
        }
    }while(cont);
}
void Remove(HashTable& hashTable, int theKey, bool& error){
    int i = Find(hashTable, theKey);
    if(i == -1){
        error = true;
    }else{
        error = false;
        hashTable.Count--;
        RemovePosition(hashTable, i);
    }
}

// Hiển thị bảng băm
void Display(HashTable hashTable){
    for(int i = 0; i < hashTable.M; i++){
        cout << hashTable.Arr[i].Key << endl;
    }
    cout << "Count: " << hashTable.Count << endl;
}

// Hủy bỏ bảng băm
void Clear(HashTable& hashTable){
    for(int i = 0; i < hashTable.M; i++){
        hashTable.Arr[i].Key = FREE;
    }
    hashTable.Count = 0;
}
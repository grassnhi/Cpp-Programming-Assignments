/*
Cho node root của một danh sách liên kết đơn, hiện thực hàm sau đây:

void reduceDuplicate(Node* root);
để giảm các phần tử trùng lặp liên tiếp trong danh sách. Nếu có các phần tử liên tiếp giống nhau, 
ta chỉ giữ lại 1 phần tử.
Ví dụ, ta có 1 danh sách 122234452, sau khi thực hiện hàm reduceDuplicate ta thu được danh sách 123452. 
(số 2 cuối cùng giữ nguyên do nó không liên tiếp với dãy 222 phía trước)

Lưu ý: Các bạn có thể include thêm thư viện nếu cần thiết

Cấu trúc của một node được cho bên dưới. Các bạn chỉ cần viết nội dung hàm reduceDuplicate, 
các cấu trúc khác đã được import sẵn.

class Node
{
    int data;
    Node* next;
public:
    Node(): data(0), next(nullptr){}

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node* getNext()
    {
        return this->next;
    }

    void setNext(Node* next)
    {
        this->next = next;
    }
};

*/

void reduceDuplicate(Node* root)
{
    Node* curr = root;
    while (curr != nullptr && curr->getNext() != nullptr) {
        if (curr->getData() == curr->getNext()->getData()) {
            Node* tmp = curr->getNext();
            curr->setNext(curr->getNext()->getNext());
            delete tmp;
        } else {
            curr = curr->getNext();
        }
    }
}

// Your code failed one or more hidden tests.

void reduceDuplicate(Node* root)
{   
    if(root == nullptr){
        return;
    }
    Node* head = root;
    Node* tmp = head;
    Node* curr = tmp->getNext();
    while (tmp != nullptr && curr != nullptr)
    {
        while (curr != nullptr)
        {
            if(curr->getData() == tmp->getData()){
                curr = curr->getNext();
                tmp->setNext(curr); // Fall ở TH 0-1-1-1-1-..
            }else{
                curr = curr->getNext();
            }
        }
        
        if(tmp != nullptr && tmp->getNext() != nullptr){
            tmp = tmp->getNext();
            curr = tmp->getNext();
        }
    }
}

/*
Node* node1 = new Node(1, nullptr);
Node* node2 = new Node(1, node1);
Node* node3 = new Node(0, node2);
printList(node3);
reduceDuplicate(node3);
printList(node3);
*/
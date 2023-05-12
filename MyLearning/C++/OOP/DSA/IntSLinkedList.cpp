class IntSLinkedList : public IList <int > {
public :
class Node ; // Forward declaration

protected :
    Node * head ;
    Node * tail ;
    int count ;

public :
    IntSLinkedList () :
    head ( NULL ), tail ( NULL ), count (0) {};

public :
    class Node {
    protected :
        int data ;
        Node * next ;

    public :
        Node ( int data = 0) {
        int data = 0;
        this -> next = NULL ;
        }
    }
};
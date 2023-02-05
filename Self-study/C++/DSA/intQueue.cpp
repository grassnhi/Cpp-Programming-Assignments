class IntQueue {
private :
    IntSLinkedList * list ;

public :
    IntQueue () {
        this -> list = new IntSLinkedList ();
    }

    ~ IntQueue () {
        this -> list - > clear ();
        delete list ;
    }

    void enqueue ( int element ) {
        // this - > list - > add (0 , element );
        this -> list - > add ( element );
    }

    int dequeue () {
        // int size = this - > list - > size ();
        // return this - > list - > removeAt ( size - 1);
        return this -> list -> removeAt (0);
    }

    int front () {
        // int size = this - > list - > size ();
        // return this - > list - > get ( size - 1);
        return this -> list -> get (0);
    }

    int rear () {
        // return this - > list - > get (0);
        int size = this -> list -> size ();
        return this -> list -> get ( size - 1);
    }

    bool empty () {
        return this -> list -> empty ();
    }

    bool contains ( int element ) {
        return this -> list -> contains ( element );
    }
};
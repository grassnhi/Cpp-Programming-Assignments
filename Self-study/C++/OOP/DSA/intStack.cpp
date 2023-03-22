class IntStack {
private :
    IntSLinkedList * list ;

public :
    IntStack () {
        this -> list = new IntSLinkedList ();
    }

    ~ IntStack () {
        this -> list - > clear ();
        delete list ;
    }

    void push ( int element ) {
        // this - > list - > add (0 , element );
        this -> list - > add ( element );
    }

    int pop () {
        // return this - > list - > removeAt (0);
        int size = this -> list -> size ();
        return this -> list -> removeAt ( size - 1);
    }

    int peek () {
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
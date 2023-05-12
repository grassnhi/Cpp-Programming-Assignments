template <class T >
class IList
{
public :
    virtual void add (T e) = 0;
    virtual void add ( int index , T e) = 0;
    virtual T removeAt (int index ) = 0;
    virtual bool removeItem (T item ) = 0;
    virtual bool empty () = 0;
    virtual int size () = 0;
    virtual void clear () = 0;
    virtual T get (int index ) = 0;
    virtual void set ( int index , T e) = 0;
    virtual int indexOf (T item ) = 0;
    virtual bool contains ( T item ) = 0;
    virtual string toString () = 0;
};

class IntArrayList : public IList <int > {
protected :
    int * data ;
    int capacity ;
    int count ;
public :
    IntArrayList ();
    virtual ~ IntArrayList ();
    virtual void add ( int element );
    virtual void add ( int index , int element );
    virtual int removeAt ( int index );
    virtual bool removeItem ( int item );
    virtual bool empty ();
    virtual int size ();
    virtual void clear ();
    virtual int get ( int index );
    virtual void set ( int index , int element );
    virtual int indexOf ( int item );
    virtual bool contains ( int item );
    virtual string toString ();
    virtual void dump ();

private :
    void checkIndex (int index );
    void ensureCapacity ( int capacity );
};

IntArrayList :: IntArrayList (){
    this -> capacity = 10;
    this -> data = new int[this -> capacity ];
    this -> count = 0;
}

IntArrayList ::~ IntArrayList (){
    delete [] this -> data ;
}

void IntArrayList :: add ( int element ){
    this -> ensureCapacity (this -> count + 1);
    this -> data [this - > count ] = element ;
    this -> count ++;
}

void IntArrayList :: add ( int index , int element ){
    this -> checkIndex ( index );
    this -> ensureCapacity (this -> count + 1);

    int moveCount = this -> count - index ;
    if ( moveCount > 0)
        memmove (this -> data + index + 1, this -> data + index ,moveCount * sizeof ( int ));

    this -> data [ index ] = element ;
    this -> count ++;
}

int IntArrayList :: removeAt ( int index ){
    this -> checkIndex ( index );
    int elementToRemove = this -> data [ index ];

    int moveCount = this -> count - index - 1;
    if ( moveCount > 0)
        memmove (this -> data + index, this -> data + index + 1, sizeof ( int ) * moveCount );

    this -> count - -;
    return elementToRemove ;
}

bool IntArrayList :: removeItem (int element ){
    for(int index = 0; index < this - > count ; index ++){
        if(this - > data [ index ] == element ) {
            this -> removeAt ( index );
            return true ;
        }
    }
    return false ;
}

bool IntArrayList :: empty (){
    return this -> count == 0;
}

int IntArrayList :: size (){
    return this -> count ;
}

void IntArrayList :: clear (){
    delete [] this -> data ;

    this -> capacity = 10;
    this -> data = new int[this -> capacity ];
    this -> count = 0;
}

int IntArrayList :: get( int index ){
    this -> checkIndex ( index );

    return this -> data [ index ];
}

void IntArrayList :: set( int index , int element ){
    this -> checkIndex ( index );

    this -> data [ index ] = element ;
}

int IntArrayList :: indexOf ( int element ) {
    for (int index = 0; index < this - > count ; index ++)
        if (this - > data [ index ] == element )
            return index ;
    return -1;
}

bool IntArrayList :: contains ( int element ) {
    return this -> indexOf ( element ) != -1;
}

string IntArrayList :: toString (){
    stringstream ss ;
    ss << "[";
    for (int index = 0; index < count - 1; index ++)
    ss << data [ index ] << ", ";

    if ( count > 0) ss << data [ count - 1] << "]";
    else ss << "]";

    return ss . str ();
}

void IntArrayList :: dump () {
    string line (50 , ’=’);
    cout << line << endl ;
    cout << " Integer list ’s information :" << endl ;
    cout << "- Capacity : " << this -> capacity << endl ;
    cout << "- Size : " << this -> count << endl ;
    cout << "- Data : " << this -> toString () << endl ;
    cout << line << endl ;
}

void IntArrayList :: checkIndex (int index ){
    if ( index < 0 || index >= this -> count )
        throw std :: out_of_range (" Index is out of range ");
}

void IntArrayList :: ensureCapacity ( int capacity ){
    if ( capacity > this -> capacity ) {
        int newCapacity = this -> capacity * 3 / 2;
        int * newData = new int[ newCapacity ];
        memmove ( newData , this -> data, this -> count * sizeof ( int ));
        this -> capacity = newCapacity ;
        delete [] this -> data ;

        this -> data = newData ;
    }
}
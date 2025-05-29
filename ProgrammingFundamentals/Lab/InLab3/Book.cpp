/*
Cho class như sau:

class Book {
public:
    Book(const char*);
    ~Book();
    void display();
private:
    char* name;
};
Hiện thực constructor và destructor của Book sao cho chương trình sau không bị lỗi khi chạy:
Book * pBook = new Book("To Kill a Mockingbird");
pBook->display();
delete pBook;
Kết quả in ra:
Book: To Kill a Mockingbird

[English]

Given the class definition:
class Book {
public:
     Book(const char*);
     ~Book();
     void display();
private:
     char* name;
};
Implement Book's constructor and destructor so that the following program does not crash at runtime:

Book * pBook = new Book("To Kill a Mockingbird");
pBook->display();
delete pBook;
Output:
Book: To Kill a Mockingbird


For example:

Test	Input	Result
1
To Kill a Mockingbird
Book: To Kill a Mockingbird
Deleted

*/

// string.h is included

class Book {
    char* name;
public:
    Book(const char*);
    ~Book();
    
    void display();
    char* getName();
};

void Book::display() {
    cout << "Book: " << this->name << endl;
}

char* Book::getName() {
    return this->name;
}


// TODO: Book and ~Book
Book::Book(const char* bk){
    name = new char[strlen(bk) + 1];
    for(int i = 0; i < strlen(bk); i++){
        name[i] = bk[i];
    }
    name[strlen(bk) + 1] = '\0';
}

Book::~Book(){
    delete[] name;
}
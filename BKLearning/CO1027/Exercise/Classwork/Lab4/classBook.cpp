/*
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
*/

// string.h is included

#include<iostream>

using namespace std;

class Book {
    char* name;
public:
    Book( char* name){
        this->name = name;
        int len = 0;
        while(name[len] != '\0') len++;
        char * newName = new char[len+1];
        for(int i = 0; i < len; i++){
            newName[i] = name[i];
            newName[len] = '\0';
            this->name = newName;
        }
        
    }
    ~Book(){
        delete name;
    }
    
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

int main(){
    Book * pBook = new Book("To Kill a Mockingbird");
    pBook->display();
    delete pBook;
}
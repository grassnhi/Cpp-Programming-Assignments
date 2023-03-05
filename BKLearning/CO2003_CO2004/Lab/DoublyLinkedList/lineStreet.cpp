/*
Assume that you build a toy called  line-street. You have to impletement 
some functions followed by some rules:
void LineStreet(string homepage): make a root for a line
void addNewElement(string ele): add new element in line, and clear up 
all forward elements
void back(int steps): you have to back to element behind with steps. 
If you can only back to n while n < steps. You should back to n steps.
void forward(int steps): you have to forward to element behind with steps. 
If you can only forward to n while n < steps. You should 
forward n steps.
Simple Example:
LineStreet* line = new LineStreet("home");
line->addNewElement("Bob");
line->addNewElement("Smith");
line->addNewElement("Ann");
line->back(1);                                 -->   return "Smith"
line->back(1);                                 -->   return "Bob"
line->forward(1);                              -->   return "Smith"
line->addNewElement("Peter");
line->forward(2);                              -->   return "Peter"
line->back(1);                                 -->   return "Smith"
Constraints: 1 <= steps <= 100
1<= len(homepage), len(ele) <= 20

Note: In this exercise, libraries iostream, string and using namespace std; 
have been used. You can add other 
functions for your answer, but you are not allowed to add other libraries.
*/

#include <iostream>
#include <string>

using namespace std;

class LineStreet {
public:
    LineStreet(string homepage) {
        current = new Node(homepage);
    }
    
    void addNewElement(string ele) {
        Node* new_node = new Node(ele);
        current->next = new_node;
        new_node->prev = current;
        current = new_node;
        
        // Clear all forward elements
        Node* next_node = current->next;
        while (next_node != nullptr) {
            Node* to_delete = next_node;
            next_node = next_node->next;
            delete to_delete;
        }
        current->next = nullptr;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (current->prev == nullptr) {
                break;
            }
            current = current->prev;
        }
        return current->val;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (current->next == nullptr) {
                break;
            }
            current = current->next;
        }
        return current->val;
    }
    
private:
    class Node {
    public:
        string val;
        Node* prev;
        Node* next;
        
        Node(string val) {
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };
    
    Node* current;
};

/*
Test	Result
LineStreet* obj = new LineStreet("home");
obj->addNewElement("Bob");
obj->addNewElement("Smith");
obj->addNewElement("Ann");
cout << obj->back(1) << endl;
cout << obj->back(1) << endl;
cout << obj->forward(1) << endl;
obj->addNewElement("Peter");
cout << obj->forward(2) << endl;
cout << obj->back(1) << endl;
Smith
Bob
Smith
Peter 
Smith

*/
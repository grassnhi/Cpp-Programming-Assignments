/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private: // đối tượng thuộc lớp 
    int x;
    int y;
public:
    // default constructor
    Point(int x=0, int y=0){ // nếu không truyền x or y thì x = 0 or y = 0
        //this là con trỏ chứa địa chỉ của đối tượng hiện tại, đối tượng đang được gọi
        this->x = x; //thuộc tính của đối tượng hiện tại: object = 
        this->y = y; // gán tọa độ ox, oy là vị trí của các nhân vật trong quá trình di chuyển vào object của lớp
    }

    // phương thức hằng
    string toString() const{ // kiểu trả về là string
        // x, y được gán vào là kiểu int nên phải chuyển sang string để trả về kiểu string
        return ("<Point[" + to_string(x) + "," + to_string(y) + "]>"); 
    }

    // phương thức hằng
    int distanceTo(const Point & otherPoint) const{ // truyền tham chiếu tọa độ otherPoint thuộc kiểu Point là const
        return ceil(sqrt((otherPoint.x - x)*(otherPoint.x - x) + (otherPoint.y - y)*(otherPoint.y - y)));
        //
        // trả về khoảng cách từ đối tượng hiện tại đến đối tượng otherPoint theo công thức
        // ceil dùng để làm tròn lên
    }

    // destructor được gọi tự động dù không được định nghĩa
};

class Node { // tạo linked list
private:
    Point point; // thuộc tính point thuộc kiểu Point chứa nội dung phần tử
    Node * next; // con trở tham khảo đển Node kế tiếp  

    friend class Path; // class Path là lớp bạn của lớp Node 
    //-> các đối tượng (object) của Path có thể truy xuất các thành phần private và protected của Node
    // tính đóng gói (encapsulated)

public:
    // default constructor
    Node(const Point & point=Point(), Node * next=NULL){ // truyền tham chiếu tọa độ point thuộc kiểu point
        this->point = point; // gán tọa độ điểm vào thuộc tính point của đối tượng khởi tạo có kiểu dữ liệu Point
        this->next = next; // gán con trỏ trỏ đến phần tử kế tiếp vào thuộc tính next
    }

    // phương thức hằng
    string toString() const{ // kiểu trả về là string
        return ("<Node[" + point.toString() + "]>"); // gọi phương thức toString của class Point, point thuộc kiểu Point
        // tương tự .. + "<Point[" + to_string(point.x) + "," + to_string(point.y) + "]>") + ..
    }

    // destructor được gọi tự động dù không được định nghĩa
};

class Path { // tạo linked list
private:
    // vì class Path là lớp bạn của lớp Node 
    //-> các đối tượng (object) của Path có thể truy xuất các thành phần private Node
    Node * head; // con trỏ chứa địa chỉ của Node đầu tiền trong Path và có kiểu Node
    Node * tail; // con trỏ chứa địa chỉ của Node cuối cùng trong Path
    int count; // thuộc tính lưu trữ số lượng Node trong Path
    int length; // thuốc tính lưu chiều dài Path

public:
    Path(){
        // Khi mới tạo, Path chưa có Node nào nên head = tail = null, count = 0 và length = -1
        head = NULL; 
        tail = NULL;
        this->count = 0; 
        this->length = -1; 
    }
    ~Path(){ // hàm hủy được gọi tự động chỉ xóa các đối tượng được tạo nên chỉ xóa head và tail và không xóa hết các Node
    // Để xóa hết các Node, ta cho delNode = head rồi xóa delNode, head sẽ là head->next như vậy ta vẫn được giữ là Node có vị trí đầu tiên
    // Next là vùng chứa con trỏ chỉ đến node kế tiếp =) head-> next chỉ đến node kế tiếp
    // head = head->next =) head trỏ đến node kế tiếp
    //Node hiện tại là delNode đã bị xóa nên head chỉ đến Node đầu tiên
    //Vòng lặp while chạy cho đến khi head = null tức là không còn node nào nữa thì dừng
        while(head!=NULL){
            Node *delNode = head;
            
            delete delNode;
            head = head->next;
        }
    }

    void addPoint(int x, int y){
        Node* newPoint = new Node(); //tạo node mới có kiểu Node, một vùng chứa point một vùng chứa next
        newPoint->point = Point(x, y); // goin hàm tạo point và gán tọa độ x, y vào vùng chứa thuộc tính point
        newPoint->next = NULL; // con trỏ next của newPoint trỏ đến null
        if(head == NULL){ // khi 1 điểm được tạo = 1 node
            head = tail = newPoint;
            length = 0;
            count = 1;
        }else{
            // Node* temp = head;
            // while(temp != NULL){
            //     if(temp->next == NULL){
            //         temp->next = newPoint;
            //         tail = newPoint;
            //         break;
            //     }
            //     temp = temp->next;
                          
            // }
            
            length += (tail->point).distanceTo(newPoint->point);
            tail->next = newPoint;
            tail = tail->next;
            count++;
            // count++;
            // length += tail->point.distanceTo(temp->point);  
        }
    
    }

    int getLength(){
        return length;
    }

    string toString() const{
        string result = "<Path[count:" + to_string(count) + ",length:" + to_string(length) + ",[";
        Node* p = head;
        while(p != NULL){
            result += p->toString();
            p = p->next;
            if(p != NULL){
                result += ",";
            }
        
        }
        result += "]]>";
        return result;
    }
    Point getLastPoint() const{
        return tail->point;
    }
};


class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name=""){
        this->name = name;
        path = new Path();
    }
    ~Character(){
        delete path;
    }

    string getName() const{
        return this->name;
    }
    void setName(const string & name){
        this->name = name;
    }

    void moveToPoint(int x, int y){
        path->addPoint(x, y);
    }
    string toString() const{
        return ("<Character[name:" + getName() + ",path:" + path->toString() + "]>");
    }
    int getLength() const{
        return path->getLength();
    }
    Point getCurrentPosition() const{
        return path->getLastPoint();
    }
};

bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {

            if(chWatson.getLength() - chMurderer.getLength() <= maxLength){
                outDistance = chWatson.getCurrentPosition().distanceTo(chMurderer.getCurrentPosition());
                if(outDistance <= maxDistance){
                    return true;
                }else{
                    return false;
                }
            }else{
                outDistance = -1;
                return false;
            }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
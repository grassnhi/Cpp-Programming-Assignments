/*
Hãy thiết kế một class Room với constructor gồm 3 biến length, breadth, height (theo thứ tự). Hiện thực các phương thức sau cho class Room:

Constructor: đầu vào lần lượt là length, breadth, height
calculateArea: tính diện tích của căn phòng.
calculateVolume: tính thể tích của căn phòng
Define class Room with three variable length, breadth and height and:
_ A constructor with three input for length, breadth and height.
_ Function calculateArea to calculate and return the room area.
_ Function calculateVolume to calculate and return the room volume.

For example:

Test	Result
cout<<"Constructor test";
Room r(20,3,4);
Room *r2=new Room(10.5,5.5,5.4);
delete r2;
Constructor test

*/

class Room{
    private:
        double length;
        double breadth;
        double height;
        
    public:
        Room(double length, double breadth, double height){
            this->length = length;
            this->breadth = breadth;
            this->height = height;
        }
        
        double calculateArea(){
            return length * breadth;
        }
        
        double calculateVolume(){
            return length * breadth * height;
        }
};
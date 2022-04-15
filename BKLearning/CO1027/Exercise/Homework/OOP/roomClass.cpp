/*
Define class Room with three variable length, breadth and height and:
_ A constructor with three input for length, breadth and height.
_ Function calculateArea to calculate and return the room area.
_ Function calculateVolume to calculate and return the room volume.
*/

#include <iostream>

using namespace std;

class Room
{
    private:
        float length;
        float breadth;
        float height;
    public:
        Room(float length, float breadth, float height){
            this->length = length;
            this->breadth = breadth;
            this->height = height;
            
        }
        
        float calculateArea(){
            this->length = length;
            this->breadth = breadth;
            return length*breadth;
        }
        
        float calculateVolume(){
            this->length = length;
            this->breadth = breadth;
            this->height = height;
            return length*breadth*height;
        }
         
};

int main(){
    cout<<"Constructor test";
    Room r(20,3,4);
    Room *r2=new Room(10.5,5.5,5.4);
    delete r2;
}
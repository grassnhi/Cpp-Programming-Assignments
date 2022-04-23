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
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0){
        this->x = x;
        this->y = y;
    }

    string toString() const{
        return ("<Point[" + to_string(x) + "," + to_string(y) + "]>");
    }

    int distanceTo(const Point & otherPoint) const{
        return ceil(sqrt((otherPoint.x - x)*(otherPoint.x - x) + (otherPoint.y - y)*(otherPoint.y - y)));
    }
};

class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point & point=Point(), Node * next=NULL){
        this->point = point;
        this->next = next;
    }
    string toString() const{
        return ("<Node[" + point.toString() + "]>");
    }
};

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path(){
        head = NULL;
        tail = NULL;
        this->count = 0;
        this->length = -1; 
    }
    ~Path(){
        while(head!=NULL){
            Node *delNode = head;
            head = head->next;
            delete delNode;
        }
    }

    void addPoint(int x, int y){
        Node* newPoint = new Node();
        newPoint->point = Point(x, y);
        newPoint->next = NULL;
        if(head == NULL){
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
            count++;
            tail = tail->next;
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
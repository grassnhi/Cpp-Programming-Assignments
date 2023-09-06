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
        return ("<Point[" + to_string(this->x) + "," + to_string(this->y) + "]>");
    }

    int distanceTo(const Point & otherPoint) const{
        return (ceil(sqrt(pow(otherPoint.x - this->x, 2) + pow(otherPoint.y - this->y, 2))));
    }
};

class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point & point=Point(), Node * next=NULL){
        this->point = Point(x, y);
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
        head = tail = NULL;
        int count = 0;
        int length = -1;
    }
    ~Path(){
        Node* curr = head;
        while(curr != NULL){
            head = head->next;
            delete curr;
            curr = head;
        }
        head = tail = NULL;
    }

    void addPoint(int x, int y){
        Point point = Point(x, y);
        Node *newPoint = new Node(point);
        if(head = NULL){
            head = tail = newPoint;
            this->count = 1;
            this->length = 0;
        }else{
            this->length += (tail->point).distanceTo(newPoint->point);
            tail->next = newPoint;
            tail = tail->next;
            this->count++;
        }
    }
    string toString() const{
        string result = "<Path[count:" + to_string(count) + ",length:" + to_string(length) + ",[";
        if(head == NULL){
            result += "]]>";
        }else{
            Node *point = head;
            while (point != NULL)
            {
                result += point->toString();
                point = point->next;
                if(point != NULL){
                    result += ",";
                }
            }
            result += "]]>";
            
        }
        return result;
    }
    Point getLastPoint() const{
        return tail->point;
    }

    int getLength(){
        return length;
    }
};

class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name=""){
        this->name = name;
        this->path = new Path();
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
        return "<Character[name:" + getName() + ",path:" + path->toString() + "]>";
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
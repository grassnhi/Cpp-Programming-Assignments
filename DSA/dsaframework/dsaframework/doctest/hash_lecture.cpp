#include <iostream>
#include <iomanip>
#include <string>

#include "tree/AVL.h"
using namespace std;


struct Country{
    string name;
    string captical;
    Country(string name, string capital){
        ///
    }
};
void demo1(){
    string countries[] = {"Vietnam",  "Thailand",  "Lao",        "China"}; //many
    string capital[]   = {"Hanoi",    "Bangkok",   "Vientaine",  "Bejing"}; //many

    //assume N countries added
    
    string key = "a country name here"; //get its capital
    //Time Complexity: O(N)
    
}

void demo2(){
    Country countries[] = {
        Country("Vietnam", "Hanoi"),
        Country("Thailand", "Bangkok"),
        Country("Lao", "Vientaine"),
        Country("China", "Bejing")
    };
    //assume N countries added
    
    string key = "a country name here"; //get its capital
    
    //Time Complexity: O(N)
}

void demo3(){
    AVL<string, string> countries;
    countries.add("Vietnam", "Hanoi");
    countries.add("Thailand", "Bangkok");
    countries.add("Lao", "Vientaine");
    countries.add("China", "Bejing");
    //assume N countries added
    
    string key = "a country name here"; //get its capital
    //Time Complexity:  O(logN)
}


void demo4(){
    DLinkedList<Country> countries; //May XArrayList, SLinkedList
    countries.add(Country("Vietnam", "Hanoi"));
    countries.add(Country("Thailand", "Bangkok"));
    countries.add(Country("Lao", "Vientaine"));
    countries.add(Country("China", "Bejing"));
    //assume N countries added
    
    string key = "a country name here"; //get its capital
    //Time Complexity: O(N)
    
}

void demo5(){
    XArrayList<Country> countries; //May XArrayList, SLinkedList
    countries.add(Country("Vietnam", "Hanoi"));
    countries.add(Country("Thailand", "Bangkok"));
    countries.add(Country("Lao", "Vientaine"));
    countries.add(Country("China", "Bejing"));
    //assume N countries added
    
    //Something done here
    ///
    
    string key = "a country name here"; //get its capital
    //Time Complexity: O(logN)
    
}


//Do we have any data structure be able to provide constant time for the above problem????
/*
 YES: That is HashMap
 * 
 
 */
/*
 y = 4
 y = 4*x + 4
 y = 4*x^2
 */
/**
 O(c) < O(logn) < O(n)
 */
int main(int argc, char** argv){
    
}

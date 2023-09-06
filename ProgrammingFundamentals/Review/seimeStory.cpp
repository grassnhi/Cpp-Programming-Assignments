#include<iostream>
#include <cstring>
#include <vector>

using namespace std;

class Demon
{
private:
    char name[30];
    int hp;
    int x; int y;

    friend class Place;
public:
    Demon(){

    }

    Demon(char name[30], int x, int y){
        this->name = name;
        this->x = x;
        this->y = y;
    }

    ~Demon(){

    }

    char* getName(){
        return this->name;
    }
};

class Human
{
private:
    char name[30];
    int x; int y;

    friend class Place;
public:
    Human(){}
    Human(int x, int y){
        this->x = x;
        this->y = y;
    }
    ~Human(){}

    virtual colide(char* demon){
        this->met.push_back(demon);
    }

    char* getName(){
        this->name = name;
    }
};

class Wizard: public Human
{
private:
    vector<string> exorcist;
    
    friend class Place;
public:
    Wizard(){
        this->getName = "Abe no Seimei";
    }
    ~Wizard(){

    }

    virtual colide(char* finished){}
};

class Scout
{
private:
    vector<string> met;
    int score;

    friend class Place;
public:
    Scout(int score){
        this->score = score;
    }
    ~Scout(){}

    void colide(char* demon){
        this->met.push_back(demon);
        this->score--;
    }
};

class Place
{
private:
    int m; int n;
    int map[m][n];

    Wizard wizard;
    
    int nScout;
	Scout scouts;
	
    int nDemon;
	Demon demons;
public:
    Place(int m, int n, Wizard wizard, int nScout, int nDemon){
        this->m = m;
        this->n = n;
        int **map = new int*[m];
        for(int i = 0; i < m; i++){
            this->map[i] = new int[n];
        }
        this->wizard = wizard;
        this->nScout = nScout;
        this->nDemon = nDemon;
        this->scouts = new Scout[nScout];
        this->demons = new Demon[nDemon];
    }

    void turn(int** direction, int nD){}
    ~Place(){}
};


int main(){

}
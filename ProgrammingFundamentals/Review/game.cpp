#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class Tower;
class Monster;

class GameManager{
public:
    vector<Tower*> towerSet;
    vector<Monster*> monsterSet;
    GameManager(){};
    Tower* createTower(string type, int id, int x, int y);
    Monster* createMonster(string type, int id, int x, int y);
};

class Monster{
    // TODO
private:
    int x;
    int y;
    int id;
    int hp;

public:
    void setPosition(int x, int y){
        this->x = x;
        this->y = y;
    }
    void move(string direction){
        
    }

};

class Tower{
    // TODO
private:
    int x;
    int y;
    int id;
    Monster monster;

public:
    void setPosition(int x, int y){
        this->x = x;
        this->y = y;
    }

    int distanceToTarget(){}
    int getTarget(Monster monster){
        int targetId = 0;
        while (monster.monsterSet)
        return 
    }
    void attack(){}
}

//class, functions, ... if needed
Tower* GameManager:: createTower(string type, int id, int x, int y){
    // TODO
}

Monster* GameManager:: createMonster(string type, int id, int x, int y){
    // TODO
}


int main(){
    GameManager* Instance = new GameManager();
    Tower *tower1 = gameInstance->createTower("tower_1", 1, 0, 0);
    cout << "tower 1 position: " << tower1->x << " " << tower1->y << endl;
    tower1->setPosition(0, 10);
    cout << "tower 1 position: " << tower1->x << " " << tower1->y << endl;
    Monster *monster1 = gameInstance->createMonster("monster_1", 2, 15, 25);
    cout << "monster1 position: " << monster1->x << " " << monster1->y << endl;
}
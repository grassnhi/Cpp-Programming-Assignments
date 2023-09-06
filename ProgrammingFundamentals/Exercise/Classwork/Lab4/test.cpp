#include<iostream>
using namespace std;
enum Weapon {Sword, Bow, Spear, ShieldSword, HeavyAxe, Dagger};
class gladiator{
    Weapon weapon;
    double power;
    double learningRate;
    public:
    gladiator(){};
    gladiator(Weapon x, double a, double b){
        this->weapon = x;
        this->power = a;
        this->learningRate = b;
        
    }
    void winAgainst(gladiator b){
        this->learningRate *= b.learningRate;
    }
    double getPow(){
        return this->power;
    }
    Weapon getWeapon(){
        return this->weapon;
    }
};
class colosseum{
    int count;
    gladiator* Glads;
    public:
    colosseum(){
        count = 0;
        Glads=new gladiator[100];
    }
    double getPow (){
        return Glads->getPow;
    }
    ~colosseum(){
        delete []Glads;
    }
    void addGlad(gladiator a){
        Glads[count] = a;
        this->count++;
    }
    void addGlad(gladiator *a,int n){
        for (int i=0;i<n;i++){
            Glads[count+i] = a[i];
        }
        count+=n;
    }
    void startFight(int pos1, int pos2){
        cout<<"To day fight is between \n ";
        cout << "the Gla "<< pos1<< "a "<< Glads[pos1].getWeapon<<" user with the power of "<<Glads[pos1].getPow<<
        "and the Gla "<< pos2<< " a " << Glads[pos2].getWeapon<< " user with the power of "<<Glads[pos2].getPow;
        if (Glads[pos1].getPow == Glads[pos2].getPow)
        cout << pos1<<  " won";
        }
};

int main (){
    colosseum Roma;
    Roma.addGlad(gladiator(Sword,40,0.1));
    Roma.addGlad(gladiator(Bow,40,0.1));
    Roma.startFight(0,1); 
}

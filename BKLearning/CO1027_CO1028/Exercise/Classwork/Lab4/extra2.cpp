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
        // int count;
        Glads=new gladiator[100];
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
        
    }
};



colosseum Roma;
Roma.addGlad(gladiator(Sword,50,0.1));
Roma.addGlad(gladiator(Bow,40,0.1));
Roma.startFight(0,1);  
colosseum Roma;
gladiator group[]={gladiator(Sword,41,0.1),gladiator(Spear,40,0.1)};
Roma.addGlad(group,2);
Roma.startFight(0,1);
Roma.addGlad(gladiator(HeavyAxe,45,0.2)); 
Roma.startFight(0,1);

enum Weapon {Sword, Bow, Spear, ShieldSword, HeavyAxe, Dagger};
class gladiator{
    Weapon weapon;
    double power;
    double learningRate;
    public:
    gladiator(){};
    gladiator(Weapon, double, double);
    void winAgainst(gladiator b);
    double getPow();
    Weapon getWeapon();
}
class colosseum{
    int count;
    gladiator* Glads;
    public:
    colosseum(){
        count=0;
        Glads=new gladiator[100];
    }
    ~colosseum(){
        delete []Glads;
    }
    void addGlad(gladiator a);
    void addGlad(gladiator *a,int n);
    void startFight(int , int );
}

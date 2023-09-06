#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class demon {
protected:
	char* name = new char[30];
	double hp;
	int x, y;
	friend class place;
public:
	demon();
	demon(char* name, double hp, int x, int y) {
		this->name = name;
		this->hp = hp;
		this->x = x;
		this->y = y;
	}

	char* temp() {
		return name;
	}

	~demon(){};
};

class human {
protected:
	char* name = new char[30];
	double hp;
	int x, y;
	friend class place;
public:
	human();
	human(char* name, double hp, int x, int y) {
		this->name = name;
		this->hp = hp;
		this->x = x;
		this->y = y;
	}

	virtual void colide(char* temp) {};

	~human(){};
};

class wizard: public human{
private:
	vector<string> exo;
	friend class place;
public:
	wizard() {
		this->name = (char*)"Abe no Seimei";
	}

	void colide(char* temp) {
		exo.push_back(temp);
	}

	~wizard(){};
};

class scout: public human {
private:
	vector<string> met;
	int mentalscore;
	friend class place;
public:
	scout();

	scout(int mental) {
		this->mentalscore = mental;
	}

	void colide(char* temp) {
		met.push_back(temp);
		mentalscore--;
	}

	~scout(){};
};

class place{
private:
	int n;
	int m;
	int** arr;
	wizard wiz;
	int numsc;
	
	scout* sc;
	int numsd;
	demon* de;

public:
	place(int m, int n, wizard wiz, int numscout, int numdemon) {
		this->m = m;
		this->n = n;
		this->arr = new int* [m];
		for (int i = 0; i < m; i++) arr[i] = new int[n];
		this->wiz = wiz;
		this->numsc = numscout;
		this->numsd = numdemon;
		this->sc = new scout[numscout];
		this->de = new demon[numdemon];
	}

	void turn(int** direction, int nD);
};

void place::turn(int** direction, int nD) {
	human* ptr = nullptr;
	
	for (int i = 0; i < nD; i++) {
		if ()
	}
}
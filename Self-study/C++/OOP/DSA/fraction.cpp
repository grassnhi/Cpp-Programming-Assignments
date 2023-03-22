#include<iostream>

using namespace std;

template <class T>
class Fraction{
private: 
    T num;
public:
    Fraction(T num){
        this->num = num;
    }

    Fraction operator +(const Fraction x){
        Fraction result(this->num + x.num);
        return result;
    }

    Fraction operator -(const Fraction x){
        Fraction result(this->num - x.num);
        return result;     
    }

    Fraction operator *(const Fraction x){
        Fraction result(this->num * x.num);
        return result;
    }
    Fraction operator /(const Fraction x){
        Fraction result(this->num / x.num);
        return result;
    }

    friend ostream& operator<<(ostream& out, Fraction x){
        out << x.num << endl;
        return out;
    }

    friend istream& operator >> (istream& in, Fraction& x){
        in >> x.num;
        return in;   
    }

    void Display(){
        cout << this->num << endl;
    }
};

int main(){
    Fraction<int> a(10); a.Display();
    Fraction<int> b(2); b.Display();

    Fraction<int> c = a + b; c.Display();
    Fraction<int> d = a - b; d.Display();
    Fraction<int> e = a*b; e.Display();
    Fraction<int> f = a/b; f.Display();

    cout << endl;
    
    cout << a;
    cin >> b; 
    cout << b;

    return 0;
}
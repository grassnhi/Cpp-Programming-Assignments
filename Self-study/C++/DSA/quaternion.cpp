#include<iostream>

using namespace std;

class Quaternion{
private:
    int a, b, c, d;
    
public:
    Quaternion(int a, int b, int c, int d){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    Quaternion operator +(const Quaternion x){
        Quaternion result(this->a + x.a, this->b + x.b, this->c + x.c, this->d + x.d);
        return result;
    }

    Quaternion operator -(const Quaternion x){
        Quaternion result(this->a - x.a, this->b - x.b, this->c - x.c, this->d - x.d);
        return result;     
    }

    Quaternion operator *(const Quaternion x){
        Quaternion result(this->a * x.a - this->b * x.b - this->c * x.c - this->d * x.d, 
                        this->a * x.b + this->b * x.a + this->c * x.d + this->d * x.c,
                        this->a * x.c + this->c * x.a + this->d * x.b - this->b * x.d, 
                        this->a * x.d + this->d * x.a + this-> b * x.c - this->c * x.b);
        return result;
    }
    Quaternion operator /(const Quaternion x){
        Quaternion result(this->a / x.a, this->b / x.b, this->c / x.c, this->d / x.d);
        return result;
    }

    friend ostream& operator<<(ostream& out, Quaternion x){
        out << x.a << " + " << x.b << "i + " << x.c << "j + " << x.d << "k" << endl;
        return out;
    }

    friend istream& operator >> (istream& in, Quaternion& x){
        in >> x.a >> x.b >> x.c >> x.d;
        return in;   
    }

    void operator = (const Quaternion& x){
        this->a = x.a;
        this->b = x.b;
        this->c = x.c;
        this->d = x.d;
    }
};

int main(){
    Quaternion a(10, 2, 1, 5); cout << a;
    Quaternion b(2, 6, 7, 1); cout << b;

    Quaternion c = a + b; cout << c;
    Quaternion d = a - b; cout << d;
    Quaternion e = a*b; cout << e;
    Quaternion f = a/b; cout << f;

    //cin >> c; cout << c;

    Quaternion u = a; cout << u;

    return 0;
}
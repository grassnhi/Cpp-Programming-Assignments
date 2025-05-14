#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream

using namespace std;

class Vector {
    // allow user to access
public:
    static double epsilon;
    
    friend Vector operator+(double lhs, const Vector& obj);
    
    Vector(int ndims = 1, double value = 0.0): ndims(ndims) {
        if (ndims <= 0) throw std::range_error("Number of dimension is illegal!");
        data = new double[ndims];
        for (int i = 0; i < ndims; i++) {
            data[i] = value;
        }
    }

    Vector (double* arr, int size) {
        ndims = size;
        data = new double[size];
        memcpy(data, arr, size * sizeof(double));
    }

    Vector (const Vector& obj) {    
        cout << "Copy constructor" << endl;
        this->ndims = obj.ndims;
        this->data = new double[ndims];
        memcpy(data, obj.data, obj.ndims * sizeof(double));
    }

    Vector& operator=(const Vector& obj){
        cout << "???" << endl;
        if(this->data != nullptr){
            delete[] data;
        }
        this->ndims = obj.ndims;
        this->data = new double[ndims];
        memcpy(data, obj.data, obj.ndims * sizeof(double));

        return *this;
    }

    Vector operator+(double rhs){
        Vector result(*this);
        for(int idx = 0; idx < result.ndims; idx++){
            result.data[idx] += rhs;
        }
        return result;
    }

    ~Vector() {
        delete[] data;
    }

    void display() {
        stringstream os;
        os << "[";
        for (int i = 0; i < ndims; i++) {
            os << setw(6) << setprecision(2) << left << data[i] << ",";
        }
        string s = os.str();
        s = s.substr(0, s.rfind(","));
        cout << s << "]" << endl;
    }

    static double dot(const Vector& a, const Vector& b){
        if(a.ndims != b.ndims){
            throw "2 nums of dims must be the same";
        }
        double d = 0;
        for(int idx = 0; idx < a.ndims; idx++){
            d += a.data[idx] + b.data[idx];
        }
        return d;
    }

    double dot(const Vector& a){
        return 0.0;
    }

// allow subclass to inherit
protected:
    int ndims;
    double* data; // pointer => 100% have destructor

private:

};

double Vector::epsilon = 1e-7;

// By default, operator + must have lhs = vector, declare outside + friend for lhs other
Vector operator+(double lhs, const Vector& obj){
    Vector result(obj);
    for(int idx = 0; idx < result.ndims; idx++){
        result.data[idx] += lhs;
    }
    return result;
}

void demo_1(){
    Vector v;
    v.display();
    Vector a(5, 1.0);
    v.display();
}

void demo_2(){
    double array[] = {1.5, 3.0, 5.5, 4.5};
    int size = sizeof(array) / sizeof(double);
    Vector v(array, size);
    v.display();
}

void demo_3(){
    double array[] = {1.5, 3.0, 5.5, 4.5};
    int size = sizeof(array) / sizeof(double);
    Vector v(array, size);
    v.display();

    Vector a(v);
    a.display();

    Vector b;
    b = v;
    b.display();

    Vector c = v;
    c.display();
}

// Assignment operator
void demo_4(){
    double array[] = {1.5, 3.0, 5.5, 4.5};
    int size = sizeof(array) / sizeof(double);
    Vector v(array, size);
    v.display();

    Vector b = v + 5.0;
    b.display();

    Vector c = 5.0 + v;
    c.display();
}

void demo_5(){
    double array1[] = {1.5, 3.0, 5.5, 4.5};
    double array2[] = {0.5, 1.5, 2.5, 3.5};
    
    int size = sizeof(array1) / sizeof(double);
    
    Vector a(array1, size);
    Vector b(array2, size);

    a.display();
    b.display();

    double d = Vector::dot(a, b);
    cout << "dot(a,b): " << d << endl;

    double e = a.dot(b);
    cout << "a.dot(b): " << e << endl;

    cout << "epsilon: " << Vector::epsilon << endl;
}
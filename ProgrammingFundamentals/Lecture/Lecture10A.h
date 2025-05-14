#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;

class Vector {
    // allow user to access
public:
    friend Vector operator+ (double lhs, Vector& rhs);

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

    Vector(const Vector& obj) {
        this->ndims = obj.ndims;
        this->data = new double[ndims];
        memcpy(data, obj.data, obj.ndims * sizeof(double));
    }

    ~Vector() {
        delete[] data;
    }

    Vector& operator= (const Vector& obj) {
        this->ndims = obj.ndims;
        if (data) delete[] data;
        this->data = new double[obj.ndims];
        memcpy(data, obj.data, obj.ndims * sizeof(double));
        return *this;
    }

    Vector operator+ (double rhs) {
        Vector result(*this);
        for (int i = 0; i < result.ndims; i++) {
            data[i] += rhs;
        }
        return result;
    }

    void display() {
        stringstream os;
        os << "[";
        for (int i = 0; i < ndims; i++) {
            os << setw(6) << setprecision(2) << left << data[i] << ", ";
        }
        string s = os.str();
        s = s.substr(0, s.rfind(", "));
        cout << s << "]\n";
    }

    static double dot(const Vector& a, const Vector& b) {
        if (a.ndims != b.ndims) throw "Two dimensions must be the same!";
        double d = 0;
        for (int i = 0; i < a.ndims; i++) {
            d += a.data[i] * b.data[i];
        }
        return d;
    }

    double dot(const Vector& b) {
        if (this->ndims != b.ndims) throw "Two dimensions must be the same!";
        double d = 0;
        for (int i = 0; i < this->ndims; i++) {
            d += this->data[i] * b.data[i];
        }
        return d;
    }

    // allow subclass to inherit
protected:
    int ndims;
    double* data;
private:
};

Vector operator+ (double lhs, Vector& rhs) {
    Vector result(rhs);
    for (int i = 0; i < rhs.ndims; i++) {
        result.data[i] += lhs;
    }
    return result;
}

void demo_1() {
    Vector v;
    v.display();
}

void demo_2() {
    double arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(double);
    Vector v(arr, size);
    Vector a;
    a = v;
    v.display();
    a.display();
}

void demo_3() {
    double arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(double);
    Vector v(arr, size);
    Vector a = 5 + v;
    v.display();
    a.display();
}

void demo_4() {
    double arr1[] = {1, 2, 3, 4, 5};
    double arr2[] = {6, 7, 8, 9, 10};
    int size = sizeof(arr1) / sizeof(double);
    Vector a(arr1, size);
    Vector b(arr2, size);
    a.display();
    b.display();
    double d = Vector::dot(a, b);
    cout << d << endl;
}

void demo_5() {
    double arr1[] = {1, 2, 3, 4, 5};
    const Vector a(arr1, 3); // constant object can only call constant method
}
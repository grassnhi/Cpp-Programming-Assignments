#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;

class Vector {
    // allow user to access
public:
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
        cout << s << "]";
    }

    // allow subclass to inherit
protected:
    int ndims;
    double* data;
private:
};

void demo_1() {
    Vector v;
    v.display();
}
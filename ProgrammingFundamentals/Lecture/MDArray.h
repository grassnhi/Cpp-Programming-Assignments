#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;


#define MAX_NDIM 10

class MDArray{
    public:
        MDArray(){
            ndim = 1;
            size = 1;
            data = new int[size];
            shape[0] = 1;
        }

        ~MDArray(){
            if(data != nullptr){
                delete[] data;
            }
        }

        void removeInternalData() {
            if (this->data) {
                delete[] data;
            }
        }

        MDArray& arange(int size) {
            removeInternalData();

            this->data = new int[size];
            this->ndim = 1;
            this->size = size;
            this->shape[0] = size;

            for (int i = 0; i < size; i++) {
                this->data[i] = i;
            }
            return *this;
        }

        MDArray& reshape(int r, int c){
            // Check the validity of r, c and size
            // TODO

            this->ndim = 2;
            this->shape[0] = r;
            this->shape[1] = c;
            return *this;
        }

        string toString(){
            string rs;
            if(this->ndim == 1){
                stringstream os;
                for(int i=0; i < size; i++){
                    os << data[i] << ", "; 
                }

                rs = os.str();
                rs = rs.substr(0, rs.rfind(","));
                rs = "{" + rs + "}";
            }
            else if(this->ndim == 2){
                int nrows = this->shape[0];
                int ncols = this->shape[1];
                int idxID;
                stringstream os;
                for(int r = 0; r < nrows; r++){
                    stringstream row_os;
                    // idxID = r*ncols;
                    for(int c = 0; c < ncols; c++){
                        idxID = r*ncols + c;
                        row_os << data[idxID] << ", ";
                    }
                    string rowstr = row_os.str();
                    rowstr = rowstr.substr(0, rowstr.rfind(","));
                    rowstr = "[" + rowstr + "]";
                    os << rowstr << endl;
                }
                rs = string("{\n") + os.str() + "}";
            }
            return rs;
        }
    
    protected:

    private:
        int* data;
        int ndim;
        int size;
        int shape[MAX_NDIM];
};

void demo1(){
    MDArray array;
    cout << "Data: " << array.toString() << endl;
    array.arange(12);
    cout << "Data: " << array.toString() << endl;
    array.reshape(2, 6);
    cout << "Data:\n" << array.toString() << endl;
    array.reshape(4, 3);
    cout << "Data:\n" << array.toString() << endl;
}
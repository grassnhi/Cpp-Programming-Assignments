/*
Class Array2D will manage a matrix with m rows and n columns. Implement following requirements:
1. Implement the constructor with 2 parameters Array2D(int r, int c), allocating memory for a 2-dimensional array of size r x c.
2. Implement the constructor with 3 parameters Array2D(int r, int c, T init), initialize the each element of a 2-dimensional array of size r x c with the initial value init

3. Implement the destructor to deallocate dynamically allocated memory.

4. Overriding operator* performs matrix multiplication with another Array2D object (notice to the matrix multiplication condition). The method returns a pointer to an object of Array2D holding the result of multiplication. In case the matrix multiplication condition is not satisfied, the method will return NULL.

5. Overriding operator[] so that the following code can run. Assume that the data type T* has overridden the [] operator to return the value at the required position (for example, arr[i] will return the ith element of the array arr of data type T. In other words, students don't need to care about the [] operator of *arr)


int main() {
    Array2D<int>* p = new Array2D<int>(1, 2, 3);
    cout << (*p)[0][1] << endl;
    return 0;
}

*/

template <class T> 
class Array2D {
private:
	int r;
	int c;
	T** arr;

public:
    // TODO
    Array2D(int r, int c){
        T** arr = new T*[this->r];
        for(int i = 0; i < this->r; i++){
            T*arr = new T[c];
        }
    }
    
    Array2D(int r, int c, T init){
        T** arr = new T*[this->r];
        for(int i = 0; i < this->r; i++){
            T*arr = new T[c];
            for(int j = 0; j < this->c; j++){
                arr[i][j] = init;
            }
        }
    }
    ~Array2D(){
        for(int i = 0; i < this->r; i++){
            delete arr[i];
        }
        delete arr;
    }
    
    Array2D<T> operator* (const Array2D & array) const{
        
    }
    
    Array2D<T> operator[] (){
        
    }

    int getR() {return this->r;}
    int getC() {return this->c;}
    
    void disp() {
        for (int i = 0; i < this->r; i++) {
            for (int j = 0; j < this->c; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};
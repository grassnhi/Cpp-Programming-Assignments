/*
template <class T> 
class Array2D {
	int m;
	int n;
	T** arr;
}
Class Array2D sẽ quản lý một ma trận mxn 

1. Hiện thực constructor gồm 2 tham số Array2D(int r, int c), cấp phát vùng nhớ cho mảng 2 chiều có kích thức r x c.

2. Hiện thực constructor gồm 3 tham số  Array2D(int r, int c, T init), khởi tạo các thành phần của mảng 2 chiều có kích thước r x c với giá trị khởi tạo toàn mảng là init.

3. Hiện thực destructor thực hiện thu hồi vùng nhớ đã được cấp phát động.

4. Overriding operator* thực hiện phép nhân ma trận với một đối tượng Array2D khác (chú ý điều kiện nhân ma trận). Yêu cầu trả về con trỏ đến kết quả là một đối tượng của Array2D, trong trường hợp không thỏa điều kiện nhân ma trận thì trả về NULL.

5. Overriding operator[] để trường hợp sau code có thể chạy được. Giả thiết rằng kiểu dữ liệu T*  đã overriding toán tử [] để trả ra giá trị tại vị trí cần thiết (ví dụ: arr[i] sẽ trả ra giá trị phần tử thứ i của mảng arr có kiểu dữ liệu T. Nói cách khác, sinh viên không cần quan tâm đến toán tử [] của *arr)


int main() {
    Array2D<int>* p = new Array2D<int>(1, 2, 3);
    cout << (*p)[0][1] << endl;
    return 0;
}
[English]

Given class template:

template <class T> 
class Array2D {
	int m;
	int n;
	T** arr;
}
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




For example:

Test	Input	Result
1
2 3 4
3 4 5
-2 -4
4 4 4 
-2 4 4 
5 5 5 5 
5 5 -4 5 
5 5 5 5 
60 60 24 60 
30 30 -6 30 

*/

template <class T> 
class Array2D {
private:
	int r;
	int c;
	T** arr;

public:
    // TODO
    Array2D(int rows, int cols) : r(rows), c(cols) {
        arr = new T*[r];
        for (int i = 0; i < r; i++) {
            arr[i] = new T[c];
        }
    }
    
    Array2D(int rows, int cols, T init) : r(rows), c(cols) {
        arr = new T*[r];
        for (int i = 0; i < r; i++) {
            arr[i] = new T[c];
            for (int j = 0; j < c; j++) {
                arr[i][j] = init;
            }
        }
    }
    
    ~Array2D() {
        for (int i = 0; i < r; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    
    Array2D<T>* operator*(const Array2D<T>& other){
        if (this->c != other.r) {
            return nullptr; 
        }
        
        Array2D<T>* result = new Array2D<T>(this->r, other.c);
        
        for (int i = 0; i < this->r; i++) {
            for (int j = 0; j < other.c; j++) {
                result->arr[i][j] = T();
            }
        }
        
        for (int i = 0; i < this->r; i++) {
            for (int j = 0; j < other.c; j++) {
                for (int k = 0; k < this->c; k++) {
                    result->arr[i][j] += this->arr[i][k] * other.arr[k][j];
                }
            }
        }
        return result;
    }
    
    T* operator[](int i) {
        return arr[i];
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
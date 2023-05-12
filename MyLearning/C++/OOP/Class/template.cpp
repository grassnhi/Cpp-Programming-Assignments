// Template -> parametric polymorphism
// Function template - method template

template <class    identifier> function_name(...)
template <typename identifier> function_name(...)

// Call:
 
function_name<indentifier>(...)

#include<iostream>
using namespace std;

template <typename Kieu>
void Swap(Kieu& a, Kieu& b){
    Kieu tam = a;
    a = b;
    b = tam;
}

int main(){
    int a = 5;
    int b = 8;

    cout << "a = " << a << " - b = " << b << endl;

    Swap<int>(a, b);

    cout << "a = " << a << " - b = " << b << endl;

    string x = "diem";
    string y = "yeu";

    cout << x << " " << y << endl;

    Swap<string>(x, y);

    cout << x << " " << y << endl;

    return 0;
}

// Class template

- Declare: 
    template <class identifier> class class_name{...};

- Create: 
    class_name<identifier> object_name(...);

- Define:
    template <class identifier>
    return_type class_name<identifier>::method_name(...){
        . . .
    }

// => Example:

#include<iostream>
using namespace std;

const int MaxN = 10;

template <class Kieu>
class Mang{
    private:
        int n;
        Kieu Arr[MaxN];

    public:
        Mang(Kieu a[], int m){
            n = m;
            for(int i = 0; i < n; i++){
                Arr[i] = a[i];
            }
        }

        void Display();
};

template <class Kieu> void Mang<Kieu>::Display(){
    for(int i = 0; i < n; i++)
        cout << Arr[i] << " ";
    
    cout << endl;
}

int main(){
    int m = 5;
    int nguyen[] = {1, 2, 3, 4, 5};

    Mang<int> dt1(nguyen, m);
    dt1.Display();

    m = 4;
    string chuoi[] = {"ky", "thuat", "lap", "trinh"};

    Mang<string> dt2(chuoi, m);
    dt2.Display();

    return 0;
}
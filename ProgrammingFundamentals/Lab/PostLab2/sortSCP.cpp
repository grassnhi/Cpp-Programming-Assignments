/*
Mô tả tiếng Việt:

Cho struct SCP lưu trữ thông tin các vật thể dị thường được mô tả như sau:

struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

Tổ chức SCP lưu trữ thông tin các vật thể dị thường dưới dạng một array được cấp phát động. Tuy nhiên, vì một vài lý do, các hồ sơ không được sắp xếp theo một trật tự nào.

Hiện thực một hàm với prototype sau:

SCP** sortDatabase(SCP** arr, int n);

Trong đó arr là một array chứa các pointer trỏ đến các instance kiểu SCP, n là độ dài của mảng. Hàm thực hiện sắp xếp theo chiều tăng dần mã định danh các đối tượng SCP và trả về mảng sau khi sắp xếp.

Ghi chú: (Các) thư viện iostream và string đã được khai báo, và namespace std đã được sử dụng.

English version:

Struct SCP used to store information about paranormal objects is declared as below:

struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

SCP Foundation's classified archives are stored as a dynamic allocated array. However, because of some specific reason, the array is not sorted in any order.

Implement the function with the following prototype:

SCP** sortDatabase(SCP** arr, int n);

Where arr is the array of SCP typed pointers, n is the length of the array. The function returns the sorted array in item number (id) increasing order.

Note: Libraries iostream and string have been imported, and namespace std has been used.

For example:

Test	Result
int n = 3;
SCP** data = new SCP* [n];
data[0] = new SCP {2, 1, "SCP-002 is to remain connected to a suitable power supply at all times.", "SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.", nullptr, 0};
data[1] = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", nullptr, 0};
data[2] = new SCP {49, 1, "SCP-049 is contained within a Standard Secure Humanoid Containment Cell in Research Sector-02 at Site-19.", "SCP-049 is a humanoid entity, roughly 1.9 meters in height, which bears the appearance of a medieval plague doctor.", nullptr, 0};

data = sortDatabase(data, n);

for (int i = 0; i < n; i++) cout << data[i]->id << " ";

for (int i = 0; i < n; i++) {
    delete [] data[i]->addendums;
    delete data[i];
}
delete [] data;
2 49 55 
Answer:(penalty regime: 0 %)

*/

SCP** sortDatabase(SCP** arr, int n) {
    // Student answer
    if (!arr || n <= 1) return arr;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j]->id > arr[j + 1]->id) {
                SCP* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    return arr;
}
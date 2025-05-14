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

Chỉ số objClass của mỗi vật thể dị thường đánh giá mức độ khó khăn trong việc quản thúc đối tượng. Chỉ số này càng cao, đối tượng càng khó bị quản thúc, và việc quản thúc cần tiêu tốn nhiều tài nguyên hơn.

Hiện thực một hàm với prototype sau:

int compareObjectClass(const SCP &objA, const SCP &objB);

Hàm so sánh mức độ khó khăn trong việc quản thúc của hai đối tượng objA và objB và trả về -1 nếu objA dễ quản thúc hơn objB, 1 nếu objA khó quản thúc hơn objB, 0 nếu mức độ khó khăn trong việc quản thúc của hai vật thể này tương đương nhau.

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

The objClass of each object indicates how difficult an object is to contain. The higher the value, the more resources and budget are needed to contain the object.

int compareObjectClass(const SCP &objA, const SCP &objB);

The function returns -1 if objA is easier to be contained than objB, 1 if objA is more difficult to be contained than objB, or 0 if the difficulties in containing two objects are equivalent.

Note: Libraries iostream and string have been imported, and namespace std has been used.

For example:

Test	Result
SCP objA {2, 1, "SCP-002 is to remain connected to a suitable power supply at all times.", "SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.", nullptr, 0};
SCP objB {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", nullptr, 0};
cout << compareObjectClass(objA, objB);
-1
Answer:(penalty regime: 0, 0, 0, 0, 0, 100 %)
*/

int compareObjectClass(const SCP &objA, const SCP &objB) {
    // Student answer
    if(objA.objClass < objB.objClass){
        return -1;
    }else if(objA.objClass == objB.objClass){
        return 0;
    }else{
        return 1;
    }
}
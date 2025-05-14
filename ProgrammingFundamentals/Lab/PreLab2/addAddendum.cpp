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

Hiện thực một hàm với prototype sau:

void addAddendum(SCP &obj, string addendum);

Hàm thực hiện bổ sung một phụ lục addendum vào cuối danh sách phụ lục (addendums) của obj.

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

Implement the function with the following prototype:

void addAddendum(SCP &obj, string addendum);

The function appends a new addendum into the array of addendums of the object obj.

Note: Libraries iostream and string have been imported, and namespace std has been used.

For example:

Test	Result
string* addendums = new string[1];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";

SCP obj {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 1};

addAddendum(obj, "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.");

cout << obj.addendums[1];

delete [] obj.addendums;
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
Answer:(penalty regime: 0 %)
*/

void addAddendum(SCP &obj, string addendum) {
    // Student answer
    string* newAdd = new string[obj.numAddendums + 1];
    
    for(int i = 0; i < obj.numAddendums; i++){
        newAdd[i] = obj.addendums[i];
    }
    newAdd[obj.numAddendums] = addendum;
    
    delete[] obj.addendums;
    
    obj.addendums = newAdd;
    obj.numAddendums++;
}
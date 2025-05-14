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

Một đối tượng dị thường là SCP-038 có khả năng tạo bản sao của các vật thể dị thường khác, ví dụ như SCP-500 (thuốc vạn ứng). Khi đối tượng gốc bị tiêu thụ/phá hủy, bản sao vẫn tồn tại độc lập.

Hiện thực một hàm với prototype sau:

SCP* cloneSCP(SCP* original);

Hàm có chức năng tạo một bản sao con trỏ loại SCP chứa các thông tin như đối tượng gốc original, sau đó trả về con trỏ đó. Lưu ý về shallow copy và deep copy.

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

The paranormal object SCP-038 has the ability to clone other objects, such as SCP-500 (panacea). The clone is independent of the original, and the clone will remain the same whether the original is destroyed or modified.

Implement the function with the following prototype:

SCP* cloneSCP(SCP* original);

The function returns a pointer of the new cloned instance of the original object original. Choose the appropriate copy method.

Note: Libraries iostream and string have been imported, and namespace std has been used.

For example:

Test	Result
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

obj->id = 1;
cout << obj->id << " " << newObj->id << "\n";

delete [] obj->addendums;
delete obj;

delete [] newObj->addendums;
delete newObj;
1 55
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

obj->description = "The object cannot be described.";
cout << obj->description << " " << newObj->description << "\n";

delete [] obj->addendums;
delete obj;

delete [] newObj->addendums;
delete newObj;
The object cannot be described. All known information about the object is that it is not round.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

obj->addendums[0] = "Access authority required.";
cout << obj->addendums[0] << " " << newObj->addendums[0] << "\n";

delete [] obj->addendums;
delete obj;

delete [] newObj->addendums;
delete newObj;
Access authority required. Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

delete [] obj->addendums;
delete obj;

cout << newObj->id << "\n";

delete [] newObj->addendums;
delete newObj;
55
{
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

delete [] obj->addendums;
delete obj;

cout << newObj->addendums[0] << "\n";

delete [] newObj->addendums;
delete newObj;
}
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

obj->id = 1;
cout << obj->id << " " << newObj->id << "\n";

delete [] obj->addendums;
delete obj;

delete [] newObj->addendums;
delete newObj;
1 55
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

obj->description = "The object cannot be described.";
cout << obj->description << " " << newObj->description << "\n";

delete [] obj->addendums;
delete obj;

delete [] newObj->addendums;
delete newObj;
The object cannot be described. All known information about the object is that it is not round.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

obj->addendums[0] = "Access authority required.";
cout << obj->addendums[0] << " " << newObj->addendums[0] << "\n";

delete [] obj->addendums;
delete obj;

delete [] newObj->addendums;
delete newObj;
Access authority required. Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

delete [] obj->addendums;
delete obj;

cout << newObj->id << "\n";

delete [] newObj->addendums;
delete newObj;
55
{
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP* obj = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

SCP* newObj = cloneSCP(obj);

delete [] obj->addendums;
delete obj;

cout << newObj->addendums[0] << "\n";

delete [] newObj->addendums;
delete newObj;
}
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Answer:(penalty regime: 0 %)

*/

SCP* cloneSCP(SCP* original) {
    // Student answer
     if (original == nullptr) return nullptr;

    SCP* clone = new SCP;
    clone->id = original->id;
    clone->objClass = original->objClass;
    clone->speConProcedures = original->speConProcedures;
    clone->description = original->description;
    clone->numAddendums = original->numAddendums;
    
    if(clone->numAddendums != 0 && original->addendums != nullptr){
         clone->addendums = new string[original->numAddendums];
        for (int i = 0; i < original->numAddendums; ++i) {
            clone->addendums[i] = original->addendums[i];
        }
    } else {
        clone->addendums = nullptr;
    }

    return clone;
}
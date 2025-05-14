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

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums);

Hàm có chức năng khởi tạo instance của struct SCP với các thông tin đã truyền vào, sau đó trả về instance đó.

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

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums);

The function returns a new instance of struct SCP with the passed parameters.

Note: Libraries iostream and string have been imported, and namespace std has been used.

For example:

Test	Result
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

for (int i = 0; i < 2; i++) cout << obj.addendums[i] << "\n";

delete [] addendums;
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

cout << obj.id;

delete [] addendums;
55
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

cout << obj.objClass;

delete [] addendums;
2
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

cout << obj.speConProcedures;
Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

cout << obj.description;

delete [] addendums;
All known information about the object is that it is not round.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

for (int i = 0; i < obj.numAddendums; i++) cout << obj.addendums[i] << "\n";

delete [] addendums;
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

for (int i = 0; i < obj.numAddendums; i++) cout << obj.addendums[i] << "\n";

delete [] addendums;
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

for (int i = 0; i < obj.numAddendums; i++) cout << obj.addendums[i] << "\n";

delete [] addendums;
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

for (int i = 0; i < obj.numAddendums; i++) cout << obj.addendums[i] << "\n";

delete [] addendums;
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

for (int i = 0; i < obj.numAddendums; i++) cout << obj.addendums[i] << "\n";

delete [] addendums;
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
Answer:(penalty regime: 0 %)
*/

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums) {
    // Student answer
    SCP scp;
    scp.id = id;
    scp.objClass = objClass;
    scp.speConProcedures = speConProcedures;
    scp.description = description;
    scp.addendums = addendums;
    scp.numAddendums = numAddendums;
    
    return scp;
}
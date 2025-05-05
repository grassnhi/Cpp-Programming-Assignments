/*
Mô tả tiếng Việt:

Cho struct SCP lưu trữ thông tin các vật thể dị thường được mô tả như sau:

struct SCP { int id; int objClass; string speConProcedures; string description; string* addendums; int numAddendums; };

Hiện thực một hàm với prototype sau:

string convertToString(SCP obj);

Hàm trả về một string duy nhất, với format chuẩn được quy định bởi tổ chức:

Item #: SCP-<Mã định danh, thêm 0 vào trước nếu chưa đủ 3 chữ số>
Object Class: <Safe nếu objClass là 0, Euclid nếu là 1, Keter nếu là 2>
Special Containment Procedures: <Quy trình quản thúc đặc biệt>
Description: <Mô tả vật thể>
<Phụ lục 0>
<Phụ lục 1>
...
<Phụ lục n>

Tham khảo ví dụ để hiểu về format đầu ra.

Ghi chú: (Các) thư viện iostream, sstream và string đã được khai báo, và namespace std đã được sử dụng.

English version:

Struct SCP used to store information about paranormal objects is declared as below:

struct SCP { int id; int objClass; string speConProcedures; string description; string* addendums; int numAddendums; };

Implement the function with the following prototype:

string convertToString(SCP obj);

The function returns a string with the following format:

Item #: SCP-<Item number, zero-left-padded until it has 3 or more digits.>
Object Class: <Safe if objClass is 0, Euclid if 1, Keter if 2>
Special Containment Procedures: <The specification of the object's special containment procedures.>
Description: <The object's description.>
<Addendum 0>
<Addendum 1>
...
<Addendum n>

Refer to the example to understand the format.

Note: Libraries iostream and string have been imported, and namespace std has been used.

For example:

Test	Result
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

cout << convertToString(obj);

delete [] addendums;
Item #: SCP-055
Object Class: Keter
Special Containment Procedures: Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.
Description: All known information about the object is that it is not round.
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
SCP obj {2, 1, "SCP-002 is to remain connected to a suitable power supply at all times.", "SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.", nullptr, 0};
cout << convertToString(obj);
Item #: SCP-002
Object Class: Euclid
Special Containment Procedures: SCP-002 is to remain connected to a suitable power supply at all times.
Description: SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.
SCP obj {500, 0, "SCP-500 must be stored in a cool and dry place away from bright light.", "SCP-500 is a small plastic can which at the time of writing contains forty-seven (47) red pills.", nullptr, 0};
cout << convertToString(obj);
Item #: SCP-500
Object Class: Safe
Special Containment Procedures: SCP-500 must be stored in a cool and dry place away from bright light.
Description: SCP-500 is a small plastic can which at the time of writing contains forty-seven (47) red pills.
SCP obj {1487, 1, "SCP-1487 is to be kept in Humanoid Containment Chamber #3821 at Site 23.", "SCP-1487 is a female humanoid of Filipino descent. The entity is fifteen (15) years old and measures 1.7m in height and 70kg in weight.", nullptr, 0};
cout << convertToString(obj);
Item #: SCP-1487
Object Class: Euclid
Special Containment Procedures: SCP-1487 is to be kept in Humanoid Containment Chamber #3821 at Site 23.
Description: SCP-1487 is a female humanoid of Filipino descent. The entity is fifteen (15) years old and measures 1.7m in height and 70kg in weight.
string* addendums = new string[1];
addendums[0] = "Site 81/715 Protocol: [ACCESS RESTRICTED]\nPlease Access Using 715/5 Authorization Code";

SCP obj {715, 0, "SCP-715 is to be contained at its point of origin within the ---- City Mall in ----, Ohio.", "SCP-715 is a \"Take Your Own Photo\" fotomat model photo booth manufactured by the Sony corporation in 1972.", addendums, 1};

cout << convertToString(obj);

delete [] addendums;
Item #: SCP-715
Object Class: Safe
Special Containment Procedures: SCP-715 is to be contained at its point of origin within the ---- City Mall in ----, Ohio.
Description: SCP-715 is a "Take Your Own Photo" fotomat model photo booth manufactured by the Sony corporation in 1972.
Site 81/715 Protocol: [ACCESS RESTRICTED]
Please Access Using 715/5 Authorization Code
string* addendums = new string[2];
addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

SCP obj {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

cout << convertToString(obj);

delete [] addendums;
Item #: SCP-055
Object Class: Keter
Special Containment Procedures: Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.
Description: All known information about the object is that it is not round.
Document #055-1: An Analysis of SCP-055
The author puts forward the hypothesis that SCP-055 was never formally acquired.
Document #055-2: Report of Dr. John Marachek
Survey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.
SCP obj {2, 1, "SCP-002 is to remain connected to a suitable power supply at all times.", "SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.", nullptr, 0};
cout << convertToString(obj);
Item #: SCP-002
Object Class: Euclid
Special Containment Procedures: SCP-002 is to remain connected to a suitable power supply at all times.
Description: SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.
SCP obj {500, 0, "SCP-500 must be stored in a cool and dry place away from bright light.", "SCP-500 is a small plastic can which at the time of writing contains forty-seven (47) red pills.", nullptr, 0};
cout << convertToString(obj);
Item #: SCP-500
Object Class: Safe
Special Containment Procedures: SCP-500 must be stored in a cool and dry place away from bright light.
Description: SCP-500 is a small plastic can which at the time of writing contains forty-seven (47) red pills.
SCP obj {1487, 1, "SCP-1487 is to be kept in Humanoid Containment Chamber #3821 at Site 23.", "SCP-1487 is a female humanoid of Filipino descent. The entity is fifteen (15) years old and measures 1.7m in height and 70kg in weight.", nullptr, 0};
cout << convertToString(obj);
Item #: SCP-1487
Object Class: Euclid
Special Containment Procedures: SCP-1487 is to be kept in Humanoid Containment Chamber #3821 at Site 23.
Description: SCP-1487 is a female humanoid of Filipino descent. The entity is fifteen (15) years old and measures 1.7m in height and 70kg in weight.
string* addendums = new string[1];
addendums[0] = "Site 81/715 Protocol: [ACCESS RESTRICTED]\nPlease Access Using 715/5 Authorization Code";

SCP obj {715, 0, "SCP-715 is to be contained at its point of origin within the ---- City Mall in ----, Ohio.", "SCP-715 is a \"Take Your Own Photo\" fotomat model photo booth manufactured by the Sony corporation in 1972.", addendums, 1};

cout << convertToString(obj);

delete [] addendums;
Item #: SCP-715
Object Class: Safe
Special Containment Procedures: SCP-715 is to be contained at its point of origin within the ---- City Mall in ----, Ohio.
Description: SCP-715 is a "Take Your Own Photo" fotomat model photo booth manufactured by the Sony corporation in 1972.
Site 81/715 Protocol: [ACCESS RESTRICTED]
Please Access Using 715/5 Authorization Code
Answer:(penalty regime: 0 %)

*/

string convertToString(SCP obj) {
    // Student answer
    stringstream ss;
    
    ss << "Item #: SCP-";
    if(obj.id < 100){
        ss << "0";
        if(obj.id < 10){
            ss << "0";
        }
    }
    ss << obj.id << endl;
    
    ss << "Object Class: ";
    if(obj.objClass == 0){
        ss << "Safe" << endl;
    }else if(obj.objClass == 1){
        ss << "Euclid" << endl;
    }else if (obj.objClass == 2) {
        ss << "Keter" << endl;
    }
    
    ss << "Special Containment Procedures: " << obj.speConProcedures << endl;
    
    ss << "Description: " << obj.description << endl;
    
    for (int i = 0; i < obj.numAddendums; i++) {
        ss << obj.addendums[i] << endl;
    }
    
    return ss.str();
}
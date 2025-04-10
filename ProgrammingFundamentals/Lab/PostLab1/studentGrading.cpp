/*
Viết hàm void studendGrading(string fileName) đọc một file đuôi txt, dòng đầu gồm 1 số nguyên dương N, N dòng theo sau mỗi dòng chứa 4 số thực lần lượt là điểm số của các môn NMĐT,  KTLT, DSA và PPL của N học sinh.

Điểm trung bình (ĐTB) của sinh viên sẽ là trung bình cộng của 4 cột điểm trên. Sinh viên sẽ được xếp loại dựa trên ĐTB như sau:

 

Loại A nếu ĐTB >= 8 và không có môn nào dưới 5.
Loại B nếu 8 > ĐTB >= 6.5 và không có môn nào dưới 5.
Loại C nếu 6.5 > ĐTB >= 5 và không có môn nào dưới 5
Loại D cho các trường hợp còn lại
 

Xác định số lượng sinh viên mỗi loại và xuất kết quả ra màn hình.

Đầu vào:

 


Biến "fileName" là tên file chứa chứa thông tin về điểm số của sinh viên.

 

Đầu ra:

Số lượng sinh viên mỗi loại được ghi ra màn hình.

 

Write a function void studendGrading(string fileName) that reads a txt file, the first line consists of a positive integer N, N lines follow each line containing 4 real numbers, respectively, the scores of the subjects NMDT, KTLT, DSA and PPL of N students.

The student's grade point average (GPA) will be the average of the above 4 score columns. Students will be graded based on the following scores:

 

Grade A if the test score is >= 8 and no subject is below 5.
Grade B if 8 > GPA >= 6.5 and no subject below 5.
Grade C if 6.5 > GPA >= 5 and no subject below 5.
Grade D for the remaining cases.
 

Determine the number of students of each category and output the results to the screen.

Input:

The variable "fileName" is the file name that contains information about the student's score.

Output:

The number of students in each category is recorded on the screen.

Lưu ý: Sinh viên chỉ có 5 lần nộp không tính penalty, ở lần nộp thứ 6 trở đi bài làm sẽ được tính là 0 điểm.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void studentGrading(string fileName)   {
    // TODO
    ifstream file(fileName);
    if(file.is_open()){
        int N;
        int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0;
        double nmdt, ktlt, dsa, ppl;
        file >> N;
        for(int i = 0; i < N; i++){
            file >> nmdt >> ktlt >> dsa >> ppl;
            double avg = (nmdt + ktlt + dsa + ppl) / 4;
            bool below5 = (nmdt < 5) || (ktlt < 5) || (dsa < 5) || (ppl < 5);
            if(avg >= 8 && (!below5)){
                gradeA++;
            }else if(avg < 8 && avg >= 6.5 && (!below5)){
                gradeB++;
            }else if(avg < 6.5 && avg >= 5 && (!below5)){
                gradeC++;
            }else{
                gradeD++;
            }
        }
        file.close();
        
        cout << "A " << gradeA << endl;
        cout << "B " << gradeB << endl;
        cout << "C " << gradeC << endl;
        cout << "D " << gradeD << endl;
    }
}

int main() {
    // Tạo file mẫu để test
    ofstream outFile("input.txt");
    outFile << "2\n";
    outFile << "8 8 8 6\n";
    outFile << "9 9 9 5\n";
    outFile.close();

    // Gọi hàm grading
    studendGrading("input.txt");

    return 0;
}

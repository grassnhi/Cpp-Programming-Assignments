/*
Một đường truyền thông tin gồm các kí tự bị hacker tấn công. Cuộc tấn công chỉ làm ảnh hưởng đến các tín hiệu có giá trị là kí tự trong bảng chữ cái làm cho các chữ thường thành chữ in hoa và ngược lại các chữ in hoa thành chữ thường. Sinh viên được chủ đường truyền nhờ để khôi phục dữ liệu lại về như ban đầu.

Sinh viên viết hàm xử lý void recover(char signal[]) để biến đổi tất cả chữ cái in hoa thành chữ viết thường và chữ cái thường thành chữ in hoa có trong chuỗi signal (lưu ý biến đổi trực tiếp trên signal)

Đầu vào (Input):

Chuỗi kí tự cần biến đổi chữ hoa thành chữ thường và chữ thường thành chữ hoa
Đầu ra (Output):

Kết quả biến đổi trực tiếp trên signal (lưu ý các kí tự không phải kí tự trong bảng chữ cái thì giữ nguyên) 
---------------------------------------

The information transmission line is attacked by hackers. The attack only affects the signals with characters that have a value in the alphabet, converting lowercase letters to uppercase and vice versa. The student is asked by the transmission owner to restore the data to its original state.

The student writes a processing function void recover(char signal[]) to transform all uppercase letters into lowercase letters and lowercase letters into uppercase letters in the string signal (note the transformation is inplace). 

Input:

A character string to transform uppercase letters to lowercase and lowercase letters to uppercase
Output:

The transformed result in signal
*/
#include <iostream>
#include <cstdio>
using namespace std;

void recover(char signal[]) {
    int i = 0;
    while (signal[i] != '\0') {
        if (signal[i] >= 'a' && signal[i] <= 'z') {
            signal[i] = signal[i] - ('a' - 'A'); // Lowercase → Uppercase
        } else if (signal[i] >= 'A' && signal[i] <= 'Z') {
            signal[i] = signal[i] + ('a' - 'A'); // Uppercase → Lowercase
        }
        i++;
    }
}

int main() {
    char signal1[] = "hello world";
    recover(signal1);
    printf("%s\n", signal1); // Output: HELLO WORLD

    char signal2[] = "CSE HCMUT";
    recover(signal2);
    printf("%s\n", signal2); // Output: cse hcmut

    char signal3[] = "I waNT tO hAVe 10 MaRk In FudaMenTAL of PRogRamInG couRsE.";
    recover(signal3);
    printf("%s\n", signal3);
    // Output: i WAnt To HavE 10 mArK iN fUDAmENtal OF prOGrAMiNg COUrSe.

    return 0;
}

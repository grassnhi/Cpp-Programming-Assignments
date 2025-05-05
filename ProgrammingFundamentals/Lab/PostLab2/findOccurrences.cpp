/*
[Tiếng Việt]

Hiện thực hàm findOccurrences với ba đối số: một mảng số nguyên nums, độ dài của mảng size và một số nguyên element. Hàm sẽ trả về số lần xuất hiện của element trong nums.

 

Ví dụ:

Input: nums = {1,2,3}, size = 3, element = 3
Output: 1

Lưu ý: Xin lưu ý rằng bạn không thể sử dụng từ khóa for, while, goto (ngay cả trong tên biến, comment).

Bạn có thể triển khai các hàm đệ quy khác nếu cần.

Đối với bài tập này, chúng ta có #include <iostream> và using namespace std;

 

[English]

Implement the function findOccurrences with three parameters: an array of integers nums, the length of the array size, and an integer element. The function will return the number of occurrences of the element in nums.

 

Example:

Input: nums = {1,2,3}, size = 3, element = 3
Output: 1

Note: Please note that you cannot use the keywords for, while, goto (even in variable names, comments).

You may implement additional recursive functions if necessary.

For this exercise, we have #include <iostream> and using namespace std;

For example:

Test	Result
int nums[] = {1,2,3};
cout << findOccurrences(nums, 3, 3);
1

*/

int findOccurrences(int nums[], int size, int element) {
    // TODO:
    if(size == 0){
        return 0;
    }
    return (nums[0] == element ? 1 : 0) + findOccurrences(nums + 1, size - 1, element);
}
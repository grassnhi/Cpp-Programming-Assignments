// Jagged array (Mảng không đều) -> khai báo số hàng, mỗi hàng dài bất kì

type_name[][] array_name;

// Truy xuất:

array_name[i][j]

// Example

const int H = 3;
int[][] a = new int[H][];
a[0] = new int[4];
a[1] = new int[3];
a[2] = new int[5];
// Declare:

type_name array_name[array_size];

// Assign:

type_name array_name[array_size] = initializer_list;

// If initializer_list = { } => các phần tử = 0

Tính phần tử của mảng a = sizeof(a) / sizeof(a[0])  (byte/byte)

// Define new array then declace an array type array

typedef type_name array_type[array_size];
array_type array_name;

// => Example:

int a[5];

const int N = 5;
int a[N];

int a[5] = {1, 2, 3, 4, 5}; == a[] = {1, 2, 3, 4, 5};

a[N] = {1, 2, 3, 0, 0}; == a[5] = {1, 2, 3}

typedef int Arr[5];
Arr a = {1, 2, 3, 4, 5};

// Truy xuất:

array_name[index]
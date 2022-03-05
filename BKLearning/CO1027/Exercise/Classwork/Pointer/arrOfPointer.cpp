#include <iostream>

using namespace std;
const int MAX = 4;

int main() {
	const char *names[MAX] = { "An Nguyen", "Binh Tran", "Cong Pham", "Dat Le" };

	for (int i = 0; i < MAX; i++) {
		cout << "Value of names[" << i << "] = " << *(names + i) << endl;
	}

	return 0;
}

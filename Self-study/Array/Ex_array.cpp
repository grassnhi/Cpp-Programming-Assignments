#include <iostream>
using namespace std;

int main()
{   
    const int n = 5;
    int target;

	int nums[n];

	cout << "Array input:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "nums[" << i << "] = ";
		cin >> nums[i];
	}

    cout << " Enter target: " << endl;
    cin >> target;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (nums[i] + nums[j] == target){
                cout << nums[i] << " " << nums[j] << endl;
        }
    }
}
	return 0;
}
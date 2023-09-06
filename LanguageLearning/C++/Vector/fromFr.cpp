#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int count = 0;
	int a = n;
	vector<int> temp;
	while (a != 0) {
		count++;
		temp.push_back(a % 10);
		a /= 10;
	}
	
	sort(temp.begin(), temp.end());
	if (count <= 2) cout << temp[1];
	else cout << temp[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
		cout << '\n';
	}

	return 0;
}
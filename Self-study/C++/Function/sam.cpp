#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ret(int n, int M) {
	if (n < 0) return n - (n / M - 1) * M;
	else return n % M;
}

void solve() {
	int n, M;
	cin >> n >> M;
	vector<int> a;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] + a[j] + ret(a[i] - a[j], M) > max) max = a[i] + a[j] + ret(a[i] - a[j], M);
		}
	}

	cout << max;
}

int main(){
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
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <bit>
#include <atcoder/all>
#include <format>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	bool isYes = true;
	for (int i = 0;i < n;i++) {
		cin >> x[i];
		if (x[i] >= 0) {
			isYes = false;
		}
	}
	if (isYes) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

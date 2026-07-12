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
	int n,m;
	cin >> n >> m;
	vector<int> c(n);
	vector<int> s(n);
	vector<int> biggest(m+1, -1);
	for (int i = 0;i < n;i++) {
		cin >> c[i] >> s[i];
		biggest[c[i]] = max(biggest[c[i]], s[i]);
	}
	for (int col = 1;col <= m; col++) {
		cout << biggest[col] << " ";
	}
}

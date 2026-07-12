#include <iostream>
#include <vector>
#include <queue>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	vector<int> coodinates(n + 1);
	for (int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		coodinates[x] = y;
	}
	fenwick_tree<int> fw(n + 1);
	for (int x = 1;x <= n;x++) {
		if (fw.sum(0, coodinates[x]) == 0) {
			ans++;
		}
		fw.add(coodinates[x], 1);
	}
	cout << ans << endl;
}

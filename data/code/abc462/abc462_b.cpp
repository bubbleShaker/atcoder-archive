#include <iostream>
#include <vector>
#include <queue>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> ans(n + 1);
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++) {
			int a;
			cin >> a;
			ans[a].push_back(i);
		}
	}
	for (int i = 1;i <= n;i++) {
		cout << ans[i].size() << " ";
		for (int j = 0;j < ans[i].size();j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

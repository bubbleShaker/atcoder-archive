#include <iostream>
#include <vector>
#include <queue>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
	int x, y, l, r, a, b;
	cin >> x >> y >> l >> r >> a >> b;
	int ans = 0;
	for (int i = a;i <= b-1;i++) {
		if (l <= i && i < r) {
			ans += x;
		}
		else {
			ans += y;
		}
	}
	cout << ans << endl;
}

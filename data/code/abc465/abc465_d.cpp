#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long X, Y, K;
		long long ans = 0;
		cin >> X >> Y >> K;
		while (X != Y) {
			if (X > Y) {
				X = X / K;
				ans++;
			}
			else if (X < Y) {
				Y = Y / K;
				ans++;
			}
		}
		cout << ans << endl;
	}
}

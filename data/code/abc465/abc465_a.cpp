#include <iostream>
#include <vector>
#include <queue>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
	int a, b;
	cin >> a >> b;
	string ans = (3 * a > 2 * b) ? "Yes" : "No";
	cout << ans << endl;
}

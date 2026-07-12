#include <iostream>
#include <vector>
#include <queue>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
	string s;
	cin >> s;
	string ans = "";
	for (int i = 0;i < s.size();i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			ans += s[i];
		}
	}
	cout << ans << endl;
}

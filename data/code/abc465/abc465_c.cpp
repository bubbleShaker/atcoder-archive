#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> head;
	vector<int> tail;
	bool should_head = false;
	for (int i = n;i >= 1;i--) {
		if (s[i-1] == 'o') {
			should_head = !should_head;
		}
		if (should_head) {
			head.push_back(i);
		}
		else {
			tail.push_back(i);
		}
	}
	reverse(tail.begin(), tail.end());
	head.insert(head.end(), tail.begin(), tail.end());
	for (int i = 0;i < n;i++) {
		cout << head[i] << " ";
	}
}

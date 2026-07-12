#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 回文かどうかを判定する関数
bool isPalindrome(const string& str) {
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);

    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // すべてのペア (i, j) を試す
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                string combined = S[i] + S[j];
                if (isPalindrome(combined)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n + 1);  // 1-indexed のために n+1 のサイズに
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    // 結果の累積和
    vector<long long> rsw(n + 1, 0);

    // 右から左にスキャンして、単調増加スタックを使って解く
    stack<int> s;
    
    for (int j = 1; j <= n; ++j) {
        // スタック内の要素が h[j] 以下のものを全て取り除く
        while (!s.empty() && h[s.top()] <= h[j]) {
            s.pop();
        }
        
        // スタックが空なら、そのまま全区間に対してカウント
        if (s.empty()) {
            rsw[1]++;
            rsw[j]--;
        } else {
            // スタックに残っているものの中で最大のインデックスに対してカウント
            int idx = s.top();
            rsw[idx]++;
            rsw[j]--;
        }
        
        // 現在のインデックスをスタックに追加
        s.push(j);
    }

    // 累積和を計算
    for (int i = 1; i <= n; ++i) {
        rsw[i] += rsw[i - 1];
    }

    // 結果を出力
    for (int i = 1; i <= n; ++i) {
        cout << rsw[i] << (i != n ? ' ' : '\n');
    }

    return 0;
}

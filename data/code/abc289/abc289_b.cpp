#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    for(auto& x : a) cin >> x;
    vector<int> re(N + 1);
    for(auto& x : a) re[x] = 1;
    vector<int> ans;
    for(int i = 1, j = 1; i <= N; i = ++j){
        while(re[j]) j++;
        for(int k = j; k >= i; k--) ans.push_back(k);
    }
    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i + 1 == N];
}

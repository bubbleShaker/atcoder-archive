#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    int n;
    cin >> n;
    vector<set<int>> st(n);
    rep(i,n) {
        int c;
        cin >> c;
        rep(j,c) {
            int a;
            cin >> a;
            st[i].insert(a);
        }
    }
    int x;
    cin >> x;
    vector<int> ans;
    int mi = 100;
    rep(i,n) {
        if(st[i].count(x)){
            mi = min(mi,(int)st[i].size());
        }
    }
    rep(i,n) {
        if(st[i].count(x)){
            if(st[i].size() == mi){
                ans.push_back(i+1);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i,ans.size()) {
        cout << ans[i] << " \n"[i+1 == ans.size()];
    }
    return 0;
}

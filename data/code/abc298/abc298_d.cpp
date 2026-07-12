#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using mint = modint998244353;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    
    queue<int> q;
    q.push(1);
    mint ans = 1;
    
    rep(qi,Q) {
        int type;
        cin >> type;
        if(type == 1) {
            int x;
            cin >> x;
            q.push(x);
            ans = ans*10+x;
        }
        if(type == 2) {
            int x = q.front(); q.pop();
            ans -= mint(x)*mint(10).pow(q.size());
        }
        if(type == 3) {
            cout << ans.val() << endl;
        }
    }
    return 0;
}
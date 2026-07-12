#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<pair<ll, ll>> que;

ll calc(ll c){
    ll ans = 0;
    if(que.front().second < c){
        c -= que.front().second;
        ans += que.front().first * que.front().second;
        que.pop();
        ans += calc(c);
    }else{
        ans = que.front().first * c;
        que.front().second -= c;
    }
    return ans;
}

int main(void){
    int Q;
    cin >> Q;
    
    for(int i = 0; i < Q; i++){
        int n;
        cin >> n;
        if(n == 1){
            ll x, c;
            cin >> x >> c;
            que.push(make_pair(x, c));
        }else{
            ll c;
            cin >> c;
            ll ans = calc(c);
            cout << ans << endl;
        }
    }
    return 0;
}
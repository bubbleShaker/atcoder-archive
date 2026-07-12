#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i = 0; i < N; i++)
typedef long long ll;

int main(void){
    ll d;
    int n, m;
    
    cin >> d >> n >> m;
    
    vector<ll> s(n+1), k(m);
    
    for(int i = 1; i < n; i++) cin >> s[i];
    
    for(int i = 0; i < m; i++) cin >> k[i];
    
    s[n] = d;
    
    sort(s.begin(), s.end());
    
    ll sum = 0;
    
    for(int i = 0; i < m; i++){
        ll tmp;
        tmp = lower_bound(s.begin(), s.end(), k[i]) - s.begin();
        ll dis1, dis2, m_dis;
        dis1 = abs(s[tmp] - k[i]);
        dis2 = abs(s[tmp-1] - k[i]);
        m_dis = min(dis1, dis2);
        sum += m_dis;
    }
    
    cout << sum << endl;
    
    return 0;
}

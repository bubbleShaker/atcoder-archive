#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll N;
    int Q;
    cin >> N >> Q;
    
    map<ll, set<ll>> m_u;
    
    for(int i = 0; i < Q; i++){
        int t;
        ll a, b;
        cin >> t >> a >> b;
        if(t == 1){
            m_u[a].insert(b);
        }else if(t == 2){
            m_u[a].erase(b);
        }else{
            if(m_u[a].count(b) && m_u[b].count(a)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}

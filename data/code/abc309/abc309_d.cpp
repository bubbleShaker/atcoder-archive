#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll N1, N2, M;
    cin >> N1 >> N2 >> M;
    
    vector<vector<ll>> l(N1 + N2 + 1);
    
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a);
    }
    
    queue<ll> que;
    que.push(1);
    vector<ll> step(N1 + 1, -1);
    step[1] = 0;
    vector<bool> ch(N1 + 1, false);
    
    while(!que.empty()){
        ll tmp = que.front();
        que.pop();
        
        if(!ch[tmp]){
            for(ll a : l[tmp]){
                if(step[a] != -1) continue;
                que.push(a);
                step[a] = step[tmp] + 1;
            }
        }
        
        ch[tmp] = true;
    }
    
    ll ma1 = 0;
    
    for(ll i = 1; i <= N1; i++){
        ma1 = max(ma1, step[i]);
    }
    
    queue<ll> que2;
    que2.push(N1+N2);
    vector<ll> step2(N1 + N2 + 1, -1);
    step2[N1+N2] = 0;
    vector<bool> ch2(N1 + N2 + 1, false);
    
    while(!que2.empty()){
        ll tmp = que2.front();
        que2.pop();
        
        if(!ch2[tmp]){
            for(ll a : l[tmp]){
                if(step2[a] != -1) continue;
                que2.push(a);
                step2[a] = step2[tmp] + 1;
            }
        }
        
        ch2[tmp] = true;
    }
    
    ll ma2 = 0;
    
    for(ll i = N1 + 1; i <= N1 + N2; i++){
        ma2 = max(ma2, step2[i]);
    }
    
    cout << ma1 + ma2 + 1 << endl;
    
    return 0;
}

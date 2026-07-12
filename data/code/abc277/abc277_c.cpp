#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    set<int> st;
    st.insert(1);
    
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        for(int t : mp[f]) {
            if(st.count(t)) continue;
            q.push(t);
            st.insert(t);
        }
    }
    
    cout << *rbegin(st) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int q;
    cin >> q;
    set<int> st;
    map<int,int> mp;
    rep(i,q) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            st.insert(x);
            mp[x]++;
        }else if(t == 2) {
            int x, c;
            cin >> x >> c;
            mp[x] -= c;
            if(mp[x] <= 0) {
                st.erase(x);
                mp[x] = 0;
            }
        }else {
            int ma = *rbegin(st);
            int mi = *begin(st);
            cout << ma - mi << endl;
        }
    }
    return 0;
}

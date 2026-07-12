#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int L, q;
    cin >> L >> q;
    set<int> st;
    st.insert(0);
    rep(i,q) {
        int c, x;
        cin >> c >> x;
        if(c == 1)  st.insert(x);
        if(c == 2) {
            auto it = st.lower_bound(x);
            if(it == st.end()) cout << L-*(--it) << endl;
            else cout << *it - *(--it) << endl;
        }
    }
    return 0;
}

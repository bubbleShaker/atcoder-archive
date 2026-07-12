#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int mi = 1001001001;
    set<int> st;
    rep(i,k) {
        st.insert(p[i]);
        mi = min(mi,p[i]);
    }
    cout << mi << endl;
    for(int i = k; i < n; i++) {
        if(p[i] < mi) {
            cout << mi << endl;
        }
        if(p[i] > mi) {
            st.insert(p[i]);
            st.erase(mi);
            mi = *begin(st);
            cout << mi << endl;
        }
    }
    return 0;
}

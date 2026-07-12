#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<P> ps(n);
    rep(i,n) {
        int x, y;
        cin >> x >> y;
        ps[i].first = x;
        ps[i].second = y;
    }
    set<P> st;
    rep(i,n) {
        rep(j,n) {
            if(i == j) continue;
            auto [x1,y1] = ps[i];
            auto [x2,y2] = ps[j];
            int dx = x2-x1, dy = y2-y1;
            int sk = gcd(dx,dy);
            dx /= sk; dy /= sk;
            st.insert(P(dx, dy));
        }
    }
    cout << (int)st.size() << endl;
    return 0;
}

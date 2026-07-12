#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<P> ps(n);
    rep(i,n) cin >> ps[i].first >> ps[i].second;
    rep(i,n)for(int j = i+1; j < n; j++)for(int k = j+1; k < n; k++) {
        auto [x1,y1] = ps[i];
        auto [x2,y2] = ps[j];
        auto [x3,y3] = ps[k];
        if((x2-x1)*(y3-y1) == (y2-y1)*(x3-x1)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
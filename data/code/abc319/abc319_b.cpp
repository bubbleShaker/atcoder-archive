#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    cout << 1 ;
    for(int i = 1; i <= n; i++) {
        vector<pair<int,int>> t;
        for(int j = 1; j <= 9; j++) {
            if(n%j == 0) t.emplace_back(n/j, j);
        }
        rep(j,t.size()) {
            if(i%t[j].first == 0) {
                cout << t[j].second;
                break;
            }
            if(j+1 == t.size()) {
                cout << '-';
            }
        }
    }
    return 0;
}
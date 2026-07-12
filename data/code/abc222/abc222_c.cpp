#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using dII = tuple<double,Int,Int>;
using mint = modint1000000007;
using bP = pair<ll,bool>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<string> a(2*n);
    rep(i,2*n) cin >> a[i];
    map<int,multiset<int>> mp;
    rep(i,2*n) mp[0].insert(i);
    vector<int> cnt(2*n+1);
    
    auto f = [&](int x, int y, int ro) {
        char c1 = a[x][ro];
        char c2 = a[y][ro];
        if(c1 == 'G') {
            if(c2 == 'P') return y;
            if(c2 == 'C') return x;
            if(c2 == 'G') return -1;
        }
        if(c1 == 'C') {
            if(c2 == 'G') return y;
            if(c2 == 'P') return x;
            if(c2 == 'C') return -1;
        }
        if(c1 == 'P') {
            if(c2 == 'C') return y;
            if(c2 == 'G') return x;
            if(c2 == 'P') return -1;
        }
    };
    
    rep(i,m) {
        vector<int> match;
        for(int j = 2*m+1; j >= 0; j--) {
            if(!mp.count(j)) continue;
            for(int p : mp[j]) match.push_back(p);
        }
        int size = match.size();
        for(int k = 0; k < size; k+=2) {
            int x = match[k];
            int y = match[k+1];
            int winner = f(x,y,i);
            if(winner == x) {
                cnt[x]++;
            }else if(winner == y) {
                cnt[y]++;
            }
        }
        map<int,multiset<int>> nmp;
        rep(j,2*n) {
            nmp[cnt[j]].insert(j);
        }
        mp = nmp;
    }
    for(int i = 2*m+1; i >= 0; i--) {
        if(!mp.count(i)) continue;
        for(int p : mp[i]) cout << p+1 << endl;
    }
    return 0;
}
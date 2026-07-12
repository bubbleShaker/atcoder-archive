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
    
    Int n;
    cin >> n;
    vector<lP> ps(n);
    rep(i,n) cin >> ps[i].first >> ps[i].second;
    priority_queue<bP,vector<bP>,greater<bP>> q;
    rep(i,n) {
        auto [a,b] = ps[i];
        Int in = a;
        Int out = a+b;
        q.emplace(in,true);
        q.emplace(out,false);
    }
    Int cnt = 0;
    Int ans = 0;
    vector<Int> cv(n+1);
    while(!q.empty()) {
        auto [eve,fl] = q.top();
        q.pop();
        if(fl) cnt++;
        else cnt--;
        auto [neve,nfl] = q.top();
        cv[cnt] += neve-eve;
    }
    for(int i = 1; i <= n; i++) {
        cout << cv[i] << " ";
    }
    return 0;
}
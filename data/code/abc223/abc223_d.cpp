#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()

vector<Int> toposort(vector<vector<Int>> graph) {
    Int n = graph.size();
    vector<Int> indegree(n);
    rep(from,n) {
        for(Int to : graph[from]) indegree[to]++;
    }
    vector<Int> res;
    priority_queue<Int,vector<Int>,greater<Int>> heap;
    rep(i,n) {
        if(indegree[i] == 0) heap.push(i);
    }
    while(!heap.empty()) {
        Int from = heap.top(); heap.pop();
        res.push_back(from);
        for(Int to : graph[from]) {
            indegree[to]--;
            if(indegree[to] == 0) heap.push(to);
        }
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    Int n, m;
    cin >> n >> m;
    vector<vector<Int>> g(n);
    rep(i,m) {
        Int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
    }
    vector<Int> ans = toposort(g);
    if(ans.size() != n) {
        cout << -1 << endl;
        return 0;
    }
    rep(i,n) cout << ans[i]+1 << " ";
    return 0;
}
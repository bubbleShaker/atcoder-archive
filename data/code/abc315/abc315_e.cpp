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

vector<Int> topological_sort(vector<vector<Int>> graph) {
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
    
    Int n;
    cin >> n;
    vector<vector<Int>> g(n);
    vector<vector<Int>> tg(n);
    rep(i,n) {
        Int c; cin >> c;
        rep(j,c) {
            Int p; cin >> p; p--;
            g[p].push_back(i);
            tg[i].push_back(p);
        }
    }
    vector<Int> ans;
    ans = topological_sort(g);
    queue<Int> q;
    q.push(0);
    vector<bool> visited(n);
    visited[0] = true;
    while(!q.empty()) {
        Int from = q.front(); q.pop();
        for(Int to : tg[from]) {
            if(!visited[to]) {
                visited[to] = true;
                q.push(to);
            }
        }
    }
    rep(i,ans.size()) {
        if(ans[i] == 0) continue;
        if(visited[ans[i]]) {
            cout << ans[i]+1 << " ";
        }
    }
    return 0;
}
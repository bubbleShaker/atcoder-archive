#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int n,x,y;cin>>n>>x>>y;x--;y--;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<int> isVisited;
    vector<int> path;
    vector<int> ans;
    auto dfs=[&](auto dfs,int from,int p=-1)->void{
        path.push_back(from);
        if(from==y){
            ans=path;
            return;
        }
        for(int to:g[from]){
            if(to==p)continue;
            dfs(dfs,to,from);
        }
        path.pop_back();
        return;
    };
    dfs(dfs,x);
    int m=ans.size();
    for(int i=0;i<m;i++){
        cout<<ans[i]+1<<" \n"[i+1==m];
    }
    return 0;
}
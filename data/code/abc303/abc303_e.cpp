#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int start;
    for(int i=0;i<n;i++){
        if(deg[i]==1){
            start=i;
            break;
        }
    }
    vector<int> ans;
    auto dfs=[&](auto dfs,int from,int parent=-1)->void{
        if(deg[from]!=1){
            // cout<<from<<endl;
            ans.push_back(deg[from]);
        }
        for(int to:g[from]){
            if(to==parent)continue;
            if(deg[from]==1){
                dfs(dfs,to,from);
            }else{
                if(deg[to]==1)continue;
                for(int tonext:g[to]){
                    if(tonext==from)continue;
                    for(int next:g[tonext]){
                        if(next==to)continue;
                        dfs(dfs,next,tonext);
                    }
                }
            }
        }
    };
    dfs(dfs,start);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
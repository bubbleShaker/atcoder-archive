#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> g(n+1);
    int start;
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            start=i;
            continue;
        }
        g[i].push_back(a[i]);
        g[a[i]].push_back(i);
    }
    vector<int> ans;
    auto dfs=[&](auto dfs,int from,int parent=-1)->void{
        ans.push_back(from);
        for(int to:g[from]){
            if(to==parent)continue;
            dfs(dfs,to,from);
        }
    };
    dfs(dfs,start);
    int m=ans.size();
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
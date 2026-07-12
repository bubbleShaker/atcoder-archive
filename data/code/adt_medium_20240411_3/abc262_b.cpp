#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<set<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(g[i].count(j)&&g[j].count(k)&&g[k].count(i)){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
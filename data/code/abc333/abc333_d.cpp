#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int n;cin>>n;
    dsu uf(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        if(u==0||v==0)continue;
        uf.merge(u,v);
    }
    map<int,int> leaderMap;
    for(int i=1;i<n;i++){
        leaderMap[uf.leader(i)]++;
    }
    vector<int> vec;
    for(auto [leader,cnt]:leaderMap){
        vec.push_back(cnt);
    }
    sort(vec.begin(),vec.end());
    int ans=0;
    for(int i=0;i<vec.size()-1;i++){
        // cout<<vec[i]<<endl;
        ans+=vec[i];
    }
    cout<<ans+1<<endl;
    return 0;
}
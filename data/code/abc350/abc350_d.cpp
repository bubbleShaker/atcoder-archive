#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
    long long n,m;
    cin>>n>>m;
    dsu uf(n);
    vector<vector<long long>> g(n);
    for(int i=0;i<m;i++){
        long long a,b;
        cin>>a>>b;
        a--;b--;
        uf.merge(a,b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        long long s=uf.size(i);
        long long gs=g[i].size();
        ans+=s-1-gs;
    }
    ans/=2;
    cout<<ans<<endl;
    return 0;
}
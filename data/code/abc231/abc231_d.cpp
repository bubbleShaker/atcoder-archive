#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int n,m;cin>>n>>m;
    vector<int> deg(n);
    dsu uf(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;a--;b--;
        deg[a]++;
        deg[b]++;
        uf.merge(a,b);
    }
    map<int,int> twoDegCount,oneDegCount,p;
    set<int> jSet;
    for(int i=0;i<n;i++){
        if(deg[i]==0)continue;
        int j=uf.leader(i);
        jSet.insert(j);
        if(deg[i]==1)oneDegCount[j]++;
        if(deg[i]==2)twoDegCount[j]++;
        p[j]++;
    }
    bool isOk=true;
    for(int j:jSet){
        if(oneDegCount[j]==2&&twoDegCount[j]==(p[j]-2)){
        }else{
            isOk=false;
        }
        // cout<<oneDegCount[j]<<" "<<twoDegCount[j]<<" "<<p[j]<<endl;
    }
    if(isOk)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
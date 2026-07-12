#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<long long> x(m);
    vector<long long> rsw(n+1);
    for(int i=0;i<m;i++){
        cin>>x[i];
    }
    for(int i=0;i<m-1;i++){
        long long nowCost,anoCost,resCost;
        long long left,right;
        nowCost=abs(x[i]-x[i+1]);
        anoCost=abs(n-nowCost);
        resCost=nowCost-anoCost;
        left=min(x[i],x[i+1]);
        right=max(x[i],x[i+1]);
        rsw[left]+=resCost;
        rsw[right]-=resCost;
    }
    for(int i=0;i<n;i++){
        rsw[i+1]+=rsw[i];
    }
    pair<long long,long long> numCost;
    numCost={0,-(long long)1e18};
    for(int i=1;i<=n;i++){
        if(numCost.second<rsw[i]){
            numCost.first=i;
            numCost.second=rsw[i];
        }
    }
    long long ersBridge=numCost.first;
    // cout<<ersBridge<<endl;
    long long ans=0;
    for(int i=0;i<m-1;i++){
        long long left,right;
        left=min(x[i],x[i+1]);
        right=max(x[i],x[i+1]);
        if(left<=ersBridge&&ersBridge<=right-1){
            ans+=(n-(right-left));
        }else{
            ans+=right-left;
        }
    }
    cout<<ans<<endl;
    return 0;
}
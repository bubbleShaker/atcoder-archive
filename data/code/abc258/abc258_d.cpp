#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<pair<long long,long long>> s(n);
    for(int i=0;i<n;i++){
        long long a,b;cin>>a>>b;
        s[i]={a,b};
    }
    vector<long long> rsw(n+1);
    for(int i=0;i<n;i++){
        auto [a,b]=s[i];
        rsw[i+1]+=rsw[i]+a+b;
    }
    vector<long long> minBLength(n);
    for(int i=0;i<n;i++){
        auto [a,b]=s[i];
        if(i==0){
            minBLength[i]=b;
            continue;
        }
        minBLength[i]=min(minBLength[i-1],b);
    }
    long long ans=(long long)2e18;
    for(int i=0;i<n;i++){
        if(x-(i+1)<0)break;
        ans=min(ans,(long long)rsw[i+1]+(long long)minBLength[i]*(x-(i+1)));
    }
    cout<<ans<<endl;
    return 0;
}
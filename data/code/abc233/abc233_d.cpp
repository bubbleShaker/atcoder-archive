#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;cin>>n>>k;
    vector<long long> a(n);
    vector<long long> rsw(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        rsw[i+1]+=rsw[i]+a[i];
    }
    long long ans=0;
    map<long long,int> mp;
    for(int i=n;i>=0;i--){
        ans+=mp[rsw[i]+k];
        mp[rsw[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}
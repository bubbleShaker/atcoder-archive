#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    map<long long,long long> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    a.push_back(0);
    sort(a.rbegin(),a.rend());
    a.erase(unique(a.begin(),a.end()),a.end());
    int l=a.size();
    l--;
    long long ans=0;
    for(int i=0;i<l;i++){
        long long d=a[i]-a[i+1];
        long long s=(a[i]-d+1+a[i])*d/2;
        if(k>mp[a[i]]*d){
            k-=mp[a[i]]*d;
            ans+=mp[a[i]]*s;
            // cout<<ans<<endl;
            mp[a[i+1]]+=mp[a[i]];
            mp[a[i]]=0;
            // cout<<k<<" "<<ans<<" "<<mp[a[i+1]]<<endl;
        }else{
            long long p=k/mp[a[i]];
            long long q=k%mp[a[i]];
            ans+=(a[i]+a[i]-p+1)*p*mp[a[i]]/2;
            ans+=q*(a[i]-p);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
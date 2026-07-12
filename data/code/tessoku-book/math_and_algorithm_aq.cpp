#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a,long long b,long long MOD){
    map<long long,long long> mp;
    long long ans=1;
    mp[1<<0]=a;
    for(int i=0;(1<<i)<=b;i++){
        if(i>=1){
            mp[1<<i]=mp[1<<(i-1)]*mp[1<<(i-1)];
            mp[1<<i]%=MOD;
        }
        if((b|(1<<i))==b){
            ans*=mp[(1<<i)];
        }
        ans%=MOD;
    }
    return ans;
}
int main(){
    const long long MOD=(long long)1e9+7;
    long long a,b;
    cin>>a>>b;
    cout<<modpow(a,b,MOD)<<endl;
    return 0;
}
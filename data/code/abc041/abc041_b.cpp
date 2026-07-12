#include <bits/stdc++.h>
using namespace std;
int main(){
    const long long MOD=(long long)1e9+7;
    long long a,b,c;cin>>a>>b>>c;
    long long ans=1;
    ans*=a*b;
    ans%=MOD;
    ans*=c;
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}
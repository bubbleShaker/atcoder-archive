#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b;cin>>n>>a>>b;
    long long ans=0;
    ans+=(n/(a+b))*a;
    n%=(a+b);
    if(n>=a)ans+=a;
    else ans+=n;
    cout<<ans<<endl;
    return 0;
}
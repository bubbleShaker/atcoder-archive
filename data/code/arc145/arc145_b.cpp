#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b;cin>>n>>a>>b;
    long long ans=((n/a)-1)*min(a,b)+min(n-((n/a)*a-1),min(a,b));
    ans=max(ans,(long long)0);
    cout<<ans<<endl;
    return 0;
}
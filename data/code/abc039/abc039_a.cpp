#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;cin>>a>>b>>c;
    int ans=0;
    ans+=a*b*2;
    ans+=a*c*2;
    ans+=b*c*2;
    cout<<ans<<endl;
    return 0;
}
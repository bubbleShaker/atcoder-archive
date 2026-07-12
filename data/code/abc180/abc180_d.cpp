#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,y,a,b;cin>>x>>y>>a>>b;
    long long t=0;
    for(long long i=0;i<=30;i++){
        if(x>y/a)break;
        if(x*a>=y)break;
        if(x*a>=x+b)break;
        t++;
        x*=a;
    }
    long long ans=(y-1-x)/b+t;
    cout<<ans<<endl;
    return 0;
}
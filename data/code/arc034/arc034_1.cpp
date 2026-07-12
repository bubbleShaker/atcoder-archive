#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    double ans=0;
    for(int i=0;i<n;i++){
        double a,b,c,d,e;cin>>a>>b>>c>>d>>e;
        double sum=a+b+c+d+e*110/900;
        ans=max(ans,sum);
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    double ans=0;
    for(int i=0;i<n;i++){
        double x;
        string u;
        cin>>x>>u;
        if(u=="JPY")ans+=x;
        else ans+=x*(double)380000;
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
    return 0;
}
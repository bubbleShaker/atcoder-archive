#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    sort(p.rbegin(),p.rend());
    int ans=0;
    for(int i=0;i<n;i++){
        if(i==0)ans+=p[i]/2;
        else ans+=p[i];
    }
    cout<<ans<<endl;
    return 0;
}
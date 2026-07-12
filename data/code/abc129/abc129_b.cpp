#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> w(n);
    for(int i=0;i<n;i++)cin>>w[i];
    int ans=(int)2e9;
    for(int k=1;k<=n-1;k++){
        int s1=0,s2=0;
        for(int i=0;i<k;i++){
            s1+=w[i];
        }
        for(int i=k;i<n;i++){
            s2+=w[i];
        }
        ans=min(abs(s1-s2),ans);
    }
    cout<<ans<<endl;
    return 0;
}
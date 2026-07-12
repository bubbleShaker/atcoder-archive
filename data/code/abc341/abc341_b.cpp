#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<long long> s(n+1),t(n+1);
    for(int i=1;i<=n-1;i++){
        cin>>s[i]>>t[i];
    }
    for(int i=1;i<=n-1;i++){
        a[i+1]+=t[i]*(a[i]/s[i]);
        a[i]-=s[i]*(a[i]/s[i]);
    }
    cout<<a[n]<<endl;
    return 0;
}
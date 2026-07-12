#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),rsw(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        rsw[i+1]+=rsw[i]+a[i];
    }
    long long ans=0;
    int r=0;
    for(int l=0;l<n;l++){
        while(r<=n&&rsw[r]-rsw[l]<=k){
            r++;
        }
        r--;
        ans+=(long long)r-l;
    }
    cout<<ans<<endl;
    return 0;
}
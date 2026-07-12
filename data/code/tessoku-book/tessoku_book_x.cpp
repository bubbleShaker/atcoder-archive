#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> dp(n+1);
    vector<int> l(n+1);
    int len=0;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(l.begin()+1,l.begin()+len+1,a[i])-l.begin();
        dp[i]=pos;
        l[pos]=a[i];
        if(pos>len){
            len++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
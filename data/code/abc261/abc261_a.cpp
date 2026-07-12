#include <bits/stdc++.h>
using namespace std;
int main(){
    int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    vector<int> cnt(101);
    for(int i=l1;i<=r1;i++)cnt[i]++;
    for(int i=l2;i<=r2;i++)cnt[i]++;
    int ans=0;
    for(int i=0;i<=101;i++){
        if(cnt[i]==2)ans++;
    }
    if(ans!=0)ans--;
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int r=0;
    int cnt=0;
    int ans=0;
    map<int,int> x;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        while(r<n){
            if(x[a[r]]==0&&cnt==k)break;
            if(x[a[r]]==0)cnt++;
            x[a[r]]++;
            r++;
        }
        ans=max(ans,r-i);
        if(x[a[i]]==1){
            cnt--;
        }
        x[a[i]]--;
    }
    cout<<ans<<endl;
    return 0;
}
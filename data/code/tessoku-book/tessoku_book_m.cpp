#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans=0;
    int r;
    for(int i=0;i<n;i++){
        if(i==0){
            r=0;
        }else{
            r--;
        }
        while(r<n&&a[r]-a[i]<=k){
            r++;
        }
        ans+=(long long)r-i-1;
    }
    cout<<ans<<endl;
    return 0;
}
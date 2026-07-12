#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<bool> v(n+1,true);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(v[t]){
            v[t]=false;
        }else{
            v[t]=true;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
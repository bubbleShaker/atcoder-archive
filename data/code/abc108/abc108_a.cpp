#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;cin>>k;
    int ans=0;
    for(int i=1;i<=k;i+=2){
        for(int j=2;j<=k;j+=2){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
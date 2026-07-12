#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> p(n);
    vector<int> turnCount(n);
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++){
        int j=(n+i-p[i])%n;
        for(int k=-1;k<=1;k++){
            turnCount[(n-j+k)%n]++;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)ans=max(ans,turnCount[i]);
    cout<<ans<<endl;
    return 0;
}
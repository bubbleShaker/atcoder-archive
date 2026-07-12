#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    vector<int> t(n);
    for(int i=0;i<n;i++)cin>>t[i];
    for(int i=0;i<=n-3;i++){
        if(t[i]+t[i+1]+t[i+2]<k){
            cout<<i+3<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
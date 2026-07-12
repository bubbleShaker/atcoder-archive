#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> t(n);
    for(int i=0;i<n;i++)cin>>t[i];
    int sum=0;
    for(int i=0;i<n;i++)sum+=t[i];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int p,x;cin>>p>>x;p--;
        sum-=t[p];
        sum+=x;
        cout<<sum<<endl;
        sum-=x;
        sum+=t[p];
    }
    return 0;
}
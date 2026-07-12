#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    map<int,int> mp;
    mp[1]=300000;
    mp[2]=200000;
    mp[3]=100000;
    int ans=mp[x]+mp[y];
    if(x==1&&y==1){
        ans+=400000;
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,set<int>> mp;
    for(int i=0;i<n;i++){
        int a,c;
        cin>>a>>c;
        mp[c].insert(a);
    }
    int ans=0;
    for(auto [c,st]:mp){
        ans=max(ans,*st.begin());
    }
    cout<<ans<<endl;
    return 0;
}
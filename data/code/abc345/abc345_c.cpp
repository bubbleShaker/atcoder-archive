#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    long long n=s.size();
    map<char,long long> mp;
    long long ans=(n-1)*n/2;
    bool canAdd=false;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
        if(mp[s[i]]>=2)canAdd=true;
    }
    if(canAdd){
        ans++;
    }
    for(auto [c,cnt]:mp){
        ans-=(cnt-1)*cnt/2;
    }
    cout<<ans<<endl;
    return 0;
}
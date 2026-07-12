#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    map<char,int> mp;
    for(int i=0;i<3;i++){
        mp[s[i]]++;
    }
    for(auto [c,cnt]:mp){
        if(cnt==1){
            cout<<c<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
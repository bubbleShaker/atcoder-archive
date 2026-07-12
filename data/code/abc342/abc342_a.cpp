#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    map<char,int> mp;
    int n=s.size();
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp[s[i]]==1){
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}
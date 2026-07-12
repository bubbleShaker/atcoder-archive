#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char,int> mp;
    string w;cin>>w;
    for(char c:w){
        mp[c]++;
    }
    for(auto [c,cnt]:mp){
        if(cnt%2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
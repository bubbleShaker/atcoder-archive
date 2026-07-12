#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    vector<pair<int,char>> vec;
    for(auto [c,cnt]:mp){
        vec.push_back({cnt,c});
    }
    auto f=[&](pair<int,char> a,pair<int,char> b){
        if(a.first==b.first){
            return a.second<b.second;
        }else{
            return a.first>b.first;
        }
    };
    sort(vec.begin(),vec.end(),f);
    cout<<vec[0].second<<endl;
    return 0;
}